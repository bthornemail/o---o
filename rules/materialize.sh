#!/bin/sh
set -eu

ENVELOPE=${1:?usage: rules/materialize.sh receipts/<receipt>.json}
REGISTRY=${OMI_RULE_REGISTRY:-rules/registry.json}

slot=$(sed -n 's/.*"rule_slot": "\(0x[0-9A-Fa-f][0-9A-Fa-f]\)".*/\1/p' "$ENVELOPE")

[ -n "$slot" ] || {
  printf 'materializer rejected: missing rule_slot\n' >&2
  exit 1
}

slot_hex=$(printf '%s' "$slot" | sed 's/^0[xX]//; y/abcdef/ABCDEF/')
slot=0x$slot_hex

module=$(awk -v slot="$slot" '
  $0 ~ "\"" slot "\"" { in_block = 1; next }
  in_block && /"module"/ {
    line = $0
    sub(/.*"module"[[:space:]]*:[[:space:]]*"/, "", line)
    sub(/".*/, "", line)
    print line
    exit
  }
' "$REGISTRY")

[ -n "$module" ] || {
  printf 'materializer rejected: unknown rule_slot %s\n' "$slot" >&2
  exit 1
}

[ -f "$module" ] || {
  printf 'materializer rejected: module not found: %s\n' "$module" >&2
  exit 1
}

sh "$module" "$ENVELOPE"
