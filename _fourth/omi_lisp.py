#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import math
import re
import sys
from dataclasses import dataclass, asdict
from pathlib import Path
from typing import Any, Callable, Iterable, Iterator, Optional

MASK16 = 0xFFFF
RING_SIZE = 5040
SCOPES = ("FS", "GS", "RS", "US")
SCOPE_MASKS = {"FS": 0x0001, "GS": 0x0010, "RS": 0x0100, "US": 0x1000}
SUBPATH_MASKS = {"o": 0x000F, "/": 0x00F0, "?": 0x0F00, "@": 0xF000}
GOVERNORS = {"FACTS": -1, "RULES": 0, "CLOSURES": 1, "COMBINATORS": 2, "CONS": 3}
NULL_RING = (0x00, 0x20, 0x7F, 0xFF)
DPLUS = (0x0, 0x5, 0xA, 0xF)
DMINUS = (0x3, 0x6, 0x9, 0xC)
OMNICRON_ENVELOPE = (0xFF, 0x00, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0xFF)


class OmiError(Exception):
    pass


class Symbol(str):
    pass


@dataclass(frozen=True)
class Pair:
    car: Any
    cdr: Any

    def __iter__(self) -> Iterator[Any]:
        cur: Any = self
        while isinstance(cur, Pair):
            yield cur.car
            cur = cur.cdr
        if cur is not NIL:
            raise OmiError("improper list")

    def __repr__(self) -> str:
        parts: list[str] = []
        cur: Any = self
        while isinstance(cur, Pair):
            parts.append(format_value(cur.car))
            cur = cur.cdr
        if cur is NIL:
            return "(" + " ".join(parts) + ")"
        return "(" + " ".join(parts) + " . " + format_value(cur) + ")"


class _Nil:
    def __repr__(self) -> str:
        return "()"

    def __bool__(self) -> bool:
        return False


NIL = _Nil()


@dataclass
class Receipt:
    slot: int
    accepted: bool
    hash: str
    cycle: int
    source: str
    value: Any
    reason: str
    governor: str
    scope: str
    phase: int

    def to_json(self) -> dict[str, Any]:
        d = asdict(self)
        d["value"] = to_jsonable(self.value)
        return d


@dataclass
class GaugeResult:
    governor: str
    exponent: int
    scope: str
    scope_mask: int
    subpath: str
    subpath_mask: int
    phase: int
    value: float
    normalized_angle: float

    def to_json(self) -> dict[str, Any]:
        return asdict(self)


class Environment(dict[str, Any]):
    def __init__(self, parent: Optional["Environment"] = None, **values: Any):
        super().__init__(values)
        self.parent = parent

    def find(self, key: str) -> "Environment":
        if key in self:
            return self
        if self.parent is not None:
            return self.parent.find(key)
        raise OmiError(f"unbound symbol: {key}")


TOKEN_RE = re.compile(
    r'''\s*(,@|[()']|\.|"(?:\\.|[^"\\])*"|;[^\n]*|[^\s()'";]+)'''
)


def tokenize(source: str) -> list[str]:
    tokens: list[str] = []
    for match in TOKEN_RE.finditer(source):
        tok = match.group(1)
        if tok.startswith(";"):
            continue
        tokens.append(tok)
    return tokens


def parse_many(source: str) -> list[Any]:
    tokens = tokenize(source)
    forms: list[Any] = []
    while tokens:
        forms.append(read_form(tokens))
    return forms


def read_form(tokens: list[str]) -> Any:
    if not tokens:
        raise OmiError("unexpected EOF")
    token = tokens.pop(0)
    if token == "(":
        return read_list(tokens)
    if token == ")":
        raise OmiError("unexpected )")
    if token == "'":
        return Pair(Symbol("quote"), Pair(read_form(tokens), NIL))
    return atom(token)


def read_list(tokens: list[str]) -> Any:
    items: list[Any] = []
    while True:
        if not tokens:
            raise OmiError("unexpected EOF while reading list")
        if tokens[0] == ")":
            tokens.pop(0)
            return list_to_pair(items)
        if tokens[0] == ".":
            tokens.pop(0)
            if not items:
                raise OmiError("dot requires a CAR")
            tail = read_form(tokens)
            if not tokens or tokens.pop(0) != ")":
                raise OmiError("dotted pair must end with )")
            return list_to_pair(items, tail)
        items.append(read_form(tokens))


def atom(token: str) -> Any:
    if token.startswith('"'):
        return bytes(token[1:-1], "utf-8").decode("unicode_escape")
    if token == "#t":
        return True
    if token == "#f":
        return False
    if token.lower().startswith("0x"):
        try:
            return int(token, 16)
        except ValueError:
            pass
    try:
        return int(token)
    except ValueError:
        try:
            return float(token)
        except ValueError:
            return Symbol(token)


