# Projective Closure and the Empty List Principle

## The Projective Closure

A finite row is not merely a line. When rolled, it becomes a projective closure.

For a 4-bit wheel:

```text
2^4 = 16
```

OMI reads this as:

```text
15 active states
1 closure state
```

This is the **15-of-16 principle**.

For an 8-state wheel:

```text
2^3 = 8
```

OMI reads this as:

```text
7 active states
1 closure state
```

This is the **7-of-8 principle** (which maps to the Fano plane's 7 points, 7 lines).

The missing state is not lost. It is the projective center.

### Why This Matters

In ordinary binary representation, every bit pattern is a valid value. In OMI, one state in every bounded wheel is reserved as the closure state -- the projective center that makes the wheel a closed surface rather than a linear range.

This closure state is not a value. It is the condition of boundedness. It is what lets a finite register say: "I am not infinite. I have an edge, and that edge returns through the center."

### The 15-of-16 Canon

```text
A 4-bit wheel has 16 states.
15 are active.
1 is the projective center.
The center is not a value.
The center is the closure of the surface.
```

### The 7-of-8 Canon

```text
An 8-state wheel has 8 states.
7 are active.
1 is the projective center.
The Fano plane selects among the 7 active points.
The 8th point closes the projective surface.
```

## The Empty List Principle

Lisp reveals a deep computational truth:

```lisp
()
```

is both an atom and a list.

OMI treats closure the same way. The closure state is both:

```text
a point
and
a space
```

It is origin and container. It is empty and structural.

### () as Both Atom and List

In Lisp, the empty list is not merely a list with no elements. It is also an atom. It terminates every proper list. It is the identity element for `append`. It is the seed of structure.

OMI reads this principle into its own closure:

```text
The closure state of a projective wheel is both:
  a point (one state among many)
  a space (the center that makes the surface closed)

It is the origin of the wheel.
It is the container of the wheel.
```

### Why This Is Necessary

Without the empty list principle, every register would need an explicit sentinel value, creating a two-register problem (one for the value, one for the sentinel). OMI avoids this by treating closure as a structural property of the wheel itself.

```text
The wheel is bounded because it has a center.
The center is not a value.
The center is the closure state.
```

### Canonical Form

```text
()  =  the empty enclosure
()  =  both origin and container
()  =  the projective center of any OMI wheel
0!  =  ()  =  omi---imo
```

The zero-point `Ω₀ = 0! = omi---imo` is the empty list principle applied to the whole OMI frame: one bounded relation that is both origin and container.

## Rotation Preserves Closure

The Delta Law's use of rotations (not shifts) is the operational expression of projective closure:

```text
rotl(x, 1) XOR rotl(x, 3) XOR rotr(x, 2) XOR C
```

Rotations preserve all bits. Nothing falls off the edge. The edge returns through the orbit. The missing state is not lost -- it is the projective center that every orbit circles around.

## Source

This document derives from sections 11 and 12 of [MANIFESTO.md](../MANIFESTO.md).

See also:

- [2.2 The Delta Law](2.2_THE_DELTA_LAW.md) -- period-8 rotation preserves closure
- [1.4 The OMI Universal Constant](../1_FOUNDATIONS/1.4_THE_OMI_UNIVERSAL_CONSTANT.md) -- the zero-point as empty closure
- [1.1 The Palindrome](../1_FOUNDATIONS/1.1_THE_PALINDROME.md) -- the palindrome as bounded enclosure
