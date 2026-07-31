# State 05 — Pure Algorithms: How the Kernel Moves

## What This State Is

This state is the transition from "what is the irreducible object" to "how does it move." After establishing the atomic kernel — Null, Bit, Pair, Relation — the next question is what operations can be performed on these objects without introducing nondeterminism.

A pure algorithm is one that:

- Accepts only Relations as input
- Produces only Relations as output
- Performs no IO
- References no external state
- Terminates or provably progresses
- Preserves deterministic replay

---

## The Seven Canonical Operations

### 1. Transition

Transition is the movement from one Relation to another by a deterministic rule. The canonical transition is the Delta Law:

```
Δ_C(x) = rotl(x, 1) ⊕ rotl(x, 3) ⊕ rotr(x, 2) ⊕ C
```

Applied to a 16-bit segment within a Relation, the Delta Law produces a period-8 orbit. Every state returns to itself after exactly eight transitions.

Transition is the most fundamental algorithm because it defines how a Relation changes without external input. The Delta Law is one transition function — but the algorithm layer permits any transition function that is deterministic, reversible, and bounded.

### 2. Partition

Partition separates a Relation into its constituent fields:

```
relW16a, relW16b, …, relW16h  — the eight 16-bit fields
relW32a, relW32b, relW32c, relW32d  — the four 32-bit fields
```

Partition does not create new information. It exposes existing structure. A partitioned Relation can be reassembled through the corresponding construction operations (setW16a, setW32b, etc.).

### 3. Projection

Projection maps a Relation onto a specific interpretation without modifying the Relation itself:

```
projectNode :: Relation → CanvasNode
projectEdge :: Relation → CanvasEdge
```

Projection is not computation in the traditional sense. It is a selection of which face to read. The Relation remains unchanged; only the viewing frame changes. This is the fundamental difference between OMI algorithms and conventional data transformation: OMI algorithms do not mutate data — they select interpretations.

### 4. Receipt

Receipt is the acceptance witness. A receipt binds a Path and a Relation into an accepted state:

```
receipt :: Path → Relation → Receipt
```

A receipt is not a signature in the cryptographic sense. It is a structural witness — a Relation that records which Path accepted which state at which point in the replay sequence. Receipts are the only objects that advance the canonical cursor.

### 5. Branch

Branch selects between two algorithmic paths based on a predicate over a Relation:

```
branch :: (Relation → Bit) → Relation → Relation → Relation
```

Branch does not introduce nondeterminism because the predicate is a pure function. For the same Relation input, the same branch is always taken.

### 6. Escape

Escape pauses the deterministic algorithm and awaits external input through a declared port:

```
escape :: Port → Relation → (Relation, Signal)
```

Escape is the only algorithm that interacts with the outside world. It takes a Relation and a port identifier, and returns either a continuation (if no signal is available) or a new Relation incorporating the external signal.

This is the boundary between pure computation (States 00–15) and the open world (States 16–19).

### 7. Composition

Any pure algorithm can be composed with any other:

```
compose :: (Relation → Relation) → (Relation → Relation) → (Relation → Relation)
```

Composition is the mechanism by which the seven canonical operations are combined into larger algorithms. The entire OMI protocol stack is a composition of these seven primitive operations, from the atomic kernel through the surface applications.

---

## Algorithmic Invariants

Every pure algorithm must satisfy:

1. **Replay identity**: Given the same input Relation and the same initial state, the algorithm must produce the same output Relation.
2. **Bounded progress**: Every loop or recursion must have a proven bound (typically the Fano bound of 15 iterations).
3. **No observable side effects**: The algorithm must not write to files, send network packets, or modify global state.
4. **Termination on valid input**: For every valid Relation input, the algorithm must terminate.

---

## Doctrine Sentence

> Pure algorithms describe how Relations move. They do not describe why they move. Interpretation belongs to the gauge. Motion belongs to the law.
