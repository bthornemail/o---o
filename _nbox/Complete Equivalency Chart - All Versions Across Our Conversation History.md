# Complete Equivalency Chart: All OMI Definitions and Versions

## Overview

This chart maps every version of OMI terminology, definitions, and concepts across all documents in our conversation history. It shows how terms evolved, which definitions were stable, and which were clarified or corrected.

---

## 1. Core OMI Metalanguage Evolution

| Term | Original Field Document | Your Correction | Scaling Laws Document | Full Specification | Final Canonical |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **UNKNOWN** | `NULL` | `NULL` | Not present | `NULL` | `NULL` |
| **KNOWN** | `BIND` | `BIND` | Not present | `BIND` | `BIND` |
| **NULL** | Unbound coordinate | Unbound coordinate | Not present | Unbound coordinate | Unbound coordinate |
| **BIND** | Only encapsulation | Only encapsulation | Not present | Only encapsulation | Only encapsulation |
| **XOR** | Only operation | Only operation | `REMOTE = LOCAL XOR 0x80` | Only operation | Only operation |
| **META** | Mask selecting coordinates for XOR | Mask selecting coordinates for XOR | Not present | Mask selecting coordinates for XOR | Mask selecting coordinates for XOR |
| **ESC** | META condition that cancels a selected BIND to NULL | META condition that cancels a selected BIND to NULL | Not present | META condition that cancels a selected BIND to NULL | META condition that cancels a selected BIND to NULL |

---

## 2. Scope Entry Forms Evolution

| Entry | Original Field | Your Correction | Simplified (FIX) | Full Specification | Final Canonical |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **FS** | `(BIND GS RS US ESC)` | `(BIND GS RS US ESC)` | `[FIX, GS, RS, US]` | `(BIND GS RS US ESC)` | `(BIND GS RS US ESC)` |
| **GS** | `(BIND RS US BIND ESC)` | `(BIND RS US BIND ESC)` | `[FIX, RS, US, FIX]` | `(BIND RS US BIND ESC)` | `(BIND RS US BIND ESC)` |
| **RS** | `(BIND US BIND BIND ESC)` | `(BIND US BIND BIND ESC)` | `[FIX, US, FIX, FIX]` | `(BIND US BIND BIND ESC)` | `(BIND US BIND BIND ESC)` |
| **US** | `(BIND BIND BIND BIND ESC)` | `(BIND BIND BIND BIND ESC)` | `[FIX, FIX, FIX, FIX]` | `(BIND BIND BIND BIND ESC)` | `(BIND BIND BIND BIND ESC)` |

---

## 3. Field Definition Evolution

| Concept | Original Field | Your Correction | Scaling Laws | Simplified | Full Spec |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Complete Field** | `[S− W− 0− C− \| PO:TO \| C+0+W+S+]` | `[S− W− O− C− \| P0:T0 \| C+ O+ W+ S+]` | Not directly present | `[S− W− O− C− \| P0:T0 \| C+ O+ W+ S+]` | `[S− W− O− C− \| P0:T0 \| C+ O+ W+ S+]` |
| **Hinge** | `PO:TO` | `P0:T0` | Not directly present | `P0:T0` | `P0:T0` |
| **Parity Reference** | `PO` | `P0` | Not directly present | `P0` | `P0` |
| **Tangential Source** | `TO` | `T0` | Not directly present | `T0` | `T0` |
| **Negative Arrangement** | `S− W− 0− C−` | `S− W− O− C−` | Not directly present | `S− W− O− C−` | `S− W− O− C−` |
| **Positive Arrangement** | `C+0+W+S+` | `C+ O+ W+ S+` | Not directly present | `C+ O+ W+ S+` | `C+ O+ W+ S+` |

---

## 4. Plane Classes Evolution

