# OMI Glossary

> A comprehensive term map of the Omicron Object Model — covering the
> canonical doctrine, mathematics, protocol, engineering, and cosmology.

---

## 0. Cosmological / Biblical Origin

| Term | Definition |
|------|------------|
| **The Void** | The primordial undefined state (Genesis 1:2 — "without form and void"). In OMI, this is the pre-notation substrate: the bitboard before any bits are set, the stream parser in WAITING state, the observer before the reading. |
| **The Observer** | The entity hovering over the void (Genesis 1:2 — "Spirit of God hovering over the face of the waters"). The primordial reader before interpretation begins. Maps to: the interpreter, the lens, the active reading context. |
| **The Word / Logos** | The primordial notation (John 1:1 — "In the beginning was the Word... and the Word was God"). Observer and notation are one. Maps to: omi---imo, Omega_0, the palindrome as the fundamental computational relation. |
| **Canonical Cosmological Computation Model (CCCM)** | The unifying theory: (1) Computation is the lawful transformation of interpretation, not mutation of data. (2) The Word (Logos) is the primordial notation. (3) The observer in the void is the primordial computational context. (4) OMI is the formalization of this cosmology. |
| **God is Word / Word is God** | The collapse of observer and notation. The same entity is both the source of interpretation and the notation being interpreted. This is the OMI collapse (representation ↔ interpretation) stated as theology. |

---

## 1. Core Acronyms and Primary Concepts

| Term | Definition |
|------|------------|
| **OMI** | Omicron Object Model — a docs-first specification for turning open-world actions, claims, identities, links, events, and objects into bounded, inspectable, replayable structure. OMI is notation as cipher and cipher as notation. |
| **o---o** | (1) The abstract OMI documentation/protocol repository. (2) The shorthand enclosure form of the palindrome: `o---o`. The two `o`s represent the entry and closure points of an OMI relation. |
| **omi---imo** | The fundamental palindrome of OMI. Read forward: `omi` (entry). Read backward: `imo` (closure). The three hyphens are the join field / rewrite bus / compiler lane. |
| **Ω₀ / Omega_0** | The OMI Universal Constant = `0! = omi---imo`. The zero-point of bounded agreement — the smallest bounded relation capable of carrying meaning. |
| **0! = 1** | Factorial of zero. One arrangement of nothing. Null action returns identity. In OMI: `0! = omi---imo` means "null agreement returns frame." |
| **Ο / ο** | Greek Capital/Small Omicron. `U+039F` / `U+03BF`. The structural frame anchors. `ο` (small) = low gate / entry. `Ο` (capital) = high gate / closure. |

---

## 2. Mathematics

