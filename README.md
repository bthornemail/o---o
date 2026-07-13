# OMI: Omicron Object Model (o---o)

```text
   ___    __  __    _
  / _ \  |  \/  |  | |
 | (_) | | |\/| |  | |
  \___/  |_|  |_|  |_|
  omi --- imo
```

**OMI** is the **Omicron Object Model**: a docs-first specification for turning open-world actions, claims, identities, links, events, and objects into bounded, inspectable, replayable structure.

The entire model is governed by one canon:

> Computation is not the mutation of data.
> Computation is the lawful transformation of interpretation.

The binary source remains. The reading changes. The rewrite is the computation.

This is the OMI Manifesto. For the full philosophical lens, read [MANIFESTO.md](MANIFESTO.md) first.

## Notation as Cipher

OMI begins with a palindrome:

```text
omi---imo
```

Read forward, `omi` is the opening side of the relation. Read backward, `imo` is the closing side. The hyphen bridge is the join field, the rewrite bus, and the compiler lane.

The palindrome is not merely a mnemonic. It is the visible surface of a deeper principle: **notation as cipher, cipher as notation**. The same binary surface can be read as text, address, proof, graph, route, receipt, or rewrite table depending on the declared interpretation.

The zero-point is:

```text
Ω₀ = 0! = omi---imo
```

From that zero-point, OMI builds a complete object doctrine:

```text
validate -> resolve -> record -> materialize -> project -> inspect
```

A portal may show an OMI object as a card, map pin, QR code, JSON Canvas node, SVG widget, local file, receipt row, event page, or timeline entry. Those are projections. They help humans inspect the object, but they do not authorize it.

The authority belongs to the accepted frame, its truth-row resolution, its receipt, its replay path, and its address relation.

```text
carrier != authority
projection != validation
glyph != meaning
portal != proof
```

OMI is a way to make open-world structure portable without handing truth to one platform.

## What This Repository Is

This is a **documentation-only OMI canon repository**.

It is not trying to be a package manager artifact, production runtime, or single app. It is the written specification, narrative map, and conceptual architecture for the Omicron Object Model.

The repo is organized as a progressive reader path:

```text
MANIFESTO.md       the philosophical lens (read first)
1_FOUNDATIONS      what OMI is
2_MATH             why the laws work
3_ARCHITECTURE     how accepted state projects into DOM/portal space
4_NETWORK          how frames map to IPv6, eBPF, and RULES.omi
5_MEMORY           how replay and receipts persist
6_IMPLEMENTATION   how runtimes prove conformance
7_CANON            how the final doctrine reconciles the versions
8_COSMOLOGY        how OMI's proportions become a ring/world model
public             static public pages and browser-facing models
_archive           source notes, extracted sessions, and older drafts
```

The goal is that a reader can enter from any layer:

- from the palindrome,
- from the math,
- from the browser architecture,
- from the IPv6/eBPF mapping,
- from the replay ring,
- from the open-world portal model,
- or from the final canon.
- or from the cosmology of bounded return.

Each path should lead back to the same core doctrine:

```text
Agreement is the moment shared intelligence becomes validated, replayable structure.
```

## Why OMI Exists

Most software portals are closed worlds.

A closed-world platform assumes:

```text
this app owns the account
this app owns the feed
this app owns the object ID
this app owns the database
this app decides the truth state
```

That makes the interface convenient, but it traps context. A post cannot naturally become a map object. A note cannot naturally become an event object. A receipt cannot naturally become portable proof. A local community page cannot easily move between a browser, phone, QR code, mesh node, personal archive, and public portal without losing structure.

OMI starts from a different assumption:

```text
the world is not complete
objects may appear from outside the app
multiple naming systems may coexist
offline state may later sync
different portals may project the same object
the user should be able to inspect what happened
```

So OMI does not ask one platform to own truth.

It asks:

```text
Can this object be addressed?
Can this frame be validated?
Can this truth row resolve?
Can this receipt be replayed?
Can this object be projected safely?
Can the reader inspect where it came from?
```

That is the open-world promise.

## Agreement Is All You Need

In OMI, **agreement** is not passive approval, voting, social consensus, or platform acceptance.

Agreement is a structural event.

An informal action becomes agreement only when it can be lowered into a bounded object path:

```text
someone says something
  ↓
the portal frames it
  ↓
the frame validates
  ↓
the truth row resolves
  ↓
a receipt is recorded
  ↓
the object becomes inspectable
  ↓
the object can be projected
```