| Concept | Original Field | Your Correction | Scaling Laws | Simplified | Full Spec |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Scalar (mag 4)** | `S−`, `S+` | `S−`, `S+` | Not present | `S−`, `S+` | `S−`, `S+` |
| **Weight (mag 3)** | `W−`, `W+` | `W−`, `W+` | Not present | `W−`, `W+` | `W−`, `W+` |
| **Order (mag 2)** | `0−`, `0+` (ambiguous) | `O−`, `O+` | Not present | `O−`, `O+` | `O−`, `O+` |
| **Capacity (mag 1)** | `C−`, `C+` | `C−`, `C+` | Not present | `C−`, `C+` | `C−`, `C+` |
| **Parity Zero** | `0` (ambiguous) | `P0` | Not present | `P0` | `P0` |
| **Source Zero** | `0` (ambiguous) | `T0` | Not present | `T0` | `T0` |

---

## 5. Scaling Laws Evolution

| Domain | Scaling Laws Document | Field Document Connection | Unified Expression |
| :--- | :--- | :--- | :--- |
| **Boolean Assignments** | `2^k` | Truth-table word width | `W = 2^k` |
| **Boolean Functions** | `2^(2^k)` | Complete field arrangement | `F_k = 2^(2^k)` |
| **Quaternary Omicron** | `4^k` | Four-state layer | `4^k` |
| **Hex Place** | `16^n = 2^(4n)` | Plane magnitudes | `16^n = 2^(4n)` |
| **Compound Hex Place** | `(16^n)^p = 2^(4np)` | Field width | `(16^n)^p = 2^(4np)` |
| **Truth-Table Bridge** | `4np = 2^k` | Field completeness | `4np = 2^k` |
| **Scope Permutations** | `4! = 24` | FS/GS/RS/US orderings | `4! = 24` |
| **Anchored Operations** | `6! = 720` | OMINO operational domain | `6! = 720` |
| **Full Rotations** | `7! = 5040` | Complete compact word | `7! = 5040` |
| **Algorithmic Clock** | `6 × 3 × 4 × 60 = 4320` | Temporal synchrony | `4320` |
| **Artifact Environment** | `5 × 3 = 15` | .omi/.imo/.o surfaces | `5 × 3 = 15` |
| **Control Quotients** | `2^4 = 16` | Four scope coordinates | `2^4 = 16` |
| **OMINO Rows** | `2^6 = 64` | Six operational coordinates | `2^6 = 64` |

---

## 6. Hamming Code Evolution

| Concept | Original Field | Scaling Laws Document | Combined Definition |
| :--- | :--- | :--- | :--- |
| **Compact Word** | Not present | `[7,4,3]` Hamming code | 7 codepoints, 4 data, 3 parity |
| **LOGOS** | Not present | `0x19` | Relation coordinate 1 |
| **NOMOS** | Not present | `0x1A` | Relation coordinate 2 |
| **PATHOS** | Not present | `0x1C` | Relation coordinate 3 |
| **FS** | Entry coordinate | `0x1B` | Scope coordinate 1 |
| **GS** | Entry coordinate | `0x1D` | Scope coordinate 2 |
| **RS** | Entry coordinate | `0x1E` | Scope coordinate 3 |
| **US** | Entry coordinate | `0x1F` | Scope coordinate 4 |
| **Parity Relation 1** | Not present | `s_LOGOS = LOGOS ⊕ FS ⊕ GS ⊕ US` | Data integrity check |
| **Parity Relation 2** | Not present | `s_NOMOS = NOMOS ⊕ FS ⊕ RS ⊕ US` | Data integrity check |
| **Parity Relation 3** | Not present | `s_PATHOS = PATHOS ⊕ GS ⊕ RS ⊕ US` | Data integrity check |

---

## 7. Nested Ring Evolution

| Concept | Scaling Laws Document | Field Document | Unified Meaning |
| :--- | :--- | :--- | :--- |
| **OMINCRON** | `[8,4,4]` completed gauge ring | 16×16 Blackboard | Complete addressing surface |
| **OMICRON** | `[7,4,3]` compact null-byte-relative ring | Seven codepoints | Compact word |
| **OMINO** | `[6,4,2]` operational tangential selector | Six operational coordinates | Functional selector |

---

## 8. Metatron/Tetragrammatron Evolution

