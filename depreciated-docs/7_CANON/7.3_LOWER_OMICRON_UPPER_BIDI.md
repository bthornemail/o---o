# Lower Omicron / Upper Bidi

This document fixes the authority split between lower OMI validity and upper reader projection.

## Correction

`unicode-bidi` is not a lower validation authority.

It does not decide whether a frame is valid. It does not determine `Q_frame(S) = 0`. It does not authorize chirality, receipts, truth rows, Fano resolution, or replay acceptance.

`unicode-bidi` is an upper reader lens used after lower validation has already accepted a frame.

## Lower Authority

Lower authority belongs to:

```text
Omicron anchors
Q_frame(S)
Delta Law
Fano resolution
replay receipts
```

Lower authority answers:

```text
Is the frame bounded?
Is the frame structurally valid?
Does it yield one truth row?
Does MM resolve from NN under LL?
Was the accepted row recorded?
```

## Upper Reader Lens

Upper reader lenses include:

```text
unicode-bidi
direction
CSSOM
SpectrumDOM color
font/glyph rendering
DOM order
SVG orientation
JSON Canvas layout
portal UI
```

Upper lenses answer:

```text
How should the accepted state be read?
How should it be projected?
Which view is forward?
Which view is mirror/recovery?
How should a human inspect it?
```

## Correct Pipeline

```text
lower validation
  -> Q_frame(S) = 0
  -> truth row (LL, NN, MM)
  -> Delta/Fano resolution
  -> receipt
  -> upper reader lens
  -> projection
```

Never:

```text
unicode-bidi -> lower validity
```

## Quadratic Split

`Q_frame` is the lower admission gate.

`Q_xy` is the upper projection geometry.

```text
Q_frame(S) validates.
Q_xy(x,y) projects.
unicode-bidi lenses projection.
```

The cross-term sign may be used as a reader-side projection convention, but it is not the source of acceptance.

## BiDi as Dual Reading

BiDi is not merely text direction. In OMI, BiDi expresses lawful dual interpretation.

The same source may be read:

```text
forward
backward
mirrored
folded
projected
```

without changing the source. This is why OMI treats direction as part of computation. Direction is interpretation. Interpretation is rewrite.

The palindrome `omi---imo` already encodes this duality: read forward it yields `omi`, read backward it yields `imo`. BiDi is the reader-lens that selects the direction, but it does not authorize the frame. The same frame may be projected under any direction; the direction changes the reading, not the validity.

This framing derives from section 16 of [MANIFESTO.md](../MANIFESTO.md).

## Canonical Statement

```text
Lower Omicron validates.
Upper Bidi reads.
Direction is interpretation.
Interpretation is rewrite.
Projection is never authority.
```
