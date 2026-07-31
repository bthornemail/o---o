# Comparative Analysis of the Earlier and Current OMINO Models

## Executive Summary

The earlier model and the current model describe the same underlying ambition from different stages of development.

The **earlier model** begins with geometry:

* four semantic elements arranged as tetrahedral vertices;
* six pairwise relationships represented as edges;
* CONS treated as a central hinge;
* a six-variable truth-table field with (2^6=64) relationship states;
* higher polytopes used as spatial lenses;
* 256-bit storage words divided into geometric regions;
* Delta used to track changes in relationships.

The **current model** retains that geometry but separates it into more precise layers:

* the tetrahedral incidence object (\langle4,6,4;1\rangle);
* the unconventional OMINO `[6,4,2]` operational gauge;
* FS, GS, RS, and US as the four persistent controls;
* a six-edge truth-table coordinate;
* OMICRON `[7,4,3]` and OMNICRON `[8,4,4]` as integrity extensions;
* exact low/high control planes and tangential rows;
* projection, clock, rotation, and resolution as separate coordinates;
* incidence-derived geometric quantities rather than stored floating-point constants;
* Emergent-Axial-Lisp as the lowering mechanism from symbolic constructions to executable coordinates.

The older model should therefore not be discarded. It should be **translated into the newer vocabulary**, with unsupported claims removed and unfinished mappings marked explicitly.

---

# 1. Developmental Lineage

## 1.1 Earliest logic-first construction

Before the Hamming terminology was introduced, OMINO was conceived as a truth-table logic counter.

Four semantic elements formed the tetrahedral vertices:

[
V=
{
\text{RULES},
\text{FACTS},
\text{CLOSURES},
\text{COMBINATORS}
}.
]

Every pair of vertices determines one edge:

[
\binom{4}{2}=6.
]

The six relations therefore define a six-variable Boolean state:

[
e\in{0,1}^{6}.
]

The complete relation-state field has:

[
2^6=64
]

possible edge configurations.

In this earliest model:

* the four vertices supplied semantic categories;
* the six truth-table bits supplied simultaneous relationships;
* Delta tracked changes in those relationships;
* CONS supplied the coordinate or ordered construction associated with the state.

This is the conceptual origin of the later OMINO `[6,4,2]` notation.

## 1.2 Geometry-first spatial model

The truth-table construction was then interpreted as a tetrahedral spatial object:

[
\mathcal T=(V_4,E_6,F_4,C_1).
]

It contains:

* four vertices;
* six edges;
* four triangular faces;
* one distinguished centroid.

The uploaded geometry development explicitly defines the tetrahedral incidence values (4,6,4,1) and verifies the standard incidence balances.

The intended semantic binding was:

| Tetrahedral component | OMI interpretation                      |
| --------------------- | --------------------------------------- |
| Four vertices         | RULES, FACTS, CLOSURES, COMBINATORS     |
| Six edges             | Direct pairwise transformation channels |
| Four faces            | Three-vertex closure contexts           |
| Centroid              | CONS ordered-pair hinge                 |

## 1.3 Hamming-era reinterpretation

The geometry was later expressed through code-like notation:

```text
OMINO     [6,4,2]
OMICRON   [7,4,3]
OMNICRON  [8,4,4]
```

The newer specification correctly distinguishes these:

* OMINO `[6,4,2]` is an **architectural incidence profile**, not a conventional named Hamming code.
* OMICRON `[7,4,3]` is the compact Hamming integrity form.
* OMNICRON `[8,4,4]` is the extended integrity form.

Therefore Hamming theory did not originate the six-coordinate OMINO. It supplied a later integrity framework for a preexisting tetrahedral truth-table construction.

---

# 2. Terminology Comparison

## 2.1 OMINO versus OMNION

### Earlier form

The older drafts often used:

```text
OMNION
OMNION centroid
one unified OMNION footprint
```

### Current form

The normalized name is:

```text
OMINO
```

OMINO is short for the generalized polyomino/polyomnio construction and refers to the composable Polyharmonic Omino Block.

### Resolution

`OMNION` should be treated as deprecated terminology unless it refers to a separately defined historical object.

Use:

```text
OMINO centroid
OMINO block
Polyharmonic Omino Block
```

---

## 2.2 Receipt terminology

### Earlier form

CLOSURES was described as:

```text
Receipt Boundary
Validated System Limits
```

### Current form

The newer architecture rejects receipt or external-authority semantics.

CLOSURES should mean:

