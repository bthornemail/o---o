# State 04 — Atomic Kernel: The Irreducible Object

## What This State Is

This state is the transition from "what cannot be reduced further" to "what is the smallest deterministic object." After establishing the irreducible boundaries of the cosmology, the atomic kernel asks the sharper question:

> What is the smallest mathematical object that still preserves deterministic replay?

Everything else is derived. The kernel is what cannot be removed.

---

## The Four Primitives

### 1. Null — The Void

Null is not zero. Zero is a numeric position within a carrier. Null is the absence of any relation — the state before the first distinction.

Null answers: what exists before naming?

```
Null = the void
Null ≠ 0
Null is not a carrier position
Null is not a bit
Null is the empty cons
```

### 2. Bit — The Binary Choice

Bit is the first distinction. From Null, the only possible transition is into a choice between two states. Bit is that choice.

```
Bit = O | I
O = not-Yet-distinguished
I = distinguished
```

Bit is not boolean truth. Boolean truth is an interpretation of Bit after a projection has been selected. In the kernel, Bit is simply: there are two states.

### 3. Pair — The Relation

Pair is the second distinction — not between two states, but between two positions in a relation. A Pair connects two Bits into a directed relation.

```
Pair a b = the relation from a to b
```

Pair is not a data structure. It is the atomic relation form. Every relation in OMI is either a Pair or a composition of Pairs.

The three canonical operations on Pair:

```
cons a b = Pair a b     — construct a relation
car (Pair a b) = a      — the first position
cdr (Pair a b) = b      — the second position
```

### 4. The Compound Types

From Bit and Pair, the compound types are derived:

```
Nibble = Bit Bit Bit Bit        — 4-bit field
Byte   = Nibble Nibble          — 8-bit field
Word16 = Byte Byte              — 16-bit segment
Word32 = Word16 Word16          — 32-bit word
```

These are not primitives. They are conveniences for describing the 128-bit wire frame, which decomposes as 8 segments × Word16. The kernel recognizes only Bit and Pair. Every larger type is a named arrangement of Bits in relation.

### The Minimal Claim

The atomic kernel makes one claim:

> Every deterministic computation can be expressed as an orbit over a fixed relation of Bits, where the transitions are Pairs and the fixed points are Null.

If a concept cannot be reduced to Bit, Pair, and Null, it is not part of the atomic kernel.

---

## Relation — The Carrier

Relation is the 12-field carrier that holds the kernel's state:

```
Relation =
  Word16 Word16 Word16 Word16
  Word16 Word16 Word16 Word16
  Word32 Word32 Word32 Word32
```

Relation is not primitive in the same sense as Bit and Pair. It is the first derived structure — the smallest carrier that can hold an address, a scope, a payload, and a receipt in one object.

Everything above the kernel is a projection of Relation.

---

## What the Kernel Does Not Contain

The atomic kernel explicitly excludes:

- **Gauge** — Gauge is a selection word, not a primitive structure. It belongs to the algorithm layer, where it chooses which alignment to read on an already-existing Relation.
- **Address** — Address is a place-value numbering within a Relation. The kernel has no addresses; it has positions.
- **Frame** — Frame is a carrier boundary. The kernel has no boundaries; it has Relations.
- **Canvas** — Canvas is a projection. The kernel has no projections; it has Relations.
- **Numeric literals** — The kernel has no numbers. It has Bits in relation. Numbers emerge from counting.

---

## Doctrine Sentence

> The atomic kernel is what remains when every interpretation has been removed: Null, Bit, and the relations between them.