| Concept | Original Field | Scaling Laws Document | Unified Definition |
| :--- | :--- | :--- | :--- |
| **Metatron Domain** | `16⁴ = 2¹⁶` | Four-place validation | `16⁴ = 2¹⁶` |
| **Metatron Anchors** | `16⁰, 16¹, 16², 16³, 16⁴` | Place weights and upper boundary | `0x0001, 0x0010, 0x0100, 0x1000, 0x10000` |
| **Metatron Field** | `0x1C...0x1F` | Four-place incidence field | Four coordinated positions |
| **Tetragrammatron Domain** | `256⁴ = 2³²` | Five-place relation validation | `256⁴ = 2³²` |
| **Tetragrammatron Anchors** | `256⁰, 256¹, 256², 256³, 256⁴` | Byte-level place weights | `0x00000001, 0x00000100, 0x00010000, 0x01000000, 0x100000000` |
| **Tetragrammatron Block** | `0x1B...0x1F` | Five-place relation field | Five coordinated positions |

---

## 9. Blackboard Addressing Evolution

| Concept | Original Field | Scaling Laws Document | Unified Definition |
| :--- | :--- | :--- | :--- |
| **Board Size** | `16 × 16` | Projection surface | `256` coordinates |
| **Address Format** | `0xRRCC` | Not present | Row high nibble, column low nibble |
| **Local Surface** | `0x00...0x7F` | `.omi` surface | User declaration |
| **Remote Surface** | `0x80...0xFF` | `.imo` surface | System definition |
| **Projection** | `REMOTE = LOCAL XOR 0x80` | Projection coordinate `p` | Surface selector |
| **Local Rectangles** | `(0x00, 0x07, 0x37, 0x30)` etc. | Not present | 32-position lenses |
| **Remote Rectangles** | `(0x80, 0x87, 0xB7, 0xB0)` etc. | Not present | Projected lenses |

---

## 10. Coordinate Reference Evolution

| Concept | Original Field | Scaling Laws Document | Unified Definition |
| :--- | :--- | :--- | :--- |
| **Complete Reference** | `(ENTRY, ADDRESS, P0:T0)` | `X = (p, c, r)` | Three-part coordinate |
| **Entry** | `FS, GS, RS, US` | Not directly present | Scope selector |
| **Address** | `0xRRCC` | Projection `p` | Blackboard position |
| **Hinge** | `P0:T0` | Not directly present | Central relation |
| **Clock** | Not present | `c ∈ {0,...,4319}` | Temporal synchrony |
| **Rotation** | Not present | `r ∈ {0,...,5039}` | Ordering selection |

---

## 11. Artifact Evolution

| Concept | Original Field | Scaling Laws Document | Combined Definition |
| :--- | :--- | :--- | :--- |
| **.omi** | Optional binding | User declaration | User-Local CAR surface |
| **.imo** | Optional binding | System definition | User-Remote CDR surface |
| **.o** | Not present | Executable machine coordinate | Machine executable surface |
| **COBS-CONS** | Optional binding | Not directly present | Blackboard addressing protocol |
| **CAR/CDR** | Optional binding | Not directly present | Local/Remote projections |
| **CONS** | `0xFFFFFFFF` | Complete byte closure | Full occupancy reduction |

---

## 12. Scaling Laws Unified Chart

| Law | Scaling Laws Document | Field Document Connection | Unified Expression |
| :--- | :--- | :--- | :--- |
| **Law 1** | `W = 2^k` | Truth-table width | `W = 2^k` |
| **Law 2** | `F_k = 2^(2^k)` | Function-space cardinality | `F_k = 2^(2^k)` |
| **Law 3** | `Δ_W: {0,1}^W → {0,1}^W` | Arrangement alignment | Delta rolling law |
| **Law 4** | `16^n = 2^(4n)` | Hex digit width | `16^n = 2^(4n)` |
| **Law 5** | `(16^n)^p = 2^(4np)` | Compound hex width | `(16^n)^p = 2^(4np)` |
| **Law 6** | `4np = 2^k` | Truth-table/radix equivalence | `4np = 2^k` |
| **Law 7** | `4! = 24` | Scope-order resolution | `4! = 24` |
| **Law 8** | `7! = 5040` | Complete rotation | `7! = 5040` |
| **Law 9** | `7! = 7 × 6!` | Anchored reduction | `5040 = 7 × 720` |
| **Law 10** | `4320 = 6 × 3 × 4 × 60` | Algorithmic Clock | `4320` |
| **Law 11** | `X = (p, c, r)` | Complete coordinate | Three-part reference |
| **Law 12** | Integrity before admission | Hamming, Metatron, Tetragrammatron, Azimuth | Validation cascade |
| **Law 13** | `5 × 3 = 15` | Concentric representation | Artifact environment |