So agreement does not mean:

```text
I like this
I voted for this
the platform accepted this
the majority approved this
```

Agreement means:

```text
this object has a valid frame
this object has an address relation
this object has a replay path
this object has a receipt
this object can be inspected
this object can be projected without becoming corrupted
```

Disagreement is not failure. Disagreement is an unresolved path.

```text
disagreement -> missing structure -> new object/path/test/receipt
```

For example:

| Disagreement | Missing Structure | OMI Output |
|--------------|-------------------|------------|
| "What is this?" | boundary | create or reveal object address |
| "Who said this?" | source | show identity/provenance object |
| "Where does this belong?" | containment | show hierarchy path |
| "What changed?" | replay | show linear event stream |
| "Why trust it?" | receipt | show validation evidence |
| "What does this word mean?" | semantic identity | resolve POS / synset / graph node |
| "Which version is current?" | conflict rule | show competing receipts |
| "Can I open it elsewhere?" | carrier projection | export as card, canvas, QR, SVG, or file |

OMI does not erase disagreement. It routes disagreement into construction.

## The Core Pipeline

The minimal OMI pipeline is:

```text
Q_frame(S) = 0
  ↓
truth row = (LL, NN, MM)
  ↓
MM resolves from NN under the LL-modulated Delta Law
  ↓
receipt writes into the 5040-slot replay ring
  ↓
LL selects rule_slot = 0xE0 + (LL & 0x0F)
  ↓
external rule materializer consumes the accepted envelope
  ↓
Q_xy projects accepted state into readable geometry
  ↓
portal surfaces inspect the accepted object
```

Expanded:

```text
A frame is valid iff Q_frame(S) = 0.

A valid frame yields one truth row:
  (LL, NN, MM)

A truth row is accepted iff MM resolves from NN under the LL-modulated Delta Law within the bounded Fano window.

An accepted row writes a replayable receipt into the 5040-slot ring.

Only after validation, resolution, and receipt may a rule block be materialized and projected into DOM, SVG, JSON Canvas, IPv6, QR, portal UI, or reader lenses.

Projection is never authority.
```

`start.sh` is therefore policy-blind: it validates, resolves, records, and emits the accepted `0xE_` rule address using `LL & 0x0F`. Named semantics such as snub truncation, DOM patching, CSSOM import/export, page-frame projection, and the `0xEC-0xEF` outer control surface live in `rules/registry.json` and the materializer layer, not in the shell gate.

The `LL` byte is the ket-like scope selector of the truth row: its high nibble carries context, and its low nibble selects one address in the folded `0xE_` materializer manifold. See `6_IMPLEMENTATION/6.5_LL_KET_SCOPE_AND_0xE_MANIFOLD.md`.

The viewport is receipt-bound when controlled through `0xEC-0xEF`. A conforming projection must not treat out-of-band camera or lens changes as accepted state.

This is the order that must not collapse:

```text
validate -> resolve -> record -> materialize -> project -> inspect
```

Not:

```text
render -> believe
```

## The Palindrome

The story begins with:

```text
omi---imo
```

The readable mnemonic form is `omi` and `imo`.

The compiled symbolic boundary uses the Omicron pair:

```text
ο = U+03BF = Greek small omicron
Ο = U+039F = Greek capital Omicron
```

OMI treats those symbols as structural anchors, not decorative glyphs.

```text
omi-  ->  ο  ->  entry into the object
-imo  ->  Ο  ->  closure of the object
```

The lower Omicron pair acts as the zero-frame marker. It tells the system where interpretation begins and where closure occurs.

The short rule:

```text
Omicron is not display.
Omicron is structure.
```

This distinction matters because OMI may render many visual forms, but the rendered form is not what validates the object.

## The Two Major Laws

OMI is governed by two major mathematical laws.

### 1. The Delta Law

The Delta Law is the atomic 16-bit transition engine:

```text
Δ(x) = rotl(x, 1) ⊕ rotl(x, 3) ⊕ rotr(x, 2) ⊕ C
```

The canonical base constant is:

```text
C = 0x5A3C
```

The Delta Law uses:

```text
rotations  -> preserve bits
XOR        -> reversible mixing
constant   -> breaks the zero fixed point
mask       -> keeps state bounded to 16 bits
```

The bounded form is:

```text
Δ₁₆(x) = (rotl(x,1) ⊕ rotl(x,3) ⊕ rotr(x,2) ⊕ C) & 0xFFFF
```

In OMI, Delta gives local motion, orbit tracking, replay cadence, deterministic step behavior, and truth-row resolution.

It produces the period-8 cadence that connects to the repeating decimal block of `1/73`:

```text
1/73 = 0.01369863...
B = [0, 1, 3, 6, 9, 8, 6, 3]
W = 36
(epoch, phase) = divmod(position, 36)
```

The short rule:

```text
Atomic Delta clocks.
Cosmic 36 orbits.
```

### 2. The Quadratic Law

OMI's projection and address geometry is:

```text
Q_xy(x, y) = 60x² + 16xy + 4y²
```

Each term has a role:

| Term | Role | OMI Meaning |
|------|------|-------------|
| `4y²` | low side | `omi-`, atomic data, `data-*`, local payload |
| `16xy` | meeting plane | CSSOM/JSDOM bridge, shared address relation |
| `60x²` | high side | `-imo`, DOM `id`, stable identity, orientation |

The number `60` anchors sexagesimal orientation. The number `16` anchors the nibble/word-boundary bridge. The number `4` anchors the visible selector/control face.

The Quadratic Law is projection geometry. It is not the structural validator itself.

Structural validation belongs to:

```text
Q_frame(S) = 0
```

This distinction is central:

```text
Q_frame validates.
Q_xy projects.
```

## The 128-Bit Frame

An OMI frame is an 8-segment structure of 16-bit words:

```text
S0-S1-S2-S3-S4-S5-S6-S7
```

A canonical frame has this shape:

| Segment | Value | Role |
|---------|-------|------|
| `S0` | `0xLL00` | opening boundary |
| `S1` | `0x03BF` | small omicron delimiter |
| `S2` | `0xNNNN` | antecedent input |
| `S3` | `0x2BLL` | interior lens binding |
| `S4` | `0x2FLL` | interior lens binding |
| `S5` | `0xMMMM` | consequent output |
| `S6` | `0x039F` | capital Omicron delimiter |
| `S7` | `0xLLFF` | closing boundary |

Frame validation checks two things:

```text
E_var    -> repeated LL agreement across S0, S3, S4, S7
E_const  -> fixed delimiter and constant alignment
```

A valid frame satisfies:

```text
Q_frame(S) = E_var + E_const = 0
```

This is the lower structural gate. A glyph, CSS rule, DOM node, Base36 symbol, emoji, color field, or portal card cannot make an invalid frame valid.

## Truth-Row Resolution

Once the frame validates, OMI extracts the truth row:

```text
(LL, NN, MM)
```

The resolver tries to reach `MM` from `NN` under the LL-modulated Delta Law.

One canonical modulation is:

```text
C_LL = (LL × 0x1337) & 0xFFFF
```

The resolver iterates:

```text
NN -> Δ_C_LL(NN) -> ... -> MM
```

If `MM` is reached within the bounded Fano window, the row is accepted and the step count becomes a receipt field.

If `MM` is not reached, the row is rejected.

This gives OMI a deterministic acceptance path:

```text
valid frame
  ↓
truth row extracted
  ↓
bounded resolution attempted
  ↓
accepted or rejected
```

This is not majority vote. It is not probabilistic social consensus. It is a structural resolver.

## The 5040 Replay Ring

Accepted truth rows are recorded into the replay ring:

```text
7! = 5040 slots
```

Each receipt stores enough information to replay the accepted relation.

A receipt contains:

```text
provenance
step count
LL
NN
MM
```

The ring makes agreement durable:

```text
agreement -> receipt -> replay path
```

The replay ring is why OMI can say an object has history without depending on a hidden platform database. The object's visible state can be inspected through its accepted receipts.

The short rule:

```text
5040 replays.
```

## Lower Omicron and Upper Bidi

OMI separates lower structural law from upper reader law.

The lower stack is governed by:

```text
Omicron symbols
Delta Law
binary quadratic form
Q_frame
Fano replay
hidden 5! orbit recovery
5040 receipts
```

The upper stack is governed by:

```text
reader sequencing
CSS unicode-bidi
LTR/RTL display orientation
visual lenses
observer order
template phase
```

The correction is important:

```text
unicode-bidi does not belong to the lower stack as authority.
unicode-bidi belongs to the upper stack as a cosmetic reader lens.
```

