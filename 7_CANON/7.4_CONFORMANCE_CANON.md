# Conformance Canon

A conforming OMI implementation must preserve the lower validation pipeline, receipt semantics, and projection boundary.

## Required Acceptance Pipeline

```text
frame S
  -> anchor check
  -> Q_frame(S) = 0
  -> truth row (LL, NN, MM)
  -> LL-modulated Delta/Fano resolution
  -> 64-bit receipt
  -> 5040-slot replay ring
  -> projection
```

## Required Rules

1. Recognize `0x03BF` and `0x039F` as canonical lower frame anchors.
2. Validate frames via `Q_frame(S) = E_var + E_const = 0`.
3. Treat `Q_frame` as the sole structural admission predicate.
4. Extract exactly one truth row `(LL, NN, MM)` from a valid frame.
5. Implement the Delta Law with circular rotations, XOR mixing, and explicit 16-bit masking.
6. Implement LL-modulated Fano resolution for accepted truth rows.
7. Reject truth rows that do not resolve inside the bounded Fano window.
8. Write accepted rows as replayable 64-bit receipts.
9. Store receipts in the `7! = 5040` slot replay ring.
10. Accept the canonical genesis frame.
11. Reject malformed, byte-swapped, or anchor-invalid frames.
12. Treat DOM, SVG, JSON Canvas, QR, portal UI, typography, color, and `unicode-bidi` as projection or reader lenses only.

## Genesis Fixture

```text
BOOT_ADDRESS = 0x7C00
BOOT_SLOT = 0x7C00 mod 5040 = 1504
GENESIS_LL = 0x01
GENESIS_NN = 0x7C00
C = (0x01 * 0x1337) & 0xFFFF = 0x1337
GENESIS_MM = Delta_{0x1337}(0x7C00) = 0x1434
GENESIS_STEPS = 1
```

Canonical frame:

```text
0100-03bf-7c00-2b01-2f01-1434-039f-01ff
```

## Projection Boundary

After acceptance, implementations may project state into:

```text
DOM
SVG
JSON Canvas
IPv6
QR
portal UI
ShadowDOM
text
color
reader lenses
```

Those projections must remain downstream of validation and receipt.

## Non-Conformance

An implementation is non-conforming if it:

```text
uses unicode-bidi as lower validation authority
accepts frames without Q_frame(S) = 0
projects before validation
writes receipts before Fano resolution
treats glyphs, color, DOM, or portal UI as semantic authority
collapses conflicting receipts without an inspectable rule

## Rule-to-Fact Derivation Conformance

A conforming implementation must support grounding rules as facts. This means:

```text
A rule exists in RULES.omi.
An implementation satisfies the invariant.
A test verifies the implementation.
A fact is emitted to FACTS.omi.
A projection makes the fact inspectable.
```

The derivation follows the rule-to-fact protocol:

1. Address scope is determined by prefix (CIDR depth).
2. Constrained segments are identified.
3. A bitboard mask is built for structurally relevant fields.
4. The axiom family determines the bitblip policy (how deviations are handled).
5. Input state is defined, transition is applied, output state is recorded.
6. A derived fact row is emitted with test and projection attachments.

A conforming implementation must not:

```text
emit facts without corresponding rules
emit facts without passing tests
skip bitboard validation during derivation
use different bitblip policies than declared
project facts before validation
```

See also: [7.5 Rule-to-Fact Derivation](7.5_RULE_TO_FACT_DERIVATION.md)
```
