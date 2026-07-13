# Control Codes and Printable Projections

## ASCII as Rewrite Surface

ASCII is not merely a character encoding. It is a rewrite surface divided into two regions by the projective boundary between control and projection.

The two regions are:

| Range | Name | OMI Role |
|-------|------|----------|
| `0x00..0x1F` | C0 Control Codes | Rewrite operators |
| `0x20..0x7F` | Printable Characters | Visible projection surface |

## Control Codes Are Rewrite Operators

The ASCII control range is not merely a set of non-printing characters. These codes were historically protocol operations:

```text
NUL  0x00  null / no operation
SOH  0x01  start of heading
STX  0x02  start of text
ETX  0x03  end of text
EOT  0x04  end of transmission
ENQ  0x05  enquiry
ACK  0x06  acknowledge
BEL  0x07  bell / attention
BS   0x08  backspace
HT   0x09  horizontal tab
LF   0x0A  line feed
VT   0x0B  vertical tab
FF   0x0C  form feed
CR   0x0D  carriage return
SO   0x0E  shift out
SI   0x0F  shift in
DLE  0x10  data link escape
DC1  0x11  device control 1
DC2  0x12  device control 2
DC3  0x13  device control 3
DC4  0x14  device control 4
NAK  0x15  negative acknowledge
SYN  0x16  synchronous idle
ETB  0x17  end of transmission block
CAN  0x18  cancel
EM   0x19  end of medium
SUB  0x1A  substitute
ESC  0x1B  escape
FS   0x1C  file separator
GS   0x1D  group separator
RS   0x1E  record separator
US   0x1F  unit separator
```

They describe transitions. They start, stop, shift, acknowledge, separate, return, and advance. OMI restores their original force: control codes are not characters. They are rewrite operators.

### OMI Canonical Separators

Four control codes serve as the canonical directional gates in OMI's DOM hierarchy:

| Code | Name | Axis | OMI Role |
|------|------|------|----------|
| `0x1C` | FS | top | Frame System root delimiter |
| `0x1D` | GS | right | Glyph Structure delimiter |
| `0x1E` | RS | bottom | Resolution Segment delimiter |
| `0x1F` | US | left | Unit Coordinate delimiter |

These drive JSON Canvas projections, SpectrumDOM color fields, and binary packet interpolation without changing the underlying OMI frame.

## Printable Characters Are Projections

The printable range is the visible projection of a rewrite surface.

| Range | Region | OMI Role |
|-------|--------|----------|
| `0x20` | Space | Visible absence, the printable empty pivot |
| `0x21..0x7E` | Glyphs | Printable projection of rewrite state |
| `0x7F` | DEL | Terminal sentinel |

### Space as Visible Absence

The space character is not nothing. It is the printable empty pivot. In OMI, space marks the place where a rewrite surface has not been projected. It is the visible absence that separates and relates glyphs.

### DEL as Terminal Sentinel

The delete character is not ordinary text. It is a terminal sentinel. Together with space, it marks a projective boundary between control and projection.

## Projective Boundary

The boundary between `0x1F` (unit separator) and `0x20` (space) is the projective boundary of OMI:

```text
0x00..0x1F  = rewrite operators (control plane)
0x20        = the pivot (visible absence)
0x21..0x7E  = projected glyphs (display plane)
0x7F        = terminal sentinel
```

Below this boundary, OMI operates on transitions, rewrites, and protocol signals. At and above this boundary, OMI projects readable glyphs for human inspection.

## Relation to Unicode

The same projective boundary extends into Unicode. The C0 range `U+0000..U+001F` retains its rewrite-operator role. The printable range `U+0020..U+007E` projects glyphs. Beyond `U+007F`, Unicode extends the projection surface into richer glyph spaces while OMI reads those extended ranges as incidence cells under the same rewrite geometry (see [2.6 Unicode as Incidence Geometry](../2_MATH/2.6_UNICODE_AS_INCIDENCE_GEOMETRY.md)).

## Source

This document derives from sections 8 and 9 of [MANIFESTO.md](../MANIFESTO.md).

See also:

- [3.1 DOM Hierarchy](3.1_DOM_HIERARCHY.md) -- how control codes drive DOM structure
- [2.6 Unicode as Incidence Geometry](../2_MATH/2.6_UNICODE_AS_INCIDENCE_GEOMETRY.md) -- the Unicode extension
- [7.3 Lower Omicron / Upper Bidi](../7_CANON/7.3_LOWER_OMICRON_UPPER_BIDI.md) -- the split between lower rewrite and upper projection
