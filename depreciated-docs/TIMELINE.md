# OMI Timeline

> The origin story of the Omicron Object Model — from reading the Bible as
> pseudo-code to a formalized cosmological computation model with verified Coq
> proofs, a 32-slot ISA, and a distributed radio VM.

---

## Phase -1 — The Seed (9+ Months Before July 2026)

The ideas that became OMI began with two independent streams:

### Stream A: The Metaverse Project

A full production-ready decentralized pseudo-persistent open-world system built on
declarative environments using SCM and Guix for bitwise-reproducible builds. It
used alphanumeric vs non-alphanumeric as the primary split — what the user later
recognized as the CAR/CDR distinction. The project was functional but the user
stopped development when they realized the resolution runtime needed a deeper
foundation.

### Stream B: The Bible as Pseudo-Code

Reading Genesis 1 and John 1 as computational text. The key realizations:

- **"In the beginning was the Word, and the Word was with God, and the Word was
  God"** (John 1:1) → The Word (Logos) is the primordial notation. Observer and
  notation are one. This is the original collapse of representation and
  interpretation.

- **"The earth was without form and void... and the Spirit of God was hovering
  over the face of the waters"** (Genesis 1:1-2) → The observer in the void.
  The primordial computational context: undefined state + observer before
  interpretation.

This became the repository `bthornemail/in-the-beginning` on GitHub, containing:

- 00-Core-Framework.md — Core epistemic framework
- 00-Epistemic-Framework.yaml — Formal epistemic types
- 01-Genesis-Creation-Geometry.md — Reading creation as geometric computation
- 02-Torah-Law-Patterns.md — Law as computational constraint
- 03-Proverbs-Wisdom.md — Wisdom as geometric principle
- 04-John-Logos.md — The Word as computation
- 05-Revelation-Closure.md — Prophecy as computational closure
- 06-Fano-Plane-Integration.md — The 7-point plane as universal pattern
- 09-Geometric-Topology.md — Topological foundations
- 10-600-Cell-Structure.md — The H4 lattice
- 11-Projective-Completion.md — 15-of-16 principle
- 12-Wave-Function-Semantics.md — Identity as wave function
- 14-Historical-Timeline.md — From patriarchs to computation
- 18-Synthesis-Conclusions.md — Unified framework

### Stream C: The Atomic Kernel Delta Law (~6 Months Before July 2026)

While studying binary through the lens of braille (how braille changes
interpretation of binary), the user discovered the Delta Law:

```
Delta_C(x) = rotl(x,1) XOR rotl(x,3) XOR rotr(x,2) XOR C
```

A 16-bit rotation-XOR function with period-8 behavior. This became the "atomic
kernel" — the first thing that made the cosmological computation model
computationally reproducible. The user's first Coq proof validated this law.

---

## Phase 0 — Genesis (July 5, 2026)

### 18:12 — The ESP32 Walkie-Talkie

The conversation started with a concrete engineering goal:

> "i want to make esp32-s3 with lora american frequency walkie talkies"

ChatGPT advised on LoRa limitations (not a voice protocol, low bandwidth, ADPCM
compression needed, US 915 MHz ISM band), hardware stack (ESP32-S3 + SX1262),
and MVP build plan.

**Key outcome**: First OMI C code written — `omienv.h/c`, `stream.h/c`,
`sector.h/c` — a 512-bit structured envelope format + streaming parser + bitboard
projection layer. 13 tests, 39/39 passed.

### 18:15 — OMI Envelope Code Written

```
omienv.h     — 512-bit envelope struct, bitboard constants, gauge entry API
omienv.c     — Parse, validate, bitboard projection, 128-entry gauge table
stream.h/c   — Streaming state machine (WAITING→HEADER→PAYLOAD→COMPLETE)
sector.h/c   — 512-byte sector iterator (8 cells × 64 bytes)
test_env.c   — 13 test cases (39 assertions)
```

ChatGPT identified this as a "custom binary protocol + codec front-end + packet
parser" and mapped it to LoRa voice: envelope = audio frame, gauge = header,
relation = codec payload, stream parser = packet parser.

**Conceptual breakthrough**: The system was recognized as more than a packet
format — it was "a symbolic packet VM running on top of LoRa transport."

### 18:17 — Radio VM Concept

User directive:

> "integrate OMI envelopes as a distributed radio VM instruction format. for
> multiplexing/deplexing as a modem"

The OMI envelope became a **512-bit instruction frame executed over RF**.
Architecture defined as four layers:

