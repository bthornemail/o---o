# Chirality Selection and Snub Cardinality

## Purpose

This document updates the older `CHIRALITY_SELECTION_LAW_v0` into the current OMI cosmology.

The original law stated:

```text
Chirality turns partition into order.
Order turns incidence into schedule.
Schedule governs all interaction.
```

That remains correct.

The new geometric reading adds:

```text
Snubbing turns parent geometry into handed form.
Handed form exposes chirality.
Chirality selects the active orientation.
```

Together:

```text
partition -> chirality -> order
parent body -> snub operation -> handed form
incidence -> Fano selection -> replayable schedule
```

This is why the snub cube and snub dodecahedron matter. They are not just examples of a geometric operation. They are visible witnesses of the chirality law.

They show that the same parent body can share a centroid, preserve identity, and split into left/right handed forms without collapsing into mirror sameness.

## The Old Law in One Sentence

The original chirality law solved a specific ambiguity:

```text
Given a partitioned candidate space, which side is first?
```

A partition alone does not define order.

```text
partition(S) -> (S0, S1)
```

only says that the set has been divided.

It does not say which subset should activate first.

The old law resolved this by deriving a chirality bit from canonical replayable state:

```text
bit := kernel_bit(state, tick)
```

Then:

```text
if bit = 0:
  ordered := (S0, S1)
else:
  ordered := (S1, S0)
```

The critical principle was:

```text
Selection order is derived from canonical state, not representation.
```

That principle remains central to OMI.

UI order has no authority.
Serialization order has no authority.
Display order has no authority.
Runtime iteration order has no authority.

Only canonical replayable state may choose orientation.

## Updated OMI Reading

In the current OMI model, the chirality law applies to the hyphen field:

```text
omi---imo
```

The hyphen is not empty punctuation.

The hyphen is the join operation, the rewrite bridge, the gravity field, and the meta-compiler lane.

So when OMI partitions a candidate space, the partition does not create authority. It creates possible structure.

The hyphen field then needs chirality to choose orientation.

```text
partition gives possible relation
chirality gives traversal orientation
snubbing gives geometric transformation
receipt gives replayable memory
```

The updated law is:

```text
Selection = Partition + Chirality + Replay
```

And the geometric form is:

```text
Transformation = Parent Body + Snub Operation + Handed Orientation
```

## Why Snub Geometry Fits Better Than Permutation

Permutation only reorders existing elements.

```text
same parts
different order
```

Circular inversion only reverses inside and outside.

```text
inside <-> outside
```

Snub truncation does more.

```text
cut
twist
re-face
generate chirality
preserve parent relation
```

That is why snubbing is the better OMI operation.

OMI does not only reorder candidates.
OMI does not only invert a view.
OMI joins terms through the hyphen field and transforms them into an oriented agreement surface.

Short form:

```text
The hyphen joins.
The snub twists.
The triangle agrees.
The receipt remembers.
```

## Chirality as Cardinality

The snub cube and snub dodecahedron expose the simplest visible cardinality of chirality:

```text
left-handed form
right-handed form
```

So the first chirality cardinality is:

```text
|chirality| = 2
```

But this binary handedness unfolds across different surface counts.

For the snub cube:

```text
6 squares
32 triangles
38 total faces
2 handed forms
```

For the snub dodecahedron:

```text
12 pentagons
80 triangles
92 total faces
2 handed forms
```

This gives OMI two levels of cardinality:

```text
handed cardinality = 2
surface cardinality = number of agreement faces produced by the snub
```

The handedness is binary.

The agreement surface is scaled.

That matters for peer-to-peer structure.

Two peers may hold complementary orientations around the same centroid. They do not need to collapse into one visual form. They need to resolve against the same canonical chirality law.

## Shared Centroid and P2P Complementarity

In a P2P system, each peer may approach the same object from a different orientation.

Without a canonical chirality law, this creates ambiguity:

```text
Which branch is first?
Which direction is active?
Which peer's view becomes schedule?
```

OMI resolves this by rooting the candidate geometry at a shared centroid.

The centroid is not a visual center. It is the canonical reference point of the bounded object.

```text
same centroid
different handedness
lawful transformation
replayable schedule
```

This means chirality is not disagreement.

```text
chirality = oriented complementarity
```

Peer A may hold the left-handed relation.
Peer B may hold the right-handed relation.
The OMI system resolves schedule from canonical state, not from either peer's display order.

So P2P agreement becomes:

```text
shared centroid
canonical partition
kernel-derived chirality
bounded Fano resolution
receipt-backed replay
```

## Two's-Complement Analogy

The left and right snub forms can be read as a geometric two's-complement pair.

In two's-complement arithmetic, positive and negative values share the same bounded word space.

In OMI chirality, left and right orientations share the same bounded centroid space.

The analogy is:

```text
binary word space      -> bounded numeric complement
snub centroid space    -> bounded geometric complement
OMI frame space        -> bounded replayable complement
```

This does not mean the snub solid is literally two's-complement arithmetic.

It means both systems encode opposition inside a bounded domain.

OMI uses this principle to prevent complementary orientations from becoming contradictions.

```text
left/right != true/false
left/right = complementary orientation
```

The chirality bit selects which orientation activates at the current tick.

## Relation to the Quadratic Form

The OMI quadratic form is:

```text
Q_xy(x, y) = 60x² + 16xy + 4y²
```