| Term | Definition |
|------|------------|
| **Q_frame(S)** | The frame validation function. `Q_frame(S) = E_var + E_const`. Must equal 0 for a valid frame. Validates structural integrity of an 8-segment OMI frame. |
| **Q_xy(x, y)** | The projection geometry. `60x² + 16xy + 4y²`. Maps high-plane identity (x) and low-plane payload (y) to a bounded quadratic surface. Positive-definite, elliptic paraboloid. |
| **Delta Law (Δ)** | The bitwise transition engine. `Δ_C(x) = rotl(x,1) ⊕ rotl(x,3) ⊕ rotr(x,2) ⊕ C`. Produces period-8 orbits. The atomic kernel of OMI dynamics. |
| **Δ₁₆(x)** | Bounded 16-bit form: `Δ_C(x) & 0xFFFF`. |
| **C / C_LL** | Delta Law constant. Canonical base: `0x5A3C`. Modulated: `C_LL = (LL × 0x1337) & 0xFFFF`. Alternatives: `0xACAB`. |
| **0x5A3C** | Canonical base constant for the Delta Law. Decimal 23098. |
| **0x1337** | LL modulation multiplier. |
| **Period-8** | Every Delta Law state returns after exactly 8 applications. The fundamental orbital period. |
| **B = [0,1,3,6,9,8,6,3]** | Orbital weight block from the decimal expansion of `1/73`. The weight sequence for the period-8 Delta orbit. |
| **Prime 73** | `1/73 = 0.01369863...` — generates the orbital weight sequence. 73 is prime. |
| **W = 36** | Weight sum = `6!/20`. Master frame stride for the chronograph. |
| **(epoch, phase) = divmod(position, 36)** | Stream position decomposition into macro-cycle (epoch) and local offset (phase). |
| **Sexagesimal system** | Base-60. A superior highly composite number with 12 divisors. OMI's orientation grammar. |
| **60x²** | High-side term of Q_xy. Cosmic orbit / orientation / identity ring. Maps to 4D regular polytope orbit. |
| **16xy** | Cross-term of Q_xy. Meeting plane / bridge / Archimedean-Catalan snub. The addressable relation between rings. |
| **4y²** | Low-side term of Q_xy. Atomic data / local declaration / Platonic seed. |
| **15-of-16 principle** | 4-bit wheel: 15 active states + 1 projective center (closure state). |
| **7-of-8 principle** | 8-state wheel: 7 active states + 1 closure state. Maps to the Fano plane (7 points + 1 center). |
| **Projective closure** | A finite wheel where one state is the projective center — simultaneously a point and a space. Foundational to OMI's treatment of finite state spaces. |
| **() as atom and list** | The empty list principle from Lisp. `()` is both atom and list. OMI treats closure the same way — origin and container. |
| **det(A) = 176** | Determinant of the quadratic form matrix `[[60,8],[8,4]]`. |
| **Fano plane** | PG(2,2) — the smallest projective plane: 7 points, 7 lines. Used for bounded incidence resolution (≤15 steps). |
| **Fano resolution** | The process of proving MM is reachable from NN within the bounded Fano window (max 15 steps). |
| **240-state bridge** | `2 × 5! = 240` and `15 × 16 = 240`. The meeting point of five-fold and four-fold symmetry. |
| **5! = 120** | Smallest complete semantic universe / packet root. |
| **6! = 720** | Semantic sweep stride. |
| **7! = 5040** | Full replay ring size. Slot count for the receipt ring. |
| **Factorial tower** | The address space generated by successive factorial operations. Each factorial layer (n!) is a level of the OMI address hierarchy. |
| **Polycubes** | 3D combinatorial geometry with 33 symmetry types. 8 layers mapping to the factorial tower. |
| **Chirality** | Left/right handed orientation. Cardinality = 2. Snub cube and snub dodecahedron are chiral. |
| **Snub truncation** | The OMI geometric update model: cut + twist + re-face. "Cut = isolate unresolved boundary, twist = introduce chirality, re-face = create triangular agreement surfaces, record = preserve path, project = expose accepted state." |
| **Trigintaduonions** | 32-dimensional noncommutative, nonassociative algebra over the reals. The 32 dimensions map to the 32-slot OMI ISA. 155 distinguished triples in the multiplication table map to PG(4,2) incidence lines. |
| **PG(4,2)** | 4-dimensional projective space over GF(2). 31 points. Maps to the 32-slot ISA space (31 active + 1 closure). |
| **BQF** | Binary Quadratic Form — specifically `60x² + 16xy + 4y²`. |

---

## 3. Protocol and Frame Structure

