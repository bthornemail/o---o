# State 03 — Foundations: The Primitives

## What This State Is

This state is the transition from "why it matters" to "what cannot be reduced further." After establishing the philosophical significance, I needed to find the irreducible boundaries — the primitives that cannot be decomposed into simpler elements.

This state documents the foundational structures: the palindrome, the omicron anchors, the zero-frame, the slash path, the Omi-Ring, and the construction and fold operations that define what can be built and how.

---

## Part I — The Palindrome

### 1.1 omi---imo

The entire OMI Object Model turns on the palindrome:

```text
omi---imo
```

This is not decorative. It is structural.

- `omi` = U+03BF (Greek small omicron) = the Low Gate / entry
- `---` = three hyphens = the Join Field
- `imo` = U+039F (Greek capital omicron) = the High Gate / exit

The three hyphens are simultaneously:
- A **separator** (between entry and exit)
- A **join field** (binding them into one identity)
- A **rewrite bus** (where transformation happens)
- A **compiler lane** (where interpretation is routed)

Every valid OMI transmission is exactly 128 characters (2⁷), framing a 1024-bit instruction word decomposed into 8 hyphen-delimited 16-bit hex segments.

### 1.2 The Structural Meaning

The palindrome embodies the core OMI principle: the identity is bidirectional. You can read forward (`omi → imo`) or backward (`imo → omi`). The structure is the same; only the direction of reading changes.

```text
omi---imo = binary rewrite identity
```

The hyphen is the **primary topological operator**. It is not a separator in the conventional sense. It is a boundary that also joins. Every hyphen in an OMI address is a place where interpretation enters.

### 1.3 The 128-Character Frame

An OMI transmission is exactly 128 characters because 2⁷ = 128 is the minimum power of two that accommodates:

- 8 segments × 4 hex digits each (32 hex digits)
- Plus delimiters and structural markers
- Within a frame that maps cleanly to ASCII printable space

This is not an arbitrary choice. The 128-character frame is the physical surface of OMI computation — the irreducible carrier.

---

## Part II — The Omicron Anchors

### 2.1 The Two Anchors

OMI uses two Greek omicron codepoints as structural anchors:

| Glyph | Codepoint | Name | Role |
|-------|-----------|------|------|
| ο | U+03BF | Greek small omicron | Chiral entry / Low anchor / Execution operator |
| Ο | U+039F | Greek capital omicron | Cardinal exit / High anchor / Boundary operator |

These are not values. They are **operators** that frame the address space.

### 2.2 Entry and Exit

Every valid OMI frame begins with a lower omicron anchor and ends with an upper omicron anchor:

```text
S₁ = 0x03BF  — lower anchor (entry)
S₆ = 0x039F  — upper anchor (exit)
```

The anchors are invertible: a frame starting with 0x03BF and ending with 0x039F reads forward. Reversed, it reads right-to-left.

### 2.3 Frame Detection

The omicron anchors enable constant-time frame boundary detection:

- An eBPF/XDP filter can scan the first and last 2 bytes of an IPv6 source address
- If 0x03BF and 0x039F are present in the expected positions, the frame is a candidate
- No payload parsing required

This is how OMI can run at kernel line rate without protocol-specific parsing.

### 2.4 The Five Tetrahedral Packet Frames

The anchors define five tetrahedral packet frames:

```text
facts, rules, closures, combinators, cons
```

Each is enclosed by omicron anchors. The anchors are the universal frame delimiters that work across all five truth gates.

---

## Part III — The Zero-Frame

### 3.1 Omicron Is Not Zero

This is one of the most critical distinctions in the entire cosmology.

Zero (`0`, U+0030) is an **arithmetic value**:
- Additive identity: `x + 0 = x`
- Multiplicative absorber: `x × 0 = 0`
- It participates in arithmetic

Omicron (`ο`/`Ο`, U+03BF/U+039F) is an **observer-origin marker**:
- No arithmetic properties
- Marks frame boundaries
- Selects interpretation direction

Without this distinction, addresses like `omi-0500-03bf-0000-2b05-2f05-0000-039f-05ff` would be ambiguous — you could not distinguish segment values from operator markers.

### 3.2 The Omicron Cons Construction

```text
Ο(<car>, <cdr>)
```

Where:
- Ο (capital omicron) = the cons boundary operator
- <car> = control, address, boundary
- <cdr> = payload, continuation

The omicron cons is the OMI generalization of the Lisp cons cell. It defines not just a pair but a **bounded relation** between entry and exit.