The updated geometric reading is:

```text
4y²   = Platonic vertex seed
16xy  = Archimedean/Catalan snub bridge
60x²  = 4D regular polytope orbit
```

Chirality belongs most directly to the `16xy` bridge.

Why?

Because `16xy` is the joined relation. It is the hyphen field. It is the place where one side meets the other and must be given orientation.

```text
omi --- imo
     ^
   16xy
```

So:

```text
4y² gives the local body.
16xy chooses/twists the relation.
60x² expands the orientation field.
```

The snub operation is the geometry of `16xy`.

## Relation to Fano Selection

The old law depended on A5 / Fano Selection.

That still fits.

The Fano layer supplies finite incidence:

```text
7 points
7 lines
3 points per line
```

The chirality law supplies orientation:

```text
partition -> possible incidence
chirality -> active incidence
```

The truth row is triangular:

```text
(LL, NN, MM)
```

This can be read as:

```text
lens
antecedent
consequent
```

or:

```text
declaration
definition
receipt
```

or:

```text
source
frame
projection
```

The Fano selector answers:

```text
Which triangular relation resolves?
```

The chirality bit answers:

```text
Which orientation activates first?
```

Together:

```text
Fano selects incidence.
Chirality selects orientation.
Replay records schedule.
```

## Updated Reference Algorithm

The old algorithm was:

```text
function chirality_select(state, tick, S):
    (S0, S1) = partition(S)
    bit = kernel_bit(state, tick)

    if bit == 0:
        return S0
    else:
        return S1
```

The updated OMI version names the geometry:

```text
function omi_chirality_select(frame_state, tick, candidate_geometry):
    (left_candidate, right_candidate) = canonical_partition(candidate_geometry)

    chirality = kernel_bit(frame_state, tick)

    if chirality == 0:
        active = left_candidate
        handedness = "left"
    else:
        active = right_candidate
        handedness = "right"

    return snub_orient(active, handedness)
```

But the invariant is unchanged:

```text
same canonical state
same tick
same candidate geometry
-> same active orientation
```

No UI list order may affect the result.

No rendering order may affect the result.

No platform iteration order may affect the result.

## Important Correction: Label Invariance

The old law said that swapping labels should not change the outcome.

The updated wording should be stricter:

```text
External labels must not affect selection.
Canonical partition labels may affect selection only if they are derived from canonical state.
```

In other words:

```text
S0 and S1 cannot be arbitrary names.
```

If `S0` and `S1` are merely UI labels, then selecting `S0` or `S1` is invalid.

If `S0` and `S1` are canonical partitions derived from the frame state, then the chirality bit may select between them.

So the corrected invariant is:

```text
Renaming or reordering candidate labels must not change the selected canonical subset.
```

This preserves the original intent while closing the ambiguity.

## Mandatory Invariants

A conforming chirality selection must satisfy:

### Determinism

```text
same(state, tick, candidate_space) -> same(selection)
```

### Replay Stability

```text
replay(trace) -> identical orientation sequence
```

### Projection Invariance

The following have no authority:

```text
UI order
DOM order
rendering order
serialization order
network arrival order
runtime iteration order
```

### Single Activation Per Tick

```text
tick_n -> one chirality bit -> one active orientation
```

No double activation.

No mid-tick reordering.

No simultaneous "first" branches.

### Canonical Input Constraint

The chirality bit must come from canonical replayable state.

Invalid inputs include:

```text
wall clock time
UI state
external randomness
unseeded runtime order
display orientation
unicode-bidi
CSS layout
```

## Snub Cube and Snub Dodecahedron as Witnesses

The snub cube and snub dodecahedron are the two strongest geometric witnesses of the chirality law.

The snub cube shows the cubic version:

```text
parent cube
  -> cut
  -> twist
  -> 32 triangular agreement faces
  -> left/right handed snub cube
```

The snub dodecahedron shows the larger pentagonal version:

```text
parent dodecahedron
  -> cut
  -> twist
  -> 80 triangular agreement faces
  -> left/right handed snub dodecahedron
```

They show that chirality is not arbitrary order.

Chirality is a lawful orientation of transformation around a shared centroid.

The same parent body can produce two complementary handed forms.

The centroid remains stable.

The surface orientation changes.

The replay path records which orientation was selected.

## Final Canon

The updated chirality law is:

```text
Chirality turns partition into orientation.
Orientation turns incidence into schedule.
Schedule turns transformation into replayable memory.
```

The geometric witness is:

```text
Snub truncation turns parent body into handed form.
```

The OMI bridge is:

```text
4y²   = Platonic seed
16xy  = Archimedean/Catalan chirality bridge
60x²  = 4D closure orbit
```

The P2P doctrine is:

```text
Peers may hold complementary handed views.
Agreement requires a shared centroid and canonical chirality selection.
```

Short doctrine:

```text
Partition gives possibility.
Chirality gives order.
Snubbing gives handed form.
Fano gives incidence.
Replay gives memory.
```

One-line canon:

```text
In OMI, chirality is the canonical bit that turns a partitioned candidate space into an oriented snub transformation around a shared centroid.
```

For the P2P traversal model of edge, vertex, face, and mirror space, see [8.10 P2P Traversal and Mirror Space](8.10_P2P_TRAVERSAL_AND_MIRROR_SPACE.md).