| Term | Definition |
|------|------------|
| **128-bit frame** | The OMI canonical frame: 8 segments × 16 bits = 128 bits. Same width as an IPv6 address. |
| **8-segment frame (S0–S7)** | The eight 16-bit segments of a canonical OMI frame. |
| **S0** | `0xLL00` — opening boundary segment. |
| **S1** | `0x03BF` — small omicron delimiter (ο). |
| **S2** | `0xNNNN` — antecedent input. |
| **S3** | `0x2BLL` — interior lens binding. |
| **S4** | `0x2FLL` — interior lens binding. |
| **S5** | `0xMMMM` — consequent output. |
| **S6** | `0x039F` — capital Omicron delimiter (Ο). |
| **S7** | `0xLLFF` — closing boundary segment. |
| **E_var** | Variable constraint term in Q_frame: LL agreement across S0, S3, S4, S7. |
| **E_const** | Fixed constraint term in Q_frame: delimiter and constant alignment. |
| **Truth row (LL, NN, MM)** | The smallest agreement face. LL = scope/ket selector, NN = antecedent input, MM = consequent output. Every valid frame yields exactly one truth row. |
| **LL** | Ket-like scope selector (8 bits). High nibble = context / lens family. Low nibble = execution slot selector. |
| **NN** | Antecedent / free variable input in the truth row. The beginning of a transition. |
| **MM** | Consequent / output in the truth row. The resolution of a transition. |
| **Genesis frame** | The first conformance anchor: `0100-03bf-7c00-2b01-2f01-1434-039f-01ff`. |
| **0x7C00** | BOOT_ADDRESS — canonical boot address. x86 MBR boot signature offset. |
| **BOOT_SLOT = 1504** | `0x7C00 mod 5040` — canonical boot ring slot. |
| **GENESIS_LL = 0x01** | Genesis truth row LL value. |
| **GENESIS_NN = 0x7C00** | Genesis truth row NN value. |
| **GENESIS_MM = 0x1434** | Genesis truth row MM value. |
| **GENESIS_STEPS = 1** | Genesis resolution step count. |
| **Hyphen field / Join field** | `---` in `omi---imo`. Carries the rewrite, binds terms, acts as compiler lane. Simultaneously separator, join, bus, and operation. |
| **Slash path** | `/---/` — the declared interpretation route. Full form: `omi-<frame>/<control>/<scale>/<relation>/<unit>-imo`. |
| **OMI envelope** | A 512-bit (64-byte) structured data unit: gauge[8] + orientation[8] + recovery[8] + target[8] + relation[32]. The fundamental OMI packet. |
| **512-bit envelope** | The minimum complete boot relation for the OMI protocol. 64 bytes total. |
| **OMI preheader** | 8-byte canonical header: `0xFF 0x00 0x1C 0x1D 0x1E 0x1F 0x20 0xFF`. |
| **gauge[8]** | First 8 bytes of envelope. OPCODE / instruction prefix / sync header. |
| **orientation[8]** | Bytes 8–15 of envelope. Channel / source context / device identity. |
| **recovery[8]** | Bytes 16–23 of envelope. Execution state / retry / ACK / fault flags. |
| **target[8]** | Bytes 24–31 of envelope. Destination / control flags / routing directive. |
| **relation[32]** | Bytes 32–63 of envelope. Payload / operands / compressed data / sub-instructions. |
| **OMI-Lisp** | The lazy declaration language for OMI relations. The readable surface available after the pre-language control stream reaches the readable boundary. Uses cons cells and S-expression-like structure. |
| **OMI-Cons256** | Full spectrum cons cell structure for OMI-Lisp. 256 variants for the full byte range. |
| **Non-printing gauge table** | A gauge table that operates at the control-code level (0x00–0x1F), not as printable ASCII. The ISA is declared through control characters, not text. |

---

## 4. Architecture and Implementation