### 3.3 The Empty Cons Identity

```text
()! = ()
```

The empty cons is the zero-frame: the place where structure can be addressed, evaluated, and replayed.

In Lisp, `()` is simultaneously an atom and a list. In OMI, the empty cons is simultaneously:
- A point (a position in the address space)
- A space (a bounded region of interpretation)

The zero-frame is not nothing. It is the observer-origin — the position from which all subsequent computation is measured.

### 3.4 Why Omicron Is the Observer-Origin

The Spirit in Genesis 1:2 hovers over the face of the waters. This is the observer before creation — present but not yet interpreting. Omicron is the computational equivalent: the marker that says "an observer is here" without specifying what they observe.

Omicron is not the data. Omicron is the position from which data is read.

---

## Part IV — The Slash Path

### 4.1 Interpretation Routing

The slash path `/---/` is the declared interpretation route appended to the palindrome identity:

```text
omi-<frame>-imo/<control>/<scale>/<relation>/<unit>
```

The hyphens bind terms. The slashes name their functional roles.

### 4.2 The Slash Path Is Not Storage

The slash path does not store data. It declares how the source is read.

Where the hyphens define the identity surface, the slashes define the derivation route outside the identity closure. Every slash segment is a Horn-clause selector narrowing the interpretation domain:

```text
omi---imo/semantic/subject/predicate/object/
```

Each slash adds a clause: `domain(Frame, subject)`, `domain(Frame, predicate)`, etc. The receipt records the accepted traversal.

### 4.3 Canonical Path Classes

The slash path supports seven classes of interpretation:

1. **Prefix** — CIDR depth `/N`
2. **HD Derivation** — hardware-dependent address derivation
3. **Browser Overlay** — RGBA/visual routing
4. **Agreement Role** — LL/NN/MM/OO selector
5. **Semantic** — S/P/O/Modality
6. **Quadratic F-Expression** — Q_xy coordinate mapping
7. **Control Separator** — FS/GS/US/RS structural markers

---

## Part V — The Omi-Ring

### 5.1 The Atomic Waveform Enclosure

The Omi-Ring is the atomic waveform enclosure of `omi---imo` — the minimal enclosure where intent can be preserved before it is fully interpreted.

It is the boundary between:
- **Omi-Portal** (outward public projection)
- **Omi-Mirror** (inward introspective recovery)

The Ring captures "a harmony with no listeners" — a bounded possibility before interpretation, agreement, or projection.

### 5.2 The Ring and the Frame

The Omi-Ring is not a file, voice, barcode, or DOM node. Those are **carriers** and **projections**. The Ring is the declared activity itself.

```text
The Ring:   omi---imo
Portal:     outward projection of the Ring
Mirror:     inward recovery of the Ring
```

### 5.3 Omi-Ring vs. Receipt

A crucial doctrinal distinction:

> The Omi-Ring is the addressed palindromic notation witness. A receipt is the accepted state verifier.

The Ring preserves. The receipt validates.

The Ring is what makes OMI objects addressable rather than interpreted. The Omi-Ring is the unit that Portal and Mirror both refer to. Everything else — Light, Sound, Gnomon, Sense, Dome, Portal, Mirror, Avatar, Image — are views, carriers, or embodiments of the Ring.

### 5.4 The Omi Constant

The Omi Universal Constant `Ω₀` = 16 bits = one `0xNNNN` word. This is the minimum structural quantum from which all OMI objects scale. Every larger structure is a composition of 16-bit words.

The constant is the zero-point of bounded agreement — the smallest unit that can be agreed upon.

---

## Part VI — The Euclidean Postulates (What May Be Constructed)

### 6.1 The Analogy

Euclid begins by defining points, lines, and circles, then states what constructions are permitted. OMI begins with address pointers, clauses, masks, receipts, and projections:

| Euclidean Role | OMI Role |
|---|---|
| Point | OMI pointer |
| Line | Rule path or state transition |
| Circle | Bounded replay/orbit cycle |
| Plane | Address/prefix surface |
| Construction | Derived declaration |
| Proposition | Rule/fact theorem proven by tests |
| Diagram | CSSOM/Canvas/telemetry projection |

### 6.2 Central Postulate

> From any valid OMI pointer, a rule path may be constructed.

An OMI pointer is not only a label. It is a constructible point in the protocol space. Given `omi-S0-S1-S2-S3-S4-S5-S6-S7/prefix`, the system may construct: rule binding, state transition, bitboard mask, bitblip policy, test path, replay receipt, and visible projection.