Below `8!`, OMI is governed by actual Omicron zero-frame symbols, Delta, the binary quadratic form, and replay.

Above `9!`, OMI may use `unicode-bidi` to display alternate reader orientation without changing the underlying character representation, validating the frame, or authorizing lower-state mutation.

Short doctrine:

```text
Lower Omicron encodes.
Atomic Delta clocks.
Hidden 5! roots.
Cosmic 36 orbits.
Upper Bidi displays.
Characters stay fixed.
```

A lower error means the object body drifted. An upper error means the reader lens tilted.

That separation protects the protocol from confusing display with truth.

## The Open-World Portal

A consumer does not experience OMI as equations.

A consumer experiences OMI as a normal web portal:

```text
open -> browse -> inspect -> act -> verify -> share -> replay
```

They see:

```text
cards
profiles
events
maps
posts
notes
files
routes
products
services
receipts
comments
local groups
```

Underneath, the portal sees:

```text
validated frames
addressed payloads
source/object relations
linear replay streams
hierarchical containment trees
graph links
receipt rows
carrier projections
```

The same object can appear as:

```text
web card
JSON Canvas node
map pin
SVG element
QR code
local file
portal widget
timeline entry
receipt row
```

The object is the addressed state. The portal surface is only a carrier.

## The Two Reader Views

Every accepted OMI object should be inspectable in two basic views.

### Linear View

The linear view answers:

```text
What happened?
In what order?
What was replayed?
What led to this state?
```

In OMI notation:

```text
omi -> payload -> imo
```

For an event, the linear view might show:

```text
event created
route added
food note added
safety note added
rider joined
time updated
comment posted
```

The linear view shows how the object moved.

### Hierarchical View

The hierarchical view answers:

```text
Where does this belong?
What contains it?
What context controls it?
What unit am I inspecting?
```

In OMI notation:

```text
FS -> GS -> RS -> US
```

For the same event, the hierarchy might show:

```text
Community
  Bike Ride
    Route
      Stop
        Comment
```

The hierarchical view shows where the object belongs.

Together:

```text
linear view       = how the state moved
hierarchical view = where the state belongs
receipts          = why the state was accepted
```

## Example: Local Event Portal

A community organizer creates a bike ride portal.

The consumer sees:

```text
Sunday Night Lights Ride
Meetup: Popeyes parking lot
Route: Vermont Ave Florence -> Imperial and back
Distance: 3.2 miles one way
Food: hot dogs, hot links, sodas
Status: active
```

Behind the interface, the event is an object:

```text
omi-event
  payload: ride details
  source: organizer
  context: local community
  route: map path
  receipts: updates / joins / comments
imo-event
```

A rider opens the portal and gets multiple views:

| View | Consumer Value |
|------|----------------|
| Card | fast summary |
| Linear replay | what changed and when |
| Hierarchy | where the object belongs |
| Map | where to go |
| Receipts | why the object is trusted |

If the route changes, the old version is not silently erased. The update becomes a new addressed state.

The portal can say:

```text
Route updated 12 minutes ago.
Accepted frame.
Mirrored by 2 peers.
Previous route still replayable.
```

That is consumer-facing agreement.

## Example: Local Marketplace Portal

A vendor publishes a cart menu through the same portal.

The consumer sees:

```text
Hot dogs: $2
Hot links: $3
Soda: $2
Combo: 2 hot dogs + soda for $5
Available near the ride meetup
```

The OMI object contains:

```text
vendor identity
item identity
price state
location state
availability state
event relationship
receipt history
```

If the vendor changes the menu, the portal records the update as a new object state.

The consumer can inspect:

```text
current menu
previous menu
vendor source
event relationship
last update
receipt status
```

This makes local commerce portable. The vendor does not need to be trapped inside one delivery app, marketplace app, or social platform.

## Example: Personal Knowledge Portal

A user saves a source, note, and claim.

In a normal notes app, this becomes private content inside one database.

In an OMI portal, the note can become an addressed object chain:

```text
source object
  -> note object
    -> claim object
      -> evidence object
```

The same knowledge can be inspected as replay:

```text
source found
note written
claim extracted
evidence linked
summary revised
shared with group
```

And as containment:

```text
Project
  Topic
    Claim
      Evidence
        Source
```

Thinking has both a timeline and a structure. OMI preserves both.

## Reading Order