| Term | Definition |
|------|------------|
| **Stream parser** | The state machine that syncs and parses OMI envelopes from a byte stream. States: WAITING → HEADER → PAYLOAD → COMPLETE / INVALID. |
| **Bitboard** | A 64-bit projection of the 512-bit envelope onto a feature register. Flags for bridge, seal, boot, place, and result fields. |
| **Gauge table** | A 128-entry semantic opcode registry. Each entry is a lambda-like structure: opcode, class, diag, action, s[8] (symbolic stack), payload, mask, car, cdr, bridge. |
| **Gauge entry** | A single slot in the gauge table. Defines the class, diagnostic, action, and lambda structure for one opcode. |
| **Dispatch table** | `omi_handler dispatch_table[128]` — function pointers indexed by opcode. Turns the parser into a VM. |
| **Probe sync** | A self-describing handshake protocol using special OMI envelopes. Lifecycle: IDLE → PROBE_SENT → PROBE_RECEIVED → NEGOTIATING → SYNCED → ACTIVE. |
| **Capability bitfield** | Runtime ABI descriptor: AUDIO_ADPCM=0x01, AUDIO_OPUS=0x02, SENSOR_GPIO=0x04, VM_EXEC=0x08, MESH_ROUTING=0x10, RELAY_MODE=0x20. |
| **Radio VM** | A distributed virtual machine where each OMI envelope is a 512-bit instruction executed over RF. Nodes are VM instances, mesh is shared execution graph. |
| **OMI-ISA** | The 32-slot instruction set architecture: 20 core opcodes (0x00–0x13, fixed semantics) + 12 extended opcodes (0x14–0x1F, gauge-table dynamic). |
| **Core ISA (0x00–0x13)** | 20 non-negotiable base opcodes: NOP, PROBE, PROBE_ACK, SYNC_COMMIT, SEAL, BOOT, RESET, ROUTE, BROADCAST, SEND, RECV, STORE, LOAD, EXEC, CALL, RETURN, SENSOR_IN, SENSOR_OUT, AUDIO_IN, AUDIO_OUT. |
| **Extended ISA (0x14–0x1F)** | 12 gauge-table dynamic opcodes: GAUGE_BIND, GAUGE_UNBIND, GAUGE_INVOKE, PLACE_WRITE, PLACE_READ, FOLD, BITBOARD_APPLY, STATE_COMMIT, STATE_REVERT, STREAM_SPLIT, STREAM_MERGE, VM_ESCAPE. |
| **validate → resolve → record → materialize → project → inspect** | The strict OMI pipeline. Must not be shortcut or reordered. |
| **render → believe** | The forbidden shortcut. Projection must never authorize validation. |
| **0xE_ manifold** | The accepted execution manifold: 0xE0–0xEF. 12 inner materializer slots + 4 outer controller vertices. |
| **0xE0–0xEB** | Twelve inner materializer slots. Pack the object: page-frame-root, DOM/CSSOM/JSDOM, OMI patch, edge/vertex traversal, snub bridge, stellated octahedron, Fano triangle, 59/60/61 band, receipt export. |
| **0xEC–0xEF** | Four outer controller vertices. Hold the object: translation/scale/rotation/boundary. |
| **rule_slot = 0xE0 + (LL & 0x0F)** | Slot selection formula. Maps LL's low nibble to one of 16 execution slots. |
| **4 semantic lenses** | SYSTEM (local VM), REMOTE (probe/sync/transport), USER (OMI-Lisp), HW (probe→hardware bridge). |
| **Place-value notation** | Each nibble is a position in a 32-character omi---imo citation. Each character can be a point or line, like n-ball or monoid. |
| **Spectrum modem** | A modem based on place-value notation — bytes are symbols, gauge table is the opcode lattice, envelope is the instruction word, LoRa is the carrier wave. |

---

## 5. Memory and Receipts

| Term | Definition |
|------|------------|
| **5040 replay ring** | A circular buffer of 5040 slots (7!) for storing accepted receipts. |
| **Receipt** | A 64-bit packed evidence of acceptance: provenance (16-bit), step count, LL, NN, MM. |
| **Provenance** | 16-bit epoch + sub-epoch identifier in a receipt. |
| **Ring indexer** | Cursor management for the 5040-slot ring using Atomics.compareExchange. |
| **Overwrite policy** | Rules for slot reuse: epoch tag, cold/warm/phantom states. |
| **Quotient atlas** | The 5040-slot ring redefined as a quotient space — not storage, but the canonical boundary signature: `o---o/---/?---?@---@`. |
| **Slot5040 = fano7 × 720 + role3 × 240 + local240** | The slot decomposition: Fano selection (7) × semantic sweep (720 = 6!) + role (3) × 240 bridge + local position (240 = 2 × 5!). |
| **META64** | 64-bit metadata format for receipt verification (`omi_receipt.h/c`). |

