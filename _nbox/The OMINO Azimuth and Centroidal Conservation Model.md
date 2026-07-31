# The OMINO Azimuth and Centroidal Conservation Model

## A First-Principles Specification of the Tetrahedral Logic Field

## Abstract

The OMINO model begins with a simple geometric observation: four semantic positions form a tetrahedron, and a tetrahedron contains exactly six pairwise relations, four triangular faces, and one distinguished center.

This gives the finite incidence object:

[
\langle 4,6,4;1\rangle
]

meaning:

* four vertices;
* six edges;
* four faces;
* one centroid.

The four vertices are assigned to the semantic roles:

```text
0x1C = RULES
0x1D = FACTS
0x1E = CLOSURES
0x1F = COMBINATORS
```

The six tetrahedral edges form a six-bit logical field. Because six binary variables admit (2^6=64) configurations, the complete local relationship state of the tetrahedron can be represented by a 64-row truth table.

The OMINO Azimuth projects this four-position tetrahedral state into three balanced XOR coordinates. Those three coordinates form a three-bit directional address. Its seven nonzero values correspond naturally to the seven points of the Fano plane, while `000` represents the balanced centroid or closure position.

A fourth orientation bit distinguishes a direction from its antipodal reflection. This expands the local Azimuth from eight values to sixteen hexadecimal positions.

Logical conservation is then expressed through exact bit accounting. Rotations and permutations preserve the number of active bits. XOR exposes differences and cancellations. Tetrahedral incidence parity guarantees that every active edge contributes to two endpoints, so the total endpoint parity always closes.

This produces a deterministic logical geometry in which relationships may move, rotate, cancel, or project without silently disappearing.

---

# 1. Geometry Before Encoding

The OMINO model did not begin with Hamming codes, the Blackboard pattern, or conventional error correction.

It began with the tetrahedron.

A tetrahedron is the smallest closed three-dimensional simplex. It is constructed from four vertices:

[
V={v_0,v_1,v_2,v_3}.
]

Every vertex is connected to every other vertex, giving:

[
\binom{4}{2}=6
]

edges.

Every choice of three vertices forms one triangular face, giving:

[
\binom{4}{3}=4
]

faces.

The complete tetrahedral incidence structure is therefore:

[
(V_4,E_6,F_4,C_1).
]

The centroid (C_1) is not a fifth peer vertex. It is the distinguished point from which the entire tetrahedral relation is inspected.

This structure is already sufficient to define a local semantic logic field.

---

# 2. The Four Semantic Vertices

The original semantic tetrahedron assigns the four terminal codepoints:

```text
0x1C = RULES
0x1D = FACTS
0x1E = CLOSURES
0x1F = COMBINATORS
```

These roles have distinct functions.

## 2.1 RULES — `0x1C`

RULES contain declared laws, constraints, or conditions governing what transformations are permitted.

## 2.2 FACTS — `0x1D`

FACTS contain grounded values, observations, symbols, or byte-level inputs.

## 2.3 CLOSURES — `0x1E`

CLOSURES determine whether a finite relation terminates, balances, or satisfies its declared boundary condition.

## 2.4 COMBINATORS — `0x1F`

COMBINATORS determine how values are ordered, rotated, shifted, paired, or recursively composed.

Together, these form the four persistent semantic controls:

[
(R,F,C,K).
]

The letters will be used as follows:

```text
R = RULES
F = FACTS
C = CLOSURES
K = COMBINATORS
```

---

# 3. The Six Tetrahedral Relations

Four vertices generate exactly six pairwise relations:

[
E=
{
RF,\ RC,\ RK,\ FC,\ FK,\ CK
}.
]

Written explicitly:

```text
RULES ↔ FACTS
RULES ↔ CLOSURES
RULES ↔ COMBINATORS
FACTS ↔ CLOSURES
FACTS ↔ COMBINATORS
CLOSURES ↔ COMBINATORS
```

These are the six structural edges of the semantic tetrahedron.

They may be indexed as:

```text
e0 = RULES ↔ FACTS
e1 = RULES ↔ CLOSURES
e2 = RULES ↔ COMBINATORS
e3 = FACTS ↔ CLOSURES
e4 = FACTS ↔ COMBINATORS
e5 = CLOSURES ↔ COMBINATORS
```