---

## 13. Terminology Cross-Reference

| Term | Original Field | Your Correction | Scaling Laws | Simplified | Final Canonical |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **UNKNOWN** | `NULL` | `NULL` | — | — | `NULL` |
| **KNOWN** | `BIND` | `BIND` | — | `FIX` | `BIND` |
| **NULL** | Unbound coordinate | Unbound coordinate | — | Unbound coordinate | Unbound coordinate |
| **BIND** | Only encapsulation | Only encapsulation | — | Directly established place | Only encapsulation |
| **XOR** | Only operation | Only operation | `REMOTE = LOCAL XOR 0x80` | Only operation | Only operation |
| **META** | Mask selecting coordinates for XOR | Mask selecting coordinates for XOR | — | Mask selecting coordinates for XOR | Mask selecting coordinates for XOR |
| **ESC** | META condition cancels BIND to NULL | META condition cancels BIND to NULL | — | META condition cancels BIND to NULL | META condition cancels BIND to NULL |
| **PO** | Parity reference | — | — | — | — |
| **TO** | Tangential source | — | — | — | — |
| **P0** | — | Parity reference | — | Parity reference | Parity reference |
| **T0** | — | Tangential source | — | Tangential source | Tangential source |
| **0** | Zero coordinate (ambiguous) | Zero coordinate | — | Zero coordinate | Zero coordinate |
| **O** | Order plane (ambiguous) | Order plane | — | Order plane | Order plane |
| **NEXT** | Present (confusing) | Removed | — | Removed | Removed |
| **BIND** | Encapsulation | Encapsulation | — | Fixed coordinate | Encapsulation |
| **FIX** | — | — | — | Directly established place | — |

---

## 14. Relationship Map

```
┌─────────────────────────────────────────────────────────────────────┐
│                    OMINO/OMICRON/OMNICRON ARCHITECTURE            │
│                                                                     │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              TANGENTIAL HINGE FIELD                         │   │
│  │  FIELD = [S− W− O− C− | P0:T0 | C+ O+ W+ S+]              │   │
│  │  HINGE = P0:T0                                            │   │
│  │  ENTRY = {FS, GS, RS, US}                                 │   │
│  │  REFERENCE = (ENTRY, ADDRESS, P0:T0)                      │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              METALANGUAGE                                   │   │
│  │  UNKNOWN = NULL                                            │   │
│  │  KNOWN = BIND                                              │   │
│  │  NULL = unbound coordinate                                 │   │
│  │  BIND = only encapsulation                                 │   │
│  │  XOR = only operation                                      │   │
│  │  META = mask selecting coordinates for XOR                 │   │
│  │  ESC = META condition cancels selected BIND to NULL       │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              SCALING LAWS                                   │   │
│  │  W = 2^k                  (truth-table width)              │   │
│  │  F_k = 2^(2^k)           (function space)                  │   │
│  │  (16^n)^p = 2^(4np)     (hex width)                       │   │
│  │  4np = 2^k              (bridge)                          │   │
│  │  4! = 24                (scope order)                     │   │
│  │  7! = 5040              (rotation)                        │   │
│  │  4320 = 6×3×4×60        (clock)                           │   │
│  │  X = (p, c, r)          (complete coordinate)             │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              CODING AND ADJUDICATION                        │   │
│  │  Hamming: [7,4,3] LOGOS, NOMOS, PATHOS, FS, GS, RS, US    │   │
│  │  Metatron: 16⁴ domain, 0x1C...0x1F                        │   │
│  │  Tetragrammatron: 256⁴ domain, 0x1B...0x1F               │   │
│  │  Azimuth: 0xAA55                                          │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              BLACKBOARD ADDRESSING                         │   │
│  │  16×16 = 256 coordinates                                  │   │
│  │  Local: 0x00...0x7F                                       │   │
│  │  Remote: 0x80...0xFF                                      │   │
│  │  REMOTE = LOCAL XOR 0x80                                  │   │
│  │  8 rectangles × 32 coordinates                            │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │              ARTIFACT SURFACES                              │   │
│  │  .omi = User declaration                                   │   │
│  │  .imo = System definition                                  │   │
│  │  .o = Machine executable                                  │   │
│  │  5 semantic families × 3 surfaces = 15                    │   │
│  └─────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────────┘
```