---

## 6. Network and Transport

| Term | Definition |
|------|------------|
| **IPv6 → OMI frame mapping** | 128-bit IPv6 address directly maps to 8 × 16-bit OMI frame segments. |
| **/48 canonical frame** | Canonical OMI address prefix (48-bit). |
| **text/x-omi-mnemonic** | Human-readable hyphenated OMI notation MIME type. |
| **application/x-omi-cbos** | Raw Chiral Binary Object Stream MIME type. |
| **application/x-omi-chronograph** | Full chronograph instruction envelope MIME type. |
| **web+omi:** | Browser protocol handler for local OMI routing. |
| **CBOS / BOM** | Chiral Binary Object Stream / Byte-Order Mark framing. |
| **RULES.omi** | Constraint rule file. Keyword: MUST. |
| **FACTS.omi** | Grounded implementation facts. Keyword: FACT. |
| **CLOSURES.omi** | Bounded completion declarations. Keyword: CLOSE. |
| **COMBINATORS.omi** | Lawful composition declarations. Keyword: COMBINE. |
| **CONS.omi** | Pair structure declarations. Keyword: CONS. |
| **CONFIGURATIONS.omi** | Runtime bindings. |
| **Horn-clause derivation** | Address path segments as Prolog-like clause selectors. |
| **MCRSGSP** | Monotone Causal Reed-Solomon Gossip Storage Protocol — the gossip/recovery layer providing candidates for OMI acceptance. |
| **Reed-Solomon** | Error correction code used in the gossip layer for fragment recovery. |
| **eBPF / XDP** | Kernel-level packet filter. Gate 1 = Q_frame validation, Gate 2 = Delta/Fano resolution. XDP_PASS / XDP_DROP. |
| **delta_orbital_gate.bpf.c** | eBPF source for the kernel gate. ~14.7 KB ELF, ~1.5 KB JIT native code. |
| **Transport simulator** | Linked ring-buffer transport pair for two-node simulation (`omi_transport_sim.h/c`). |

---

## 7. Engineering and Hardware

| Term | Definition |
|------|------------|
| **ESP32-S3** | Espressif dual-core WiFi/BLE MCU. Primary target for OMI embedded runtime. |
| **SX1262** | Semtech LoRa transceiver. Sub-GHz radio for OMI mesh networking. |
| **SX1276 / RFM95** | Older but widely supported LoRa radio module. Alternative to SX1262. |
| **LoRa** | Long-range sub-GHz packet radio physical layer. 915 MHz (US ISM band). |
| **ADPCM** | Adaptive Differential Pulse Code Modulation. Audio codec for LoRa voice. |
| **Opus** | Higher-quality audio codec (heavier CPU) for LoRa voice. |
| **INMP441** | I2S MEMS microphone for audio capture on ESP32-S3. |
| **FCC Part 15** | US unlicensed RF device regulation. 902–928 MHz ISM compliance. |
| **Web Serial** | Browser-based serial bridge for OMI envelope transport. |
| **WASM** | WebAssembly substrate. ~2.7 KB C99 module. |
| **C99 core** | Portable C99 reference implementation. `axiomatic.c`, `omi_orbit.c`, etc. |
| **SharedArrayBuffer(1024 × 16)** | 16 KB shared memory wormhole (128 slots × 128 bytes) for browser-based transport. |

---

## 8. Canon and Doctrine

