# Horn-Clause Address Derivation

## Three Components

An OMI address has three distinct components:

```text
omi---imo = binary rewrite identity
/---/     = routed interpretation path
?---?     = external payload or stream attachment
```

These compose into a full derivation surface:

```text
omi---imo/---/
```

or with payload:

```text
omi---imo/---/?---?
```

---

## Identity: `omi---imo`

The binary rewrite identity is the `omi---imo` surface. The `---` bridge holds the frame:

```text
omi---imo = binary rewrite identity
omi  = entry
---  = bridge / join field
imo  = closure
```

With concrete frame segments:

```text
omi-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-imo
```

The identity is the frame. The path is not identity — the path is interpretation.

---

## Path: `/---/`

The routed interpretation path is a separate slash-delimited component outside the `omi-...-imo` closure:

```text
omi---imo/<depth>/<domain>/<selector>/<overlay>/
```

The path carries the derivation route:

```text
The frame identifies.
The path derives.
The clauses validate.
The receipt accepts.
```

### Path Segments as Horn Clauses

Every path segment is a clause selector. The path `/hardware/i2c/euler/` may be interpreted as:

```prolog
derive(Frame, Surface) :-
    domain(Frame, hardware),
    interface(Frame, i2c),
    selector(Frame, euler),
    receipt(Frame, Surface).
```

A path is therefore not just navigation — it is a query, a derivation program, a clause route.

### Path Classes

| Class | Form | Meaning |
|---|---|---|
| Prefix | `/<depth>/` | Resolve at exact bit depth |
| HD derivation | `/p/q/r/` | Ordered stepwise derivation |
| Semantic | `/S/P/O/M/` | Subject/Predicate/Object/Modality |
| Domain | `/domain/selector/overlay/` | Protocol domain route |
| Agreement role | `/LL/NN/MM/OO/` | Lens/antecedent/consequent/operator |

### Canonical Path Form

The preferred path form is:

```text
/<depth>/<domain>/<selector>/<overlay>/
```

Where:

```text
depth    = resolution depth or derivation horizon
domain   = protocol domain or interpretation space
selector = route target, role, mnemonic, or clause
overlay  = projection, modality, or secondary frame
```

---

## Payload: `?---?`

External payloads or stream attachments use `?` as delimiters:

```text
omi---imo/---/?base64payload?
```

The payload is not part of the frame or path. It is an external carrier — data to be interpreted through the path:

```text
?---? = external payload or stream attachment
```

---

## Binary Compatibility

Path derivation is outside the frame:

```text
omi---imo
```

remains valid as pure identity. The path only adds interpretation:

```text
Frame-compatible nodes route.
Path-aware nodes derive.
Receipt-aware nodes accept.
```

Legacy or constrained nodes may ignore the path and still route by identity. Higher-level nodes may interpret the path as a derivation route and produce receipts.

---

## Aliases

All surface aliases normalize to the same internal structure:

```text
omi---imo                           binary rewrite identity
omi-XXXX-...-XXXX-imo               concrete frame identity
omi---imo/---/                      identity with path
omi---imo/---/?---?                 identity with path and payload
```

Aliases may vary. Normalization must not.

---

## Canonical Doctrine

```text
omi---imo is binary rewrite identity.
/---/ is routed interpretation path.
?---? is external payload or stream.

Frame identifies.
Path derives.
Clauses validate.
Receipt accepts.
```

---

See also: [4.1 IPv6 Frame Mapping](4.1_IPv6_FRAME_MAPPING.md), [4.2 RULES.omi](4.2_RULES_OMI.md), [1.5 The Slash Path](../1_FOUNDATIONS/1.5_THE_SLASH_PATH.md)