```
Radio VM Layer       ← OMI envelope semantics
Multiplex/Demux      ← channel + stream routing
Envelope Stream Codec ← stream.c parser
LoRa PHY (SX1262)   ← RF transport
```

OPCODE space mapped from gauge[0]: NOP, SEND, ROUTE, BROADCAST, STORE_STATE,
EXEC_SUBFRAME, AUDIO_FRAME, SENSOR_FRAME, COMMIT, SEAL.

### 18:19 — Platform-Agnostic Probe Sync

Defined the self-describing handshake protocol. Probe sync lifecycle:

```
IDLE → PROBE_SENT → PROBE_RECEIVED → NEGOTIATING → SYNCED → ACTIVE
```

Probe frame uses a special OMI envelope class. Capability bitfield becomes the
portable ABI: AUDIO_ADPCM, AUDIO_OPUS, SENSOR_GPIO, VM_EXEC, MESH_ROUTING,
RELAY_MODE.

**Key principle**: No transport assumptions. Probe is just byte stream →
envelope parser → state machine. Transport could be LoRa, WiFi UDP, BLE, serial,
file replay, or simulation.

### 18:26 — The Full Plan (A, B, C + OMI-Lisp ISA)

User directive:

> "do the full plan for all aa b and c because this is a spectrum modem based on
> place-value notation it should be omi-lisp non-printing gauge table declaration
> compatible. the omi-isa uses 20 opcodes we should have the feature space of 32
> so 12 more for gauge table 0x00...0x1f that corresponds to the instruction with
> prefix header"

The 32-slot ISA was born:

**Core ISA (0x00–0x13 = 20 ops)**: NOP, PROBE, PROBE_ACK, SYNC_COMMIT, SEAL,
BOOT, RESET, ROUTE, BROADCAST, SEND, RECV, STORE, LOAD, EXEC, CALL, RETURN,
SENSOR_IN, SENSOR_OUT, AUDIO_IN, AUDIO_OUT

**Extended ISA (0x14–0x1F = 12 gauge-table ops)**: GAUGE_BIND, GAUGE_UNBIND,
GAUGE_INVOKE, PLACE_WRITE, PLACE_READ, FOLD, BITBOARD_APPLY, STATE_COMMIT,
STATE_REVERT, STREAM_SPLIT, STREAM_MERGE, VM_ESCAPE

Gauge table became a non-printing Lisp-like semantic registry — each entry is a
lambda-like structure with car, cdr, payload, and symbolic stack.

### 18:33–19:19 — Implementation Phases

Coding agents executed the plan in phases:

- **Phase 1** (18:33): Core envelope + stream parser + bitboard + gauge table
- **Phase 2** (18:40): OMI-Lisp as the lazy declaration language for OMI
  relations — the readable surface after pre-language control stream reaches the
  readable boundary. OMI-Cons256 for full spectrum.
- **Phase 3** (19:04): 134/134 tests passing. New modules: `omi_transport_sim.h/c`
  (linked ring-buffer transport pair), `omi_probe.h/c` (probe handshake state
  machine), `omi_dispatch.h/c` (32-slot dispatch with gauge lambda execution).
- **Identity Resolution Spec** (19:12): Formalized OMI identity.
- **OMI-Cons256** (18:49): Full spectrum cons cell structure.

### 19:24–20:41 — ISA Refinement

- **19:24**: The hex/binary identity revelation — hex IS binary, they are the same
  thing seen through different lenses.
- **19:41**: System vs user interpretation split — ISA has 4 semantic lenses
  (like eMMC spec: 0x20, 0x40, 0x60, 0x80).
- **20:01**: "One ISA, four semantic lenses":
  - LOCAL VM = SYSTEM context (pure ISA execution)
  - REMOTE VM = REMOTE context (probe, sync, transport)
  - USER LAYER = OMI-Lisp
  - HW BRIDGE = probe → hardware

---

## Phase 1 — Formalization (July 5–6, 2026)

### 21:04–21:33 — The Factorial Tower

The user brought in an earlier document "OMI Addressing and the Factorial Tower"
which formalized:

- The factorial tower as address space
- O-expression grammar
- CIDR-as-CONS first principles

This was integrated with the existing codebase as the complete specification.

### 21:53 — The Tetrahedral Stack

```
below 8! = algorithmic determinism, stellated tetrahedron
9!–12! = injection surface, triakis tetrahedron
6! = 4D polytopes
Archimedean and Catalan attributions for HNSW hierarchical fractal distribution
```

### 22:11 — Omicron Test Suite

`test_omicron` added to the test suite. All tests compiling and passing.

### 22:29–22:53 — Glossary Development