| Term | Definition |
|------|------------|
| **Third Collapse** | OMI collapses representation and interpretation (after Lisp collapsed program/object and POSIX collapsed storage/communication). |
| **Notation as cipher / Cipher as notation** | The core OMI collapse. A notation declares how a surface is read. A cipher declares how a surface is transformed. OMI removes the distinction. |
| **Rewrite register** | OMI is not a database — it is a register of transformations. The address is where interpretation begins, not where data is stored. |
| **Bitblip** | A small binary transition inside a rotating rewrite surface. The primitive OMI operation. |
| **Agreement** | A structural event where open-world declaration becomes bounded, validated, replayable, and inspectable. Not a feeling, vote, or platform decision. |
| **Disagreement → missing structure → new object/path/test/receipt** | OMI's disagreement routing. Disagreement is not failure — it is missing structure. |
| **carrier != authority** | A carrier may transport state, but does not authorize it. |
| **projection != validation** | A projection displays state but cannot validate it. |
| **glyph != meaning** | A visual form is not semantics. |
| **portal != proof** | A portal surface is not proof of acceptance. |
| **prefix != identity** | A naming prefix is not an object identity. |
| **render != believe** | Rendering is not acceptance. |
| **gossip != authority** | Recoverability from gossip is not authoritative acceptance. |
| **The reader may recognize. The resolver may promote. Only validation and receipt may accept.** | The core agreement sentence. |
| **Five meta-memory families** | RULES (MUST), FACTS (FACT), CLOSURES (CLOSE), COMBINATORS (COMBINE), CONS (CONS). |
| **Four channel operators** | JOIN (binds), COMPOSE (orders), ENCODE (lowers), DECODE (raises). |
| **Twelve Tribes of Agreement** | Foundation (Freedom, Autonomy, Sovereignty, Reciprocity) + Attention (Focus, Attention, Observation, Experience) + Boundary (Stop, Yes, No, Acknowledgement). |
| **Four human modes** | Focus (selects), Attention (alerts), Observation (verifies), Experience (remembers). |
| **0x00–0x1F** | C0 Control Codes — rewrite operators, not characters. |
| **0x20–0x7F** | Printable characters — the visible projection surface. |
| **0x1C (FS)** | File Separator — Frame System root delimiter. |
| **0x1D (GS)** | Group Separator — Glyph Structure delimiter. |
| **0x1E (RS)** | Record Separator — Resolution Segment delimiter. |
| **0x1F (US)** | Unit Separator — Unit Coordinate delimiter. |
| **0x20 (Space)** | Visible absence / printable empty pivot. |
| **0x7F (DEL)** | Terminal sentinel — marks the boundary between control and projection. |
| **Non-collapse doctrine** | Projection is not authority. Implementation is not doctrine. Doctrine is not proof. Proof is not collaboration. |

---

## 9. Cosmology

