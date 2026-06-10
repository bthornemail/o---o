# OMI Matrix Lookup Rewrite Tables

Status: draft v0  
Repository role: abstract documentation and derivation surface  
Implementation companion: `bthornemail/omi-portal`

This directory encodes the refined native OMI addressing model into `.omi` source lookup tables and `.imo` inspection mirrors.

The purpose is to document the pure-function rewrite table layer that promotes already-tested GPIO/message/QEMU/eBPF routing into the stricter native OMI derivation grammar:

```text
omi-<frame>/<claim>/@<lens>/@<selector>/@<overlay>-imo
```

Meaning:

```text
frame  = identity
claim  = CIDR claim reduction
@ path = Horn-clause reader lens route
-imo   = closed derivation surface
```

These files are a documentation-side seed layer. They do not replace the production-qualified `omi-portal` root lookup tables. They describe how refined OMI declarative modules should be encoded, inspected, and eventually folded into implementation.

## File set

```text
RULES.address-derivation.omi       constraints
FACTS.address-derivation.omi       observed/applied states
CLOSURES.address-derivation.omi    bounded acceptance surfaces
COMBINATORS.address-derivation.omi rewrite/f-expression transforms
CONS.address-derivation.omi        monotone lookup pairs
ADDRESS_DERIVATION.imo             Omicron-delimited inspection mirror
TEST_PLAN.md                       parity and promotion test doctrine
```

## Core doctrine

```text
RULES constrain.
FACTS declare.
CLOSURES bound.
COMBINATORS transform.
CONS folds.
JOIN binds.
COMPOSE orders.
ENCODE projects.
DECODE reads.
Receipt accepts.
```

## Native acceptance chain

```text
GPIO edge
→ omi-<frame>/128/@hardware/@esp32-s3/@gpio/@edge-imo
→ RULES lookup
→ FACTS row
→ CLOSURE window
→ COMBINATOR decode
→ CONS fold
→ JOIN device world
→ COMPOSE previous_state MM
→ ENCODE projection
→ DECODE carrier NN
→ receipt accepted
→ OMI Matrix projection
```

## Non-collapse rule

```text
The .omi tables declare and route.
The .imo mirror inspects and exports.
The OMI Matrix projects.
The receipt accepts.
```

Projection does not become authority. Display does not become acceptance. Address validity remains frame-governed; the path is the derivation route.
