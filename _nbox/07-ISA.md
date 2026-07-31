# State 07 — ISA: The Machine

## What This State Is

This state is the transition from "what mathematics emerges" to "how it runs." After unfolding the geometry, I needed to build the machine — the instruction set architecture that makes the cosmology executable.

This state defines the opcodes, the dispatch mechanism, the gauge tables, the C99 core implementation, the NodeJS compiler, and the test suite that proves the machine works.

---

## 1. The 32-Slot ISA

### 1.1 The Opcode Space

The OMI ISA has 32 slots (0x00–0x1F), divided into:

| Range | Slots | Category |
|-------|-------|----------|
| 0x00–0x13 | 20 | Core ISA |
| 0x14–0x1F | 12 | Extended ISA (gauge table ops) |

### 1.2 Core ISA (0x00–0x13)

```text
0x00  NOP            No operation
0x01  PROBE          Send probe frame
0x02  PROBE_ACK      Acknowledge probe
0x03  SYNC_COMMIT    Commit synchronization
0x04  SEAL           Seal envelope
0x05  BOOT           Boot sequence
0x06  RESET          Reset state
0x07  ROUTE          Route envelope
0x08  BROADCAST      Broadcast to all peers
0x09  SEND           Send to specific peer
0x0A  RECV           Receive from peer
0x0B  STORE          Store to local state
0x0C  LOAD           Load from local state
0x0D  EXEC           Execute sub-frame
0x0E  CALL           Call procedure
0x0F  RETURN         Return from procedure
0x10  SENSOR_IN      Read sensor input
0x11  SENSOR_OUT     Write sensor output
0x12  AUDIO_IN       Read audio input
0x13  AUDIO_OUT      Write audio output
```

### 1.3 Extended ISA (0x14–0x1F)

```text
0x14  GAUGE_BIND       Bind gauge entry
0x15  GAUGE_UNBIND     Unbind gauge entry
0x16  GAUGE_INVOKE     Invoke gauge lambda
0x17  PLACE_WRITE      Write to place
0x18  PLACE_READ       Read from place
0x19  FOLD             Fold surface
0x1A  BITBOARD_APPLY   Apply bitboard mask
0x1B  STATE_COMMIT     Commit state transition
0x1C  STATE_REVERT     Revert state transition
0x1D  STREAM_SPLIT     Split stream
0x1E  STREAM_MERGE     Merge streams
0x1F  VM_ESCAPE        Escape to host
```

---

## 2. The Four Semantic Lenses

The ISA operates through four semantic lenses, selected by the context:

| Lens | Context | Role |
|------|---------|------|
| LOCAL VM | System context | Pure ISA execution |
| REMOTE VM | Remote context | Probe, sync, transport |
| USER LAYER | User context | OMI-Lisp surface |
| HW BRIDGE | Hardware context | Probe → hardware |

The same opcode has different meanings in different lenses. This is not ambiguity — it is contextual interpretation, which is the OMI principle applied to the ISA itself.

---

## 3. The Gauge Table

### 3.1 Structure

The gauge table is a 128-entry registry that maps opcodes to their execution semantics:

```text
Entry 0x00–0x1F: Core and extended ISA
Entry 0x20–0x7F: Application-specific gauge lambdas
Entry 0x80–0xFF: Reserved
```

### 3.2 Gauge Entry

Each gauge entry is a lambda-like structure:

```text
car     — operation selector
cdr     — continuation
payload — data or reference
stack   — symbolic execution stack
```

### 3.3 Gauge Invocation

When an opcode is dispatched:

1. Look up the gauge entry
2. Evaluate car to determine operation
3. Evaluate cdr to continue
4. Apply payload
5. Execute any pending stack operations

---

## 4. The Dispatch Mechanism

### 4.1 Dispatch Flow

```text
envelope received
  → extract gauge index from header
  → look up gauge table entry
  → dispatch to handler
  → execute handler
  → write receipt
  → advance ring cursor
```

### 4.2 The Gate Interface

The dispatch mechanism has two gates:

**Gate 1 — Structural Validation:**

```text
Verify Q_frame(S) = 0
Verify omicron anchors present
Verify segment layout
If invalid → XDP_DROP
```

**Gate 2 — Semantic Resolution:**

```text
Extract LL, NN, MM from frame
Set C = (LL × 0x1337) & 0xFFFF
Apply Delta_C up to 15 steps
If NN → MM not found → reject
```

### 4.3 The Gate and Registry Separation

- **The Gate** is blind: validates structure, extracts truth row, resolves Delta, writes receipt. It knows nothing of geometry, DOM, or application semantics.
- **The Registry** owns meaning: looks up the accepted rule slot, applies the implementation, projects and explains the result.

---

## 5. The LL Ket Scope and 0xE_ Manifold

### 5.1 LL as Ket Selector

The LL nibble pair selects the execution context:

- High nibble = context/family (0x0–0xF)
- Low nibble = execution slot (0x0–0xF)

### 5.2 The 0xE_ Manifold

The `0xE0–0xEF` band is the single accepted execution manifold:

**Inner materializers (0xE0–0xEB):**

