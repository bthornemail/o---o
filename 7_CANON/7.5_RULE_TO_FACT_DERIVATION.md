# Rule-to-Fact Derivation Protocol

## Central Derivation Law

> **A fact is a grounded rule transition.**

A rule is normative: `<omi-address>/<prefix> MUST <invariant-name>`

A fact is grounded: `<omi-address>/<prefix> FACT <applied-fact-name>`

A rule says what must be true for conformance. A fact says where that rule is grounded in the current system.

```text
RULES.omi = normative invariant space
FACTS.omi = applied runtime/physical/deployment space

rule clause
→ state transition
→ observed or configured fact
```

---

## Provider Contract

```text
No address without a rule.
No rule without a test.
No test without a replay path.
No replay path without visible state.
```

A provider emits a derived fact only when:

```text
the rule exists
the address is stable
the implementation exists
the test passes
the failure behavior is defined
the projection is inspectable
```

---

## A-List State Transition Form

Every derivation is expressible as an association list:

```lisp
(
  (rule . <rule-pointer>)
  (modal . MUST)
  (invariant . <invariant-name>)
  (state-before . <input-state>)
  (transition . <transition-name>)
  (state-after . <derived-fact-state>)
  (bitboard . <mask>)
  (bitblip . <correction-policy>)
  (fact . <fact-pointer>)
  (test . <test-file>)
  (projection . <visible-output>)
)
```

Canonical abstract form:

```lisp
(
  (rule . "omi-.../prefix MUST invariant-name")
  (state-before . "unverified")
  (transition . "derive-applied-fact")
  (state-after . "configured")
  (fact . "omi-.../prefix FACT applied-fact-name")
)
```

---

## Bitboard Masks

A **bitboard** is the fixed-width mask used to extract or compare rule-bearing fields.

For an OMI frame `S = [S0, S1, S2, S3, S4, S5, S6, S7]` (each segment 16 bits), a bitboard mask declares which fields are structurally relevant.

Default mask derivation by prefix:

| Prefix | Segment Mask |
|---|---|
| `/48` | `[ffff,ffff,ffff,0000,0000,0000,0000,0000]` |
| `/80` | `[ffff,ffff,ffff,ffff,ffff,0000,0000,0000]` |
| `/96` | `[ffff,ffff,ffff,ffff,ffff,ffff,0000,0000]` |
| `/112` | `[ffff,ffff,ffff,ffff,ffff,ffff,ffff,0000]` |
| `/120` | byte-specific narrowing of final segment |
| `/128` | `[ffff,ffff,ffff,ffff,ffff,ffff,ffff,ffff]` |

Many OMI rules use sparse symbolic masks, not plain CIDR masks. When a rule explicitly constrains non-contiguous segments, derive the mask from the invariant name rather than prefix alone.

---

## Bitblip Policies

A **bitblip** is a small bit-level deviation from an expected mask. Bitblip handling defines what happens when an input is near the expected rule pointer but not exact.

| Policy | Meaning |
|---|---|
| `accept-exact` | Only exact bitboard match is valid |
| `correct-single` | One-bit deviation may be corrected |
| `evict-single` | One-bit deviation is rejected |
| `correct-up-to-2` | Up to two bit deviations may be repaired |
| `evict-over-2` | More than two bit deviations are rejected |
| `warn-near-miss` | Near miss routes to warning but does not commit |
| `drop-packet` | Kernel/network failure path |
| `skip-replay` | Do not write receipt |
| `route-preset-1` | Visual warning projection |

Default bitblip policies by axiom family:

| Axiom Family | Default Bitblip Policy |
|---|---|
| `algebraic-membership` | `evict-single` |
| `delta-orbit` | `evict-single` |
| `barcode-ecc` | `correct-up-to-2`, then `evict-over-2` |
| `telemetry-isolation` | `accept-exact` |
| `kernel-enforcement` | `drop-packet` |
| `browser-projection` | `warn-near-miss` |
| `replay-ring` | `reject-warm-overwrite` |
| `clock-tree` | `mark-gated` |
| `notation` | `evict-fractional-overflow` |
| `service-bus` | `accept-exact` |

