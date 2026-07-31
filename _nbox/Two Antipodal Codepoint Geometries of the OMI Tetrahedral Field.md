# Two Antipodal Codepoint Geometries of the OMI Tetrahedral Field

## Comparing the Four-Codepoint Fano–Tetrahedron Construction with the Six-Row Relational Construction

**Status:** Analytical Draft
**Subject:** OMI codepoint geometry, XOR incidence, antipodal projection, and tetrahedral relation expansion

---

## Abstract

Two related codepoint constructions have emerged within the OMI model.

The first is the original compact construction:

```text
Low Fano-plane carrier:
0x11  0x1E  0x6E  0x61

Low tetrahedron:
0x01  0x0F  0x7F  0x70

High Fano-plane carrier:
0x91  0x9E  0xEE  0xE1

High tetrahedron:
0x81  0x8F  0xFF  0xF0
```

The second is the newer six-row construction:

```text
Low rows:
0x20..0x2F
0x30..0x3F
0x40..0x4F
0x50..0x5F
0x60..0x6F
0x70..0x7F

High rows:
0xA0..0xAF
0xB0..0xBF
0xC0..0xCF
0xD0..0xDF
0xE0..0xEF
0xF0..0xFF
```

At first these may appear to be competing descriptions. They are better understood as two resolutions of the same tetrahedral field.

The four-codepoint construction describes the compact control geometry of four tetrahedral positions and their Fano-oriented translation. The six-row construction expands the six pairwise relations between those four positions.

The common antipodal operation is:

```text
codepoint XOR 0x80
```

This operation sends every low-plane codepoint to its corresponding high-plane codepoint.

The two versions therefore appear to describe complementary layers:

```text
4 tetrahedral positions
        ↓
6 pairwise relations
        ↓
15 unordered relations between relations
```

The resulting structure resembles the triangular growth associated with Pascal’s triangle, although the current construction is a codepoint-incidence geometry rather than a direct use of Pascal coefficients.

---

# 1. The Original Four-Codepoint Construction

The original construction consists of two groups in the low codepoint plane.

## 1.1 Low tetrahedron

```text
0x01
0x0F
0x7F
0x70
```

These four codepoints form the tetrahedral control set.

They may be read as four positions, four controls, four semantic vertices, or four mutually related states.

The important fact is not merely that there are four values. Four positions generate exactly six pairwise connections:

```text
Position 1 ↔ Position 2
Position 1 ↔ Position 3
Position 1 ↔ Position 4
Position 2 ↔ Position 3
Position 2 ↔ Position 4
Position 3 ↔ Position 4
```

This is the incidence structure of a tetrahedron:

```text
4 positions
6 connections
4 triangular faces
1 shared center
```

The codepoint set therefore provides a compact carrier for a tetrahedral field.

---

## 1.2 Low Fano-plane carrier

The corresponding low Fano-oriented set is:

```text
0x11
0x1E
0x6E
0x61
```

A direct XOR comparison reveals a strong internal structure.

Take `0x11` as the local anchor:

```text
0x11 XOR 0x00 = 0x11
0x11 XOR 0x0F = 0x1E
0x11 XOR 0x7F = 0x6E
0x11 XOR 0x70 = 0x61
```

Therefore the complete low Fano-oriented set can be generated as:

```text
anchor:
0x11

direction masks:
0x00
0x0F
0x7F
0x70
```

This gives:

```text
0x11
0x11 XOR 0x0F = 0x1E
0x11 XOR 0x7F = 0x6E
0x11 XOR 0x70 = 0x61
```

This is an important result.

The Fano-oriented group is not a random collection of four codepoints. It is an XOR translation of the closed four-state set:

```text
0x00
0x0F
0x7F
0x70
```

That four-state set is closed under XOR:

```text
0x0F XOR 0x7F = 0x70
0x0F XOR 0x70 = 0x7F
0x7F XOR 0x70 = 0x0F
```

The three nonzero values continually reproduce one another.

This gives the internal cycle:

```text
0x0F
0x7F
0x70
```

with:

```text
0x0F XOR 0x7F = 0x70
0x7F XOR 0x70 = 0x0F
0x70 XOR 0x0F = 0x7F
```

This is the clearest exact XOR incidence found in the original construction.

---

# 2. The Relationship Between the Original Fano and Tetrahedron Sets

The low Fano-plane carrier is:

```text
0x11  0x1E  0x6E  0x61
```

Pairwise XOR comparison produces:

```text
0x11 XOR 0x1E = 0x0F
0x11 XOR 0x6E = 0x7F
0x11 XOR 0x61 = 0x70
```