```text
0xE0  Page-frame-root materializer
0xE1  DOM import/export
0xE2  CSSOM import/export
0xE3  JSDOM normalization
0xE4  OMI object patch
0xE5  Edge/vertex traversal
0xE6  Snub bridge
0xE7  Stellated octahedron mirror
0xE8  Fano triangle selection
0xE9  Face band
0xEA  Receipt projection/export
0xEB  (reserved)
```

**Outer controller vertices (0xEC–0xEF):**

```text
0xEC  Translation/viewport/focus
0xED  Scale/recursion depth
0xEE  Rotation/spin/orientation
0xEF  Boundary/opacity/clipping
```

---

## 6. The C99 Core Implementation

### 6.1 Module Structure

The C core is organized into layered modules:

```text
omienv.h/c     — 512-bit envelope struct, bitboard constants, gauge entry API
stream.h/c     — Streaming state machine (WAITING→HEADER→PAYLOAD→COMPLETE)
sector.h/c     — 512-byte sector iterator (8 cells × 64 bytes)

omi_transport_sim.h/c  — Linked ring-buffer transport pair (testing)
omi_probe.h/c          — Probe handshake state machine
omi_dispatch.h/c       — 32-slot dispatch with gauge lambda execution

omi_omion.h/c   — OMIOM prefix-scoped cascade resolver
omi_receipt.h/c — META64 receipt verification
omi_sense.h/c   — Light Garden protocol adapter bridge

omi_orbit.h/c   — GL(16,2) orbit engine (Delta Law)
```

### 6.2 Orbit Engine (GL(16,2))

The orbit engine implements the Delta Law in C:

```c
uint16_t delta16(uint16_t x, uint16_t c) {
    return rotl16(x, 1) ^ rotl16(x, 3) ^ rotr16(x, 2) ^ c;
}

uint16_t rotl16(uint16_t x, int n) {
    return (x << n) | (x >> (16 - n));
}

uint16_t rotr16(uint16_t x, int n) {
    return (x >> n) | (x << (16 - n));
}
```

### 6.3 Verified Extraction

The C99 core is designed for verified extraction:

```text
Coq proof → verified C spec → compiled binary
```

The verification layer aligns C ↔ Coq via a representation map. The proof ensures that the C implementation faithfully executes the Delta Law, the quadratic validator, and the ring indexer.

---

## 7. The NodeJS Compiler

### 7.1 Compilation Pipeline

```text
.omi source file
  → lexer (tokenize hex, anchors, segments)
  → parser (construct frame, extract truth row)
  → validator (Q_frame = 0)
  → resolver (Delta/Fano)
  → code generator (emit 32-slot ISA)
  → .imo output (compiled mirror)
```

### 7.2 Input Format

```text
# RULES.omi
omi-0000-0000-0000-0000-0000-0000-00eb-0066/112 MUST initialize-xdp-packet-parsing-gates
```

### 7.3 Output Format

```text
# RULES.imo
ο omi-0000-0000-0000-0000-0000-0000-00eb-0066/112
  LL:0x01 NN:0x00EB MM:0x0066
  C:0x1337 STEPS:1
  SLOT:1504 RECEIPT:0x...
Ο
```

The `.imo` output is wrapped with omicron anchors (ο...Ο) and contains the compiled form of the declaration.

### 7.4 Self-Hosting

The compiler can compile its own source code — the meta-circular property that proves the system is self-describing. The compiler's rules are declared in `RULES.omi`, grounded in `FACTS.omi`, and compiled through the same pipeline as any other object.

---

## 8. The Test Suite

### 8.1 Test Structure

Tests are organized by subsystem:

```text
test_env.c            — Envelope format (13 tests, 39 assertions)
test_omicron          — Omicron kernel
test_orbit.c          — GL(16,2) orbit engine
omi_omion_test        — Prefix-scoped cascade resolver (27 tests)
omi_receipt_test      — META64 receipt verification (27 tests)
omi_sense_test        — Light Garden protocol adapter (5 tests)
```

### 8.2 Test Results (as of July 6, 2026)

- **302 tests passing**, 0 failing
- **5 Coq proof files** compiling cleanly
- C orbit engine passes all GL(16,2) tests
- All envelope parsing tests pass
- Probe handshake state machine verified

### 8.3 The Provider Contract in Tests

Every test verifies the provider contract:

```text
No address without a rule.
No rule without a test.
No test without a replay path.
No replay path without visible state.
```

A rule is complete only when it has:
```text
RULES.omi row → implementation → test → expected pass/fail
```

---

## 9. The Materializer

### 9.1 Role

The materializer is the component that applies an accepted rule address to affect object structure, document projection, DOM/CSSOM/JSDOM state, etc.

### 9.2 Materializer Rules

Materializer rules are stored in the 0xE_ manifold slots:

- Inner materializers (0xE0–0xEB) pack the object
- Outer controller vertices (0xEC–0xEF) hold the object

### 9.3 Materializer Flow

```text
validated frame
  → truth row (LL, NN, MM)
  → receipt written
  → materializer rule looked up (from 0xE_ slot)
  → rule applied
  → DOM/CSSOM state updated
  → projection refreshed
```

---

## The Transition to State 08

From this state — having built the machine — I moved to State 08 (Protocol) to answer: how does the machine communicate? What wire format carries state between observers?

Continue to `08-PROTOCOL-SEMANTICS.md`.
