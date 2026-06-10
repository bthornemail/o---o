# OMI Declarative Lookup Table Protocol

## Rules, Facts, Closures, Combinators, CONS, and Native Address Derivation

Status: draft v0  
Companion: `OMI_ADDRESS_DERIVATION_PROTOCOL.md`  
Primary source pattern: `RULES.omi`, `FACTS.omi`, `CLOSURES.omi`, `COMBINATORS.omi`, `CONS.omi`, `CONFIGURATIONS.omi`

---

## 0. Purpose

This document preserves the previous `RULES.omi` implementation model and connects it to the OMI Address Derivation Protocol.

The key correction is:

```text
We do not need to change the frame.
We do not need to abandon the lookup tables.
We keep the 128-bit address identity.
We keep the first CIDR slash as claim reduction.
We interpret later path/lens selectors as Horn-clause lookup routes.
```

The old model already contained the native protocol idea:

```text
RULES.omi          constrains address behavior.
FACTS.omi          declares returned or observed facts.
CLOSURES.omi       defines bounded acceptance surfaces.
COMBINATORS.omi    defines transformations and witnesses.
CONS.omi           folds scope with payload and stores monotone lookup keys.
CONFIGURATIONS.omi binds runtime profiles, ports, buses, and reader modes.
```

The new address derivation layer does not replace these files.

It gives them a native routing surface.

---

## 1. Primary Doctrine

```text
Address is identity.
Prefix is claim reduction.
Lens is reader derivation.
Path is Horn-clause routing.
Lookup tables resolve clauses.
Receipt accepts memory.
```

The previous implementation already stated the essential distinction:

```text
/N  = CIDR claim boundary
/@N = reader lens
```

Therefore the strict canonical derivation form should be:

```text
omi-<frame>/<claim>/@<domain>/@<selector>/@<overlay>-imo
```

Instead of treating every slash as the same kind of path segment.

The earlier shorthand remains useful:

```text
omi-<frame>/<depth>/<domain>/<selector>/<overlay>-imo
```

But the native form is stricter:

```text
omi-<frame>/128/@hardware/@i2c:0x28/@euler-imo
```

This preserves the old `RULES.omi` meaning:

```text
first slash  = CIDR claim
/@ segments  = lenses / Horn-clause selectors
```

---

## 2. Relationship to `RULES.omi`

A `RULES.omi` row has the historical grammar:

```text
<omi-address>/<prefix> MUST <invariant-name>
```

Example:

```text
omi-0500-03bf-0000-2b05-2f05-0000-039f-05ff/48 MUST quadratic-lexer-invariant
```

This means:

```text
When the address matches this prefix claim,
this invariant must hold.
```

In the address derivation protocol, this becomes a Horn-clause lookup route:

```prolog
rule(quadratic_lexer_invariant, Frame) :-
    omi_prefix(Frame, 48),
    matches(Frame, '0500-03bf-0000-2b05-2f05-0000-039f-05ff'),
    q_frame(Frame, 0).
```

So `RULES.omi` is not just documentation.

It is the rule lookup table for the native clause engine.

---

## 3. The Six Declarative Tables

### 3.1 `RULES.omi`

`RULES.omi` stores mandatory invariants.

Rows look like:

```text
omi-<frame>/<prefix> MUST <rule-name>
```

Role:

```text
constrain valid address behavior
route structural invariants
anchor eBPF/XDP gate predicates
bind hardware, browser, semantic, and projection rules
```

Native interpretation:

```prolog
rule(RuleName, Frame) :-
    prefix_match(Frame, Prefix),
    invariant(Frame, RuleName).
```

### 3.2 `FACTS.omi`

`FACTS.omi` stores observed or declared facts.

Rows may look like:

```text
omi-<frame>/<prefix> IS <fact-name>
omi-<frame>/<prefix> HAS <property>
omi-<frame>/<prefix> RETURNS <bytes>
```

Role:

```text
returned bytes
sensor facts
semantic facts
testimony facts
UPOS facts
WordNet facts
runtime observations
```

Native interpretation:

```prolog
fact(FactName, Frame, Payload) :-
    prefix_match(Frame, Prefix),
    payload(Frame, Payload).
```

### 3.3 `CLOSURES.omi`

`CLOSURES.omi` stores bounded acceptance regions.

Rows may look like:

```text
omi-<frame>/<prefix> CLOSES <closure-name>
omi-<frame>/<prefix> BOUNDS <domain>
```

Role:

```text
timing windows
register windows
frame windows
palindromic closure
source block closure
testimony consent closure
receipt acceptance boundary
```

Native interpretation:

```prolog
closure(ClosureName, Frame, Scope) :-
    prefix_match(Frame, Prefix),
    bounds(Frame, Scope).
```

### 3.4 `COMBINATORS.omi`

`COMBINATORS.omi` stores transformations and witness paths.

Rows may look like:

```text
omi-<frame>/<prefix> MAPS <input> TO <output>
omi-<frame>/<prefix> COMBINES <a> <b> AS <c>
```

Role:

