# The Slash Path: Declared Interpretation Route

## Canonical Shape

The identity surface is:

```text
omi---imo
```

The routed interpretation path is:

```text
/---/
```

The slash path does not store data. It declares how the source is read.

A fully qualified OMI expression has the shape:

```text
omi---imo/<control>/<scale>/<relation>/<unit>/
```

## Path Components

| Component | Role |
|-----------|------|
| `omi-` | Omicron opening, selects address perspective |
| `--imo` | Omicron closing, mirrors or closes interpretation |
| `/---/` | Routed interpretation path |

The source remains stable. The path declares the route.

## Relation to the Hyphen Form

The standard OMI palindrome uses hyphens as the join field:

```text
omi-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX-imo
```

The slash path is not a replacement. It is a declaration of interpretation: it names the functional role of each position in the address.

```text
omi---imo/<control>/<scale>/<relation>/<unit>/
```

The hyphens bind terms. The slashes name their roles.

## Reading the Slash Path

Forward:

```text
omi---imo bounds.
/control/ starts, stops, shifts.
/scale/ declares the reading.
/relation/ joins the terms.
/unit/ declares the atomic transition.
```

The slash path lets a reader know not just where data is, but how it should be interpreted. This is notation as cipher: the path structure is the interpretation declaration.

## Horn-Clause Derivation

The slash path is also a Horn-clause derivation route. The three-component model is:

```text
omi---imo = binary rewrite identity
/---/     = routed interpretation path
?---?     = external payload or stream attachment
```

The identity is the frame. The slash path is the derivation route outside the identity closure:

```text
omi---imo/<control>/<scale>/<relation>/<unit>/
```

The frame identifies. The path derives. Every slash segment is a clause selector that narrows the interpretation domain:

```text
omi---imo/semantic/subject/predicate/object/
```

Each segment adds a clause:

```prolog
domain(Frame, semantic).
subject(Frame, subject).
predicate(Frame, predicate).
object(Frame, object).
```

The receipt records the accepted traversal.

The slash path therefore serves two roles simultaneously:
1. It declares how the source should be read (notation as cipher).
2. It provides a clause route for derivation and receipt (Horn-clause protocol).

These are the same path — the slash path is both interpretation declaration and derivation program.

## Source

This document derives from section 7 of [MANIFESTO.md](../MANIFESTO.md).

See also:

- [1.1 The Palindrome](1.1_THE_PALINDROME.md) -- the hyphen-delimited form
- [3.3 The Meta-Circular Chronograph Compiler](../3_ARCHITECTURE/3.3_META_CIRCULAR_COMPILER.md) -- how the path compiles
- [2.7 Omi-Nomogram](../2_MATH/2.7_OMI_NOMOGRAM.md) -- the scale row
- [4.4 Horn-Clause Address Derivation](../4_NETWORK/4.4_HORN_CLAUSE_DERIVATION.md) -- paths as derivation clauses