### 6.3 The Sixteen Postulates

1. **Address Point Construction**: An OMI pointer may be constructed from eight 16-bit segments and a prefix.
2. **Rule Line Construction**: Between an OMI pointer and an invariant name, a rule line may be drawn.
3. **Fact Grounding Construction**: A normative rule may be grounded as an applied fact when a concrete runtime state satisfies it.
4. **State Transition Construction**: A rule-to-fact derivation may be expressed as an a-list state transition.
5. **Bitboard Mask Construction**: From a rule pointer, a bitboard mask may be constructed over the relevant address fields.
6. **Bitblip Correction Construction**: From a bitboard mask and expected value, a bitblip policy may be constructed.
7. **Proof Path Construction**: For every rule line, a test path may be constructed.
8. **Replay Path Construction**: For every accepted state, a replay path may be constructed.
9. **Visible Projection Construction**: For every replayable state, a visible or inspectable projection may be constructed.
10. **Algebraic Membership Construction**: A valid instruction surface may be constructed by the equation Q(S) = 0.
11. **Orbit Construction**: From a valid instruction frame, a bounded Δ_C orbit may be constructed.
12. **Kernel Boundary Construction**: A packet-validity construction may be moved to the kernel boundary.
13. **Clock Construction**: A clock state may be constructed as an addressable period and gating condition.
14. **Optical Frame Construction**: A page may be constructed as a scannable protocol state.
15. **Declaration Construction**: Every grounded fact may be declared by a derivation expression.
16. **Complement Construction**: For any OMI pointer, mask, rule, or fact, a ones-complement anti-surface may be constructed.

### 6.4 The Final Postulate

> Whatever OMI can validate, it must be able to address; whatever it can address, it must be able to declare; whatever it declares, it must be able to test; whatever it tests, it must be able to replay; whatever it replays, it must be able to show.

Therefore:

```text
construction = pointer + rule + proof + replay + projection
```

---

## Part VII — The Origami Axioms (How Constructed Objects May Be Folded)

### 7.1 The Analogy

If the Euclid-inspired postulates define what may be constructed, the origami-inspired axioms define how constructed objects may be folded, reflected, complemented, aligned, resolved, and transformed.

In OMI, the plane is the 128-bit address surface. A fold is a legal transformation over OMI pointers, clauses, transitions, masks, deviations, receipts, and projections.

### 7.2 The Central Fold Law

> Every OMI clause has a fold plane.

A clause is not only a statement. It has a geometry. Given `omi-address/prefix MUST invariant-name`, the system may construct a fold across one or more of its surfaces: address surface, bitboard surface, rule surface, fact surface, replay surface, projection surface.

### 7.3 The Ones-Complement Law

> Ones-complement is the fundamental bit fold.

For a 16-bit segment: `fold(x) = x XOR 0xFFFF`
For a full 128-bit address: `fold128(S) = S XOR 0xFFFF-FFFF-FFFF-FFFF-FFFF-FFFF-FFFF-FFFF`

This creates the complement surface: state → anti-state, mask → anti-mask, rule → counter-rule, valid rail → eviction rail, presence → absence.

### 7.4 The Thirteen Origami Axioms

| Axiom | OMI Interpretation |
|---|---|
| O1: Fold through two points | Construct transition between two pointers |
| O2: Fold point onto point | Map state-before to state-after |
| O3: Fold line onto line | Align two rules or implementations |
| O4: Fold through point perpendicular to line | Derive diagnostic/error vector |
| O5: Fold point to line through point | Resolve one state under one rule with ambiguity |
| O6: Fold two points to two lines | Solve multi-constraint rule/fact alignment |
| O7: Fold point to line perpendicular to line | Partial success with diagnostic constraint |
| O8: Fold pointer onto complement | Ones-complement reflection |
| O9: Fold rule onto failure surface | Define failure behavior |
| O10: Fold fact back to rule | Preserve source-rule grounding |
| O11: Fold test onto rule | Enforce testability |
| O12: Fold test onto replay | Enforce replayability |
| O13: Fold replay onto projection | Enforce visibility |

### 7.5 The Provider Contract as Fold Chain

The provider contract can be written as a fold chain:

```text
address → rule → test → replay → projection
```

Expanded:

```text
No address without a rule.
No rule without a test.
No test without a replay path.
No replay path without visible state.
```

If a fold is missing, the provider state is incomplete.