```text
finite relation boundary
termination condition
internal closure surface
validated bounded limit
```

### Resolution

The structural role survives, but the word **receipt** should be removed.

---

## 2.3 Validation terminology

The older statement that Catalan solids “validate” Archimedean solids has geometric value but requires a narrower definition.

The current meaning should be:

> The Catalan dual supplies a reciprocal incidence projection of the corresponding Archimedean construction, allowing the primal and dual forms to be compared from a common centroid.

This is an internal geometric consistency relation, not external certification.

---

# 3. Tetrahedral File Architecture

## 3.1 Earlier claim

The older text described “the tetrahedral geometry of the 15 formal files” and presented five file types:

```text
RULES
FACTS
CLOSURES
COMBINATORS
CONS
```

across:

```text
.omi
.imo
.o
```

## 3.2 Current interpretation

The fifteen files are not fifteen vertices or fifteen tetrahedral components.

They are:

[
5\text{ semantic families}\times3\text{ representation surfaces}=15.
]

Each representation surface contains a tetrahedral semantic view:

```text
RULES.ext
FACTS.ext
CLOSURES.ext
COMBINATORS.ext
CONS.ext
```

where `ext` is `.omi`, `.imo`, or `.o`.

Thus there are three corresponding representations of one semantic tetrahedron:

```text
.omi
    declarative surface

.imo
    defined or intermediate surface

.o
    executable finite surface
```

## 3.3 Preserved insight

The important older insight survives:

> The file system is not a flat list. It is a family of corresponding semantic tetrahedra sharing the same four vertices and CONS center.

---

# 4. Four Vertices and Six Edges

## 4.1 Earlier edge masks

The older model supplied six four-bit masks:

```text
0x03
0x05
0x09
0x06
0x0A
0x0C
```

Every mask has Hamming weight two.

With the normalized bit assignment:

```text
bit 0 = RULES
bit 1 = FACTS
bit 2 = CLOSURES
bit 3 = COMBINATORS
```

the masks become:

|   Mask | Edge                 |
| -----: | -------------------- |
| `0x03` | RULES–FACTS          |
| `0x05` | RULES–CLOSURES       |
| `0x09` | RULES–COMBINATORS    |
| `0x06` | FACTS–CLOSURES       |
| `0x0A` | FACTS–COMBINATORS    |
| `0x0C` | CLOSURES–COMBINATORS |

This is an exact enumeration of the six edges of (K_4), the complete graph on four vertices.

## 4.2 Current six-bit relation state

The earlier masks select one edge from the four vertices.

The newer six-bit field represents the simultaneous state of all six edges:

```text
edge bit 0 = RULES–FACTS
edge bit 1 = RULES–CLOSURES
edge bit 2 = RULES–COMBINATORS
edge bit 3 = FACTS–CLOSURES
edge bit 4 = FACTS–COMBINATORS
edge bit 5 = CLOSURES–COMBINATORS
```

Therefore two different coordinate types must remain separate:

```text
4-bit weight-two mask
    identifies one vertex pair

6-bit edge-state word
    identifies an arbitrary subset of all six relationships
```

The latter has 64 possible values.

## 4.3 What changed

The old model sometimes treated the four-bit pair masks and the six-variable truth table as though they were the same surface.

The current model separates them:

[
\text{edge index}
\rightarrow
\text{vertex-pair mask}
]

and:

[
\text{six-bit state}
\rightarrow
\text{set of active edges}.
]

This is a major clarification.

---

# 5. OMINO `[6,4,2]`

## 5.1 Earlier interpretation

The older model implicitly used:

```text
6
    tetrahedral relation channels

4
    semantic vertex categories

2
    paired or reciprocal readings
```

but this was not consistently distinguished from coding-theory notation.

## 5.2 Current interpretation

The normalized profile is:

[
\operatorname{OMINO}_{642}=(E_6,C_4,D_2)
]

where:

```text
E₆
    six tetrahedral pairwise relationships

C₄
    four persistent controls:
    FS, GS, RS, US

D₂
    two reciprocal classes:
    relation/scope
    or face/vertex
```

OMINO `[6,4,2]` is therefore:

> A six-coordinate operational gauge derived from four-control tetrahedral incidence and two reciprocal interpretations.

It is not asserted to be a conventional error-correcting code with minimum distance two.

## 5.3 Relationship to FS, GS, RS, and US

A direct binding can be:

