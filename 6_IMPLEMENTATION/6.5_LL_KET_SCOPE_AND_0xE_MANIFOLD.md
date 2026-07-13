# LL as Ket: Scope Selection and the Folded 0xE_ Manifold

## Purpose

This document defines the role of `LL` inside the OMI truth row:

```text
(LL, NN, MM)
```

Earlier descriptions treated `LL` mainly as a lens or modulator. That remains correct, but the completed `0xE_` execution band gives `LL` a sharper role:

```text
LL is the ket-like scope selector of the frame.
```

It does not contain the object, geometry, or application policy. It selects how a proven transition lands inside the accepted execution manifold.

```text
LL scopes.
NN begins.
MM resolves.
Delta proves.
Fano bounds.
Receipt authorizes.
Rule block materializes.
Projection displays.
```

## Truth Row

Every accepted OMI frame yields one truth row:

```text
LL = scope / lens / ket selector
NN = antecedent state
MM = consequent state
```

The transition being proven is:

```text
NN -> MM
```

That transition is accepted only when:

```text
Q_frame(S) = 0
Delta/Fano resolves NN -> MM
receipt records the accepted envelope
```

Short form:

```text
NN/MM prove the transition.
LL routes the accepted transition.
```

## LL as Ket

In Dirac notation, a ket such as `|psi>` represents a state vector. OMI does not import quantum mechanics literally, but the analogy is useful: `LL` behaves like a small bounded ket selector.

```text
|LL> = scoped selector state
```

The OMI truth row can therefore be read as:

```text
(|LL>, NN, MM)
```

or:

```text
scope ket + antecedent + consequent
```

`LL` is not the whole state, the object body, or semantic meaning. It is the scoped selector that tells the accepted frame where to land.

## Nibble Split

`LL` is interpreted as two nibbles:

```text
LL = 0xAB
```

Where:

```text
A = high nibble = context / lens family / carry-forward scope
B = low nibble  = execution slot selector
```

The POSIX gate computes:

```sh
slot_index=$((ll & 0x0f))
rule_slot=$((0xe0 + slot_index))
context=$(((ll >> 4) & 0x0f))
```

This gives the execution envelope a clean orthogonal structure:

```text
context    = high-nibble scope
slot_index = low-nibble selector
rule_slot  = 0xE0 + slot_index
```

The shell does not branch on meaning. It only extracts structure.

## Folded 0xE_ Manifold

The low nibble of `LL` addresses the complete `0xE_` execution band:

```text
0xE0-0xEB = twelve inner materializers
0xEC-0xEF = four outer controller vertices
```

The old `LL mod 12` reading was useful for the inner kissing-sphere metaphor, but the completed execution manifold uses the full nibble:

```text
rule_slot = 0xE0 + (LL & 0x0F)
```

This saturates all sixteen slots:

```text
0x0 -> 0xE0
0x1 -> 0xE1
0x2 -> 0xE2
0x3 -> 0xE3
0x4 -> 0xE4
0x5 -> 0xE5
0x6 -> 0xE6
0x7 -> 0xE7
0x8 -> 0xE8
0x9 -> 0xE9
0xA -> 0xEA
0xB -> 0xEB
0xC -> 0xEC
0xD -> 0xED
0xE -> 0xEE
0xF -> 0xEF
```

## First Twelve and Last Four

The `0xE_` band is one accepted execution manifold, but it contains two regions.

### Inner Materializer Field

```text
0xE0-0xEB
```

These twelve slots are the inner packed materializers. They correspond to the Archimedean/Catalan materializer field: accepted object transformations, snub bridges, edge traversal, vertex traversal, Fano selection, page framing, DOM/CSSOM/JSDOM/OOM patching, and receipt projection may be materialized by registry-defined operations.

They pack the object.

```text
0xE0-0xEB pack the object.
```

### Outer Controller Vertices

```text
0xEC-0xEF
```

These four slots are the outer Platonic controller vertices. They do not form a separate authority channel. They are not UI commands floating outside the protocol. They are the last four addresses of the same accepted execution manifold.

They hold the object.

```text
0xEC-0xEF hold the object.
```

They may control:

```text
0xEC = translation / viewport / focus
0xED = scale / recursion depth
0xEE = rotation / spin / orientation
0xEF = boundary / opacity / clipping
```

But only after the frame has been validated, resolved, and receipted.

## Platonic Fold

The final four controller slots can be read as Platonic controller vertices folded into the `0xE_` band. They are not extra commands. They are the tetrahedral control surface of the execution manifold.

```text
0xE0-0xEB = Archimedean/Catalan materializer field
0xEC-0xEF = Platonic controller vertices
```

The first twelve expose the packed operational field. The last four close the outer simplex. The control surface is not outside the system; it is folded into the same accepted manifold as the object operations.

Short form:

```text
The first twelve pack.
The last four hold.
The low nibble selects.
The high nibble carries.
```

## Carry-Forward Scope

The high nibble of `LL` carries context forward:

```text
context = (LL >> 4) & 0x0F
```

This can be understood as a 4-bit carry-forward scope. It does not decide semantic meaning inside the shell. It gives the materializer a bounded context value.

A materializer may interpret context as:

```text
lens family
authority context
projection family
object scope
depth band
peer scope
document scope
portal scope
```