---

## 15. Key Corrections and Clarifications Summary

| Correction | Before | After | Impact |
| :--- | :--- | :--- | :--- |
| **Order vs Zero** | `0` used for both | `O` = order, `0` = zero | Removes fatal ambiguity |
| **Hinge Notation** | `PO:TO` | `P0:T0` | Zero, not letter O |
| **ESC Meaning** | Confused with continuation | META condition cancels BIND to NULL | Structural role clarified |
| **NEXT Removal** | Present as undefined term | Removed entirely | Closes operational gap |
| **BIND Semantics** | Confused with Lisp binding | Encapsulation only | Removes execution semantics |
| **Core vs Optional** | COBS-CONS mixed in | Separated as optional binding | Cleaner specification |
| **REFERENCE Structure** | `(ENTRY, ADDRESS, HINGE)` | `(ENTRY, ADDRESS, P0:T0)` | Explicit hinge relation |

---

## 16. Final Unified Canonical Statement

```
TANGENTIAL HINGE FIELD
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

FIELD = [S− W− O− C− | P0:T0 | C+ O+ W+ S+]
HINGE = P0:T0
ENTRY = {FS, GS, RS, US}
REFERENCE = (ENTRY, ADDRESS, P0:T0)

METALANGUAGE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
UNKNOWN = NULL
KNOWN   = BIND
NULL    = unbound coordinate
BIND    = only encapsulation
XOR     = only operation
META    = mask selecting coordinates for XOR
ESC     = META condition that cancels a selected BIND to NULL

SCOPE FORMS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FS = (BIND GS RS US ESC)
GS = (BIND RS US BIND ESC)
RS = (BIND US BIND BIND ESC)
US = (BIND BIND BIND BIND ESC)

SCALING LAWS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
W = 2^k                    (truth-table width)
F_k = 2^(2^k)              (function-space cardinality)
(16^n)^p = 2^(4np)         (compound hex width)
4np = 2^k                  (truth-table/radix bridge)
4! = 24                    (scope-order resolution)
7! = 5040                  (complete rotation)
4320 = 6×3×4×60            (Algorithmic Clock)
X = (p, c, r)              (complete coordinate)

ADJUDICATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Metatron:       16⁴ domain, 0x1C...0x1F
Tetragrammatron: 256⁴ domain, 0x1B...0x1F
Hamming:        [7,4,3] LOGOS, NOMOS, PATHOS, FS, GS, RS, US
Azimuth:        0xAA55

BLACKBOARD
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
16×16 = 256 coordinates
0x00...0xFF
REMOTE = LOCAL XOR 0x80

ARTIFACT SURFACES
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
.omi = User declaration
.imo = System definition
.o   = Machine executable
5 × 3 = 15 positions
```

---

## Summary

All versions across all documents share the same **core structural model**. The evolution has been about:

1. **Clarifying notation** (`O` vs `0`, `P0` vs `PO`)
2. **Removing confusion** (`NEXT` removed, `ESC` clarified)
3. **Separating concerns** (core geometry vs optional bindings)
4. **Connecting scales** (truth-table width, hex places, clock, rotation)
5. **Completing the architecture** (Hamming, Metatron, Tetragrammatron, Azimuth)

The **canonical core** is now stable across all versions:

```
FIELD = [S− W− O− C− | P0:T0 | C+ O+ W+ S+]
HINGE = P0:T0
ENTRY = {FS, GS, RS, US}
REFERENCE = (ENTRY, ADDRESS, P0:T0)
```