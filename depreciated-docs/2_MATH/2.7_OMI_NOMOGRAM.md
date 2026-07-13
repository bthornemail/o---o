# Omi-Nomogram and Omi-SlideRule

## Nomogram, Not Database

OMI uses runtime scales to declare how a relation is read. This surface is called Omi-Nomogram. Its mechanical face is Omi-SlideRule.

A nomogram does not store answers. It aligns scales. Likewise, Omi-Nomogram does not store meaning. It declares the scale of interpretation.

## Canonical Scale Row

The canonical scale row occupies the `0x30..0x3F` range:

| Code | Name | Scale |
|------|------|-------|
| `0x30` | Identity / Unity | `1:1` relation, frame identity |
| `0x31` | Multiply-Divide | Product and quotient alignment |
| `0x32` | Square-Root | Root extraction scale |
| `0x33` | Cube-Root | Cubic root extraction |
| `0x34` | Folded π Scale | Circular / periodic alignment |
| `0x35` | Reciprocal Scale | `1/x` inversion |
| `0x36` | Sine-Cosine | Angular projection |
| `0x37` | Tangent-Cotangent | Slope and inclination |
| `0x38` | Small-Angle / Degree-Radian | Angular conversion |
| `0x39` | Pythagorean | Euclidean distance / hypotenuse |
| `0x3A` | Log10 | Base-10 logarithmic |
| `0x3B` | Natural Log / Exponential | Natural log and `e^x` |
| `0x3C` | Sexagesimal Gate | Base-60 orientation entry |
| `0x3D` | Arbitrary Powers | `x^y` general exponentiation |
| `0x3E` | Quadratic / Gnomon | Quadratic form alignment |
| `0x3F` | Period / Replay / LFSR | Delta Law period alignment |

## How the SlideRule Works

The Omi-SlideRule aligns two or more scales to produce a reading. The canonical operation is:

```text
select scale  =  choose the interpretation regime
align source and scale  =  declare how the source is read
read the result  =  project the interpretation
```

The scale does not compute a value. It declares a relation. The reading appears when the source is aligned with the scale.

### Example: Log10 Scale

If the source is a 16-bit value and the scale is `0x3A` (Log10), the interpretation is:

```text
the source is not a raw number
the source is a magnitude
the projection is the base-10 logarithm
```

The source bits remain unchanged. The scale declares the reading.

## Scale Selection in the Frame

The scale sits in the slash path:

```text
omi-<frame>/<control>/<scale>/<relation>/<unit>-imo
```

The `<scale>` position selects the nomogram scale. This is how OMI declares interpretation inline: the path carries its own reading instruction.

## The Scale as Cipher

The scale row is a cipher table. Each code tells the reader how to interpret the surface. The same binary source, read under different scales, yields different projections.

This is notation as cipher in operational form: the scale is the declared interpretation.

## Source

This document derives from section 15 of [MANIFESTO.md](../MANIFESTO.md).

See also:

- [1.5 The Slash Path](../1_FOUNDATIONS/1.5_THE_SLASH_PATH.md) -- where the scale lives in the address
- [2.3 The Sexagesimal System](2.3_SEXAGESIMAL_SYSTEM.md) -- base-60 orientation
- [2.1 The Quadratic Law](2.1_THE_QUADRATIC_LAW.md) -- quadratic projection geometry
