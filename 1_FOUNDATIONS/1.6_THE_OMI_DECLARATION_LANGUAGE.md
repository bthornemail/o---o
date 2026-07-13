# The OMI Declaration Language

## Source and Object Split

OMI declarations exist in two forms:

| Form | Extension | Role | Audience |
|---|---|---|---|
| Source | `.omi` | readable declaration | human authoring, inspection |
| Object | `.imo` | compiled native object | runtime, kernel, projection |

The source form is meant to be authored and inspected. The object form is meant to be executed and projected. The compile step transforms one into the other:

```text
.omi → .imo
source → object
readable → native
```

This split preserves the distinction between declaration and runtime state. Source files are not themselves authority — they are inputs to compilation. Object files are not themselves truth — they require validation through the agreement pipeline.

---

## The Five Declaration Files

OMI organizes declarations into five files by role:

| File | Keyword | Role |
|---|---|---|
| RULES.omi | MUST | normative obligations |
| FACTS.omi | FACT | grounded implementation |
| CLOSURES.omi | CLOSE | bounded completion |
| COMBINATORS.omi | COMBINE | lawful composition |
| CONS.omi | CONS | pair reduction |

Each file uses the same core grammar with a distinct keyword. The grammar is:

```text
<omi-address>/<prefix> <keyword> <assignment>
```

### RULES.omi

Declares what must be true:

```text
<address>/<prefix> MUST <invariant-name>
```

A rule does not claim implementation, test coverage, or deployment. It states an obligation.

### FACTS.omi

Declares what has been done:

```text
<address>/<prefix> FACT <fact-name>
```

A fact grounds a rule by pointing to an implementation, a test, or a projection. It does not create new obligations.

### CLOSURES.omi

Declares what is bounded:

```text
<address>/<prefix> CLOSE <closure-name>
```

A closure seals a structure as complete. It enables WLOG-safe reasoning — without closure, generalization is not permitted.

### COMBINATORS.omi

Declares lawful transformations:

```text
<address>/<prefix> COMBINE <combinator-name>
```

A combinator defines how inputs map to outputs. Combinators compose without validating frames.

### CONS.omi

Declares pair structure:

```text
<address>/<prefix> CONS <cons-name>
```

Cons records define pairing, nesting, dot notation, and mnemonic forms. They describe how addressed structure is assembled.

---

## O-Expressions

An O-expression is an addressed declaration inside a source block. The basic form is a cons pair:

```text
(key . value)
```

An association list is a sequence of pairs:

```text
((key1 . value1)
 (key2 . value2))
```

O-expressions are not Lisp expressions:

```text
Lisp expressions compute.
O-expressions declare addressed structure.
```

O-expressions are unevaluated by default. A parser preserves the form. A later compile phase lowers the form into lookup tables, maps, or native object structure.

---

## Source Blocks

A declaration may carry a source block:

```text
<address>/<prefix> <keyword> <assignment>

omi-
  <body>
-imo
```

The source block is not the same as the palindromic token `omi---imo`:

```text
omi-   source block opener
-imo   source block closer
omi---imo  palindromic mnemonic token (distinct concept)
```

The source block carries the declaration body. The body may contain O-expressions, lookup tables, rewrite pairs, or closure bodies.

---

## Authority Boundary

OMI defines a strict separation between validation, expression, and projection:

```text
Q_frame(S) validates the frame.
Omilog expresses the declaration body.
Q_xy(x,y) projects decoded state into geometry.
```

No expression level may override a lower level:

```text
No projection without validation.
No expression without address.
No WLOG without closure.
```

Forbidden authority collapses:

```text
emoji validates frame
hyphen count validates frame
dot notation validates frame
source block validates frame
color validates frame
```

Allowed uses:

```text
emoji carries symbolic state
hyphen count hints scale
dot notation declares structure
source block carries lookup body
color projects state
```

---

## WLOG-Safe Rewrites

A rewrite pair is a local transformation:

```text
(omi-🛹 . omi-🏷️)
```

A rewrite table is a declared set of mappings:

```text
(rewrite . '((omi-🛹 . omi-🏷️)))
```

A rewrite is **WLOG-safe** only when accompanied by a closure proving symmetry:

```text
WLOG requires symmetry closure.
```

Without a closure, a rewrite is local — it applies only to the stated case. With a closure, a rewrite may generalize across the proven symmetry class.

---

## Prefix Cascade Resolution

OMI declarations are resolved by prefix specificity:

```text
/128 > /112 > /96 > /64 > /48 > default
```

A more specific address overrides or refines a broader one. This mirrors CSS specificity:

```text
CSS:  id > class > element
OMI:  /128 > /112 > /96 > /64 > /48 > default
```

---

## Canonical Rules

```text
O-expression declares addressed structure.
Source block carries declaration body.
.omi is readable source.
.imo is compiled object.
Q_frame validates.
WLOG requires closure.
Prefix resolves by specificity.
```

---

See also: [1.1 The Palindrome](1.1_THE_PALINDROME.md), [4.2 RULES.omi](../4_NETWORK/4.2_RULES_OMI.md), [7.5 Rule-to-Fact Derivation](../7_CANON/7.5_RULE_TO_FACT_DERIVATION.md), [7.6 Agreement Operators](../7_CANON/7.6_AGREEMENT_OPERATORS.md)