But the gate does not interpret it. The gate only emits it.

If the current scope is represented as a 4-bit value, the next scope may be derived by XOR:

```text
next_scope = current_scope xor context
scope' = scope xor high_nibble(LL)
```

The XOR model keeps the scope update bitwise, bounded, reversible in form, and compatible with OMI's preference for low-level operations.

## Low Nibble as Slot Selector

The low nibble of `LL` selects the rule slot:

```text
slot_index = LL & 0x0F
rule_slot  = 0xE0 + slot_index
```

The low nibble does not contain geometry. It only selects an address. The registry owns meaning.

For example:

```text
LL = 0x07
context = 0x0
slot_index = 0x7
rule_slot = 0xE7
```

The registry may define:

```text
0xE7 = snub-bridge
```

Another example:

```text
LL = 0x3E
context = 0x3
slot_index = 0xE
rule_slot = 0xEE
```

The registry may define:

```text
0xEE = rotation-spin
```

The shell does not know either name. It only knows the frame was accepted and the envelope was recorded.

## NN and MM as the Proven Pair

`NN` and `MM` remain the transition pair:

```text
NN = antecedent
MM = consequent
```

The resolver proves that `MM` is reachable from `NN` under the accepted Delta/Fano path. The `LL` ket does not replace this proof. It scopes it.

```text
Delta/Fano proves NN -> MM.
LL selects where the proof lands.
Receipt records the accepted envelope.
```

This prevents the selector from becoming authority by itself.

```text
LL cannot accept a transition.
LL cannot bypass Q_frame.
LL cannot bypass Delta/Fano.
LL cannot bypass receipt.
```

It only routes the accepted transition.

## Execution Envelope

The accepted frame emits an envelope such as:

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

The materializer receives:

```text
context = 0x3
rule_slot = 0xEE
steps = 3
chirality = right
receipt = accepted
```

Then it applies the registered operation for `0xEE`. The materializer may know that `0xEE` means rotation/spin. The gate does not.

## Steps and Chirality

The execution envelope gives the materializer four orthogonal parameters:

```text
context
rule_slot
steps
chirality
```

Their roles are:

```text
context    = lens family / carry-forward scope
rule_slot  = operation address
steps      = magnitude / phase / recursion depth
chirality  = handed direction
```

Example:

```text
rule_slot = 0xEE
context = 0x3
steps = 3
chirality = right
```

The materializer may interpret this as rotating the projection under context `0x3` by three accepted steps in the right-handed direction. This is materialization policy, not gate policy.

## No Separate Controller Channel

The controller vertices `0xEC-0xEF` must not exist on a separate command channel. A separate channel would create double authority by letting a projection or UI move the lens outside the receipt path.

OMI rejects that.

```text
No controller outside receipt.
```

A viewport, scale, rotation, boundary, opacity, or clipping change may be local and non-authoritative. But if it claims to be an accepted OMI view operation, it must come through the same frame pipeline:

```text
validate -> resolve -> record -> materialize -> project -> inspect
```

Stricter viewport language:

```text
The viewport is receipt-bound when controlled through 0xEC-0xEF. A conforming projection must not treat out-of-band camera or lens changes as accepted state.
```

This preserves the separation:

```text
local display may vary
accepted projection must be receipted
```

## Gate and Materializer

The gate is `start.sh`. The materializer is the rule registry and its implementations.

The gate does:

```text
parse frame
validate Q_frame(S) = 0
extract (LL, NN, MM)
resolve NN -> MM
derive context
derive slot_index
derive rule_slot
write receipt
emit envelope
```

The gate does not:

```text
know snub geometry
know Platonic solids
know Archimedean/Catalan duals
know DOM policy
know CSSOM policy
know JSDOM policy
know A-Frame policy
know portal UX
```

The materializer does:

```text
read accepted envelope
lookup rule_slot
apply registered pure implementation
respect context
respect steps
respect chirality
project result
explain result
```

The split is absolute:

```text
start.sh is the gate.
The registry is the materializer.
```

## Relation to the 4D Simplex

The final four controller vertices can be read as a 4-simplex-style closure surface. They are the folded controller vertices that make the materializer manifold complete.

The first twelve slots give the dense packed field. The last four slots give the outer controller surface.

The OMI execution band is therefore a folded topology:

```text
twelve inner operations
four outer vertices
one accepted manifold
```

The `LL` ket selects into that manifold. The `NN/MM` pair proves the transition. The receipt closes the event.

## Final Canon

The OMI truth row is:

```text
(LL, NN, MM)
```

`NN` and `MM` are the proven transition pair. `LL` is the ket-like scope selector. Its high nibble carries forward context into the next scope. Its low nibble selects one address in the folded `0xE_` execution manifold.

The first twelve addresses expose the Archimedean/Catalan materializer field. The final four addresses expose the Platonic controller vertices of the simplex closure.

The gate remains blind. The registry owns meaning.

Short doctrine:

```text
LL scopes.
NN begins.
MM resolves.
Delta proves.
Fano bounds.
The high nibble carries.
The low nibble selects.
The first twelve pack.
The last four hold.
Receipt closes.
```

One-line canon:

```text
LL is the ket of the frame: a 4-bit carry-forward scope selector whose low nibble lands the accepted NN->MM transition inside the folded 0xE_ materializer manifold.
```
