# Rule Resolver and Materializer

`start.sh` is the OMI gate. It validates a frame, extracts the truth row, resolves the Delta/Fano path, computes the rule address, and writes a receipt envelope.

It does not know geometry, DOM, CSSOM, JSDOM, page frames, snub truncation, stellation, or OMI Object Model patch semantics.

```text
validate -> resolve -> record -> materialize -> project -> inspect
```

## Resolver Contract

The resolver emits an execution envelope:

```json
{
  "status": "accepted",
  "accepted": true,
  "LL": "0x3E",
  "context": "0x3",
  "slot_index": "0xE",
  "NN": "0x7C00",
  "MM": "0xF59D",
  "steps": 3,
  "rule_band": "0xE0-0xEF",
  "rule_slot": "0xEE",
  "chirality": "right",
  "receipt": "0x..."
}
```

The complete-band dispatch law is deterministic:

```text
context = LL >> 4
slot_index = LL & 0x0F
rule_slot = 0xE0 + slot_index
```

This addresses the full `0xE_` execution band as one accepted manifold. The lower nibble selects the materializer slot. The upper nibble is context carried to the materializer.

`0xE0-0xEB` pack the object through twelve inner materializers. `0xEC-0xEF` hold the object through four outer controller vertices. Both are selected by the same accepted receipt envelope.

For the normative scope model behind this nibble split, see `6.5_LL_KET_SCOPE_AND_0xE_MANIFOLD.md`.

```text
LL & 0x0F -> 0x0..0xB -> 0xE0-0xEB -> 12 inner packed spheres
LL & 0x0F -> 0xC..0xF -> 0xEC-0xEF -> 4 outer bounding vertices
```

## Parameter Ledger

The envelope gives the materializer an orthogonal instruction surface:

| Parameter | Domain | Materializer Role |
|-----------|--------|-------------------|
| `context` | `0x0-0xF` | Lens family or authority context |
| `slot_index` | `0x0-0xF` | Low-nibble selector for the `0xE_` band |
| `rule_slot` | `0xE0-0xEF` | Exact registry address |
| `steps` | integer | Magnitude, depth, phase, or recursion index |
| `chirality` | `left` / `right` | Handed direction or orientation |

For example, `LL = 0x3E` yields `context = 0x3`, `slot_index = 0xE`, and `rule_slot = 0xEE`. With `steps = 3` and `chirality = right`, the registry may materialize a right-handed rotation with step magnitude 3. The shell does not know it is rotation.

| Slot | Controller | Role |
|------|------------|------|
| `0xEC` | `translation-viewport` | Shift viewport or spatial focus |
| `0xED` | `scale-depth` | Select zoom or recursion depth |
| `0xEE` | `rotation-spin` | Rotate the projection or swap orientation |
| `0xEF` | `boundary-opacity` | Clip, expose, hide, or alpha-bound the portal surface |

The control surface does not mutate the accepted object. It controls the portal lens around the object, but it is still addressed by the accepted truth row and receipt.

Chirality is derived from the accepted path, not from rule semantics:

```text
chirality_bit = steps & 1
```

## Registry Boundary

The `rules/registry.json` manifest maps accepted addresses to external rule implementations. That registry may name operations such as `snub-bridge`, `page-frame-root`, `dom-import-export`, `receipt-projection-export`, or the four outer controllers. `rules/materialize.sh` reads that manifest and invokes the named module after a receipt envelope exists.

The shell never branches on those meanings. It only emits the accepted address.

The resolver is intentionally branchless with respect to operation type: it processes a translation frame the same way it processes a snub-bridge frame.

The viewport is receipt-bound when controlled through `0xEC-0xEF`. A conforming projection must not treat out-of-band camera or lens changes as accepted state.

```text
LL selects.
Delta proves.
Fano bounds.
Receipt authorizes.
Rule block materializes.
Projection displays.
```

## Local Invocation

```bash
./start.sh 0100-03bf-7c00-2b01-2f01-1434-039f-01ff
rules/materialize.sh receipts/01017c001434e101.json
./start.sh 0700-03bf-7c00-2b07-2f07-8182-039f-07ff
rules/materialize.sh receipts/07017c008182e701.json
./start.sh 3e00-03bf-7c00-2b3e-2f3e-f59d-039f-3eff
rules/materialize.sh receipts/3e037c00f59dee01.json
```

The first command writes an accepted receipt envelope. The second command consumes the envelope and resolves the rule name from the external registry layer.

Clean canon sentence:

```text
The 0xE_ band is a single accepted execution manifold: 0xE0-0xEB pack the object through twelve inner materializers, while 0xEC-0xEF hold the object through four outer controller vertices; start.sh selects the slot by LL & 0x0F, records the receipt, and remains blind to all semantic geometry.
```

Final substrate sentence:

```text
The OMI substrate is sealed by the 0xE_ execution band: twelve inner rule slots materialize the object, four outer controller slots hold the projection surface, and the policy-blind gate selects the slot with LL & 0x0F after validation, resolution, and receipt.
```