A complete edge state is therefore a six-bit word:

[
e=(e_0,e_1,e_2,e_3,e_4,e_5)\in\mathbb F_2^6.
]

Each bit records whether one relationship is active.

For example:

```text
000000
    no active pairwise relations

000001
    one active relation

001011
    three active relations

111111
    all six tetrahedral relations active
```

Because six bits admit:

[
2^6=64
]

configurations, the complete local tetrahedral relationship field is a 64-state truth table.

This is the foundational reason for the OMINO six-variable truth-table counter.

---

# 4. The Four-Bit Vertex Selector

The four semantic vertices also admit a direct four-bit representation:

```text
RULES       = 0001 = 0x1
FACTS       = 0010 = 0x2
CLOSURES    = 0100 = 0x4
COMBINATORS = 1000 = 0x8
```

A single tetrahedral edge is selected by activating exactly two of the four vertex bits.

The six weight-two masks are:

```text
0x3 = 0011 = RULES + FACTS
0x5 = 0101 = RULES + CLOSURES
0x9 = 1001 = RULES + COMBINATORS
0x6 = 0110 = FACTS + CLOSURES
0xA = 1010 = FACTS + COMBINATORS
0xC = 1100 = CLOSURES + COMBINATORS
```

This produces an exact distinction:

```text
four-bit vertex mask
    identifies one selected pair of vertices

six-bit edge word
    records the full simultaneous tetrahedral relation state
```

The four-bit and six-bit views are related, but they are not the same data type.

---

# 5. The CONS Centroid

The centroid is the distinguished construction point of the tetrahedron.

In the OMINO model, the centroid is represented functionally through:

[
\operatorname{CONS}(\operatorname{CAR},\operatorname{CDR}).
]

CONS preserves an ordered relationship.

This is important because XOR alone is commutative:

[
a\oplus b=b\oplus a.
]

But an ordered pair is not generally commutative:

[
\operatorname{CONS}(a,b)
\neq
\operatorname{CONS}(b,a).
]

Therefore the model separates:

```text
logical relation
    XOR, rotation, shift, parity, or difference

structural relation
    ordered CAR/CDR construction
```

The centroid is not merely where bits are combined. It is where a selected relation acquires ordered meaning.

A normalized centroidal form is:

[
\mathcal C(e)
=============

\operatorname{CONS}
\left(
\operatorname{CAR}(e),
\operatorname{CDR}(e)
\right).
]

The OMINO coordinate identifies the local logical relation around this centroid.

---

# 6. Tetrahedral Incidence Parity

Each tetrahedral edge touches exactly two vertices.

This gives four vertex-incidence parity checks.

Using the edge ordering:

[
e=
(e_{RF},e_{RC},e_{RK},e_{FC},e_{FK},e_{CK}),
]

define:

[
p_R
===

e_{RF}\oplus e_{RC}\oplus e_{RK},
]

[
p_F
===

e_{RF}\oplus e_{FC}\oplus e_{FK},
]

[
p_C
===

e_{RC}\oplus e_{FC}\oplus e_{CK},
]

[
p_K
===

e_{RK}\oplus e_{FK}\oplus e_{CK}.
]

In matrix form:

[
\begin{bmatrix}
p_R\
p_F\
p_C\
p_K
\end{bmatrix}
=============

\begin{bmatrix}
1&1&1&0&0&0\
1&0&0&1&1&0\
0&1&0&1&0&1\
0&0&1&0&1&1
\end{bmatrix}
\begin{bmatrix}
e_{RF}\
e_{RC}\
e_{RK}\
e_{FC}\
e_{FK}\
e_{CK}
\end{bmatrix}
\pmod 2.
]

This is the vertex-edge incidence matrix of the tetrahedron over (\mathbb F_2).

The four parity values always satisfy:

[
p_R\oplus p_F\oplus p_C\oplus p_K=0.
]

The reason is exact: every edge contributes to two vertices, so every edge bit appears twice in the total XOR and cancels.

This is the first centroidal conservation law.

> Every active tetrahedral relation has two endpoints; the complete incidence field contains no unpaired endpoint.