### 7.6 The Complete Fold Requirement

A complete OMI state is one that can be folded:

- From address to rule
- From rule to test
- From test to replay
- From replay to projection
- From every surface to its declared complement

Therefore:

```text
complete state = pointer + rule + complement + test + replay + projection + failure surface
```

---

## Part VIII — The Nibble Wheel Structure

### 8.1 The 16-State Wheel

The fundamental structure of OMI geometry is the nibble wheel: 16 states arranged in a projective closure.

```text
2⁴ = 16 = 15 active states + 1 closure state
```

The 15 active states form the surface. The 1 closure state is the projective center — the point through which the wheel orbits.

### 8.2 The Diagonal Structure

Within the nibble wheel, diagonals define specific relationships:

```text
0x0 — closure center
0x1, 0x2, 0x4, 0x8 — cardinal directions (powers of 2)
0x3, 0x5, 0x6, 0x9, 0xA, 0xC — intercardinal (sums of powers of 2)
0x7, 0xB, 0xD, 0xE — remaining diagonals
0xF — full complement (all bits set)
```

Each diagonal represents a different relationship to the center: identity, complement, adjacency, opposition.

### 8.3 Sexagesimal Gate

The diagonal sum `0x1E + 0x1E = 0x3C = 60` is the sexagesimal gate. It appears repeatedly in the cosmology:

- 60 = 5! / 2 (half the packet root)
- 60 = 3 × 4 × 5 (the smallest Pythagorean triple product)
- 60 = sexagesimal base (the clock gate)

---

## Part IX — Declaration Templates (merged from root DECLARATIONS.md)

### 9.1 The Derivation Template

Every derivation from a `RULES.omi` row to a `FACTS.omi` row follows this a-list template:

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

### 9.2 Bitboard Mask Rules by Prefix

| Prefix | Segment Mask |
| ------:| ------------ |
|  `/48` | `[ffff,ffff,ffff,0000,0000,0000,0000,0000]` or rule-specific first three-segment family |
|  `/80` | `[ffff,ffff,ffff,ffff,ffff,0000,0000,0000]` |
|  `/96` | `[ffff,ffff,ffff,ffff,ffff,ffff,0000,0000]` |
| `/112` | `[ffff,ffff,ffff,ffff,ffff,ffff,ffff,0000]` |
| `/120` | byte-specific narrowing of final segment |
| `/128` | `[ffff,ffff,ffff,ffff,ffff,ffff,ffff,ffff]` |

Many OMI rules use sparse symbolic masks, not plain CIDR masks. When a rule explicitly constrains non-contiguous segments, derive the mask from the comments and invariant name rather than prefix alone.

### 9.3 Bitblip Policies by Axiom Family

| Axiom Family | Default Bitblip Policy |
| ------------ | ---------------------- |
| algebraic-membership | `evict-single` |
| delta-orbit | `evict-single` |
| barcode-ecc | `correct-up-to-2`, then `evict-over-2` |
| telemetry-isolation | `accept-exact` |
| kernel-enforcement | `drop-packet` |
| browser-projection | `warn-near-miss` |
| replay-ring | `reject-warm-overwrite` |
| clock-tree | `mark-gated` |
| notation | `evict-fractional-overflow` |
| service-bus | `accept-exact` |

### 9.4 Example Derivation: eBPF XDP Gate

Source rule:
```text
omi-0000-0000-0000-0000-0000-0000-00eb-0066/112 MUST initialize-xdp-packet-parsing-gates
```

Derived fact:
```text
omi-0000-0000-0000-0000-0000-0000-00eb-0066/112 FACT xdp-packet-parsing-gate-configured
```

A-list:
```lisp
(
  (rule-id . "0x12D")
  (rule-pointer . "omi-0000-0000-0000-0000-0000-0000-00eb-0066/112")
  (modal . "MUST")
  (invariant . "initialize-xdp-packet-parsing-gates")
  (axiom-family . "kernel-enforcement")
  (state-before . "unverified")
  (transition . "compile-and-load-xdp-gate")
  (state-after . "configured")
  (segment-mask . "[0000,0000,0000,0000,0000,0000,ffff,ffff]")
  (expected-segments . "[0000,0000,0000,0000,0000,0000,00eb,0066]")
  (bitboard-mask . "0x000000000000000000000000ffffffff")
  (bitblip-policy . "evict-single")
  (fact-pointer . "omi-0000-0000-0000-0000-0000-0000-00eb-0066/112")
  (fact-name . "xdp-packet-parsing-gate-configured")
  (test . "test/ebpf-pipeline.test.js")
  (projection . "bpf-map + cssom")
  (failure-behavior . "drop-packet")
)
```