```text
RULES       ↔ FS
FACTS       ↔ GS
CLOSURES    ↔ RS
COMBINATORS ↔ US
```

or another explicitly frozen permutation.

The specific permutation remains a normative choice. What is fixed structurally is that four persistent controls generate six pairwise relations.

---

# 6. CONS Centroid

## 6.1 Earlier model

CONS was described as:

```text
absolute center
centroid hinge
compression center
```

## 6.2 Current model

CONS is not a fifth ordinary tetrahedral vertex.

It is a distinguished computational reference:

```text
ordered-pair constructor
CAR/CDR hinge
branch point
projective origin
coordinate binder
```

The correct relation is:

[
\operatorname{CONS}(\operatorname{CAR},\operatorname{CDR}).
]

CONS must preserve order because:

[
a\oplus b=b\oplus a
]

while generally:

[
\operatorname{CONS}(a,b)
\neq
\operatorname{CONS}(b,a).
]

## 6.3 What changed

The earlier model sometimes described CONS as compressing an interaction lattice directly into an `.o` file.

The current model requires CONS to preserve:

* CAR/CDR orientation;
* source coordinates;
* selected relation;
* projection profile;
* Delta state;
* integrity information.

It is therefore a constructor and coordinate hinge, not merely a compression operation.

---

# 7. Truth Table and Delta

## 7.1 Earlier purpose

The truth-table counter predated the Hamming layer.

Its purpose was to enumerate all states of the six tetrahedral relationships:

[
2^6=64.
]

Delta was intended to track which relationships changed.

The simplest relation-change operation is:

[
\delta_t=e_t\oplus e_{t-1}.
]

## 7.2 Current Delta kernel

The later formal kernel expands this into a deterministic width-bounded rotate/XOR transition:

[
\Delta_n(x)
===========

\operatorname{mask}_n
\left(
\operatorname{rotl}(x,1)
\oplus
\operatorname{rotl}(x,3)
\oplus
\operatorname{rotr}(x,2)
\oplus
C_n
\right).
]

The uploaded development proves deterministic replay for equal seeds and profiles.

## 7.3 Preserved relationship

The newer Delta does not replace the original truth-table purpose.

The layers are:

```text
six-edge truth-table state
    logical relationship configuration

basic XOR difference
    identifies changed relationships

bounded rotate/XOR Delta
    advances that relationship state through an oriented logical trajectory

replay
    regenerates the trajectory deterministically
```

---

# 8. Address-Space Comparison

## 8.1 Older 256-position geometric division

The older model divided the 256-position word into eight 32-position lenses:

```text
0x00–0x1F
0x20–0x3F
0x40–0x5F
0x60–0x7F
0x80–0x9F
0xA0–0xBF
0xC0–0xDF
0xE0–0xFF
```

Each lens was divided as:

[
32=24+8.
]

The first 24 positions were assigned to a Triakis body, and the final eight to a Stellated terminal.

The final eight were divided further:

[
8=4+4
]

into:

```text
first four
    Regular tetrahedron shared word

last four
    Tangent tetrahedron control word
```

## 8.2 Newer coding partitions

The newer nested gauge model reads the same 32-position lens through several terminal depths:

[
32=24+8
]

[
32=26+6
]

[
32=27+5
]

[
32=28+4.
]

Therefore the first lens contains:

```text
0x18–0x1F
    eight-position OMNICRON terminal

0x1A–0x1F
    six-position OMINO terminal

0x1B–0x1F
    five-position Tetragrammatron terminal

0x1C–0x1F
    four-position Metatron/control terminal
```

## 8.3 Reconciliation

These are two views of the same terminal.

### Geometric view

```text
0x18–0x1F
    Stellated terminal

0x18–0x1B
    Regular shared word

0x1C–0x1F
    Tangent control word
```

### Coding/gauge view

```text
0x18–0x1F
    OMNICRON 8

0x1A–0x1F
    OMINO 6

0x1B–0x1F
    Tetragrammatron 5

0x1C–0x1F
    Metatron/control 4
```

The two interpretations can coexist if the active view is explicitly identified.

---

# 9. Low and High Control Planes

## 9.1 Earlier model

The older model treated all eight 32-position lenses similarly and assigned geometric names within each lens.

## 9.2 Current model

The newer model gives special authority to two antipodal control planes:

```text
low affine control plane
    0x00–0x1F

high projective control plane
    0x80–0x9F
```

They are paired through:

[
x_{\text{high}}=x_{\text{low}}\oplus0x80.
]

The rows:

```text
0x20–0x7F
0xA0–0xFF
```

are then interpreted as tangential operational expansion rows.

## 9.3 What changed

The older model treated the 32-position segments primarily as repeating geometric compartments.

The newer model differentiates:

* control planes;
* projective mirrors;
* low and high tangential rows;
* axial origins;
* tangential completions.

This is a stronger executable addressing model.

---

# 10. STDIN, STDOUT, and STDERR

## 10.1 Earlier form

The earlier Lambda/Fano model proposed:

```text
Plane 1 = STDIN
Plane 2 = STDOUT
Block design = STDERR
```

It sometimes described the zero polynomial as meaning the system was “always operating over standard error.”

## 10.2 Current form

The current interpretation should be antipodal:

```text
STDIN
    incidence input plane

STDOUT
    antipodal transformed or update plane

STDERR
    centroid-relative difference field
```

A suitable abstract relation is:

[
\operatorname{STDERR}(i,o)
==========================

i\oplus A(o),
]

where (A) is the declared Azimuth transformation.

Then:

```text
STDERR = 0
    the antipodal relation closes

STDERR ≠ 0
    the difference field identifies non-closure
```

## 10.3 Meaning of `0x1D`

The formal Delta implementation repeats decimal `29`, or hexadecimal `0x1D`, across the selected width.

This gives two distinct statuses:

```text
implemented fact
    0x1D is the repeated Delta byte

architectural interpretation
    0x1D may serve as a standard-difference or STDERR-related carrier
```

The second interpretation must be explicitly frozen before it is normative.

---

# 11. Quadratic Form Comparison

## 11.1 Earlier claim

The older model stated:

[
Q(x,y)
======

4(4x^2+11x^2+4xy+y^2).
]

This simplifies to:

[
Q(x,y)
======

60x^2+16xy+4y^2.
]

The model associated the split:

[
15x^2=4x^2+11x^2
]

with branchless execution of the six tetrahedral edges.

## 11.2 Current interpretation

The algebraic identity is exact, but the direct edge mapping was never fully specified.

The newer model separates:

```text
six-bit truth table
    selects the active relationship state

four-bit vertex pair mask
    identifies participating vertices

CONS
    preserves ordered construction

quadratic form
    measures, projects, or indexes the construction
```

The form should therefore be treated as a **projection metric or Blackboard index**, not the mechanism that discovers the selected edge.

## 11.3 Remaining requirement

A complete specification still needs an explicit typed map:

[
\mu:
(E_6,V_4,P)
\rightarrow
Q_e(x,y),
]

where:

* (E_6) is the edge-state coordinate;
* (V_4) is the vertex-control coordinate;
* (P) is the plane, Azimuth, or projection profile;
* (Q_e) is the resulting indexed quadratic projection.

---

# 12. Polytope Hierarchy

## 12.1 Earlier hierarchy

The earlier model used:

```text
Tangent tetrahedron
    user graph

Regular tetrahedron
    local bigraph

Stellated tetrahedron
    remote multigraph

Triakis tetrahedron
    network hypergraph
```

It also assigned polytope families to tetrahedral vertices:

```text
Cube
Octahedron
Icosahedron
Dodecahedron
```

and higher-dimensional dual pairs:

```text
8-cell ↔ 16-cell
120-cell ↔ 600-cell
```

## 12.2 Current interpretation

These should be treated as **projection lenses**, not literal replacements for tetrahedral vertices.

The tetrahedron remains the self-dual index scaffold.

Two dual families are projected through it:

### Cubic/orthoplexic family

```text
Cube ↔ Octahedron
8-cell ↔ 16-cell
```

### Icosahedral/dodecahedral family

```text
Icosahedron ↔ Dodecahedron
120-cell ↔ 600-cell
```

## 12.3 Antipodal placement

Dual pairs should be placed antipodally across the centroid:

```text
Cube ↔ Octahedron
Icosahedron ↔ Dodecahedron
```

rather than adjacent merely because they appear consecutively in a list.

## 12.4 Archimedean and Catalan forms

The intended relation is:

```text
Archimedean construction
    primal, often chiral or vertex-oriented view

Catalan dual
    reciprocal face-oriented view

centroid
    common inspection reference

Azimuth
    orientation comparison

difference field
    transformation gauge
```

Snubbed truncation introduces chirality, while the dual construction exposes the corresponding reciprocal structure.

---

# 13. Factorial and Clock Interpretation

## 13.1 Earlier geometric associations

