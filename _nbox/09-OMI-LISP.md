# State 09 — OMI-Lisp: The Declaration Surface

## What This State Is

This state is the transition from "how the protocol communicates" to "what can be declared." After establishing the wire format, the next question is: what language expresses Relations at rest — before they are transmitted, after they are received, and as they are composed into larger structures?

OMI-Lisp is that language. It is not a general-purpose programming language. It is a notation surface for Relations.

---

## The Grammar

OMI-Lisp has four base syntactic forms:

```
SExpr =
  SNil             — the void expression
  SSym [Byte]      — a symbolic atom
  SStr [Byte]      — a quoted string
  SCons SExpr SExpr — a pair of expressions
```

Every OMI-Lisp expression is one of these four. There are no special forms, no macros, no evaluation rules. OMI-Lisp is a data notation — it describes structure, not computation.

### Decision Tables

A decision table is a structured S-expression that encodes a Karnaugh map over binary conditions. It is a fifth syntactic form defined as sugar over SCons:

```
DecisionTable =
  (decision-table
    (name . SSym)
    (inputs . (C1 C2 ... Cn))
    (output . SSym)
    (truth-operator . SSym)  ;; Wittgenstein operator: ⊥ NOR ↚ ¬p ↛ ¬q XOR NAND AND XNOR q p→q p p←q OR ⊤
    (rules . ((condition1 . output1) (condition2 . output2) ...)))
```

Each condition is a string of `T`/`F` characters of length equal to the input count (e.g. `TTFF` for 4 inputs). Each output is a symbol naming the result when that condition vector is satisfied.

The decision table does not execute — it declares a truth mapping. Evaluation of which rule fires for a given condition vector belongs to the blackboard (State 10) and the gauge (State 12).

Example — the 4-input constitutional cell:

```omi
(decision-table
  (name . "Q1-A1")
  (inputs . (C1 C2 C3 C4))
  (output . proof-form)
  (truth-operator . OR)
  (rules .
    ((TTTT . constructive)
     (TTTF . constructive)
     (TTFT . constructive)
     (TTFF . falsification)
     (TFTT . constructive)
     (TFTF . falsification)
     (TFFT . falsification)
     (TFFF . falsification)
     (FTTT . constructive)
     (FTTF . falsification)
     (FTFT . falsification)
     (FTFF . falsification)
     (FFTT . falsification)
     (FFTF . falsification)
     (FFFT . falsification)
     (FFFF . falsification))))
```

The `truth-operator` selects which Wittgenstein 16-function maps the 4 citation slots onto the binary output. A decision table with the operator `⊤` (tautology, TTTT) always outputs constructive; `⊥` (contradiction, FFFF) always outputs falsification; `AND` (TFFF) outputs constructive only when all 4 slots hold.

Truth-gate files (FACTS.omi, RULES.omi, COMBINATORS.omi, CLOSURES.omi, CONS.omi) are decision tables over the constitutional grid — each file provides the Karnaugh-map partial table for a subset of the 448 cells.

### Symbols

A symbol is a sequence of alphanumeric characters, underscores, hyphens, plus signs, or asterisks:

```
hello
world
foo-bar
+delta*
_private
```

Symbols are not variables. They are names for Relations. The mapping from symbol to Relation is established by declaration and maintained by receipt.

### Strings

A string is a sequence of bytes enclosed in double quotes:

```
"hello world"
"path/to/resource"
```

Strings carry data that is not intended to be interpreted as Relation names. They are the carrier for external content — file paths, identifiers in foreign systems, human-readable labels.

### Lists and Pairs

A proper list is a chain of SCons cells terminated by SNil:

```
(a b c)  =  SCons a (SCons b (SCons c SNil))
```

A dotted pair terminates with a non-nil expression:

```
(a . b)  =  SCons a b
```

Both forms are valid in OMI-Lisp. The difference selects whether the expression expects continuation (proper list) or declares a completed mapping (dotted pair).

---

## The Canonical Program

The smallest meaningful OMI-Lisp declaration is:

```
(boot . (seed . delta))
```

This declares:

- **boot** is the entry point
- **seed** is the initial state
- **delta** is the transition function

No object system, no type annotations, no import statements. Just nested relations.

---

## Relation to the Blackboard

OMI-Lisp declarations are not executed in the traditional sense. They are placed on the blackboard (State 10), where they become the addressed vertices for lazy evaluation:

```
OMI-Lisp Declaration
    ↓
Blackboard Vertex
    ↓
Lazy Evaluation (bitboard × bit-blip)
    ↓
Resolved Face
```

A declaration does not run. It occupies a position. Evaluation is the resolution of that position through the blackboard's surface projection.

---

## What OMI-Lisp Is Not

- Not a general-purpose language (no loops, no functions, no types)
- Not a markup language (no tags, no attributes, no schemas)
- Not a query language (no selectors, no patterns, no joins)
- Not a serialization format (no schemas, no versioning, no compression)

OMI-Lisp is a declaration surface. It says what Relations exist. It does not say what they mean — interpretation belongs to the gauge (State 12) and the projection faces (State 11).

---

## Doctrine Sentence

> OMI-Lisp does not compute. It declares. Computation is the resolution of declarations on the blackboard through the gauge-selected projection.