The remaining pairings repeat the same three results:

```text
0x1E XOR 0x6E = 0x70
0x1E XOR 0x61 = 0x7F
0x6E XOR 0x61 = 0x0F
```

Therefore all six pairwise relations among the four Fano carrier points reduce to three XOR directions:

```text
0x0F
0x7F
0x70
```

These three values are also present in the tetrahedron set:

```text
Tetrahedron:
0x01  0x0F  0x7F  0x70
```

The only difference is:

```text
Fano direction identity:
0x00

Tetrahedron active identity:
0x01
```

This suggests the following interpretation:

```text
0x00 = unexpressed or null local origin
0x01 = expressed or active tetrahedral origin
```

Under this reading, the tetrahedron replaces the inactive `0x00` origin with the active `0x01` position while preserving the three nonzero directional masks:

```text
0x0F
0x7F
0x70
```

The relationship can be displayed as:

```text
Closed XOR direction set:
0x00  0x0F  0x7F  0x70

Active tetrahedral set:
0x01  0x0F  0x7F  0x70

Fano-oriented translation:
0x11  0x1E  0x6E  0x61
```

This gives three related views of one local structure:

```text
NULL-relative view
ACTIVE tetrahedral view
FANO-oriented translated view
```

---

# 3. The High Antipodal Construction

The high-plane sets are:

```text
High Fano-plane carrier:
0x91  0x9E  0xEE  0xE1

High tetrahedron:
0x81  0x8F  0xFF  0xF0
```

Every high codepoint is obtained from its low counterpart through:

```text
XOR 0x80
```

For the Fano-oriented set:

```text
0x11 XOR 0x80 = 0x91
0x1E XOR 0x80 = 0x9E
0x6E XOR 0x80 = 0xEE
0x61 XOR 0x80 = 0xE1
```

For the tetrahedron:

```text
0x01 XOR 0x80 = 0x81
0x0F XOR 0x80 = 0x8F
0x7F XOR 0x80 = 0xFF
0x70 XOR 0x80 = 0xF0
```

The low and high constructions are therefore exact antipodal copies.

```text
LOW XOR 0x80 = HIGH
HIGH XOR 0x80 = LOW
```

Because:

```text
0x80 XOR 0x80 = 0x00
```

the operation is reversible without storing a separate inverse operation.

This gives `0x80` a natural role as the antipodal difference between corresponding low and high positions.

It does not have to replace the original centroid or slide-ruler address. It can instead serve as the local plane-reversal operation:

```text
low orientation  ↔  high orientation
```

The centroid address and the antipodal difference may therefore remain separate concepts.

---

# 4. Internal Relations of the High Fano Carrier

The high Fano-oriented set has the same internal XOR relations as the low set.

```text
0x91 XOR 0x9E = 0x0F
0x91 XOR 0xEE = 0x7F
0x91 XOR 0xE1 = 0x70
```

The high bit disappears from the pairwise difference because it occurs on both sides:

```text
0x80 XOR 0x80 = 0x00
```

Therefore:

```text
low-point XOR low-point
```

and:

```text
high-point XOR high-point
```

produce the same local relation masks.

This means the relation geometry is conserved across the antipodal transformation.

The orientation changes, but the internal incidence does not.

```text
Low Fano incidence:
0x0F  0x7F  0x70

High Fano incidence:
0x0F  0x7F  0x70
```

This is an exact form of logical conservation.

The codepoints change planes, but their relative XOR relations remain constant.

---

# 5. What Is Fano-Like About the Original Construction?

A complete conventional Fano plane contains seven points and seven three-point lines.

The four codepoints:

```text
0x11  0x1E  0x6E  0x61
```

do not by themselves enumerate all seven points of a conventional Fano plane.

They do, however, provide a compact Fano-oriented carrier because their pairwise XOR relations close through three nonzero direction values:

```text
0x0F
0x7F
0x70
```

The combined four points and three directions give a seven-part structure:

```text
Four translated carrier points:
0x11
0x1E
0x6E
0x61

Three internal XOR directions:
0x0F
0x7F
0x70
```

Together:

```text
4 + 3 = 7
```

This may be the most direct explanation of why the structure presents itself as a Fano plane.

It is not necessary to say that the four carrier codepoints alone are all seven Fano points. Instead:

```text
4 carrier positions
+
3 shared XOR directions
=
7-part projective incidence view
```

That is a precise codepoint-based interpretation of the original construction.

The high version supplies its antipodal copy:

```text
0x91
0x9E
0xEE
0xE1

with directions:

0x0F
0x7F
0x70
```

The low and high carriers share the same direction field.

