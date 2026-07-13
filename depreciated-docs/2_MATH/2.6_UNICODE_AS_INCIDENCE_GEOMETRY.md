# Unicode as Incidence Geometry

## Codepoints Are Not Glyphs

Unicode is usually treated as a character set. OMI treats it as a rewrite manifold.

A codepoint is not merely a glyph. It is an incidence cell.

Rows, columns, blocks, sentinels, private-use regions, and direction markers define lawful interpretation surfaces. Private-use regions are especially important because they give OMI bounded regions for protocol-defined notation without colliding with public character meanings.

## Incidence, Not Storage

OMI reads character tables as incidence systems:

```text
points  = codepoints
blocks  = rows, columns, mirrors, sentinels, escape sets
edges   = lawful traversals
receipt = accepted incidence proof
```

The table is not merely a lookup table. It is a finite geometry of possible rewrites.

### Codepoints as Points

Every codepoint `U+XXXX` is a point in the incidence geometry. Its position in the Unicode plane defines its neighborhood: which code blocks it belongs to, which directions are lawful, and which rewrites are valid.

### Blocks as Incidence Surfaces

A Unicode block (e.g., `U+0000..U+007F` Basic Latin) is an incidence surface. The boundaries between blocks are edges where one rewrite regime transitions to another.

OMI recognizes these canonical incidence surfaces:

| Surface | Range | OMI Role |
|---------|-------|----------|
| C0 Controls | `U+0000..U+001F` | Rewrite operators |
| Basic Latin | `U+0020..U+007E` | Printable projection |
| C1 Controls | `U+0080..U+009F` | Extended rewrite operators |
| Latin-1 Supplement | `U+00A0..U+00FF` | Extended projection |
| Private Use Areas | `U+E000..U+F8FF`, etc. | Protocol-defined notation |
| Non-characters | `U+FFFE`, `U+FFFF`, etc. | Sentinel surfaces |
| Surrogates | `U+D800..U+DFFF` | Edge escape set |

### Edges as Lawful Traversals

A traversal from one codepoint to another is lawful if it follows an edge in the incidence geometry. Edges include:

```text
block boundaries
directional transitions (bidi)
case mappings
composition / decomposition
script boundaries
numeric value relations
```

### Receipt as Accepted Incidence Proof

When a traversal is validated and recorded, it becomes an accepted incidence proof -- a receipt. The receipt says: "this codepoint was reached from that codepoint through a lawful rewrite path."

## Private Use Areas as Protocol Space

Private Use Areas (PUAs) are especially important for OMI:

```text
U+E000..U+F8FF   (BMP PUA)
U+F0000..U+FFFFF (Plane 15 PUA)
U+100000..U+10FFFF (Plane 16 PUA)
```

These regions are reserved for private agreement. OMI uses them as bounded notation spaces where protocol-defined symbols can exist without colliding with public character meanings.

A PUA codepoint in OMI is not a mystery glyph. It is a declared incidence cell whose meaning is defined by the OMI frame that addresses it.

## The Unicode Table as Finite Geometry

Unicode is not an infinite set. It is a bounded table of 1,114,112 codepoints (17 planes × 65,536 codepoints each). OMI reads this boundedness as a finite geometry:

```text
17 planes   = 17 projective surfaces
1,114,112   = total points
65536       = points per surface
```

The table has edges, boundaries, sentinels (non-characters), escape sets (surrogates), and private agreement regions. This is exactly the structure OMI needs for a rewrite geometry.

## Source

This document derives from sections 13 and 14 of [MANIFESTO.md](../MANIFESTO.md).

See also:

- [3.4 Control Codes and Printable Projections](../3_ARCHITECTURE/3.4_CONTROL_CODES_AND_PRINTABLE_PROJECTIONS.md) -- the projective boundary between control and printable
- [7.3 Lower Omicron / Upper Bidi](../7_CANON/7.3_LOWER_OMICRON_UPPER_BIDI.md) -- bidi as directional incidence
- [2.5 Projective Closure and the Empty List](2.5_PROJECTIVE_CLOSURE_AND_THE_EMPTY_LIST.md) -- the closure principle
