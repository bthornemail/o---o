# Pleth / Gauge / Difference of Powers

## First Principles

### 1. The difference of squares exposes structure

```
a² − b² = (a − b)(a + b)
```

Every product can be rewritten as a difference of squares by centering:

```
Let m = (x + y)/2, d = (x − y)/2
Then xy = m² − d²
```

This is not a trick. It is the first canonical decomposition: **any binary relation splits into a gap and a span.**

In the OMI ontology:
- `(a − b)` = the gauge line (selection, difference, gap)
- `(a + b)` = the carrier span (sum, surface, reference)

### 2. The difference of cubes exposes the plinth

```
a³ − b³ = (a − b)(a² + ab + b²)
```

Here the second factor `(a² + ab + b²)` is **not** a product in the same sense as `(a + b)`. It is a surface — the reference plane between two cubic volumes.

```
a³ − b³  =  (a − b) × (a² + ab + b²)

volume      gauge line    plinth surface
difference                 between the two cubes
```

Call `(a² + ab + b²)` the **pleth** (from πλῆθος, "fullness / surface of extension"). It is the face that connects two cubic quantities.

### 3. The sum of cubes exposes the conjugate

```
a³ + b³ = (a + b)(a² − ab + b²)
```

The sign flips on the `ab` term. This gives the SOAP structure:

```
Same    Opposite    Always Positive
(a + b)(a² − ab + b²)   ← sum of cubes
(a − b)(a² + ab + b²)   ← difference of cubes
       ^         ^
       sign      middle term is always positive
       flips     (the plinth is orientation-independent)
```

The "Always Positive" term `(a² + ab + b²)` or `(a² − ab + b²)` is what makes the comparison bijective: the plinth face is always readable regardless of which cube is larger.

### 4. The gauge as plinth line

In a nomogram or circular slide rule, the **gauge** is the hairline — the cursor that selects which line on the scale to read. It does **not** create the scale. It aligns the reader to a specific difference.

The gauge line `(a − b)`:
- selects which pair of cubes to compare
- picks the direction of traversal
- is the cursor on the plinth face

The plinth surface `(a² + ab + b²)`:
- is the reference face between the two cubes
- exists independently of the gauge
- is always positive (bijective reading)

### 5. Sexagesimal weighting makes it countable

A sexagesimal bridge of the form:

```
60x² + 16xy + 4y²
```

is a **weighted gauge surface**. The coefficients are not arbitrary — they weight the plinth so that the selected difference `(x − y)` maps to a unique position in a numeration frame.

```
weighted plinth × gauge line = traversed volume at resolution R
```

This is how the OMI gauge word works:
- The gauge table defines the possible weightings (the plinth surfaces)
- The gauge word selects one weighting in-stream (the gauge line)
- The result is a bijective numeration up to the resolution of the referenced address

### 6. OMI doctrine sentences

**The gauge is not primitive structure.**
**The gauge is the late-bound alignment selector that turns an addressed relation into a readable frame.**

**The gauge does not create the cubes.**
**It selects the line by which their difference becomes readable.**

**The gauge table explains possible alignments.**
**The gauge word selects one alignment in-stream.**

### 7. Relation to the axiomatic tower

```
Kernel (Layers 0-4)
  Null, Bit, Pair, Relation
  └── no gauge — the kernel has no selection

Address / Frame (Layer 5)
  place-value fields + in-stream escape
  └── gauge is not here either — these define where, not how to read

Algorithms (Layer 7)
  gauge :: Address → Frame → Selection
  └── here: gauge is a function over addresses and frames,
      returning a selected alignment

Projections (Layer 8-9)
  Canvas, SVG, JSON, LoRa, etc.
  └── here: the gauge-aligned relation is rendered
```

The gauge never enters the kernel because it is a **relation between two structures**, not a structure itself. It is the `(a − b)` line, not the `a³` or the `b³`.

### 8. Summary

| Concept | Algebraic form | OMI role |
|---------|---------------|----------|
| Square | a² | carrier field |
| Cube | a³ | full relation volume |
| Difference | a − b | gauge line (selection) |
| Sum | a + b | span (total width) |
| Pleth | a² + ab + b² | reference surface between volumes |
| SOAP | Same, Opposite, Always Positive | sign convention for bijective reading |
| Weighted pleth | 60x² + 16xy + 4y² | sexagesimal numeration frame |
| Gauge word | in-stream selection | chooses which plinth face to align to |
| Gauge table | canonical set of possible alignments | defines the available reference surfaces |

The conclusion arrives from first principles by asking:

> If every product is a difference of squares, and every cubic comparison is a gauge line times a plinth surface, then what does the gauge actually *do*?

The answer: it selects. It does not construct. And therefore it is not primitive.
