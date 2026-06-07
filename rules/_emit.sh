#!/bin/sh
set -eu

RULE_NAME=${1:?usage: rules/_emit.sh rule-name envelope.json}
ENVELOPE=${2:?usage: rules/_emit.sh rule-name envelope.json}

slot=$(sed -n 's/.*"rule_slot": "\(0x[0-9A-Fa-f][0-9A-Fa-f]\)".*/\1/p' "$ENVELOPE")
context=$(sed -n 's/.*"context": "\(0x[0-9A-Fa-f]\+\)".*/\1/p' "$ENVELOPE")
slot_index=$(sed -n 's/.*"slot_index": "\(0x[0-9A-Fa-f]\+\)".*/\1/p' "$ENVELOPE")
chirality=$(sed -n 's/.*"chirality": "\([^"]*\)".*/\1/p' "$ENVELOPE")
receipt=$(sed -n 's/.*"receipt": "\([^"]*\)".*/\1/p' "$ENVELOPE")

printf '{\n'
printf '  "status": "materialized",\n'
printf '  "rule_slot": "%s",\n' "$slot"
printf '  "rule_name": "%s"' "$RULE_NAME"
if [ -n "$context" ] || [ -n "$slot_index" ] || [ -n "$chirality" ] || [ -n "$receipt" ]; then
  printf ',\n'
else
  printf '\n'
fi
if [ -n "$context" ]; then
  printf '  "context": "%s"' "$context"
  if [ -n "$slot_index" ] || [ -n "$chirality" ] || [ -n "$receipt" ]; then
    printf ',\n'
  else
    printf '\n'
  fi
fi
if [ -n "$slot_index" ]; then
  printf '  "slot_index": "%s"' "$slot_index"
  if [ -n "$chirality" ] || [ -n "$receipt" ]; then
    printf ',\n'
  else
    printf '\n'
  fi
fi
if [ -n "$chirality" ]; then
  printf '  "chirality": "%s"' "$chirality"
  if [ -n "$receipt" ]; then
    printf ',\n'
  else
    printf '\n'
  fi
fi
if [ -n "$receipt" ]; then
  printf '  "receipt": "%s"\n' "$receipt"
fi
printf '}\n'