Only three of the four parity checks are independent.

Thus the tetrahedron naturally generates:

```text
six edge variables
four vertex-incidence checks
three independent parity coordinates
```

This is why the later three-coordinate Fano and Hamming interpretations fit the original geometry.

---

# 7. The Three Balanced XOR Projections

The OMINO Azimuth begins with three XOR functions over the four semantic controls.

Let:

```text
R = activity at RULES
F = activity at FACTS
C = activity at CLOSURES
K = activity at COMBINATORS
```

Define:

[
X_0=R\oplus F\oplus K,
]

[
X_1=R\oplus C\oplus K,
]

[
X_2=F\oplus C\oplus K.
]

These three values form the Azimuth address:

[
A=(X_0,X_1,X_2).
]

This is a projective reduction:

[
\mathbb F_2^4
\longrightarrow
\mathbb F_2^3.
]

The three XOR values are not three additional semantic objects. They are three balanced readings of the same four-position tetrahedral state.

The fourth possible three-term face relation is dependent on the other three through the complete tetrahedral parity law.

---

# 8. The Fano Direction Plane

A three-bit word has eight values:

```text
000
001
010
011
100
101
110
111
```

The seven nonzero values are precisely the seven nonzero vectors of:

[
\mathbb F_2^3.
]

These can address the seven points of the Fano plane:

```text
001 = direction 1
010 = direction 2
011 = direction 3
100 = direction 4
101 = direction 5
110 = direction 6
111 = direction 7
```

The zero value is reserved:

```text
000 = balanced centroid or closure position
```

Thus the Azimuth is not identical to the Fano plane or to the tetrahedron.

It is the orientation map connecting them:

> The tetrahedron supplies four semantic controls. Three balanced XOR functions project those controls into a three-bit address. The seven nonzero addresses select Fano directions, while zero represents centroidal closure.

---

# 9. The Hexadecimal Azimuth Nibble

The local three-bit Fano address fits inside the low half of one hexadecimal nibble:

```text
0x0 = 000 = centroid
0x1 = 001
0x2 = 010
0x3 = 011
0x4 = 100
0x5 = 101
0x6 = 110
0x7 = 111
```

A fourth bit may distinguish a direction from its antipodal reflection:

```text
0x8 = antipodal centroid
0x9 = antipode of 0x1
0xA = antipode of 0x2
0xB = antipode of 0x3
0xC = antipode of 0x4
0xD = antipode of 0x5
0xE = antipode of 0x6
0xF = antipode of 0x7
```

The antipodal map is:

[
A^\ast=A\oplus0x8.
]

Examples:

```text
0x1 XOR 0x8 = 0x9
0x2 XOR 0x8 = 0xA
0x7 XOR 0x8 = 0xF
```

This gives a complete 16-position local orientation field:

[
8+8=16.
]

The low half represents one orientation.

The high half represents its antipodal orientation.

---

# 10. The Wide Azimuth Pattern `0xAA55`

The wider Gnomonic Azimuth profile is represented by:

```text
0xAA55
```

In binary:

```text
0xA = 1010
0x5 = 0101
```

Therefore:

```text
0xAA55
=
1010 1010 0101 0101
```

Its two halves are complementary:

[
0xAAAA\oplus0x5555=0xFFFF.
]

This may be read as a repeated orientation gauge:

```text
local three-bit address
    selects a Fano direction

high orientation bit
    selects its antipode

0xAA55
    distributes antipodal orientation across a wider word
```

The local nibble identifies direction.

The wide pattern determines how the direction is projected across a larger storage or construction word.

---

# 11. The OMINO `[6,4,2]` Interpretation

The OMINO notation:

[
[6,4,2]
]

is unconventional.

It should not automatically be read as a conventional linear code with parameters ([n,k,d]).

Its architectural interpretation is:

```text
6
    six tetrahedral edge relations

4
    four persistent semantic controls

2
    two reciprocal orientation classes
```

The two classes may be read as:

```text
scope and relation

vertex and face

local and antipodal

input and output
```

depending on the declared profile.

The geometric source remains:

[
\langle4,6,4;1\rangle.
]

The six relation coordinates arise from the four vertices:

[
\binom42=6.
]

The tetrahedron is self-dual, so its four vertices correspond reciprocally to four opposite faces.

This gives the OMINO block both an inward and outward reading without changing its finite incidence identity.

---

# 12. The `0x20` Lens

The original four semantic vertices occupy:

```text
0x1C
0x1D
0x1E
0x1F
```

They terminate immediately before:

```text
0x20
```

A `0x20` interval contains 32 positions.

The four-control terminal may be expressed as:

[
32=28+4.
]

Thus:

```text
0x00..0x1B
    preceding lens body

0x1C..0x1F
    four semantic tetrahedral controls
```

The six-position OMINO terminal may be expressed as:

[
32=26+6.
]

Thus:

```text
0x00..0x19
    preceding lens body

0x1A..0x1F
    six-position OMINO relation terminal
```

The four semantic vertices are nested inside the six-position terminal:

```text
0x1A..0x1B
    two class or relation-extension coordinates

0x1C..0x1F
    RULES, FACTS, CLOSURES, COMBINATORS
```

This explains the staggered `0x20` spacing.

The lens creates a finite local field in which four semantic controls and six relational positions coexist.

---

# 13. Logical Conservation

Physical energy is not literally stored in a logical bit.

However, the conservation idea can be translated into exact logical invariants.

Define the logical activity of a word as its Hamming weight:

[
E(x)=\operatorname{popcount}(x).
]

For a six-bit OMINO edge state:

[
e\in\mathbb F_2^6,
]

the activity lies in the range:

[
0\leq E(e)\leq6.
]

This measures the number of active tetrahedral relations.

Examples:

```text
000000 → activity 0
000001 → activity 1
001011 → activity 3
111111 → activity 6
```

A transformation conserves logical activity when:

[
E(T(x))=E(x).
]

Bit rotations and permutations conserve Hamming weight.

XOR does not necessarily conserve Hamming weight because it exposes cancellation and difference.

For example:

[
0011\oplus0011=0000.
]

The matching patterns cancel.

Therefore the system should not require output Hamming weight alone to remain constant. Instead, it should account explicitly for:

```text
preserved activity
moved activity
cancelled activity
unresolved difference
```

A general accounting law may be defined as:

[
E_{\mathrm{input}}
==================

E_{\mathrm{preserved}}
+
E_{\mathrm{cancelled}}
+
E_{\mathrm{difference}},
]

provided each term is precisely defined for the active profile.

---

# 14. Conservation at the Tetrahedral Centroid

The stronger invariant is not merely Hamming weight. It is endpoint incidence.

Each edge has two endpoints.

Therefore, over ordinary integer counting:

[
\sum_{v\in V}\deg(v)
====================

2|E_{\mathrm{active}}|.
]

Over (\mathbb F_2), the total vertex parity always cancels:

[
p_R\oplus p_F\oplus p_C\oplus p_K=0.
]

This provides three levels of logical conservation.

## 14.1 Bit conservation

Track whether each relationship remained active, became active, or became inactive.

## 14.2 Weight conservation

Track whether the total number of active relationships was preserved under a rotation or permutation.

## 14.3 Incidence conservation

Track whether every relationship remains properly paired across its two endpoints.

The centroidal balance is exact even when individual edge positions change.

---

# 15. The Delta Law

Let:

[
e_t\in\mathbb F_2^6
]

be the tetrahedral relationship state at logical time (t).

Define the direct relational Delta:

[
\delta_t=e_t\oplus e_{t-1}.
]

For each edge bit:

```text
0
    the relationship was preserved

1
    the relationship changed
```

The incidence effect of the change is:

[
\partial\delta_t
================

\partial e_t\oplus\partial e_{t-1}.
]

Thus Delta operates in two spaces:

```text
six-edge space
    identifies which relations changed

four-vertex space
    identifies which semantic controls experienced incidence change
```

A wider Delta profile may additionally rotate, shift, or project the relation word before applying XOR.

The formal kernel supplied with the model uses width-bounded masks, left and right rotations, XOR, and a repeated `0x1D` byte constant. It also proves deterministic replay for equal widths, seeds, and step counts.

Therefore Delta can be treated as a deterministic logical traversal, not a wall-clock process.