## Part X — Ones-Complement State Table (merged from root AXIOMS.md)

| Original | Complement | OMI Meaning |
| -------- | ---------- | ----------- |
| `0000`   | `ffff`     | empty/full |
| `00ff`   | `ff00`     | low/high byte reflection |
| `03bf`   | `fc40`     | chiral delimiter complement |
| `039f`   | `fc60`     | cardinal delimiter complement |
| `5a3c`   | `a5c3`     | inversion constant complement |
| `7c00`   | `83ff`     | boot boundary complement |
| `aa55`   | `55aa`     | boot signature complement |
| `00eb`   | `ff14`     | eBPF marker complement |
| `0066`   | `ff99`     | XDP marker complement |

The complement table is not a validity table. It is a reflection table. A complement state becomes valid only if a rule explicitly accepts it.

## Part XI — Bitboard Fold Table (merged from root AXIOMS.md)

| Fold Type | Operation | Meaning |
| --------- | --------- | ------- |
| Identity fold | `x` | preserve state |
| Ones-complement fold | `x XOR all_ones` | reflect all bits |
| Segment fold | `Sᵢ XOR 0xFFFF` | reflect one segment |
| Byte fold | `byte XOR 0xFF` | reflect one byte |
| Mask fold | `mask XOR all_ones` | invert relevant fields |
| Bitblip fold | `x XOR (1 << k)` | one-bit deviation |
| Delta fold | `Δ_C(x)` | orbit transition |
| Inversion fold | `x XOR 0x5A3C` | central inversion |
| Endian fold | `swap16(x)` | orientation reversal |
| Replay fold | `slot → slot + steps mod 5040` | timeline movement |

## Part XII — The 12-Step Structural Execution Flow (merged from root AXIOMS.md)

```text
[1. SOURCE]     ──► Read high-level, human-readable .omi source files.
[2. VALIDATE]   ──► Verify the 128-bit wire carrier shell via Q_frame(S) == 0.
[3. GENERATE]   ──► Resolve principal pointer / ideal generator for the region.
[4. MIRROR]     ──► Execute Cayley-Dickson doubling to lower .omi to .imo bytecode.
[5. ENTER]      ──► Enclose the low-ASCII opcode line within native ο / Ο delimiters.
[6. COMPOSE]    ──► Process the 32x32 operator-table32 matrix for composition.
[7. ROUTE]      ──► Intersect S-P-O coordinate paths via the triad-router155 engine.
[8. SCOPE]      ──► Enforce CIDR prefix network specificity (/128 down to /64).
[9. TIMING]     ──► Advance the internal logic pacing tick via the Delta Law.
[10. NAMING]    ──► Read the derived orbital position using the Base36 label layer.
[11. PROJECT]   ──► Extrude 2.5D visual polyomino/domino voxels via Q_xy(x,y).
[12. REPLAY]    ──► Compress historical context states into the slot5040 receipt.
```

## Part XIII — Collaboration Axiom (merged from root AXIOMS.md)

> Agreement is the synthesis of shared intelligence. Disagreement is simply a missing structural file path. Productivity is appreciation made executable.

A rejected layout or conceptual gap is never left un-routed. It must immediately become a clear boundary, the boundary must become a strict rule, the rule must become an explicit test case, the test must verify a stable replay path, and the replay path must render as visible state on the user screen.

**O14 — Fold Address Onto Its Own Creation Step (Self-Sufficiency):**
Given an OMI address A, the creation step is a function of the frame alone:
```text
step720(A)  = Q_xy(S3, S4)       — LL-derived Fano/lane coordinate
slot5040(A) = fano7 × 720 + role3 × 240 + local240
```
No prefix /N or lens /@N changes step(A). The address is the thing.

**O15 — Three-Way Distinction: Claim / Backoff / Lens:**
```text
/N     = CIDR claim boundary          (first slash, no @)
/N-M   = claim backoff                (reduce claim by M bits)
/@N    = reader lens                  (select projection/cadence)
```
Neither creates identity; both operate on an already-valid address.

---

## The Transition to State 04

From this state — having identified the irreducible boundaries — I moved to State 04 (Atomic Kernel) to answer: what is the smallest deterministic object? What cannot be removed without changing replay?

Continue to `04-ATOMIC-KERNEL.md`.