The older model associated:

```text
4! = 24
    24-cell/local permutation lens

5! = 120
    5-cell or higher projection lens
```

## 13.2 Current model

The timing architecture now separates:

```text
24
    permutations of FS, GS, RS, US

720
    anchored six-position operational permutations

4,320
    Algorithmic Clock coordinate

5,040
    complete seven-position rotation coordinate
```

The factorial counts should therefore be described as permutation-address resolutions, not as identities equating factorials with polytopes.

A safe statement is:

> The 24-cell and 5-cell projection lenses are indexed using permutation resolutions related to (4!) and (5!); they are not conventionally identical to those factorial numbers.

---

# 14. Geometric Constants and Projection

## 14.1 Earlier implicit approach

The older geometry-first material sought to derive geometric relationships from polytope incidence rather than relying on stored decimal constants.

## 14.2 Current proved direction

The current proof architecture makes the boundary explicit:

```text
finite incidence
    exact

algebraic or series derivation
    reconstructive

metric projection
    resolution-dependent

raster output
    disposable
```

The tetrahedral incidence supplies the finite route associated with (\sqrt3). The ({3,5}/{5,3}) incidence route supplies the defining equation for (\phi). The Polybius and diagonal incidence schedules supply the reconstruction route for (\pi).

The (\pi) development also supplies an explicit finite approximation bound.

## 14.3 What changed

The old model described polytope lenses geometrically.

The new model gives them a possible cross-platform role:

> Serialize incidence, derivation law, root or phase selector, resolution, and arithmetic profile—not platform-specific floating-point constants or meshes.

---

# 15. Blackboard Pattern

## 15.1 Earlier understanding

The Blackboard was understood geometrically as:

* a central field;
* four semantic contributors;
* six pairwise channels;
* higher-resolution shape projections;
* a spatial logic index.

## 15.2 Current interpretation

The Blackboard is now better understood as a tangential block field:

```text
vertices or blocks
    retain origin identity

edges
    express relations

centroid
    supplies the shared projective reference

projection lenses
    expose different spatial resolutions

Delta
    traverses relationship states

CONS
    preserves ordered construction
```

The user’s geometry-first interpretation preceded the conventional software-pattern vocabulary, but it corresponds closely to a shared relational workspace.

---

# 16. Emergent-Axial-Lisp

## 16.1 Why it interrupted the geometry work

The geometric model could not become executable until the language layer answered:

* how atoms are represented;
* how CAR and CDR retain order;
* how CONS selects or constructs an edge;
* how a symbolic form becomes a bounded coordinate;
* how evaluation avoids hidden mutable state;
* how `.omi`, `.imo`, and `.o` correspond;
* how axial and tangential positions are selected.

## 16.2 Current lowering sequence

A normalized lowering pipeline is:

```text
source
    (CONS CAR CDR)

semantic binding
    identify block or vertex roles

pair selection
    obtain one weight-two four-bit mask

relation-state update
    update the six-bit edge field

typed transformation
    XOR, shift, rotate, or Azimuth profile

closure
    evaluate the relevant face/difference relation

projection
    assign clock, rotation, and resolution coordinates

machine output
    emit immutable .o representation
```

The Lisp work was therefore not unrelated. It was required to make the tetrahedral spatial model functional.

---

# 17. Claims That Should Be Deprecated

The following older claims should not appear unchanged in the final specification:

## “Completely closed, frozen, and mathematically locked”

Replace with a status table distinguishing:

```text
PROVED
EXHAUSTIVELY CHECKED
DEFINED
IMPLEMENTED
INTERPRETED
OPEN
```

## “Single-cycle”

Replace with:

> Constant bounded lookup with no data-dependent iteration.

Actual cycle count is platform-dependent.

## “Physical execution channels”

Replace with:

> Finite logical or structural relation channels.

## “No sequential loops”

Retain only as a profile restriction where explicitly required. Some proof, tooling, parsing, serialization, or rendering operations may legitimately iterate even when the atomic kernel is branchless.

## “O(1) trajectory resolution”

Specify the exact operation whose cost is bounded. Do not apply the claim to an entire scene, proof, or projection pipeline.

## “Receipt boundary”

Replace with finite closure or internal relation boundary.

## “The quadratic form executes the six edges”

Replace with:

> The edge truth table selects relationships; the quadratic form projects or indexes the selected construction.

---

# 18. Comparative Status Matrix