---

## Derivation Algorithm

Given a rule row `R = address/prefix MUST invariant`, derive a fact as follows:

1. Parse address into eight 16-bit segments.
2. Determine prefix scope.
3. Identify constrained segments.
4. Build segment bitboard mask.
5. Identify axiom family.
6. Define input state.
7. Define transition operation.
8. Define output state.
9. Define exact-match condition.
10. Define bitblip correction/eviction policy.
11. Emit derived FACT row.
12. Attach test.
13. Attach projection.

---

## Complete Derivation Template

A `FACTS.omi` row derived from `RULES.omi` is complete only when it has:

```text
rule pointer
axiom family
state transition
bitboard mask
bitblip policy
fact pointer
test
projection
failure behavior
```

Therefore:

```text
derived fact = rule clause + state transition + bitboard + bitblip + proof path
```

### Markdown Table Template

| Field | Value |
|---|---|
| Rule ID | `0x___` |
| Rule Pointer | `omi-.../...` |
| Invariant | `...` |
| Axiom Family | `...` |
| Input State | `unverified` |
| Transition | `...` |
| Output State | `configured` |
| Fact Pointer | `omi-.../...` |
| Fact Name | `...` |
| Segment Mask | `[....]` |
| Bitboard Mask | `0x...` |
| Bitblip Policy | `...` |
| Test | `test/...` |
| Projection | `...` |
| Failure Behavior | `...` |

### A-List Template

```lisp
(
  (rule-id . "0x___")
  (rule-pointer . "omi-____-____-____-____-____-____-____-____/___")
  (modal . "MUST")
  (invariant . "________________________")
  (axiom-family . "________________________")

  (state-before . "unverified")
  (transition . "derive-applied-fact")
  (state-after . "configured")

  (segment-mask . "[____,____,____,____,____,____,____,____]")
  (expected-segments . "[____,____,____,____,____,____,____,____]")
  (bitboard-mask . "0x________________________________")
  (bitblip-policy . "accept-exact | correct-single | evict-single | evict-over-2")

  (fact-pointer . "omi-____-____-____-____-____-____-____-____/___")
  (fact-name . "________________________")

  (test . "test/________________.test.js")
  (projection . "cssom | json-canvas | sse | bpf-map | replay-ring | log")
  (failure-behavior . "reject-token | evict-frame | drop-packet | route-preset-1 | skip-replay")
)
```

### FACTS.omi Section Template

```text
# ============================================================================
# Derived Facts: <Subsystem Name>
# Source: RULES.omi <rule range>
# Derivation: <a-list transition table name>
# ============================================================================

# [Derived from Rule 0x___]
# Rule: <invariant-name>
# Transition: <state-before> -> <state-after>
# Bitboard: <segment-mask>
# Bitblip: <policy>
omi-....-....-....-....-....-....-....-..../prefix FACT <applied-fact-name>
```

---

## Consumer Interpretation

A consumer reads a derived fact as:

```text
This rule has been grounded into an applied system state.
The bitboard says which address fields matter.
The bitblip policy says how deviations are handled.
The test says how the fact is verified.
The projection says where the fact becomes inspectable.
```

---

See also: [1.6 The OMI Declaration Language](../1_FOUNDATIONS/1.6_THE_OMI_DECLARATION_LANGUAGE.md), [4.2 RULES.omi](../4_NETWORK/4.2_RULES_OMI.md), [7.4 Conformance Canon](7.4_CONFORMANCE_CANON.md), [2.8 Five-Fold Four-Fold and the 240 Bridge](../2_MATH/2.8_FIVE_FOLD_FOUR_FOLD_AND_THE_240_BRIDGE.md), [7.6 Agreement Operators](7.6_AGREEMENT_OPERATORS.md)