The [MANIFESTO.md](MANIFESTO.md) is the philosophical lens for all documentation. Read it first.

Then follow the progressive path below. New files deriving from the manifesto are marked with `†`.

## Repository Map

```text
.
├── MANIFESTO.md                 ← philosophical lens (read first)
├── README.md                    ← this file
├── 1_FOUNDATIONS
│   ├── 1.0_THE_THIRD_COLLAPSE.md     † notation as cipher, rewrite register
│   ├── 1.1_THE_PALINDROME.md
│   ├── 1.2_THE_OMICRON_ANCHORS.md
│   ├── 1.3_THE_OMI_RING.md
│   ├── 1.4_THE_OMI_UNIVERSAL_CONSTANT.md
│   └── 1.5_THE_SLASH_PATH.md         † declared interpretation route
├── 2_MATH
│   ├── 2.1_THE_QUADRATIC_LAW.md
│   ├── 2.2_THE_DELTA_LAW.md
│   ├── 2.3_SEXAGESIMAL_SYSTEM.md
│   ├── 2.4_POLYCUBES_AND_GROUPS.md
│   ├── 2.5_PROJECTIVE_CLOSURE_AND_THE_EMPTY_LIST.md  † 15-of-16, () as atom and list
│   ├── 2.6_UNICODE_AS_INCIDENCE_GEOMETRY.md          † codepoints as incidence cells
│   └── 2.7_OMI_NOMOGRAM.md                           † nomogram scale row
├── 3_ARCHITECTURE
│   ├── 3.1_DOM_HIERARCHY.md
│   ├── 3.2_WORMHOLE_PORTALS.md
│   ├── 3.3_META_CIRCULAR_COMPILER.md
│   └── 3.4_CONTROL_CODES_AND_PRINTABLE_PROJECTIONS.md  † ASCII rewrite surface
├── 4_NETWORK
│   ├── 4.1_IPv6_FRAME_MAPPING.md
│   ├── 4.2_RULES_OMI.md
│   └── 4.3_eBPF_KERNEL_GATE.md
├── 5_MEMORY
│   ├── 5.1_RING_INDEXER.md
│   └── 5.2_OVERWRITE_POLICY.md
├── 6_IMPLEMENTATION
│   ├── 6.1_NODEJS_COMPILER.md
│   ├── 6.2_C99_CORE.md
│   └── 6.3_TEST_SUITE.md
├── 7_CANON
│   ├── 7.1_AGREEMENT_DOCTRINE.md
│   ├── 7.2_OPEN_WORLD_PORTAL_MODEL.md
│   ├── 7.3_LOWER_OMICRON_UPPER_BIDI.md
│   └── 7.4_CONFORMANCE_CANON.md
├── 8_COSMOLOGY
│   ├── 8.1_THE_OMI_RING_DOMAIN.md
│   ├── 8.2_ATOMIC_DELTA_AND_COSMIC_ORBIT.md
│   ├── 8.3_LIGHT_SOUND_AND_FRAME_REFERENCE.md
│   ├── 8.4_OMI_GRAVITY_AND_CENTROID.md
│   ├── 8.5_PRINCIPAL_ADDRESS_DOMAIN.md
│   ├── 8.6_SNUB_TRUNCATION_AS_MODEL_OPERATION.md
│   ├── 8.7_GEOMETRIC_BRIDGE_PLATONIC_SNUB_4D.md
│   ├── 8.8_SNUB_CUBE_AND_SNUB_DODECAHEDRON.md
│   ├── 8.9_CHIRALITY_SELECTION_AND_SNUB_CARDINALITY.md
│   ├── 8.10_P2P_TRAVERSAL_AND_MIRROR_SPACE.md
│   ├── 8.11_SNUB_TRAVERSAL_MATH_FOR_EVERYONE.md
│   └── 8.12_STANDARD_TRUNCATION_VS_SNUB_OPERATION.md
├── public
│   ├── agreement-is-all-we-need.html
│   ├── index.html
│   └── omi-block-model.html
├── _archive
└── README.md
```

## Narrative Index

### [1. Foundations](1_FOUNDATIONS/)

The foundations introduce the palindrome, the Omicron anchors, the Omi-Ring, and the universal zero-point.

The story begins with `omi---imo`: a bounded relation between source-side intelligence and object-side projection. The omicron anchors `0x03BF` and `0x039F` frame every transmission. The OMI Universal Constant is the zero-point of bounded agreement, and the Omi-Ring is the waveform enclosure built on it.

