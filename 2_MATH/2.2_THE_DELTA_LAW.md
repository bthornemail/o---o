# The Delta Law: The Period-8 Engine

## The Atomic Design Decision

The Delta Law is the minimal reversible transformation at the heart of OMI. It is not an arbitrary hash — it was the product of a single design constraint:

```
rotl(x, 1) XOR rotl(x, 3) XOR rotr(x, 2) XOR C
```

```mermaid
graph LR
    subgraph BitOps["16-bit Register Operations"]
        IN["x (uint16)"] --> R1["rotl(x, 1)<br/>left-rotate 1"]
        IN --> R3["rotl(x, 3)<br/>left-rotate 3"]
        IN --> RR2["rotr(x, 2)<br/>right-rotate 2"]

        R1 --> XOR["XOR ⊕"]
        R3 --> XOR
        RR2 --> XOR
        C["Constant C<br/>(0xACAB or LL×0x1337)"] --> XOR

        XOR --> OUT["δ(x) = (r1 ⊕ r3 ⊕ rr2 ⊕ C) & 0xFFFF"]
    end
```

Four deliberate choices:
1. **Rotations, not shifts** — no bits are ever lost
2. **XOR** — fully reversible (XOR is its own inverse)
3. **Constant C** — breaks the zero fixed point (without C, 0 maps to 0)
4. **Mask to 16-bit width** — keeps state bounded to uint16

## Properties That Emerged

From this single law, everything else was computed by the math:

- **Period = 8** — a property of the specific rotation constants (1, 3, 2) on 16-bit space. Every state returns to itself after exactly 8 applications.
- **Prime 73** — the reciprocal decimal expansion `0.01369863...` gives the orbital weight sequence `[0, 1, 3, 6, 9, 8, 6, 3]` which sums to 36 = `6! / 20`.
- **Fano plane resolution** — any trajectory through the Delta Law converges within at most 15 steps, bounded by the Fano plane's projective geometry.

## The Orbit

Given an initial state `x₀`, the Delta Law generates a closed orbit of length 8. Every state returns to itself after exactly 8 applications:

```mermaid
stateDiagram-v2
    direction LR
    S0: x₀<br/>(S[0])
    S1: x₁ = δ(x₀)<br/>(S[1])
    S2: x₂ = δ(x₁)<br/>(S[2])
    S3: x₃ = δ(x₂)<br/>(S[3])
    S4: x₄ = δ(x₃)<br/>(S[4])
    S5: x₅ = δ(x₄)<br/>(S[5])
    S6: x₆ = δ(x₅)<br/>(S[6])
    S7: x₇ = δ(x₆)<br/>(S[7])

    S0 --> S1: δ
    S1 --> S2: δ
    S2 --> S3: δ
    S3 --> S4: δ
    S4 --> S5: δ
    S5 --> S6: δ
    S6 --> S7: δ
    S7 --> S0: δ (period closes)
```

This period-8 property maps directly to the 8 segments of an OMI frame. Each segment `S[0]` through `S[7]` can be thought of as a point on a Delta Law orbit.

## Weight Block: Orbital Mass

The reciprocal of prime 73 gives the decimal expansion `0.01369863...` which defines the orbital weight sequence:

```
Position:   0   1   2   3   4   5   6   7
Weight:    [0,  1,  3,  6,  9,  8,  6,  3]
            ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓
Sum = 36  ───────────────────────────────
```

This weight block modulates how much "mass" each orbital position carries:

```mermaid
xychart-beta
    title "Orbital Weight Block B (sum = 36 = 6!/20)"
    x-axis ["pos 0", "pos 1", "pos 2", "pos 3", "pos 4", "pos 5", "pos 6", "pos 7"]
    y-axis "Weight" 0 --> 9
    bar [0, 1, 3, 6, 9, 8, 6, 3]
```

## Gate 2: Fano Intercept

The second validation gate combines the Delta Law with the Fano plane:

```
Q(N, M) = 0  ∧  fano_intercept(a, b, c) ≥ 0
```

Where the Fano point `LL ∈ {0x01..0x07}` identifies one of 7 projective points. The lexer verifies that two rays with distinct `LL₁ ≠ LL₂` resolve their intersection within the bound of ≤ 15 Delta Law steps. This is the "Transylvania Lottery" resolver.

## W = 36

The weight sum `W = 36` (from the digit block `[0,1,3,6,9,8,6,3]`) is the master frame stride:

```
position ÷ 36 = macro-cycle quotient ──→ which 36-frame block
position % 36 = local offset        ──→ which weight applies
```

```mermaid
flowchart LR
    subgraph Stream["Stream Position"]
        POS["position<br/>(0, 1, 2, ...)"]
    end

    subgraph DivMod["divmod(position, 36)"]
        Q["quotient<br/>(macro-cycle)"]
        R["remainder<br/>(local offset 0..35)"]
    end

    subgraph Weights["Weight Lookup"]
        W0["block index = remainder % 8"]
        W1["weight = B[block_index]"]
    end

    POS --> Q & R
    R --> W0 --> W1
    W1 --> APPLY["<imo-gs delta-weight='...'>"]
```
