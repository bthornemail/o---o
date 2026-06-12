# OMI Matrix Lookup Test Plan

Status: draft v0

This test plan promotes an already-working GPIO/message/QEMU/eBPF route into the refined native OMI address derivation model.

The old proof was:

```text
GPIO → address → message → route
```

The refined proof is:

```text
GPIO → omi-<frame>/128/@hardware/@esp32-s3/@gpio/@edge-imo
     → RULES/FACTS/CLOSURES/COMBINATORS/CONS lookup
     → receipt
     → OMI Matrix projection
     → QEMU/eBPF parity
```

## 1. Acceptance doctrine

```text
ESP32 declares.
QEMU reproduces.
Node validates.
eBPF enforces.
Lookup tables derive.
Receipt accepts.
OMI Matrix projects.
```

## 2. Core address under test

```text
omi-0100-03bf-0001-2b01-2f01-0000-039f-01ff/128/@hardware/@esp32-s3/@gpio/@edge-imo
```

Expected normalized form:

```json
{
  "frame": "0100-03bf-0001-2b01-2f01-0000-039f-01ff",
  "claim": 128,
  "lenses": ["hardware", "esp32-s3", "gpio", "edge"],
  "close": "imo"
}
```

## 3. Lookup reduction test

Given the address above, a resolver should find:

```text
RULES       accept-esp32-s3-gpio-edge-declaration
FACTS       esp32-s3-gpio-edge-observed
CLOSURES    gpio-debounce-window
COMBINATORS decode-returned-gpio-level-to-edge-state
CONS        esp32-s3-gpio-edge
```

## 4. Rewrite route test

The route should reduce as:

```text
DECODE carrier AS returned-gpio-level
MAPS returned-gpio-level TO edge-state
JOIN device WITH world AS device-world
COMPOSE previous-state WITH edge-state AS receipt-candidate
ENCODE edge-state AS omi-matrix-projection
```

## 5. Bitboard / bitblit test

The route should export an inspection bitboard:

```text
0100.03bf.0001.2b01.2f01.0000.039f.01ff
```

and map it to:

```text
hex-inspector → OMI Matrix projection
```

The bitboard and bitblit exports are inspection surfaces only. They do not create validity or acceptance.

## 6. QEMU parity test

QEMU raw binary, QEMU system mode, or QEMU user mode should emit or validate the same frame identity:

```text
0100-03bf-0001-2b01-2f01-0000-039f-01ff
```

Expected:

```json
{
  "esp32_frame": "0100-03bf-0001-2b01-2f01-0000-039f-01ff",
  "qemu_frame": "0100-03bf-0001-2b01-2f01-0000-039f-01ff",
  "same_identity": true,
  "different_provenance": true,
  "same_rule_family": true
}
```

## 7. eBPF parity test

User-space validation and eBPF/XDP validation should agree:

```text
valid GPIO frame       → PASS / accepted candidate
malformed delimiter    → DROP / rejected
wrong LL coherence     → DROP / rejected
byte-swapped frame     → DROP / orientation failure
```

## 8. Receipt test

A valid route should produce a receipt candidate with:

```json
{
  "address": "omi-0100-03bf-0001-2b01-2f01-0000-039f-01ff/128/@hardware/@esp32-s3/@gpio/@edge-imo",
  "frame": "0100-03bf-0001-2b01-2f01-0000-039f-01ff",
  "claim": 128,
  "lenses": ["hardware", "esp32-s3", "gpio", "edge"],
  "rule": "accept-esp32-s3-gpio-edge-declaration",
  "fact": "esp32-s3-gpio-edge-observed",
  "closure": "gpio-debounce-window",
  "receipt": "accepted-memory-candidate"
}
```

## 9. Final pass condition

The seed passes when:

```text
1. The address parses.
2. The claim/lens distinction is preserved.
3. The lookup tables resolve.
4. The rewrite route reduces.
5. The receipt candidate is emitted.
6. The bitboard exports to OMI Matrix.
7. QEMU reproduces the same frame identity.
8. eBPF and user-space agree on pass/drop.
```

One-line test canon:

```text
Do not retest that GPIO can send a message; test that a GPIO message can become an OMI-native derivation surface that resolves through declarative lookup tables into a receipt and OMI Matrix projection.
```