Read this section first if you want to understand why OMI begins with a mnemonic relation instead of a conventional object ID.

- [1.0 The Third Collapse: Notation as Cipher](1_FOUNDATIONS/1.0_THE_THIRD_COLLAPSE.md) — philosophical foundation derived from the MANIFESTO
- [1.1 The Palindrome: omi---imo](1_FOUNDATIONS/1.1_THE_PALINDROME.md)
- [1.2 The Omicron Anchors: 0x03BF and 0x039F](1_FOUNDATIONS/1.2_THE_OMICRON_ANCHORS.md)
- [1.3 The Omi-Ring: Atomic Waveform Enclosure](1_FOUNDATIONS/1.3_THE_OMI_RING.md)
- [1.4 The OMI Universal Constant: Ω₀ = 0! = omi---imo](1_FOUNDATIONS/1.4_THE_OMI_UNIVERSAL_CONSTANT.md)
- [1.5 The Slash Path: Declared Interpretation Route](1_FOUNDATIONS/1.5_THE_SLASH_PATH.md) — the `omi-<frame>/<control>/<scale>/<relation>/<unit>-imo` form

### [2. Math](2_MATH/)

The math section defines the transition, validation, projection, and symmetry laws.

`Q_frame(S)` is the lower validation gate. `Q_xy(x,y) = 60x² + 16xy + 4y²` is the projection geometry. The Delta Law generates bounded period-8 orbits used by the Fano resolver and replay ring. The sexagesimal system supplies the orientation grammar.

Read this section if you want to understand why OMI treats agreement as a bounded computation instead of a social label.

- [2.1 The Quadratic Law](2_MATH/2.1_THE_QUADRATIC_LAW.md)
- [2.2 The Delta Law](2_MATH/2.2_THE_DELTA_LAW.md)
- [2.3 The Sexagesimal System](2_MATH/2.3_SEXAGESIMAL_SYSTEM.md)
- [2.4 Polycubes and Symmetry Groups](2_MATH/2.4_POLYCUBES_AND_GROUPS.md)
- [2.5 Projective Closure and the Empty List](2_MATH/2.5_PROJECTIVE_CLOSURE_AND_THE_EMPTY_LIST.md) — 15-of-16, 7-of-8, `()` as both atom and list
- [2.6 Unicode as Incidence Geometry](2_MATH/2.6_UNICODE_AS_INCIDENCE_GEOMETRY.md) — codepoints as points, blocks as surfaces, edges as lawful traversals
- [2.7 Omi-Nomogram and Omi-SlideRule](2_MATH/2.7_OMI_NOMOGRAM.md) — the canonical scale row (0x30–0x3F)

### [3. Architecture](3_ARCHITECTURE/)

The architecture section explains how accepted state becomes inspectable without confusing display with authority.

Accepted OMI state can project into:

```text
DOM hierarchy
ShadowDOM capsules
SVG surfaces
JSON Canvas nodes
portal cards
wormhole nodes
reader lenses
```

The important rule is that all of these surfaces are downstream of validation. They may carry state, inspect state, or render state, but they do not create authority.

Read this section if you want to understand how OMI becomes visible in the browser.

- [3.1 The DOM Hierarchy](3_ARCHITECTURE/3.1_DOM_HIERARCHY.md)
- [3.2 Wormhole Portals](3_ARCHITECTURE/3.2_WORMHOLE_PORTALS.md)
- [3.3 The Meta-Circular Chronograph Compiler](3_ARCHITECTURE/3.3_META_CIRCULAR_COMPILER.md)
- [3.4 Control Codes and Printable Projections](3_ARCHITECTURE/3.4_CONTROL_CODES_AND_PRINTABLE_PROJECTIONS.md) — ASCII 0x00–0x1F as rewrite operators, 0x20–0x7F as projection surface

### [4. Network](4_NETWORK/)

The network section explains the 128-bit frame mapping.

An IPv6 source address is 128 bits. An OMI canonical frame is also 128 bits. This width alignment allows OMI frame structure to be carried directly through IPv6-style segment layout.

The eBPF/XDP gate model places validation at the network edge:

```text
packet arrives
  ↓
XDP/eBPF reads IPv6 source frame
  ↓
Gate 1: Q_frame validation
  ↓
Gate 2: Delta/Fano truth-row resolution
  ↓
valid   -> XDP_PASS
invalid -> XDP_DROP
```