| Term | Definition |
|------|------------|
| **Omi-Ring** | The atomic waveform enclosure between `omi` and `imo`. The bounded unit being viewed. Not a receipt — it is the addressed palindromic notation witness. |
| **Omi-Portal** | A public projection view of an addressed OMI object. A browser or UI surface. |
| **Omi-Mirror** | An introspective recovery / reinterpretation view. |
| **Omi-Light** | The projection spectrum. Light orients how a declaration appears. Wavelength, color, brightness, phase. |
| **Omi-Sound** | The intention spectrum. Sound carries how a declaration is intended. Cadence, rhythm, stress, call-and-response. |
| **Omi-Gnomon** | Light-field orientation: `rRgGbBaA` — the gnomon as orientation witness. |
| **Omi-Sense** | Intent capture across carriers (light, sound, gesture, etc.). The physical transducer layer. |
| **Omi-Dome** | Spatial-temporal capture environment. |
| **Omi-Avatar** | Pseudo-persistent public embodiment. |
| **Omi-Image** | Recoverable bounded package (pixels, glyphs, DOM, canvas). |
| **Omi-Gravity** | Frame-step pull toward resolution / centroid. The rewrite operator in the hyphen field. |
| **Centroid** | The center of framed intention. The point where declarations and definitions resolve into agreement. |
| **Omi-Nomogram** | Run-time scale selector for interpretation. 16 canonical scales (0x30–0x3F). |
| **Omi-SlideRule** | The mechanical face of Omi-Nomogram. The visible scale alignment surface. |
| **Canonical scale row (0x30–0x3F)** | 16 scales: identity, multiply-divide, square-root, cube-root, π, reciprocal, sine, tangent, small-angle, Pythagorean, log10, natural log, sexagesimal gate, powers, quadratic/gnomon, period/replay/LFSR. |
| **Principal Address Domain** | Every valid OMI object is generated from a bounded address element. |
| **Unique Factorization of Addressed Meaning** | Accepted objects factor into canonical parts uniquely. |
| **Light Garden** | The physical transducer profile for Omi-Sense. Defines how light is captured and interpreted as OMI events. |
| **Snub cube** | Chiral Archimedean solid: 6 squares + 32 triangles. Edge-traversal witness. |
| **Snub dodecahedron** | Chiral Archimedean solid: 12 pentagons + 80 triangles. Vertex-traversal witness. |
| **Stellated octahedron** | Compound of two tetrahedra. Inverse mirror of local snub space. |
| **59/60/61 band** | Orientation band around sexagesimal center. |
| **cosmic ring / bridge ring / atomic ring** | The three rings of Q_xy domain decomposition: `60x²` (cosmic), `16xy` (bridge), `4y²` (atomic). |

---

## 10. Implementation — Code Modules

| Term | Definition |
|------|------------|
| **omienv.h/c** | Core 512-bit envelope: struct, bitboard constants, gauge entry, parse/validate/bitboard/relation API. |
| **stream.h/c** | Streaming parser state machine. States: WAITING → HEADER → PAYLOAD → COMPLETE / INVALID. |
| **sector.h/c** | 512-byte sector iterator (8 cells × 64 bytes). |
| **omi_dispatch.h/c** | 32-slot ISA dispatch table with gauge lambda execution. Direct threaded dispatch. |
| **omi_gauge_exec.h/c** | Gauge lambda execution engine. Runtime evaluation of gauge table entries. |
| **omi_transport_sim.h/c** | Linked ring-buffer transport pair for two-node simulation. |
| **omi_probe.h/c** | Probe handshake state machine: start/poll/serve/handshake. |
| **omi_omion.h/c** | OMIOM prefix-scoped cascade resolver (27 tests). |
| **omi_receipt.h/c** | META64 receipt verification (27 tests). |
| **omi_sense.h/c** | Light Garden protocol adapter bridge (5 tests). |
| **omi_orbit.c** | GL(16,2) orbit engine. delta16 implementation. |
| **omi_pi_proof.v** | Coq proof: deterministic OMI incidence scaffold for pi. |
| **delta_orbit_theory.v** | Coq formalization of the Delta law. |
| **functorial_semantics.v** | Coq: Observer category theory (Obs : G → FinSet). |
| **coalgebraic_bisimulation.v** | Coq: Bisimulation framework. |
| **OMI_bialgebra.v** | Coq: Bialgebra formulation. |
| **verified_execution.v** | Coq: C ↔ Coq trace equivalence via representation map. |
| **PalindromicOmiEngine** | Node.js reference implementation class. |
| **DeltaLawEngine** | Period-8 transformation core in Node.js. |
| **UniversalMnemonicCompiler** | Top-level compiler orchestrator in Node.js. |
| **ChronographMetaCompiler** | Meta-circular compiler layer. |
| **delta_orbital_gate.bpf.c** | eBPF/XDP kernel gate source. |
| **test_env.c** | 13 tests (39 assertions) for envelope parsing. |
| **test_dispatch.c** | Tests for 32-slot dispatch table. |
| **test_gauge_exec.c** | Tests for gauge lambda execution. |
| **test_radio_vm.c** | Tests for radio VM transport. |
| **test_mesh.c** | Tests for mesh networking. |
| **test_omicron.c** | Omicron anchor tests. |
| **test_orbit.c** | GL(16,2) orbit engine tests. |
| **omi_vm** | OMI virtual machine executable. |
| **omi_toolchain** | OMI toolchain executable. |