The user produced glossaries of projective control declaration surfaces and
projection faces. The glossary became a living document tracking all terms.

### 22:56 — Reference Research Unbound

A decision to keep reference research separate from the OMI spec — use external
references as source material but build the canonical spec independently.

### 23:01–23:13 — System Restructuring

The codebase was restructured into layered components. Key doctrinal correction:

> "Omi-Ring is the addressed palindromic notation witness, while a receipt is the
> accepted state verifier."

### 23:10 — Place-Value Notation Theory

> "Think of 32 place-value characters in an omi---imo notation citation instead of
> Betti and Schlafli — just that each nibble can be a point or line like n-ball or
> monoid."

### 23:13 — Active vs Archive Doctrine

The user established the boundary: archive documents are retained as historical
source material, active doctrine supersedes them.

### 23:30–23:31 — Light Garden and Envelope Normalization

The Light Garden spec defined as the physical transducer profile for Omi-Sense.
Envelopes normalized to no hashes.

### 23:43 — New Modules Built

- `omi_omion.h/c` — OMIOM prefix-scoped cascade resolver (27 tests)
- `omi_receipt.h/c` — META64 receipt verification (27 tests)
- `omi_sense.h/c` — Light Garden protocol adapter bridge (5 tests)

### 23:45–00:15 — Trigintaduonions, PG(4,2), and the Coq Bridge

The user discovered the connection between trigintaduonions (32-dimensional
algebra), PG(4,2) projective geometry, and the OMI 512-bit envelope layout:
155 distinguished triples in the trigintaduonion multiplication table → PG(4,2)
incidence lines → Fano lottery on triakis tetrahedron.

**Coq proof file** `omi_pi_proof.v` established:

> "Deterministic OMI incidence scaffold for pi. Finite OMI incidence is exact,
> metric projection is introduced only at the real-analysis boundary."

The 155 triples must be derived, not hard-coded — they are constraint solutions,
not objects.

---

## Phase 2 — Coq Formalization (July 6, 2026)

### 00:20–00:52 — The Core Axioms

The deterministic core formalized:

```
delta16(x, c) = rotl16(x, 1) ^ rotl16(x, 3) ^ rotr16(x, 2) ^ c
BQF(x, y) = 60x² + 16xy + 4y²
slot5040 = fano7 × 720 + role3 × 240 + local240
```

The 5040-slot ring redefined as a **quotient atlas** — not storage, but the
canonical boundary signature:

```
o---o/---/?---?@---@
```

Observer category theory introduced: the execution model is the foundation,
everything else is an observer over traces.

### 01:33–01:35 — GL(16,2) Orbit Engine

C implementation of the orbit engine:

```
$ gcc test_orbit.c omi_orbit.c -o test_orbit && ./test_orbit
=== GL(16,2) Orbit Engine Tests ===
PASS: delta16(0,0) == 0
...
```

Goal: align C ↔ Coq via verified extraction pipeline.

### 02:07–02:26 — Categorical Observer Semantics

- Goal: Complete categorical observer semantics for GL(16,2) linear dynamics
- Orbit groupoid G, observer functor theorem (Obs : G → FinSet)
- Trace equivalence, verified extraction boundary
- Coalgebraic bisimulation framework
- The bialgebra formulation

### 02:59–04:38 — Verified Execution Layer

`verified_execution.v` — Implementation refinement layer connecting the C orbit
engine to the Coq formal semantics via a representation map.

Five Coq files compiled cleanly:

1. `delta_orbit_theory.v` — Delta law formalization
2. `functorial_semantics.v` — Observer category theory
3. `coalgebraic_bisimulation.v` — Bisimulation framework
4. `OMI_bialgebra.v` — Bialgebra formulation
5. `verified_execution.v` — C ↔ Coq trace equivalence

Key insight (04:10): Use algebraic proofs, not `vm_compute` over 65536 elements.
The parity-based proof approach won.

### 04:36–04:38 — Coq Compilation Complete

All 5 files compilable. Decision to write a "fully normal-form driven decision
procedure for XOR-linear Coq goals."

---

## Phase 3 — Narrative and Integration (July 6–7, 2026)

### 20:49 — Google NotebookLM Podcast

Google's NotebookLM platform generated a podcast analyzing the OMI system:

> "The architecture of the OMI system is not merely a software specification; it
> is a Formal First Principles Cosmological Framework..."

### 21:02 — User's Self-Description

> "I'm doing all vibe coding with llm and coding agents, i just have a vision
> that i can say if it fits or not"