Read this section if you want to understand how OMI treats packet structure as an object boundary.

- [4.1 IPv6 Frame Mapping](4_NETWORK/4.1_IPv6_FRAME_MAPPING.md)
- [4.2 RULES.omi](4_NETWORK/4.2_RULES_OMI.md)
- [4.3 The eBPF/XDP Kernel Gate](4_NETWORK/4.3_eBPF_KERNEL_GATE.md)

### [5. Memory](5_MEMORY/)

The memory section explains how accepted truth rows persist.

OMI uses:

```text
7! = 5040
```

as the replay ring size. Accepted truth rows write receipts into the ring. Cursor movement follows Delta/Fano step distance, and overwrite policy preserves epoch safety.

Read this section if you want to understand how OMI turns agreement into replayable memory.

- [5.1 The Ring Indexer](5_MEMORY/5.1_RING_INDEXER.md)
- [5.2 Ring Overwrite Policy](5_MEMORY/5.2_OVERWRITE_POLICY.md)

### [6. Implementation](6_IMPLEMENTATION/)

The implementation section describes how the same conformance surface can be expressed across runtimes.

Targets include:

```text
JavaScript reference
C99 portable core
WASM executable substrate
eBPF/XDP kernel gate
```

The goal is byte-level agreement on validation outcomes, truth-row behavior, and canonical fixtures.

Read this section if you want to understand how the written doctrine becomes testable.

- [6.1 The Node.js Compiler](6_IMPLEMENTATION/6.1_NODEJS_COMPILER.md)
- [6.2 The C99 Core](6_IMPLEMENTATION/6.2_C99_CORE.md)
- [6.3 The Test Suite](6_IMPLEMENTATION/6.3_TEST_SUITE.md)

### [7. Canon](7_CANON/)

The canon section reconciles the major doctrine versions.

It contains the final statements on:

```text
agreement as construction
open-world portal behavior
lower Omicron versus upper Bidi
conformance and non-collapse rules
```

Read this section if you want the shortest authoritative version of the OMI doctrine after the different drafts were reconciled.

- [7.1 Agreement Doctrine](7_CANON/7.1_AGREEMENT_DOCTRINE.md)
- [7.2 Open-World Portal Model](7_CANON/7.2_OPEN_WORLD_PORTAL_MODEL.md)
- [7.3 Lower Omicron / Upper Bidi](7_CANON/7.3_LOWER_OMICRON_UPPER_BIDI.md)
- [7.4 Conformance Canon](7_CANON/7.4_CONFORMANCE_CANON.md)

### [8. Cosmology](8_COSMOLOGY/)

The cosmology section interprets OMI as a ringed domain of bounded return.

Here, `x` and `y` are not treated as flat coordinate lines. They are Omi-Rings: recurring address paths inside the `omi---imo` enclosure. The quadratic form becomes a cosmological grammar:

```text
4y²  = Atomic Delta / declaration ring
16xy = Omi-Ring bridge / address relation
60x² = Cosmic Orbit / orientation ring
```

This section also introduces Omi-Light and Omi-Sound as the two most ubiquitous reference spectrums: light for projection, sound for intention. A frame step compares what is projected with what is declared, then resolves declarations toward a definitional centroid.

Snub truncation is the interpretive model operation: cut the excess, twist the relation, re-face the boundary, record the receipt, and project only after acceptance.

The three-geometry mapping reads `4y²` as the Platonic vertex seed, `16xy` as the Archimedean-Catalan snub bridge, and `60x²` as the 4D regular polytope orbit.

