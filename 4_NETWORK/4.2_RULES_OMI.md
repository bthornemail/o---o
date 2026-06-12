# RULES.omi: The Axiomatic Rule Directory

## The Constraint System

`RULES.omi` encodes the strict mathematical constraints governing the 128-bit address space. Every row defines a mandatory architectural behavior mapped to a specific 16-bit hex segment offset.

**Grammar:**
```
<omi-address>/<prefix> MUST <invariant-name>
```

The prefix is always `/48` for local canonical frames, unless otherwise specified. Rules are evaluated at bare-metal speed using hyphen-only splits — no parsing, no branching, no string operations.

```mermaid
mindmap
  root((RULES.omi))
    ::id(root)
    Foundation[0x01-0x03<br/>Foundation]
      chiral-origin
      cardinal-enclosure
      service-bus
      central-inversion
    Language[0x04<br/>Language]
      pos-tags[17 UPOS tags<br/>noun, verb, adj...]
    Stride[0x05-0x07<br/>Stride & Layer]
      factorial[5! 6! 7!]
      sexagesimal-slot[0-54]
      layer[0-7 polycube]
    Barcode[0x20-0x26<br/>Barcode Carriers]
      uss-16k[USS-16K]
      beetag[BeeTag]
      maxicode[MaxiCode]
      aztec[Aztec Code]
    Hardware[0x10-0x1F<br/>Hardware & Boot]
      boot[0x7C00]
      mbr[0xAA55]
      ula[fc00::/7]
      mmio[virt-ctrl]
    Quadratic[0x27-0x2E<br/>Quadratic Lexer]
      gate1[Q(S)=0]
      gate2[Fano intercept]
    Kernel[0x4B-0x51<br/>Kernel Gate]
      ebpf[eBPF<br/>XDP filter]
```

## The Rule Table

### Foundation (0x01–0x03)

| Rule | Segment | Constraint |
|------|---------|------------|
| 0x01 | S[0] | `ffff` = chiral origin, `039f` = cardinal enclosure |
| 0x02 | S[1] | `0001`–`0008` = 8 service bus channels |
| 0x03 | S[2] | `5a3c` triggers central inversion mirror |

### Natural Language (0x04)

| Rule | Segment | Constraint |
|------|---------|------------|
| 0x04 | S[3] | `0001`–`0017` = Universal POS tags (noun, verb, adj, etc.) |

### Tetrahedral Meta Tags (Wordlengths 21–25)

These are packet wordlength classes, not rule IDs; the numeric values intentionally do not replace the barcode carrier rule numbers below.

| Wordlength | Packet | Constraint |
|------------|--------|------------|
| 21 | facts | `2^1` flags: assertions, truth bits, chirality |
| 22 | rules | `2^2` tangential types: `text`, `file`, `link`, `group` |
| 23 | closures | `2^3` scope and environment records |
| 24 | combinators | `2^4` 16xy character/codepoint junction |
| 25 | cons | `2^5` car/cdr pointer matrix |

### Factorial Stride (0x05–0x07)

| Rule | Segment | Constraint |
|------|---------|------------|
| 0x05 | S[4] | Valid strides: `0078` (120), `02d0` (720), `13b0` (5040) |
| 0x06 | S[5] | Sexagesimal slot: `0000`–`0036` |
| 0x07 | S[6] | Factorial layers 0–7 |

### Lisp and Fixed Points (0x08–0x0F)

| Rule | Segment | Constraint |
|------|---------|------------|
| 0x08 | S[7] | `0001` = terminal closure (`()! = ()`) |
| 0x0C | /96 | Projective reciprocal ratios must resolve identically |
| 0x0D | /96/5040 | Hard reset fence |
| 0x0E | S[4]=0x02D0 | Circular slide rule pivot |
| 0x0F | S[5]=0x0036 | Combinatorial 2-of-5 structural validator |

### Hardware and Boot (0x10–0x1F)

| Rule | Segment | Constraint |
|------|---------|------------|
| 0x10 | S[6]=0x0007 | Terminal fractal depth fence |
| 0x11 | S[5]=0xFFFF | IPv4-mapped default track pair |
| 0x12 | fc00::/7 | ULA private fabric anchor |
| 0x13 | ::ffff:0:0/96 | IPv4-mapped linear gateway |
| 0x14 | /120 | Default LAN frame (192.168.1.0/24) |
| 0x15 | /128 | Terminal loopback core pivot (::8) |
| 0x16 | S[1]=0x7C00 | Boot execution entry point |
| 0x17 | S[7]=0xAA55 | MBR boot signature |
| 0x18 | fc00-7c00-...-aa55 | Unified hardware boot strap |
| 0x19 | bitmask | Decodetree instruction pattern (`insn & 0xFFFFFFF0 == 0x039F5A3C`) |
| 0x1A | S[2]=5a3c, S[3]=0001 | MTTCG parallel lane sync |
| 0x1B | S[7]=0x003C | Hardware QOM clock tree |
| 0x1C | S[7]=0x00A0 | Atomic acquire memory fence |
| 0x1D | S[4]=0x0001 | LockCnt visitor tracking |
| 0x1E | S[5]=0x0C00 | Virt-ctrl MMIO base |
| 0x1F | ...-0C00-0004-0003 | Hypervisor panic command |