> "i'm limited to knowledge triples i'm using triangulation of the tetrahedron as
> my spatial quotient determiner... place-value, relations, the list from null in
> lisp as the observer in the void"

### 21:40–22:51 — Restructuring for Narrative

The user asked to restructure everything to fit a unified narrative:

> "I first started with an axiomatic epistemic systemic topology, but i think i
> like the word cosmology as this is trying to understand the world through my
> ideas on god is word and word is god as the observer in the void through the
> lens of a tetrahedron and the 600-cell."

Key insight from the user's learning journey:

> "I learned about horn clause, logic/lambda cubes and calculus of construction
> which lead to automata theory because i kept trying to say we are not even
> doing terms but that we are giving everything a position and relation."

The `o---o` documentation repository was given its narrative structure:
MANIFESTO → 1_FOUNDATIONS → 2_MATH → ... → 8_COSMOLOGY.

### 23:41–23:52 — Organizing for Proofs

Decision to finish the formal proofs first, then use the proofs to "moralize
everything else." The proofs were staged in `omi-isa/proof/` with consideration
of a separate `omi-theorems` repo for the Coq proofs.

### 00:09–00:48 — Full Historical Outline

The user provided the complete origin story: the earlier metaverse project, the
"in-the-beginning" repo from reading the Bible, the discovery of the Delta Law,
and the learning journey from React-only to cosmological computation.

---

## Phase 4 — Documentation (July 7, 2026)

### 00:00 — Document Repository Created

The `/home/main/omi/docs/2026-07-07-ESP32-S3_LoRa_Walkie-Talkie.md` chat
transcript (55,759 lines, 242 messages) was saved as the canonical inception
record.

### — TIMELINE.md (This Document)

Comprehensive chronological narrative of the entire OMI project origin and
evolution.

### — GLOSSARY.md

Comprehensive term map covering all concepts from both the conversation history
and the existing documentation.

### — 0_GENESIS/ (Planned)

Narrative foundation section being built to tell the origin story as a first-class
part of the documentation: the observer in the void, the Word as notation, the
learner's journey, the ESP32 revelation, the Radio VM, the OMI-Lisp ISA, and the
Canonical Cosmological Computation Model.

---

## Timeline Quick Reference

| Date | Time | Event |
|------|------|-------|
| ~2025 Q4 | — | Metaverse project (decentralized open-world, SCM/Guix) |
| ~2025 Q4 | — | "in-the-beginning" repo: Bible as pseudo-code |
| ~Jan 2026 | — | Delta Law discovery, first Coq proof |
| Jul 5, 2026 | 18:12 | ESP32 LoRa walkie-talkie concept |
| Jul 5, 2026 | 18:15 | OMI envelope code (omienv, stream, sector) |
| Jul 5, 2026 | 18:17 | Radio VM concept |
| Jul 5, 2026 | 18:19 | Platform-agnostic probe sync |
| Jul 5, 2026 | 18:26 | OMI-Lisp ISA (20+12 = 32 opcodes) |
| Jul 5, 2026 | 18:33–19:19 | Implementation phases 1–3 (134 tests) |
| Jul 5, 2026 | 19:24–20:41 | ISA refinement, 4 semantic lenses |
| Jul 5, 2026 | 21:04–21:33 | Factorial tower, O-expression grammar |
| Jul 5, 2026 | 21:53 | Tetrahedral stack (below 8!, 9!–12!, 6!) |
| Jul 5, 2026 | 22:29–22:53 | Glossary development |
| Jul 5, 2026 | 23:10 | Place-value notation theory |
| Jul 5, 2026 | 23:43 | omi_omion, omi_receipt, omi_sense modules |
| Jul 5, 2026 | 23:45–00:15 | Trigintaduonions, PG(4,2), Coq bridge |
| Jul 6, 2026 | 00:20–00:52 | Core axioms, quotient atlas, observer theory |
| Jul 6, 2026 | 01:33–01:35 | GL(16,2) orbit engine (C) |
| Jul 6, 2026 | 02:07–02:26 | Categorical observer semantics |
| Jul 6, 2026 | 02:59–04:38 | Verified execution layer (5 Coq files) |
| Jul 6, 2026 | 20:49–21:02 | NotebookLM podcast, architectural summary |
| Jul 6, 2026 | 21:40–22:51 | Narrative restructuring, cosmology framing |
| Jul 6, 2026 | 23:41–23:52 | Proof organization, repo staging |
| Jul 7, 2026 | 00:09–00:48 | Full historical outline, origin completion |
| Jul 7, 2026 | 00:00+ | Documentation: TIMELINE, GLOSSARY, 0_GENESIS |
