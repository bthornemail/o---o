# Implementation Surfaces

## Relationship Between `o---o` and `omi-portal`

This repository, `o---o`, is the abstract OMI documentation and protocol surface.

The companion implementation repository, `omi-portal`, is the collaboration application surface.

The boundary is:

```text
o---o      = abstract protocol / documentation / derivation surface
omi-portal = implementation / collaboration application surface
```

Short doctrine:

```text
o---o defines the doctrine.
omi-portal proves the doctrine.
```

---

## 1. Role of `o---o`

`o---o` asks:

```text
What is the OMI protocol?
```

It is the place for:

```text
canonical doctrine
address grammar
Horn-clause derivation model
schema definitions
protocol architecture
document-based collaboration
abstract memory surfaces
self-enclosed omi---imo documents
```

Examples of `o---o` artifacts:

```text
OMI_ADDRESS_DERIVATION_PROTOCOL.md
OMI_DECLARATIVE_LOOKUP_TABLE_PROTOCOL.md
schemas/
canonical protocol notes
abstract derivation records
```

The purpose of `o---o` is to make the protocol inspectable, forkable, teachable, and documentable before it becomes only an application.

---

## 2. Role of `omi-portal`

`omi-portal` asks:

```text
How do people collaborate through OMI?
```

It is the place for:

```text
browser surfaces
object inbox
request-for-collaboration UI
runtime kernels
RULES.omi
FACTS.omi
CLOSURES.omi
COMBINATORS.omi
CONS.omi
CONFIGURATIONS.omi
SSE/WebSocket/MQTT bridges
ESP32, QEMU, x86_64, and browser target implementations
tests, fixtures, telemetry, receipts, and projections
```

The purpose of `omi-portal` is to make the protocol usable by people as a collaboration machine.

---

## 3. Boundary Rule

The two repositories must not collapse into each other.

```text
The documentation repo defines the protocol.
The portal repo instantiates the protocol.
Neither replaces the other.
```

`o---o` should not become the main runtime application.

`omi-portal` should not become an unstructured transcript archive.

Instead:

```text
o---o keeps the abstract surface clean.
omi-portal keeps the implementation surface executable.
```

---

## 4. Declarative Lookup Table Bridge

The bridge between the repositories is the OMI declarative lookup table model:

```text
RULES constrain.
FACTS declare.
CLOSURES bound.
COMBINATORS transform.
CONS folds.
CONFIGURATIONS bind runtime.
Receipts accept.
```

In `o---o`, this is described as protocol doctrine.

In `omi-portal`, this is implemented as working files and runtime behavior.

The address derivation protocol gives both repositories the same grammar:

```text
omi-<frame>/<claim>/@<lens>/@<selector>/@<overlay>-imo
```

Meaning:

```text
frame = identity
claim = CIDR claim reduction
@ lens path = Horn-clause derivation route
-imo = closed derivation surface
```

---

## 5. Collaboration Surface Relationship

`o---o` supports document-based collaboration.

`omi-portal` supports application-based collaboration.

Document collaboration means:

```text
people can inspect, edit, fork, and refine the protocol itself
```

Application collaboration means:

```text
people can submit, inspect, route, accept, export, and replay OMI objects through a working surface
```

Together:

```text
o---o is the abstract self-enclosed OMI document surface.
omi-portal is the public collaboration application surface.
```

---

## 6. Non-Collapse Doctrine

```text
Projection is not authority.
Implementation is not doctrine.
Doctrine is not proof.
Proof is not collaboration.
Collaboration is not possession.
Receipt accepts.
```

`o---o` may define a rule.

`omi-portal` must prove it through executable implementation, tests, projections, and receipts.

`omi-portal` may reveal new implementation facts.

`o---o` may later absorb those facts as doctrine only after they are named, bounded, and reduced into canonical documents.

---

## 7. Canonical Repo Map

```text
o---o
  abstract protocol
  derivation grammar
  schemas
  documentation surfaces
  document collaboration

omi-portal
  concrete implementation
  object inbox
  browser surfaces
  runtime kernels
  lookup tables
  live collaboration
```

One-line canon:

```text
o---o is the abstract OMI memory/protocol book; omi-portal is the living OMI collaboration machine.
```