---

# 16. The Significance of `0x1D`

The codepoint:

```text
0x1D = FACTS
```

also appears in the formal Delta kernel as decimal `29`, repeated across the active word width.

This gives two distinct statements.

## 16.1 Implemented fact

The current kernel constructs its width-dependent XOR constant by repeating byte:

```text
0x1D
```

across the word.

## 16.2 Architectural interpretation

Because `0x1D` is the FACTS coordinate, it may be interpreted as the grounded reference against which a rotated logical state is compared.

This interpretation should be treated as defined architecture only after it is explicitly frozen in the specification.

The distinction is important:

```text
implemented
    the kernel repeats 0x1D

interpreted
    0x1D functions as the grounded FACTS or standard-difference gauge
```

---

# 17. STDIN, STDOUT, and STDERR

STDIN and STDOUT should be treated as antipodal incidence planes rather than adjacent stages.

```text
STDIN
    incoming tetrahedral relation state

STDOUT
    antipodally projected or updated state

STDERR
    centroid-relative difference field
```

Let (A) be the declared Azimuth transformation.

Then define:

[
\operatorname{STDERR}(i,o)
==========================

i\oplus A^{-1}(o).
]

This gives:

```text
STDERR = 0
    output reconstructs input under the declared Azimuth

STDERR ≠ 0
    remaining bits identify the unresolved difference
```

STDERR is therefore not merely a failure channel.

It is an explicit difference surface.

The zero polynomial or zero word represents closure of the difference field.

It does not mean that nothing happened.

It means that the input and output relation balance under the declared transformation.

---

# 18. A Complete Local Example

Suppose the four semantic activities are:

```text
RULES       R = 1
FACTS       F = 0
CLOSURES    C = 1
COMBINATORS K = 1
```

The four-bit vertex state is:

```text
1101
```

The three XOR projections are:

[
X_0=R\oplus F\oplus K
=1\oplus0\oplus1
=0,
]

[
X_1=R\oplus C\oplus K
=1\oplus1\oplus1
=1,
]

[
X_2=F\oplus C\oplus K
=0\oplus1\oplus1
=0.
]

Therefore:

[
A=010_2=0x2.
]

The antipodal Azimuth is:

[
A^\ast=0x2\oplus0x8=0xA.
]

Thus:

```text
0x2
    local Fano direction

0xA
    antipodal reflection of that direction
```

If the six-edge relationship word is rotated from one orientation to another while preserving its Hamming weight and endpoint incidence, its logical activity is conserved even though its spatial orientation has changed.

---

# 19. The Fano Plane as an Integrity and Orientation Surface

The Fano plane contains seven points and seven lines.

Its points may be labeled by the seven nonzero vectors of:

[
\mathbb F_2^3.
]

Every line consists of three points whose vector XOR is zero:

[
a\oplus b\oplus c=0.
]

This makes the Fano plane useful for two distinct purposes.

## 19.1 Orientation

The three-bit Azimuth selects one of seven nonzero directions.

## 19.2 Integrity

Three-point Fano lines define zero-XOR closure relations.

The tetrahedron remains the semantic object.

The Fano plane is a projective reading of its balanced three-coordinate reduction.

This distinction preserves the historical order of the model:

```text
tetrahedral semantic geometry
    came first

three-coordinate parity
    emerged from its incidence

Fano geometry
    supplied a canonical projective interpretation

Hamming profiles
    later supplied conventional integrity terminology
```

---

# 20. The Polyharmonic Omino Block

A Polyharmonic Omino Block is a composable logical object whose multiple coordinate systems remain distinct but synchronized.

Its minimal state may be represented as:

[
\mathcal O=
(
V,E,P,A,\Delta,C
),
]

where:

```text
V
    four semantic vertex controls

E
    six-bit tetrahedral relationship word

P
    four vertex-incidence parity values

A
    three-bit Fano direction plus antipodal bit

Δ
    deterministic relationship transition

C
    ordered CONS centroid
```

A more complete runtime block may also contain:

```text
projection profile
clock coordinate
rotation coordinate
resolution profile
scope
origin
connection faces
```

The block is not defined by one rendered mesh or one floating-point representation.