---

## 11. Repositories and Projects

| Term | Definition |
|------|------------|
| **o---o** | The abstract OMI documentation/protocol repository. Canonical doctrine, address grammar, schemas. |
| **omi-portal** | The companion implementation/collaboration application repository. Browser surfaces, inbox, kernels, lookup tables. |
| **omi-isa** | Repository containing the OMI instruction set architecture, C implementation, and Coq proofs. |
| **bthornemail/in-the-beginning** | The original "Bible as pseudo-code" repository. Genesis creation geometry, Torah patterns, Logos, Fano integration, 600-cell structure. |
| **bthornemail/theory-of-everything** | Computational consciousness framework. Recursive self-modeling fixed point theorem. Universal Tuple Computational Theory (UTCT). |

---

## 12. Key Constants and Values

| Value | Name | Significance |
|-------|------|-------------|
| `0x03BF` | Small omicron (ο) | Low anchor / entry delimiter |
| `0x039F` | Capital omicron (Ο) | High anchor / closure delimiter |
| `0x5A3C` | C_base | Canonical Delta Law constant |
| `0x1337` | LL multiplier | LL modulation factor |
| `0xACAB` | C_alt | Alternate Delta Law constant |
| `0x7C00` | BOOT_ADDRESS | Canonical boot address |
| `0xAA55` | MBR signature | x86 boot signature |
| `0x1D6B6` | CODEHIGH_OMICRON | Mathematical Bold Capital Omicron |
| `0x7F` | DEL | Terminal sentinel / projective boundary |
| `5040` | 7! | Replay ring slot count |
| `240` | 2 × 5! / 15 × 16 | Five-fold/four-fold bridge |
| `120` | 5! | Smallest complete semantic universe |
| `720` | 6! | Semantic sweep stride |
| `36` | W / 6!/20 | Master frame stride |
| `176` | det(A) | Determinant of quadratic form matrix |
| `73` | Prime | Generates orbital weight sequence |
| `0x002D` | GF(16) alpha | Galois field multiplier constant |
| `fc00::/7` | ULA prefix | Unique Local Address IPv6 fabric |
| `0xE0–0xEB` | Materializers | 12 inner execution slots |
| `0xEC–0xEF` | Controllers | 4 outer execution slots |

---

## 13. Notation and Syntax

| Term | Definition |
|------|------------|
| **omi-<frame>/<control>/<scale>/<relation>/<unit>-imo** | The full slash path form of an OMI address. |
| **o---o/---/?---?@---@** | The canonical boundary signature. The 5040 quotient atlas projects to this form. |
| **0xNNNN** | Placeholder for a 16-bit hex value in frame segments. |
| **<omi-fs>, <imo-fs>, <imo-gs>, <imo-rs>, <imo-us>** | Custom HTML elements for the OMI DOM hierarchy. |
| **<OMI-LOW>, <IMO-HIGH>, <OMI-FS>** | Low-plane/high-plane transceivers and frame root custom elements. |
| **#id, .class, data-*** | Standard HTML attributes repurposed for OMI: id = high-plane address, data-* = low-plane payload. |
| **unicode-bidi** | CSS property. In OMI: the upper reader-lens orientation — a cosmetic lens, not a structural authority. |
| **@lens / @selector / @overlay** | Horn-clause derivation route segments in the OMI address path. |
| **?---?** | External payload or stream attachment marker in OMI notation. |