### Barcode Carriers (0x20–0x26)

| Rule | Stride | Carrier |
|------|--------|---------|
| 0x20 | 0x13B0 (5040) | USS-16K / Code 16K linear |
| 0x21 | 0x0078 (120) | BeeTag 25-bit matrix |
| 0x22 | 0x02D0 (720), bit-0=1 | MaxiCode identity matrix |
| 0x23 | 0x02D0 (720), bit-0=0 | Aztec Code spiral RS |
| 0x24 | 0x001F | 2-of-5 barcode validator |
| 0x25 | 0x0002 | Maximum bitblip tolerance |
| 0x26 | — | Canonical format registry |

### Quadratic Lexer (0x27–0x2E)

| Rule | Address | Constraint |
|------|---------|------------|
| 0x27 | 0500-03bf-...-039f-05ff | Quadratic lexer invariant Q(S)=0 |
| 0x28 | Same | Delta-C orbital lexer with Fano |
| 0x2C | 03bf-2b00-2f00-.../80 | ABI quadratic predicate |
| 0x2D | ...-13b0-000e | Bounded lottery (steps ≤ 14) |
| 0x2E | ...-00c8 | 64-bit disjoint slot packing |

### Physical and Kernel (0x4B–0x51)

| Rule | Address | Constraint |
|------|---------|------------|
| 0x4B | ...-003c | Physical signal integrity |
| 0x4C | 0x13B0 stride | Linear ingestion ladder |
| 0x4D | 0x02D0 stride | C0 control character grid |
| 0x4E | /80 | Monolithic zero-sum surface |
| 0x4F | /80 | eBPF Gate 1 quadratic enforcement |
| 0x50 | ...-13b0-000e | eBPF Gate 2 Fano resolution |
| 0x51 | 0100-7c00-...-0436 | eBPF Fano range limits |

## The Five Declaration Files

RULES.omi is part of a five-file system. Each file uses the same core grammar with a distinct keyword:

| File | Keyword | Role |
|---|---|---|
| RULES.omi | MUST | normative obligations |
| FACTS.omi | FACT | grounded implementation |
| CLOSURES.omi | CLOSE | bounded completion |
| COMBINATORS.omi | COMBINE | lawful composition |
| CONS.omi | CONS | pair reduction |

The grammar is shared:

```text
<omi-address>/<prefix> <keyword> <assignment>
```

RULES.omi declares what must be true. FACTS.omi declares what has been done — facts ground rules by pointing to implementations and tests. CLOSURES.omi seals structures as complete. COMBINATORS.omi declares lawful transformations. CONS.omi defines pair structure and dot notation.

A rule in RULES.omi may be grounded into a fact in FACTS.omi through the rule-to-fact derivation protocol. The derivation uses bitboard masks to identify structurally relevant address fields and bitblip policies to define how deviations are handled.

## Horn-Clause Derivation

A RULES.omi address carries an implicit derivation path. The identity is the frame:

```text
omi---imo = binary rewrite identity
/---/     = routed interpretation path
?---?     = external payload or stream attachment
```

Together:

```text
omi---imo/<domain>/<selector>/<overlay>/
```

The frame identifies. The path derives. Every path segment is a clause selector:

```text
omi---imo/hardware/i2c/euler/
```

may be interpreted as:

```prolog
derive(Frame, Surface) :-
    domain(Frame, hardware),
    interface(Frame, i2c),
    selector(Frame, euler),
    receipt(Frame, Surface).
```

This means RULES.omi addresses are not flat identifiers — they carry a clause route that describes how a rule obligation reaches its implementation domain.

See also: [1.6 The OMI Declaration Language](../1_FOUNDATIONS/1.6_THE_OMI_DECLARATION_LANGUAGE.md), [2.8 Five-Fold, Four-Fold, and the 240-State Bridge](../2_MATH/2.8_FIVE_FOLD_FOUR_FOLD_AND_THE_240_BRIDGE.md), [4.4 Horn-Clause Address Derivation](4.4_HORN_CLAUSE_DERIVATION.md), [7.5 Rule-to-Fact Derivation](../7_CANON/7.5_RULE_TO_FACT_DERIVATION.md), [7.6 Agreement Operators](../7_CANON/7.6_AGREEMENT_OPERATORS.md)
