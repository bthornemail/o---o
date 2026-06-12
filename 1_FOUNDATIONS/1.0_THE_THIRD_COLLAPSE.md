# The Third Collapse: Notation as Cipher

This document is the philosophical entry point to OMI. It derives directly from the MANIFESTO.md and should be read after the manifesto but before the rest of 1_FOUNDATIONS.

## Computation Is Not Mutation

OMI begins with a single claim:

> Computation is not the mutation of data.
> Computation is the lawful transformation of interpretation.

The binary source remains. The reading changes. The rewrite is the computation.

Most systems ask: "What value is stored here?" OMI asks: "What lawful transformation is declared here?"

## The Three Collapses

Every major computing paradigm begins by collapsing a boundary that once seemed natural.

### Lisp collapsed program and object.

```text
code ↔ data
```

An S-expression can be read as structure, stored as data, or evaluated as program. Lisp showed that code and data could share one form.

### POSIX collapsed storage and communication.

```text
storage ↔ communication
```

A file descriptor can point to a disk file, a terminal, a pipe, or a network socket. POSIX showed that files, pipes, sockets, and devices could share one interface.

### OMI collapses representation and interpretation.

```text
representation ↔ interpretation
notation ↔ cipher
```

OMI shows that notation and cipher can share one surface. The same binary source can be read as text, address, proof, graph, route, receipt, or rewrite table depending on the declared interpretation.

This is the OMI collapse.

## Notation as Cipher

A cipher is usually understood as a method for hiding meaning. OMI uses cipher differently.

In OMI, a cipher does not hide meaning. A cipher declares meaning.

A notation is a cipher because it tells the reader how to interpret the same surface. A cipher is notation because it defines the rules by which a surface becomes readable.

```text
notation as cipher
cipher as notation
```

This is not secrecy. This is interpretation.

## OMI Is Not a Database

A database says:

```text
address → stored value
```

OMI says:

```text
source of truth → rewrite surface → routed interpretation → receipt
```

OMI does not begin with stored data. OMI begins with a versioned binary source of truth. That source is loaded as a rewrite table. The table is not meaningful by itself. Meaning appears only when a lawful notation-cipher is declared.

## OMI Is a Rewrite Register

OMI is better understood as a rewrite register.

A rewrite register does not ask:

```text
What value is stored here?
```

It asks:

```text
What lawful transformation is declared here?
```

The primitive object is not a row in a database. The primitive object is a transition. The unit is not data. The unit is a bitblip: a small binary transition inside a rotating rewrite surface.

## The Binary Source Remains

In ordinary computation, we say the data changes. In OMI, the source may remain unchanged. What changes is the reading.

The same binary surface may be interpreted as:

```text
text
address
instruction
proof
receipt
graph
route
nomogram
rewrite table
```

The bits remain. The interpretation rotates.

## Manifesto Source

This document summarizes sections 1--5 and 18--19 of [MANIFESTO.md](../MANIFESTO.md). The full manifesto is the authoritative lens for all OMI documentation.

See also:

- [1.1 The Palindrome](1.1_THE_PALINDROME.md) -- how the palindrome embodies notation as cipher
- [1.4 The OMI Universal Constant](1.4_THE_OMI_UNIVERSAL_CONSTANT.md) -- the zero-point of bounded agreement
- [7.1 Agreement Doctrine](../7_CANON/7.1_AGREEMENT_DOCTRINE.md) -- how agreement becomes structural