---

# 6. The Newer Six-Row Construction

The newer construction begins from six low codepoint rows:

```text
0x20..0x2F
0x30..0x3F
0x40..0x4F
0x50..0x5F
0x60..0x6F
0x70..0x7F
```

Their six antipodal rows are:

```text
0xA0..0xAF
0xB0..0xBF
0xC0..0xCF
0xD0..0xDF
0xE0..0xEF
0xF0..0xFF
```

Each corresponding low and high codepoint differs by exactly `0x80`.

Examples:

```text
0x20 XOR 0xA0 = 0x80
0x2C XOR 0xAC = 0x80

0x30 XOR 0xB0 = 0x80
0x3F XOR 0xBF = 0x80

0x40 XOR 0xC0 = 0x80
0x4A XOR 0xCA = 0x80

0x50 XOR 0xD0 = 0x80
0x5E XOR 0xDE = 0x80

0x60 XOR 0xE0 = 0x80
0x67 XOR 0xE7 = 0x80

0x70 XOR 0xF0 = 0x80
0x7F XOR 0xFF = 0x80
```

The six rows naturally suggest the six connections of a tetrahedron.

```text
4 tetrahedral positions
produce
6 tetrahedral edges
```

The six rows can therefore serve as six relation fields.

For example:

```text
0x20 row = relation 1
0x30 row = relation 2
0x40 row = relation 3
0x50 row = relation 4
0x60 row = relation 5
0x70 row = relation 6
```

Their antipodal counterparts are:

```text
0xA0 row = inverse or high view of relation 1
0xB0 row = inverse or high view of relation 2
0xC0 row = inverse or high view of relation 3
0xD0 row = inverse or high view of relation 4
0xE0 row = inverse or high view of relation 5
0xF0 row = inverse or high view of relation 6
```

The exact semantic assignment of the six relations remains available to be frozen separately.

---

# 7. Why the Six-Row Version Resembles Pascal’s Triangle

Six relation fields can be compared with one another.

If a relation is not paired with itself, there are fifteen unique unordered pairings.

They can be arranged in triangular rows:

```text
Relation 1 pairs with 5 later relations
Relation 2 pairs with 4 later relations
Relation 3 pairs with 3 later relations
Relation 4 pairs with 2 later relations
Relation 5 pairs with 1 later relation
Relation 6 pairs with 0 later relations
```

This gives:

```text
5
4
3
2
1
```

or in ascending order:

```text
1
2
3
4
5
```

The total is fifteen unique pairings.

A triangular display looks like:

```text
12

13  23

14  24  34

15  25  35  45

16  26  36  46  56
```

This is why the construction visually recalls Pascal’s triangle.

The resemblance comes from combinatorial expansion:

```text
4 positions
→ 6 edges

6 edges
→ 15 edge-pairs
```

Pascal’s triangle also organizes the number of ways elements can be selected and combined.

However, the OMI construction is not currently using Pascal coefficients as stored values. It is using the same type of triangular growth in a codepoint relation field.

The distinction is:

```text
Pascal’s triangle:
counts combinations

OMI six-row field:
addresses combinations
```

The shape is similar because both arise from pair selection.

---

# 8. The Six-by-Six Relation Surface

The six relation rows can be placed on both axes of a table.

```text
        20  30  40  50  60  70

20      --  23  24  25  26  27
30      32  --  34  35  36  37
40      42  43  --  45  46  47
50      52  53  54  --  56  57
60      62  63  64  65  --  67
70      72  73  74  75  76  --
```

This symbolic table illustrates three possible readings.

## 8.1 Diagonal reading

The diagonal represents each relation compared with itself.

```text
20 with 20
30 with 30
40 with 40
50 with 50
60 with 60
70 with 70
```

A self-XOR gives:

```text
value XOR itself = 0x00
```

When the diagonal compares a low row with its corresponding high row, it gives:

```text
low value XOR high value = 0x80
```

The two diagonals therefore distinguish:

```text
same-plane identity = 0x00
antipodal-plane difference = 0x80
```

---

## 8.2 Symmetric reading

When direction is ignored:

```text
relation 1 with relation 2
```

is treated as the same pair as:

```text
relation 2 with relation 1
```

This produces fifteen unique off-diagonal pairs.

This is the triangular or Pascal-like reading.

---

## 8.3 Directed CONS reading

When CAR and CDR order is preserved:

```text
(CONS relation-1 relation-2)
```

is distinct from:

```text
(CONS relation-2 relation-1)
```

The table then retains all thirty directed off-diagonal cells.

This gives:

```text
6 diagonal cells
30 directed relation cells
36 total cells
```