- [8.1 The Omi-Ring Domain](8_COSMOLOGY/8.1_THE_OMI_RING_DOMAIN.md)
- [8.2 Atomic Delta and Cosmic Orbit](8_COSMOLOGY/8.2_ATOMIC_DELTA_AND_COSMIC_ORBIT.md)
- [8.3 Light, Sound, and Frame Reference](8_COSMOLOGY/8.3_LIGHT_SOUND_AND_FRAME_REFERENCE.md)
- [8.4 Omi-Gravity and the Centroid](8_COSMOLOGY/8.4_OMI_GRAVITY_AND_CENTROID.md)
- [8.5 Principal Address Domain](8_COSMOLOGY/8.5_PRINCIPAL_ADDRESS_DOMAIN.md)
- [8.6 Snub Truncation as Model Operation](8_COSMOLOGY/8.6_SNUB_TRUNCATION_AS_MODEL_OPERATION.md)
- [8.7 Geometric Bridge: Platonic Seed, Archimedean/Catalan Snub, and 4D Closure](8_COSMOLOGY/8.7_GEOMETRIC_BRIDGE_PLATONIC_SNUB_4D.md)
- [8.8 Snub Cube and Snub Dodecahedron: Cardinality of Chirality](8_COSMOLOGY/8.8_SNUB_CUBE_AND_SNUB_DODECAHEDRON.md)
- [8.9 Chirality Selection and Snub Cardinality](8_COSMOLOGY/8.9_CHIRALITY_SELECTION_AND_SNUB_CARDINALITY.md)
- [8.10 P2P Traversal and Mirror Space](8_COSMOLOGY/8.10_P2P_TRAVERSAL_AND_MIRROR_SPACE.md)
- [8.11 Snub Traversal: OMI Geometry for Everyone](8_COSMOLOGY/8.11_SNUB_TRAVERSAL_MATH_FOR_EVERYONE.md)
- [8.12 Standard Truncation vs. Snub Operation](8_COSMOLOGY/8.12_STANDARD_TRUNCATION_VS_SNUB_OPERATION.md)

## Public Pages

The `public/` folder contains static browser-facing pages:

- [public/index.html](public/index.html)
- [public/omi-block-model.html](public/omi-block-model.html)
- [public/agreement-is-all-we-need.html](public/agreement-is-all-we-need.html)

These pages are public projections of the docs.

No build step is required.

## Genesis Frame

The canonical genesis frame is the golden accept fixture.

```text
BOOT_ADDRESS = 0x7C00
BOOT_SLOT = 0x7C00 mod 5040 = 1504
GENESIS_LL = 0x01
GENESIS_NN = 0x7C00
C = (0x01 × 0x1337) & 0xFFFF = 0x1337
GENESIS_MM = Δ_{0x1337}(0x7C00) = 0x1434
GENESIS_STEPS = 1
```

Canonical frame:

```text
0100-03bf-7c00-2b01-2f01-1434-039f-01ff
```

This frame is the first conformance anchor:

```text
Q_frame(S) = 0
truth row resolves
steps = 1
slot = 1504
```

## Conformance

A conforming OMI implementation must:

1. Recognize `0x03BF` and `0x039F` as canonical lower frame anchors.
2. Validate frames via `Q_frame(S) = E_var + E_const = 0`.
3. Extract exactly one truth row `(LL, NN, MM)` from a valid frame.
4. Resolve `MM` from `NN` under the LL-modulated Delta Law within the bounded Fano window.
5. Write accepted rows as replayable receipts in the `5040 = 7!` slot ring.
6. Treat DOM, SVG, JSON Canvas, QR, portal UI, typography, color, and `unicode-bidi` as projection or reader lenses only.
7. Accept the canonical genesis frame.
8. Reject malformed, byte-swapped, delimiter-drifted, LL-incoherent, or projection-authorized frames.
9. Preserve the non-collapse rule:

```text
projection must never authorize validation
```

See [7.4 Conformance Canon](7_CANON/7.4_CONFORMANCE_CANON.md).

## Minimal Canonical Statement

```text
A frame is valid iff Q_frame(S) = 0.
A valid frame yields one truth row: (LL, NN, MM).
A truth row is accepted iff MM resolves from NN under the LL-modulated Delta Law within the bounded Fano window.
An accepted row advances the 5040-slot replay cursor and writes a receipt.
Only after validation, resolution, and receipt may the object be projected.
Projection is never authority.
```

## Short Doctrine

```text
Ο bounds.
ο executes.
-- carries the bridge.
0! seeds.
Q_frame validates.
Delta clocks.
Fano resolves.
5040 replays.
Q_xy projects.
Portals inspect.
Lower Omicron encodes.
Upper Bidi displays.
Characters stay fixed.
Agreement becomes structure.
```

## Consumer Promise

```text
One object.
Many portals.
Inspectable history.
Portable context.
Validation before projection.
Agreement without platform lock-in.
```

OMI is for a web where objects can move without losing their structure, where disagreement creates new paths instead of destroying shared context, and where ordinary users can inspect why something is trusted.

That is the purpose of this repository.