def list_to_pair(items: Iterable[Any], tail: Any = NIL) -> Any:
    out = tail
    for item in reversed(list(items)):
        out = Pair(item, out)
    return out


def pair_to_list(value: Any) -> list[Any]:
    out: list[Any] = []
    cur = value
    while isinstance(cur, Pair):
        out.append(cur.car)
        cur = cur.cdr
    if cur is not NIL:
        raise OmiError("expected proper list")
    return out


def format_value(value: Any) -> str:
    if value is NIL:
        return "()"
    if value is True:
        return "#t"
    if value is False:
        return "#f"
    if isinstance(value, str) and not isinstance(value, Symbol):
        return json.dumps(value)
    if isinstance(value, GaugeResult):
        return json.dumps(value.to_json(), sort_keys=True)
    if isinstance(value, Receipt):
        return json.dumps(value.to_json(), sort_keys=True)
    return repr(value) if isinstance(value, Pair) else str(value)


def to_jsonable(value: Any) -> Any:
    if value is NIL:
        return None
    if isinstance(value, Symbol):
        return str(value)
    if isinstance(value, Pair):
        try:
            return [to_jsonable(x) for x in pair_to_list(value)]
        except OmiError:
            return {"car": to_jsonable(value.car), "cdr": to_jsonable(value.cdr)}
    if isinstance(value, GaugeResult):
        return value.to_json()
    if isinstance(value, Receipt):
        return value.to_json()
    return value


def rotl16(x: int, n: int) -> int:
    n %= 16
    x &= MASK16
    return ((x << n) | (x >> (16 - n))) & MASK16


def rotr16(x: int, n: int) -> int:
    n %= 16
    x &= MASK16
    return ((x >> n) | (x << (16 - n))) & MASK16


def delta16(x: int, c: int) -> int:
    return rotl16(x, 1) ^ rotl16(x, 3) ^ rotr16(x, 2) ^ (c & MASK16)


def bqf32(x: int, y: int) -> int:
    return 60 * x * x + 16 * x * y + 4 * y * y


def xor_reduce(values: Iterable[int]) -> int:
    out = 0
    for value in values:
        out ^= int(value)
    return out


