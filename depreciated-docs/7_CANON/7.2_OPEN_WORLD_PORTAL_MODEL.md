# Open-World Portal Model

An OMI open-world portal is a normal-looking web application that displays decentralized objects without making the portal itself the authority.

The user sees:

```text
cards
profiles
events
maps
posts
notes
files
routes
products
services
receipts
comments
local groups
```

The OMI layer sees:

```text
validated frames
addressed payloads
source/object relations
linear replay streams
hierarchical containment trees
graph links
receipt rows
carrier projections
```

## Consumer Promise

```text
One object.
Many portals.
Inspectable history.
Portable context.
Validation before projection.
Agreement without platform lock-in.
```

## Portal Flow

```text
consumer action
  -> portal UI
  -> object projection
  -> OMI frame / object address
  -> Q_frame validation
  -> truth-row resolution
  -> receipt write
  -> linear replay stream
  -> hierarchical containment tree
  -> portable carrier output
```

The portal should hide protocol complexity until inspection is requested. Power users must still be able to verify, export, mirror, and replay objects without depending on a single platform.

## Two Core Views

Every portal object should be inspectable in two basic forms.

| View | Consumer Question | Canonical Meaning |
|------|-------------------|-------------------|
| Linear | What happened? | Replay/source-object order |
| Hierarchical | Where does it belong? | Scope and containment order |

Linear view:

```text
omi -> payload -> imo
```

Hierarchical view:

```text
FS -> GS -> RS -> US
```

Both are projections. Neither validates the object.

## Carrier Surfaces

The same accepted object may be projected as:

```text
web card
map pin
JSON Canvas node
QR code
SVG badge
ShadowDOM widget
local file
mesh message
receipt row
timeline event
```

The carrier is not the source. The rendered view is not the proof.

## Trust Labels

A consumer portal may translate protocol state into plain labels:

```text
Accepted
Unverified
Conflicting
Expired
Mirrored
Local-only
Rejected
Replayed
```

The label is only an interface summary. The receipt chain remains the inspectable evidence.

## Safety

Open world does not mean unsafe world. Portal surfaces should default to:

```text
read-only projection first
interaction second
execution last
```

Safety requirements:

```text
sanitize innerHTML
sandbox iframe-like portals
isolate ShadowDOM widgets
separate display from validation
mark unknown sources
show unverified objects
block unsafe scripts
preserve receipt inspection
```

## Minimal Portal Canon

```text
An open-world portal does not own truth.
It projects accepted objects.

An object is accepted when its frame validates,
its truth row resolves,
and its receipt can be replayed.

A user trusts the portal not because the portal says so,
but because the object can be inspected.

Linear projection shows how the object moved.
Hierarchical projection shows where the object belongs.
Receipts show why the object was accepted.
```