It is defined by exact finite incidence and deterministic reconstruction rules.

---

# 21. Scene Construction as Visual Logic

Multiple OMINO blocks may be connected through declared tetrahedral relations.

A scene can therefore be represented as a graph of exact logical constructions:

```text
select block
select semantic face or edge
select Azimuth
apply Delta orientation
bind through CONS
check closure
project at requested resolution
```

A two-dimensional scene may be generated from connected planar faces.

A three-dimensional scene may be generated from face-closing tetrahedral complexes.

The scene is stored as:

```text
exact incidence
ordered relationships
orientation
resolution instructions
```

rather than as an authoritative list of platform-dependent floating-point vertices.

Metric constants may be regenerated from exact incidence at the projection boundary. The supplied geometry formalization explicitly separates finite exact incidence from real-valued metric projection.

The supplied (\pi) projection development also provides a convergent incidence route and an explicit finite approximation bound.

Thus resolution can expand dynamically without changing the identity of the logical construction.

---

# 22. Formal Status

The model should distinguish different levels of certainty.

## Defined

* four semantic codepoints `0x1C..0x1F`;
* six tetrahedral pair relations;
* 64-state six-bit truth field;
* functional CONS centroid;
* three balanced XOR projections;
* seven Fano directions plus zero centroid;
* antipodal high-bit orientation;
* tetrahedral incidence parity;
* relational Delta;
* `0x20` lens nesting.

## Implemented

* width-bounded rotate/XOR Delta kernel;
* repeated `0x1D` constant;
* deterministic replay definitions;
* several finite incidence constructions.

## Proved

* Delta determinism for equal inputs;
* replay determinism;
* replay length;
* finite tetrahedral incidence equalities;
* several Fano incidence properties;
* incidence-derived projection convergence results.

## Interpreted

* `0x1D` as the normative FACTS or STDERR gauge;
* `0xAA55` as the universal wide Azimuth pattern;
* conservation terminology applied to Hamming weight;
* particular semantic names for every Fano direction.

## Open

* the final canonical assignment of Fano directions;
* exact serialization of the Azimuth profile;
* a complete cross-platform fixed-point renderer;
* proof of complete block encode/decode reconstruction;
* proof that every declared scene projection is platform invariant.

---

# 23. Canonical Definition

> **The OMINO Azimuth is a centroid-relative orientation map derived from a four-position semantic tetrahedron. RULES, FACTS, CLOSURES, and COMBINATORS occupy the codepoints `0x1C`, `0x1D`, `0x1E`, and `0x1F`. Their six pairwise relations form a six-bit truth field with 64 possible states. Three balanced XOR functions project the four semantic controls into a three-bit coordinate. Its seven nonzero values address the seven Fano directions, while zero represents centroidal closure. A fourth bit selects the antipodal orientation. Delta tracks exact relationship changes, CONS preserves ordered CAR/CDR construction, and tetrahedral incidence parity guarantees that every active relation remains paired across two endpoints. Logical conservation is expressed through explicit accounting of preserved, moved, cancelled, and unresolved bits rather than through hidden state or platform-dependent floating-point constants.**

---

# 24. Foundational Summary

The complete first-principles chain is:

```text
four semantic codepoints
    0x1C RULES
    0x1D FACTS
    0x1E CLOSURES
    0x1F COMBINATORS

        ↓

six tetrahedral relations

        ↓

2⁶ = 64 logical relationship states

        ↓

four vertex-incidence parity checks

        ↓

three independent balanced XOR coordinates

        ↓

seven nonzero Fano directions
plus zero centroid

        ↓

one antipodal orientation bit

        ↓

16-position hexadecimal Azimuth

        ↓

Delta tracks relationship change

        ↓

CONS preserves ordered construction

        ↓

centroidal conservation exposes
preservation, cancellation, and difference
```

The tetrahedron is the semantic object.

The six-bit field is its complete local relationship state.

The Fano plane is its three-coordinate projective direction surface.

The Azimuth connects the tetrahedron to that surface.

Delta moves through the relation field.

CONS gives each relation ordered meaning.

Conservation ensures that no logical transformation disappears without being preserved, cancelled, or exposed as a difference.