def fnv1a64(data: bytes) -> int:
    h = 0xCBF29CE484222325
    for b in data:
        h ^= b
        h = (h * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return h


def generalized_mean(values: list[float], p: int) -> float:
    if not values:
        raise OmiError("mean requires at least one value")
    if any(v <= 0 for v in values):
        raise OmiError("circular governor means require positive values")
    n = len(values)
    if p == 0:
        return math.exp(sum(math.log(v) for v in values) / n)
    return (sum(v ** p for v in values) / n) ** (1.0 / p)


def normalize_notation(text: str) -> dict[str, Any]:
    text = text.strip()
    old = text.startswith("omi-") and "-imo" in text
    folded = "omi---imo" in text or old
    subpaths = [c for c in ("o", "/", "?", "@") if c in text]
    if not subpaths:
        subpaths = list(SUBPATH_MASKS)
    return {
        "folded": folded,
        "old_notation": old,
        "root": "omi---imo" if folded else text,
        "subpaths": subpaths,
        "scope_forward": list(SCOPES),
        "scope_counter": list(reversed(SCOPES)),
    }


def compile_delta(scope: str) -> str:
    scope = scope.upper()
    if scope not in SCOPE_MASKS:
        raise OmiError(f"unknown scope: {scope}")
    return f"{scope}-LL-US-MM-US-NN-US-{scope}"


def validate_structure(value: Any) -> tuple[bool, str]:
    if isinstance(value, GaugeResult):
        if value.scope not in SCOPE_MASKS:
            return False, "invalid scope"
        if value.subpath not in SUBPATH_MASKS:
            return False, "invalid subpath"
        if value.governor not in GOVERNORS:
            return False, "invalid governor"
        return True, "gauge result structurally valid"
    if isinstance(value, str):
        n = normalize_notation(value)
        if n["folded"]:
            return True, "OMI relation recognized"
        return False, "not an OMI relation"
    if isinstance(value, Pair):
        return True, "dotted relation recognized"
    if isinstance(value, (int, float, bool)) or value is NIL:
        return True, "atomic value accepted"
    return False, f"unsupported value type: {type(value).__name__}"


class OmiRuntime:
    def __init__(self) -> None:
        self.ring: list[Optional[Receipt]] = [None] * RING_SIZE
        self.cycle = 0
        self.env = self._standard_env()

    def _standard_env(self) -> Environment:
        env = Environment()
        env.update({
            "+": lambda *xs: sum(xs),
            "-": lambda x, *xs: x - sum(xs) if xs else -x,
            "*": lambda *xs: math.prod(xs),
            "/": lambda x, y: x / y,
            "=": lambda a, b: a == b,
            "<": lambda a, b: a < b,
            ">": lambda a, b: a > b,
            "not": lambda x: not truthy(x),
            "list": lambda *xs: list_to_pair(xs),
            "cons": lambda a, b: Pair(a, b),
            "car": self._car,
            "cdr": self._cdr,
            "null?": lambda x: x is NIL,
            "pair?": lambda x: isinstance(x, Pair),
            "xor": lambda *xs: xor_reduce(int(x) for x in xs),
            "rotl16": rotl16,
            "rotr16": rotr16,
            "delta16": delta16,
            "bqf32": bqf32,
            "hash": lambda x: fnv1a64(canonical_bytes(x)),
            "normalize-notation": normalize_notation,
            "compile-delta": compile_delta,
            "gauge-resolve": self.gauge_resolve,
            "validate": self.validate,
            "receipt": self.receipt_at,
            "ring-count": lambda: sum(x is not None for x in self.ring),
            "null-ring-xor": lambda: xor_reduce([NULL_RING[i] ^ NULL_RING[(i + 1) % 4] for i in range(4)]),
            "dplus-xor": lambda: xor_reduce(DPLUS),
            "dminus-xor": lambda: xor_reduce(DMINUS),
            "metatron": lambda: {"word": 0xAA55, "inverse": 0x55AA, "xor": 0xFFFF, "ones": 8, "zeros": 8},
            "tetragrammatron": lambda: {"dplus": DPLUS, "dminus": DMINUS, "sum_each": 0x1E, "fold": 0x3C, "carry": 0x78},
            "omnicron-envelope": lambda: list(OMNICRON_ENVELOPE),
            "FS": Symbol("FS"), "GS": Symbol("GS"), "RS": Symbol("RS"), "US": Symbol("US"),
            "FACTS": Symbol("FACTS"), "RULES": Symbol("RULES"), "CLOSURES": Symbol("CLOSURES"),
            "COMBINATORS": Symbol("COMBINATORS"), "CONS": Symbol("CONS"),
            "NIL": NIL,
        })
        return env

    @staticmethod
    def _car(x: Any) -> Any:
        if not isinstance(x, Pair):
            raise OmiError("car expects a pair")
        return x.car

    @staticmethod
    def _cdr(x: Any) -> Any:
        if not isinstance(x, Pair):
            raise OmiError("cdr expects a pair")
        return x.cdr

    def eval_program(self, source: str) -> Any:
        result: Any = NIL
        for form in parse_many(source):
            result = self.eval(form, self.env)
        return result

    def eval(self, expr: Any, env: Environment) -> Any:
        if isinstance(expr, Symbol):
            return env.find(str(expr))[str(expr)]
        if not isinstance(expr, Pair):
            return expr
        forms = pair_to_list(expr)
        if not forms:
            return NIL
        op = forms[0]
        if isinstance(op, Symbol):
            name = str(op)
            if name == "quote":
                self._arity(forms, 2)
                return forms[1]
            if name == "if":
                if len(forms) not in (3, 4):
                    raise OmiError("if expects 2 or 3 arguments")
                return self.eval(forms[2], env) if truthy(self.eval(forms[1], env)) else self.eval(forms[3], env) if len(forms) == 4 else NIL
            if name == "begin":
                out: Any = NIL
                for f in forms[1:]:
                    out = self.eval(f, env)
                return out
            if name == "define":
                self._arity(forms, 3)
                if not isinstance(forms[1], Symbol):
                    raise OmiError("define name must be a symbol")
                value = self.eval(forms[2], env)
                env[str(forms[1])] = value
                return value
            if name == "lambda":
                if len(forms) < 3:
                    raise OmiError("lambda expects params and body")
                params = [str(x) for x in pair_to_list(forms[1])]
                body = forms[2:]
                return self._lambda(params, body, env)
            if name == "cite":
                self._arity(forms, 2)
                value = self.eval(forms[1], env)
                return self.cite(value)
        fn = self.eval(op, env)
        args = [self.eval(x, env) for x in forms[1:]]
        if not callable(fn):
            raise OmiError(f"{format_value(fn)} is not callable")
        return fn(*args)

    @staticmethod
    def _arity(forms: list[Any], n: int) -> None:
        if len(forms) != n:
            raise OmiError(f"expected {n - 1} arguments")

    def _lambda(self, params: list[str], body: list[Any], closure: Environment) -> Callable[..., Any]:
        def fn(*args: Any) -> Any:
            if len(args) != len(params):
                raise OmiError("lambda arity mismatch")
            local = Environment(closure, **dict(zip(params, args)))
            out: Any = NIL
            for form in body:
                out = self.eval(form, local)
            return out
        return fn

    def gauge_resolve(self, governor: Any, scope: Any, subpath: Any, phase: int, *values: float) -> GaugeResult:
        g = str(governor).upper()
        s = str(scope).upper()
        pth = str(subpath)
        if g not in GOVERNORS:
            raise OmiError(f"unknown governor: {g}")
        if s not in SCOPE_MASKS:
            raise OmiError(f"unknown scope: {s}")
        if pth not in SUBPATH_MASKS:
            raise OmiError(f"unknown subpath: {pth}")
        if not values:
            raise OmiError("gauge-resolve needs numeric values")
        p = GOVERNORS[g]
        result = generalized_mean([float(v) for v in values], p)
        phase_n = int(phase) % 60
        angle = (phase_n / 60.0) * math.tau
        return GaugeResult(g, p, s, SCOPE_MASKS[s], pth, SUBPATH_MASKS[pth], phase_n, result, angle)

    def cite(self, value: Any) -> Receipt:
        accepted, reason = validate_structure(value)
        self.cycle += 1
        raw = canonical_bytes(value)
        h = fnv1a64(raw)
        scope, governor, phase = infer_context(value)
        local = bqf32(h & 0xF, (h >> 4) & 0xF) % 240
        fano = (h >> 28) % 7
        role = (h >> 24) % 3
        slot = int(fano * 720 + role * 240 + local)
        receipt = Receipt(
            slot=slot,
            accepted=accepted,
            hash=f"0x{h:016X}",
            cycle=self.cycle,
            source=format_value(value),
            value=value,
            reason=reason,
            governor=governor,
            scope=scope,
            phase=phase,
        )
        self.ring[slot] = receipt
        return receipt

    def validate(self, value: Any) -> bool:
        return validate_structure(value)[0]

    def receipt_at(self, slot: int) -> Any:
        if not 0 <= int(slot) < RING_SIZE:
            raise OmiError("receipt slot out of range")
        return self.ring[int(slot)] or NIL

    def save_ring(self, path: Path) -> None:
        data = [r.to_json() if r else None for r in self.ring]
        path.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")

    def load_ring(self, path: Path) -> None:
        data = json.loads(path.read_text(encoding="utf-8"))
        if len(data) != RING_SIZE:
            raise OmiError("invalid ring size")
        ring: list[Optional[Receipt]] = []
        for item in data:
            ring.append(None if item is None else Receipt(**item))
        self.ring = ring
        self.cycle = max((r.cycle for r in ring if r), default=0)


def infer_context(value: Any) -> tuple[str, str, int]:
    if isinstance(value, GaugeResult):
        return value.scope, value.governor, value.phase
    return "US", "RULES", 0


def truthy(value: Any) -> bool:
    return value is not False and value is not NIL


def canonical_bytes(value: Any) -> bytes:
    return json.dumps(to_jsonable(value), sort_keys=True, separators=(",", ":")).encode("utf-8")


def run_file(runtime: OmiRuntime, path: Path) -> Any:
    return runtime.eval_program(path.read_text(encoding="utf-8"))


def repl(runtime: OmiRuntime) -> None:
    print("OMI-Lisp runtime. Ctrl-D to exit.")
    while True:
        try:
            line = input("omi> ")
            if not line.strip():
                continue
            print(format_value(runtime.eval_program(line)))
        except EOFError:
            print()
            break
        except Exception as exc:
            print(f"error: {exc}", file=sys.stderr)


def main(argv: Optional[list[str]] = None) -> int:
    parser = argparse.ArgumentParser(description="OMI-Lisp circular gauge runtime")
    parser.add_argument("file", nargs="?", help="OMI-Lisp source file")
    parser.add_argument("-e", "--eval", dest="expression", help="evaluate one expression")
    parser.add_argument("--ring", help="load/save receipt ring JSON")
    parser.add_argument("--json", action="store_true", help="print JSON-compatible output")
    args = parser.parse_args(argv)

    runtime = OmiRuntime()
    ring_path = Path(args.ring) if args.ring else None
    if ring_path and ring_path.exists():
        runtime.load_ring(ring_path)

    try:
        if args.expression is not None:
            result = runtime.eval_program(args.expression)
        elif args.file:
            result = run_file(runtime, Path(args.file))
        else:
            repl(runtime)
            result = NIL
        if args.expression is not None or args.file:
            print(json.dumps(to_jsonable(result), indent=2, sort_keys=True) if args.json else format_value(result))
        if ring_path:
            runtime.save_ring(ring_path)
        return 0
    except Exception as exc:
        print(f"OMI-Lisp error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
