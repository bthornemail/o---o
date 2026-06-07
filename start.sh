#!/bin/sh
set -eu

FRAME=${1:-0100-03bf-7c00-2b01-2f01-1434-039f-01ff}
RECEIPT_DIR=${OMI_RECEIPT_DIR:-receipts}

die() {
  printf '{"status":"rejected","reason":"%s"}\n' "$1"
  exit 1
}

hex_word() {
  case "$1" in
    [0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]) ;;
    *) die "frame must contain eight 16-bit hex words" ;;
  esac
  printf '%d' "$((0x$1))"
}

rotl16() {
  x=$1
  n=$2
  printf '%d' "$(((((x << n) & 0xffff) | (x >> (16 - n))) & 0xffff))"
}

rotr16() {
  x=$1
  n=$2
  printf '%d' "$((((x >> n) | ((x << (16 - n)) & 0xffff)) & 0xffff))"
}

delta16() {
  x=$1
  ll=$2
  c=$(((ll * 0x1337) & 0xffff))
  r1=$(rotl16 "$x" 1)
  r3=$(rotl16 "$x" 3)
  rr2=$(rotr16 "$x" 2)
  printf '%d' "$(((r1 ^ r3 ^ rr2 ^ c) & 0xffff))"
}

old_ifs=$IFS
IFS=-
set -- $FRAME
IFS=$old_ifs

[ "$#" -eq 8 ] || die "frame must contain eight hyphen-separated words"

s0=$(hex_word "$1")
s1=$(hex_word "$2")
s2=$(hex_word "$3")
s3=$(hex_word "$4")
s4=$(hex_word "$5")
s5=$(hex_word "$6")
s6=$(hex_word "$7")
s7=$(hex_word "$8")

ll=$(((s0 >> 8) & 0xff))
context=$(((ll >> 4) & 0x0f))
slot_index=$((ll & 0x0f))
nn=$s2
mm=$s5

e_var=0
[ $(((s0 >> 8) & 0xff)) -eq "$ll" ] || e_var=$((e_var + 1))
[ $((s3 & 0xff)) -eq "$ll" ] || e_var=$((e_var + 1))
[ $((s4 & 0xff)) -eq "$ll" ] || e_var=$((e_var + 1))
[ $(((s7 >> 8) & 0xff)) -eq "$ll" ] || e_var=$((e_var + 1))

e_const=0
[ "$s1" -eq 959 ] || e_const=$((e_const + 1))
[ "$s6" -eq 927 ] || e_const=$((e_const + 1))
[ $(((s3 >> 8) & 0xff)) -eq 43 ] || e_const=$((e_const + 1))
[ $(((s4 >> 8) & 0xff)) -eq 47 ] || e_const=$((e_const + 1))

q_frame=$((e_var + e_const))
[ "$q_frame" -eq 0 ] || die "Q_frame(S) != 0"

steps=-1
state=$nn
k=0
while [ "$k" -lt 15 ]; do
  state=$(delta16 "$state" "$ll")
  if [ "$state" -eq "$mm" ]; then
    steps=$((k + 1))
    break
  fi
  k=$((k + 1))
done

[ "$steps" -ge 0 ] || die "Delta/Fano resolution failed"

rule_slot=$((0xe0 + slot_index))
chirality_bit=$((steps & 1))
if [ "$chirality_bit" -eq 1 ]; then
  chirality=right
else
  chirality=left
fi

receipt=$(printf '0x%02x%02x%04x%04x%02x%02x' \
  "$ll" "$steps" "$nn" "$mm" "$rule_slot" "$chirality_bit")

mkdir -p "$RECEIPT_DIR"
receipt_file=$(printf '%s/%s.json' "$RECEIPT_DIR" "${receipt#0x}")

{
  printf '{\n'
  printf '  "status": "accepted",\n'
  printf '  "accepted": true,\n'
  printf '  "LL": "0x%02X",\n' "$ll"
  printf '  "context": "0x%X",\n' "$context"
  printf '  "slot_index": "0x%X",\n' "$slot_index"
  printf '  "NN": "0x%04X",\n' "$nn"
  printf '  "MM": "0x%04X",\n' "$mm"
  printf '  "steps": %d,\n' "$steps"
  printf '  "rule_band": "0xE0-0xEF",\n'
  printf '  "rule_slot": "0x%02X",\n' "$rule_slot"
  printf '  "chirality": "%s",\n' "$chirality"
  printf '  "receipt": "%s"\n' "$receipt"
  printf '}\n'
} | tee "$receipt_file"