The symmetric form is useful for geometric incidence.

The directed form is useful for computation, rewriting, declaration, and transport.

Thus the same six-by-six field can support both:

```text
undirected geometry
directed CONS operation
```

---

# 9. Binary Quadratic XOR Interpretation

XOR by itself performs a linear combination of bits.

A quadratic XOR function requires pairs of input bits to interact before their results are joined by XOR.

At the bit level, the pair interaction is:

```text
bit-A AND bit-B
```

The collected pair results are then combined through:

```text
XOR
```

For six relation bits, the possible unique pair interactions are:

```text
1 AND 2
1 AND 3
1 AND 4
1 AND 5
1 AND 6

2 AND 3
2 AND 4
2 AND 5
2 AND 6

3 AND 4
3 AND 5
3 AND 6

4 AND 5
4 AND 6

5 AND 6
```

There are fifteen pair terms.

This is the same fifteen-position triangular field produced by the six relation rows.

The six-row construction can therefore act as an address surface for a binary quadratic XOR function:

```text
six input relations
fifteen pair interactions
XOR-combined output
```

This is not merely a visual similarity.

The fifteen pair locations required by a six-input quadratic Boolean function match the fifteen unique pairings among the six tetrahedral edges.

The tetrahedral geometry and the Boolean quadratic relation count therefore coincide at this level.

---

# 10. Comparison of the Two Versions

## 10.1 Original four-codepoint version

```text
Tetrahedron:
0x01  0x0F  0x7F  0x70

Fano carrier:
0x11  0x1E  0x6E  0x61
```

This version is compact.

It emphasizes:

```text
four tetrahedral positions
three closed XOR directions
one translated Fano-oriented carrier
```

It is especially well suited to:

```text
control positions
semantic vertices
orientation
local incidence
compact addressing
```

Its seven-part Fano interpretation appears through:

```text
4 carrier codepoints
+
3 internal XOR directions
```

---

## 10.2 New six-row version

```text
0x20 row
0x30 row
0x40 row
0x50 row
0x60 row
0x70 row
```

This version is expansive.

It emphasizes:

```text
six tetrahedral connections
six relation channels
fifteen unique relation-pairs
thirty directed CONS pairings
```

It is especially well suited to:

```text
edge states
relation logic
Boolean quadratic terms
CONS direction
expanded Blackboard addressing
```

---

## 10.3 Shared high-plane operation

Both versions use:

```text
XOR 0x80
```

to produce an antipodal copy.

Original version:

```text
0x01 → 0x81
0x0F → 0x8F
0x7F → 0xFF
0x70 → 0xF0

0x11 → 0x91
0x1E → 0x9E
0x6E → 0xEE
0x61 → 0xE1
```

Six-row version:

```text
0x20 row → 0xA0 row
0x30 row → 0xB0 row
0x40 row → 0xC0 row
0x50 row → 0xD0 row
0x60 row → 0xE0 row
0x70 row → 0xF0 row
```

Thus `0x80` acts consistently across both constructions.

---

# 11. The Two Versions as One Layered Architecture

The strongest combined interpretation is not that one version replaces the other.

Instead:

```text
Original four-codepoint version:
tetrahedral position field

New six-row version:
tetrahedral relation field
```

The progression is:

```text
4 positions
↓
6 pairwise relations
↓
15 relation-pair interactions
↓
30 directed CONS interactions
↓
36-cell complete relation table
```

The original construction supplies the four-position seed.

The newer construction expands the six edges generated by that seed.

The triangular fifteen-term structure then expands the relationships among those six edges.

This produces a hierarchy:

```text
Level 1:
4 tetrahedral positions

Level 2:
6 tetrahedral relations

Level 3:
15 unordered relation interactions

Level 4:
30 ordered CAR/CDR interactions

Level 5:
36-cell field including self-relations
```

This hierarchy explains why the second version appears Pascal-like.

It is the combinatorial expansion of the first version.

---

# 12. A Possible Codepoint Role Separation

The following assignment is analytical rather than frozen.

## Compact control region

```text
0x01  0x0F  0x7F  0x70
```

Role:

```text
four active tetrahedral positions
```

## Compact Fano-oriented region

```text
0x11  0x1E  0x6E  0x61
```

Role:

```text
translated four-position carrier
```

## Shared direction masks

```text
0x0F  0x7F  0x70
```

Role:

```text
three closed XOR directions
```

## Expanded low relation region

```text
0x20..0x7F
```

Role:

```text
six tetrahedral edge channels
```

## Expanded high relation region

```text
0xA0..0xFF
```

Role:

```text
six antipodal edge channels
```

## Antipodal operator

```text
0x80
```

Role:

```text
local low/high plane reversal
```

This preserves the original codepoint construction while giving the six-row construction a clear place in the architecture.

---

# 13. Important Distinctions

Several distinctions should remain explicit.

## 13.1 `0x80` is not automatically the original centroid

The exact finding is:

```text
low codepoint XOR high counterpart = 0x80
```

This proves that `0x80` is the antipodal difference.

It does not by itself prove that `0x80` must replace the original slide-ruler centroid address.

Possible separate roles are:

```text
original centroid:
projective address or CDR entry into cons.o

0x80:
low/high antipodal plane difference
```

These roles can coexist.

---

## 13.2 Four Fano carrier points are not the entire conventional Fano plane

The exact seven-part construction is:

```text
4 carrier points
+
3 XOR direction values
=
7 incidence elements
```

This can be called an OMI Fano projection or Fano carrier.

A complete conventional Fano labeling would additionally assign all seven elements explicit point identities and specify the seven three-point lines.

---

## 13.3 Pascal-like does not yet mean Pascal encoded

The six-row field produces triangular relation counts.

That makes it structurally similar to Pascal’s triangle.

It does not yet mean the field stores or computes Pascal coefficients.

The current exact claim is:

```text
the relation expansion has triangular combinatorial form
```

---

## 13.4 XOR alone is not quadratic

A quadratic Boolean operation requires:

```text
pair interaction through AND
then combination through XOR
```

The codepoint table can address those interactions, while XOR can collect their results.

---

# 14. Principal Discovery

The most important result of examining the two versions together is:

```text
The original construction describes four tetrahedral positions.

The newer construction describes the six relations produced by those positions.
```

This is not an accidental numerical match.

A tetrahedron necessarily has:

```text
4 vertices
6 edges
```

The next expansion necessarily has:

```text
15 unordered pairs among the 6 edges
```

The structures therefore align as:

```text
Original:
4-codepoint control geometry

Expanded:
6-row relation geometry

Quadratic:
15-term edge-interaction geometry
```

The low/high division duplicates each geometry antipodally through:

```text
XOR 0x80
```

This yields a coherent codepoint progression:

```text
four controls
six relations
fifteen quadratic interactions
two antipodal orientations
```

---

# 15. Proposed Unified Reading

The two versions may be read together as follows.

```text
0x01  0x0F  0x7F  0x70
```

define the active tetrahedral control positions.

```text
0x11  0x1E  0x6E  0x61
```

define a translated Fano-oriented carrier of those positions.

Their pairwise XOR differences recover:

```text
0x0F  0x7F  0x70
```

as the three shared directional values.

The rows:

```text
0x20..0x7F
```

expand the tetrahedron into six relation channels.

The rows:

```text
0xA0..0xFF
```

supply their antipodal counterparts.

The operation:

```text
XOR 0x80
```

moves between the two orientations without changing internal same-plane incidence.

The fifteen unique pairings among the six relation channels provide the address field required for a six-input Boolean quadratic interaction.

CONS preserves the direction of those interactions when CAR/CDR order matters.

The combined construction is therefore:

```text
a compact tetrahedral seed
expanded into a six-edge relation field
expanded again into a fifteen-term quadratic field
with reversible low/high antipodal orientation
```

---

# Conclusion

The original four-codepoint construction and the newer six-row construction should not be treated as mutually exclusive alternatives.

The original version is the more compact and foundational geometry:

```text
4 tetrahedral controls
4 translated Fano carrier points
3 closed XOR directions
```

The newer version is the relational expansion:

```text
6 tetrahedral edge channels
15 unique edge-pair interactions
30 directed CONS interactions
```

Both share an exact antipodal transformation:

```text
XOR 0x80
```

The original codepoints reveal a particularly strong result:

```text
0x11 XOR 0x1E = 0x0F
0x11 XOR 0x6E = 0x7F
0x11 XOR 0x61 = 0x70
```

and:

```text
0x0F XOR 0x7F = 0x70
0x7F XOR 0x70 = 0x0F
0x70 XOR 0x0F = 0x7F
```

This means the translated four-point Fano carrier contains a closed three-direction XOR geometry.

The six-row model then gives those relations a larger operational surface.

The most defensible unified interpretation is:

```text
The four-codepoint construction is the tetrahedral control seed.

The six-row construction is its edge and relation expansion.

The Pascal-like triangle is the next expansion into pairwise relations between the six edges.
```

In this way, the two versions describe different depths of the same Polyharmonic OMINO logic block rather than contradictory geometries.