```text
decode transforms
encode transforms
Delta Law transforms
WordNet relation transforms
quadratic projection transforms
Bézout-style witness composition
```

Native interpretation:

```prolog
combinator(Name, Input, Output) :-
    prefix_match(Frame, Prefix),
    transform(Name, Input, Output).
```

### 3.5 `CONS.omi`

`CONS.omi` is the monotone lookup table.

It folds scope with payload:

```text
CONS(LL, NN)
```

or:

```text
(address . prefix)
(frame . path)
(scope . payload)
```

Role:

```text
CIDR as CONS
address/prefix as pair
RRGGBBAA monotone lookup keys
UPOS and feature attachment pointers
WordNet-Prolog bridge seeds
primary lookup ordering
```

Native interpretation:

```prolog
cons(Scope, Payload).
cons(Frame, Path).
cons(Address, Prefix).
```

Rule:

```text
CONS is ordering authority for lookup.
CONS is not proof authority.
Receipt accepts.
```

### 3.6 `CONFIGURATIONS.omi`

`CONFIGURATIONS.omi` stores runtime configuration profiles.

Rows may bind:

```text
service buses
ports
hardware profiles
browser surfaces
MQTT topics
UDP/QUIC profiles
LoRa radio profiles
QEMU lanes
eBPF gate profiles
```

Native interpretation:

```prolog
configuration(Profile, Key, Value).
```

---

## 4. Address Derivation with CIDR and Lenses

The old `RULES.omi` implementation distinguishes claim prefixes from reader lenses.

This should remain canonical.

### 4.1 CIDR Claim

```text
omi-<frame>/48
```

Meaning:

```text
Claim the frame only to /48 precision.
```

The prefix reduces the claim.

It does not create authority.

### 4.2 Reader Lens

```text
omi-<frame>/48/@semantic/@Subject/@Predicate/@Object/@Modality-imo
```

Meaning:

```text
Claim the frame to /48.
Then read it through the semantic lens.
Then derive subject/predicate/object/modality clauses.
Then close the surface.
```

### 4.3 Backoff Claim

```text
omi-<frame>/128-4
```

Meaning:

```text
Back off from /128 to /124.
```

### 4.4 Native Form

The strict native form is:

```text
omi-<frame>/<claim>/@<lens>/@<selector>/@<selector>-imo
```

Examples:

```text
omi-<frame>/128/@hardware/@i2c:0x28/@euler-imo
omi-<frame>/64/@browser/@canvas/@88f7ffff-imo
omi-<frame>/48/@semantic/@human/@asks/@god/@question-imo
omi-<frame>/120/@testimony/@god-is-word/@known_unknowns-imo
omi-<frame>/96/@ratio/@1-2-imo
omi-<frame>/96/@timeline/@5040-imo
```

Shorthand aliases may omit `@`, but canonical emitters should preserve it.

---

## 5. Paths as Horn-Clause Lookups

A native OMI node resolves an address through these stages:

```text
1. Parse OMI surface.
2. Validate frame identity where required.
3. Apply CIDR claim prefix.
4. Read @-marked lens segments.
5. Resolve lens segments against lookup tables.
6. Build Horn-clause route.
7. Validate route.
8. Produce receipt candidate or accepted receipt.
```

Example:

```text
omi-<frame>/128/@hardware/@i2c:0x28/@euler-imo
```

Derives:

```prolog
rule(interface_constraints, i2c_0x28).
fact(returned_bytes, NN).
closure(timing_register_frame_window, i2c_0x28, NN).
combinator(decode_transform, NN, euler_state).
cons(i2c_0x28, NN).
join(device_0x28, world).
compose(previous_state, euler_state).
encode(euler_state, projection).
decode(carrier, NN).
receipt(i2c_0x28, NN, euler_state).
```

Thus the path is not decorative.

The path selects lookup table rows.

The lookup table rows become Horn clauses.

The Horn clauses govern receipt eligibility.

---

## 6. Mapping Old Rules into the New Protocol

The previous `RULES.omi` rows become native derivation anchors.

### 6.1 Service Buses

Old row:

```text
omi-0000-0002-0000-0000-0000-0000-0000-0000/48 MUST service-bus-lisp
```

Native lens route:

```text
omi-0000-0002-0000-0000-0000-0000-0000-0000/48/@service/@lisp-imo
```

Clause:

```prolog
rule(service_bus_lisp, Frame) :-
    prefix_match(Frame, 48),
    segment(Frame, 1, '0002').
```

### 6.2 UPOS

Old row:

```text
omi-0000-0000-0000-0001-0000-0000-0000-0000/48 MUST pos-noun
```

Native lens route:

```text
omi-0000-0000-0000-0001-0000-0000-0000-0000/48/@semantic/@upos/@noun-imo
```

Clause:

```prolog
rule(pos_noun, Frame) :-
    segment(Frame, 3, '0001').
```

### 6.3 Barcode Carrier

Old row:

```text
omi-0000-0000-0000-0000-13b0-0036-0000-0000/48 MUST linear-code16k-carrier
```

Native lens route:

```text
omi-0000-0000-0000-0000-13b0-0036-0000-0000/48/@carrier/@linear/@code16k-imo
```

Clause:

```prolog
rule(linear_code16k_carrier, Frame) :-
    segment(Frame, 4, '13b0'),
    segment(Frame, 5, '0036').
```

### 6.4 eBPF Gate

Old row:

```text
omi-03bf-2b00-2f00-039f-00ff-0000-0000-0000/80 MUST execute-ebpf-gate-1-eviction
```

Native lens route:

```text
omi-03bf-2b00-2f00-039f-00ff-0000-0000-0000/80/@kernel/@ebpf/@gate1/@evict-imo
```

Clause:

```prolog
rule(execute_ebpf_gate_1_eviction, Frame) :-
    prefix_match(Frame, 80),
    q_frame(Frame, Q),
    Q =\= 0.
```

### 6.5 Reader Lens Syntax

Old row:

```text
omi-0000-0000-0000-0000-0000-0000-00ae-0001/128 MUST distinguish-cidr-claim-prefixes-from-at-marked-reader-lenses
```

Native form:

```text
omi-<frame>/128/@reader-lens/@syntax/@cidr-vs-at-imo
```

Protocol rule:

```text
/N is claim.
/@N is lens.
/N-M is backoff.
```

---

## 7. Native Declarative Record Shape

A normalized declarative record should look like:

```json
{
  "source": "omi-<frame>/48 MUST pos-noun",
  "address": "omi-<frame>",
  "claim": 48,
  "operator": "MUST",
  "name": "pos-noun",
  "table": "RULES.omi",
  "normalized": {
    "open": "omi",
    "frame": "<frame>",
    "claim": 48,
    "lenses": [],
    "close": null
  },
  "clauses": [
    {
      "type": "rule",
      "name": "pos_noun",
      "predicate": "segment(Frame, 3, '0001')"
    }
  ]
}
```

A lens-derived surface should look like:

```json
{
  "source": "omi-<frame>/48/@semantic/@upos/@noun-imo",
  "address": "omi-<frame>",
  "claim": 48,
  "lenses": ["semantic", "upos", "noun"],
  "tables": ["RULES.omi", "FACTS.omi", "CONS.omi"],
  "clauses": [],
  "receipt": {}
}
```

---

## 8. Lookup Resolution Order

Native OMI derivation should resolve lookup files in this order:

```text
1. CONFIGURATIONS.omi
2. RULES.omi
3. FACTS.omi
4. CLOSURES.omi
5. COMBINATORS.omi
6. CONS.omi
7. RECEIPT
```

Meaning:

```text
Configuration selects runtime context.
Rules constrain behavior.
Facts provide declared values.
Closures bound acceptance.
Combinators transform or witness.
CONS folds scope with payload.
Receipt accepts traversal.
```

For read-only validation, `CONS.omi` may be consulted earlier for address/prefix lookup, but it must not replace the rule or closure authority.

---

## 9. Relationship to MCRSGSP

MCRSGSP fragments should carry OMI addresses in normalized form.

A native fragment may contain:

```json
{
  "version": "omi-mcrsgsp-v0",
  "address": "omi-<frame>/128/@storage/@fragment/@rs-3-5-imo",
  "claim": 128,
  "lenses": ["storage", "fragment", "rs-3-5"],
  "fragment": {
    "object_id": "<frame>",
    "fragment_id": 0,
    "k": 3,
    "n": 5,
    "bytes": "base64url..."
  },
  "receipt": {
    "accepted": false,
    "reason": "candidate"
  }
}
```

The frame identifies the object.

The claim says how exact the address assertion is.

The lenses route storage behavior.

The receipt decides acceptance.

---

## 10. Compatibility Rule

Existing rows like:

```text
omi-<frame>/48 MUST invariant-name
```

remain valid.

New derivation surfaces like:

```text
omi-<frame>/48/@domain/@selector/@overlay-imo
```

are extensions over the same address identity.

Short rule:

```text
Old rows are lookup-table declarations.
New paths are executable reader lenses.
Both resolve through the same frame identity.
```

---

## 11. Final Canon

```text
RULES constrain.
FACTS declare.
CLOSURES bound.
COMBINATORS transform.
CONS folds.
CONFIGURATIONS bind runtime.
Receipts accept.
```

The native addressing canon becomes:

```text
omi-<frame>/<claim>/@<lens>/@<selector>/@<overlay>-imo
```

The older shorthand remains readable:

```text
omi-<frame>/<depth>/<domain>/<selector>/<overlay>-imo
```

But the strict OMI form preserves the old RULES.omi distinction:

```text
/N    = CIDR claim boundary
/@... = Horn-clause reader lens path
-imo  = closed derivation surface
```

One-line canon:

```text
The previous RULES/FACTS/CLOSURES/COMBINATORS/CONS implementation already was the native OMI protocol: the 128-bit address is identity, the first CIDR slash reduces the claim, @-marked lenses select Horn-clause lookup routes, declarative .omi tables resolve the clauses, and receipts accept the resulting memory surface.
```