| Earlier component                       | Current status            | Action                                           |
| --------------------------------------- | ------------------------- | ------------------------------------------------ |
| Four semantic vertices                  | Retained                  | Freeze exact FS/GS/RS/US binding                 |
| Six structural edges                    | Retained and clarified    | Freeze edge order and masks                      |
| (2^6=64) truth table                    | Restored as foundational  | Define canonical truth-table order               |
| CONS center                             | Retained                  | Define as ordered computational centroid         |
| `[6,4,2]`                               | Retained but reclassified | Call architectural incidence profile             |
| `[7,4,3]`                               | Retained                  | Use as compact integrity profile                 |
| `[8,4,4]`                               | Retained                  | Use as extended integrity profile                |
| 15 formal files                         | Retained structurally     | Model as 5 families × 3 surfaces                 |
| 24+8 lens                               | Retained                  | Treat as geometric terminal view                 |
| 26+6 lens                               | Retained                  | Treat as OMINO operational view                  |
| 27+5 lens                               | Retained                  | Treat as Tetragrammatron view                    |
| 28+4 lens                               | Retained                  | Treat as four-control/Metatron view              |
| Triakis/Stellated/Regular/Tangent names | Partially retained        | Define as named projection profiles              |
| Polytope vertex lists                   | Interpretive              | Convert into typed antipodal dual lenses         |
| Archimedean/Catalan validation          | Needs normalization       | Define reciprocal incidence comparison           |
| 4/11 quadratic split                    | Algebraically retained    | Define exact projection map                      |
| STDIN/STDOUT/STDERR planes              | Retained with correction  | Make STDIN/STDOUT antipodal                      |
| `0x1D` standard-error role              | Partially supported       | Separate implementation fact from interpretation |
| Branchless CASE pseudocode              | Deprecated                | Replace with lookup or mask selection            |
| Single-cycle claim                      | Deprecated                | State bounded complexity only                    |
| Receipt language                        | Deprecated                | Use closure coordinates                          |
| OMNION name                             | Deprecated                | Normalize to OMINO                               |
| Stored geometric constants              | Deprecated direction      | Derive from incidence and resolution profiles    |
| Emergent-Axial-Lisp                     | Retained as necessary     | Complete formal lowering rules                   |

---

# 19. Recommended Canonical Layering

The final specification should be organized into six layers.

## Layer 1 — Tetrahedral semantic incidence

```text
RULES
FACTS
CLOSURES
COMBINATORS
CONS centroid
```

## Layer 2 — Tetrahedral logic field

```text
four-bit vertex masks
six edge indices
six-bit relationship states
64-row truth-table coordinate
```

## Layer 3 — Nested gauge integrity

```text
OMINO [6,4,2]
OMICRON [7,4,3]
OMNICRON [8,4,4]
```

## Layer 4 — Addressing and projection lenses

```text
32-position lenses
low/high control planes
axial origins
tangential completions
Metatron
Tetragrammatron
Polybius
Azimuth
```

## Layer 5 — Temporal and rotational execution

```text
Delta
Algorithmic Clock
rotation coordinate
deterministic replay
```

## Layer 6 — Polyharmonic visual construction

```text
incidence-derived geometry
dynamic resolution
polytope dual lenses
2D and 3D block composition
cross-platform reconstruction profile
```

---

# Conclusion

The old and new versions are not fundamentally competing designs.

The older version contains the **geometric generative model**:

[
4\text{ vertices}
\rightarrow
6\text{ relations}
\rightarrow
64\text{ truth states}
\rightarrow
\text{CONS-centered spatial construction}.
]

The newer version contains the **normalization and execution discipline**:

[
\text{OMINO}*{642}
\rightarrow
\text{OMICRON}*{743}
\rightarrow
\text{OMNICRON}_{844}
\rightarrow
\text{bounded addressing}
\rightarrow
\text{deterministic projection and replay}.
]

The correct integration is therefore:

> The tetrahedral truth-table field is the logical foundation. OMINO `[6,4,2]` is its reduced operational gauge. OMICRON and OMNICRON add compact and extended integrity. CONS preserves ordered construction at the centroid. The quadratic form, polytope duals, Polybius index, Azimuth, clock, and rotation coordinates project the same finite incidence into progressively higher-resolution Blackboard views. Emergent-Axial-Lisp provides the missing executable lowering from symbolic relations into those finite spatial coordinates.

The remaining work is not to invent another architecture. It is to freeze the exact mappings between layers while preserving which claims are proved, implemented, defined, interpreted, or still open.
