/* ============================================================================
 * OMNICRON COPRODUCT PARTITION
 * ----------------------------------------------------------------------------
 * A first-principles C encoding of "The Omnicron Coproduct Partition":
 * an origin-preserving sum (coproduct) of independent .o knowledge boards,
 * composed through CONS into a shared 256-position OMI-Lisp plane, with
 * validated (never automatic) equivalence maintained by Union-Find.
 *
 * Section references (# N) point back to the source doctrine document.
 *
 * Dependency-free ANSI C99. No malloc. Fixed-capacity, deterministic,
 * non-destructive bitwise operations throughout.
 * ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* ============================================================================
 * 0. LIMITS AND STATUS
 * ============================================================================
 */

#define OMI_PLANE_SIZE               256u   /* # 3  shared OMI-Lisp plane      */
#define OMI_MAX_CONTRIBUTIONS        256u   /* coproduct capacity              */
#define OMI_MAX_FIBER_CONTRIBUTORS     8u   /* # 14 per-coordinate fiber depth */

typedef enum {
    OMI_OK = 0,
    OMI_ERROR_CAPACITY,          /* blackboard or fiber is full               */
    OMI_ERROR_INVALID_INDEX,     /* contribution index out of range           */
    OMI_ERROR_NOT_VALIDATED      /* union attempted without a valid witness   */
} omi_status;

/* ============================================================================
 * 1. OMI-LISP PLANE PRIMITIVES  (# 3, # 6 sparse rank-8 boards)
 * ============================================================================
 */

typedef struct {
    uint64_t lane[4];   /* 256 bits = 4 x 64-bit lanes, bit p == coordinate p */
} OmiBoard256;

static inline void omi_board256_clear(OmiBoard256 *b) {
    b->lane[0] = b->lane[1] = b->lane[2] = b->lane[3] = 0ULL;
}

static inline void omi_board256_set(OmiBoard256 *b, uint8_t p) {
    b->lane[p >> 6] |= (1ULL << (p & 63));
}

static inline bool omi_board256_test(const OmiBoard256 *b, uint8_t p) {
    return (b->lane[p >> 6] >> (p & 63)) & 1ULL;
}

static inline void omi_board256_or(OmiBoard256 *out, const OmiBoard256 *a, const OmiBoard256 *b) {
    for (int i = 0; i < 4; i++) out->lane[i] = a->lane[i] | b->lane[i];
}

static inline void omi_board256_and(OmiBoard256 *out, const OmiBoard256 *a, const OmiBoard256 *b) {
    for (int i = 0; i < 4; i++) out->lane[i] = a->lane[i] & b->lane[i];
}

static inline void omi_board256_xor(OmiBoard256 *out, const OmiBoard256 *a, const OmiBoard256 *b) {
    for (int i = 0; i < 4; i++) out->lane[i] = a->lane[i] ^ b->lane[i];
}

/* # 42 disjoint union cardinality: |A ⊔ B| = |A| + |B| when A ∩ B = ∅ */
static inline uint32_t omi_board256_popcount(const OmiBoard256 *b) {
    uint32_t total = 0;
    for (int i = 0; i < 4; i++) {
        uint64_t v = b->lane[i];
        v = v - ((v >> 1) & 0x5555555555555555ULL);
        v = (v & 0x3333333333333333ULL) + ((v >> 2) & 0x3333333333333333ULL);
        v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
        total += (uint32_t)((v * 0x0101010101010101ULL) >> 56);
    }
    return total;
}

/* the low/high carrier mirror: m(x) = x XOR 0x80, m(m(x)) = x  (# 3) */
static inline uint8_t omi_plane_mirror(uint8_t x) {
    return (uint8_t)(x ^ 0x80u);
}

/* ============================================================================
 * 2. CONTRIBUTION AND PROVENANCE  (# 14, # 36)
 * ============================================================================
 */

typedef struct {
    uint32_t source_id;

    uint32_t car;
    uint32_t cdr;

    uint16_t resolver_profile;
    uint8_t  scope;    /* 0=FS 1=GS 2=RS 3=US, see # 46 */
    uint8_t  flags;

    uint8_t  source_digest[32];
} OmiContributionRef;

typedef struct {
    uint32_t source_id;

    uint32_t car;
    uint32_t cdr;

    OmiBoard256 board;

    uint16_t resolver_profile;
    uint8_t  scope;
    uint8_t  contribution_type;

    uint8_t  digest[32];
} OmiBoardContribution;

/* # 14 blackboard fiber: every origin-tagged contribution behind one byte */
typedef struct {
    uint8_t  visible_coordinate;
    uint32_t contribution_count;
    uint16_t contributor_index[OMI_MAX_FIBER_CONTRIBUTORS]; /* into contributions[] */
} OmiBlackboardFiber;

/* ============================================================================
 * 3. VALIDATED UNION-FIND  (# 24, # 25, # 26)
 * ----------------------------------------------------------------------------
 * Union-Find MAINTAINS equivalence classes. It never DECIDES equivalence.
 * omi_union_validated therefore requires an OmiValidationResult carrying
 * an explicit `valid` flag, produced only by omi_blackboard_validate_equivalence.
 * ============================================================================
 */

typedef struct {
    uint32_t parent[OMI_MAX_CONTRIBUTIONS];
    uint32_t rank[OMI_MAX_CONTRIBUTIONS];
    uint32_t size;
} OmiUnionFind;

typedef enum {
    OMI_VALID_REASON_NONE = 0,
    OMI_VALID_REASON_RESOLVED_MATCH,   /* CONS(left) == CONS(right)          */
    OMI_VALID_REASON_SCOPE_MISMATCH,
    OMI_VALID_REASON_RESOLVER_MISMATCH,
    OMI_VALID_REASON_NO_MATCH
} OmiValidationReason;

typedef struct {
    bool                valid;
    OmiValidationReason reason;
    uint32_t            resolved_left;
    uint32_t            resolved_right;
} OmiValidationResult;

static void omi_uf_init(OmiUnionFind *uf, uint32_t size) {
    uf->size = size;
    for (uint32_t i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

static uint32_t omi_find(OmiUnionFind *uf, uint32_t element) {
    /* iterative path compression, no recursion */
    uint32_t root = element;
    while (uf->parent[root] != root) root = uf->parent[root];
    while (uf->parent[element] != root) {
        uint32_t next = uf->parent[element];
        uf->parent[element] = root;
        element = next;
    }
    return root;
}

/* # 25 union requires a validation witness; it is never exposed unrestricted */
static bool omi_union_validated(OmiUnionFind *uf,
                                 uint32_t left,
                                 uint32_t right,
                                 const OmiValidationResult *witness) {
    if (witness == NULL || !witness->valid) return false;
    if (left >= uf->size || right >= uf->size) return false;

    uint32_t root_l = omi_find(uf, left);
    uint32_t root_r = omi_find(uf, right);
    if (root_l == root_r) return true; /* already unified, lawful no-op */

    if (uf->rank[root_l] < uf->rank[root_r]) {
        uf->parent[root_l] = root_r;
    } else if (uf->rank[root_l] > uf->rank[root_r]) {
        uf->parent[root_r] = root_l;
    } else {
        uf->parent[root_r] = root_l;
        uf->rank[root_l]++;
    }
    return true;
}

/* ============================================================================
 * 4. THE COPRODUCT BLACKBOARD  (# 36)
 * ============================================================================
 */

typedef struct {
    OmiBoard256 occupancy; /* # 7  union of every injected board             */
    OmiBoard256 conflict;  /* set bits where >1 origin-distinct board claims */

    OmiBlackboardFiber fibers[OMI_PLANE_SIZE];

    OmiBoardContribution contributions[OMI_MAX_CONTRIBUTIONS];
    uint32_t contribution_count;

    OmiUnionFind equivalence;
} OmiCoproductBlackboard;

static void omi_blackboard_init(OmiCoproductBlackboard *bb) {
    memset(bb, 0, sizeof(*bb));
    for (uint32_t p = 0; p < OMI_PLANE_SIZE; p++) {
        bb->fibers[p].visible_coordinate = (uint8_t)p;
    }
    omi_uf_init(&bb->equivalence, OMI_MAX_CONTRIBUTIONS);
}

/* ============================================================================
 * 5. INJECTION  (# 37)
 * ----------------------------------------------------------------------------
 * Injection preserves source identity, adds the contribution disjointly
 * (coproduct, not destructive merge), records overlaps in `conflict`
 * without ever collapsing them, and appends the contributor into every
 * fiber its board claims.
 * ============================================================================
 */

static omi_status omi_blackboard_inject(OmiCoproductBlackboard *bb,
                                         const OmiBoardContribution *contribution,
                                         uint32_t *out_index) {
    if (bb->contribution_count >= OMI_MAX_CONTRIBUTIONS) return OMI_ERROR_CAPACITY;

    uint32_t index = bb->contribution_count;
    bb->contributions[index] = *contribution;
    bb->contribution_count++;

    /* # 8 overlap with existing occupancy is recorded, never collapsed */
    OmiBoard256 overlap;
    omi_board256_and(&overlap, &bb->occupancy, &contribution->board);
    OmiBoard256 conflict_next;
    omi_board256_or(&conflict_next, &bb->conflict, &overlap);
    bb->conflict = conflict_next;

    OmiBoard256 occupancy_next;
    omi_board256_or(&occupancy_next, &bb->occupancy, &contribution->board);
    bb->occupancy = occupancy_next;

    for (uint32_t p = 0; p < OMI_PLANE_SIZE; p++) {
        if (!omi_board256_test(&contribution->board, (uint8_t)p)) continue;

        OmiBlackboardFiber *fiber = &bb->fibers[p];
        if (fiber->contribution_count >= OMI_MAX_FIBER_CONTRIBUTORS) {
            return OMI_ERROR_CAPACITY; /* fiber saturated at this coordinate */
        }
        fiber->contributor_index[fiber->contribution_count] = (uint16_t)index;
        fiber->contribution_count++;
    }

    if (out_index) *out_index = index;
    return OMI_OK;
}

/* ============================================================================
 * 6. CONS COMPOSITION  (# 5, # 12, # 38)
 * ----------------------------------------------------------------------------
 * CONS is the mediating map out of the coproduct into the shared plane.
 * It is deliberately NOT commutative bitwise OR: CAR and CDR keep order,
 * and the fold below is a rotate/XOR delta law consistent with the rest
 * of the OMI runtime (never plain OR of the two 32-bit words).
 * ============================================================================
 */

typedef struct {
    uint32_t left_contribution;
    uint32_t right_contribution;

    uint32_t resolved_word;      /* full 32-bit resolved relation           */
    uint8_t  visible_coordinate; /* projection pi() onto the 256-plane      */

    OmiBoard256 overlap_board;   /* left.board AND right.board              */
    bool        conflict;        /* overlap_board is non-empty              */
} OmiConsResult;

static inline uint32_t omi_rotl32(uint32_t v, uint32_t shift) {
    shift &= 31u;
    return (v << shift) | (v >> ((32u - shift) & 31u));
}

/* deterministic, order-sensitive CAR/CDR fold -- CONS(car, cdr) */
static uint32_t omi_cons_fold(uint32_t car, uint32_t cdr, uint16_t resolver_profile) {
    uint32_t r1 = omi_rotl32(car, 1);
    uint32_t r3 = omi_rotl32(cdr, 3);
    uint32_t profile_salt = ((uint32_t)resolver_profile << 16) | resolver_profile;
    return r1 ^ r3 ^ profile_salt;
}

static omi_status omi_blackboard_cons(OmiCoproductBlackboard *bb,
                                       uint32_t left_contribution,
                                       uint32_t right_contribution,
                                       uint16_t resolver_profile,
                                       OmiConsResult *out) {
    if (left_contribution >= bb->contribution_count ||
        right_contribution >= bb->contribution_count) {
        return OMI_ERROR_INVALID_INDEX;
    }

    const OmiBoardContribution *left  = &bb->contributions[left_contribution];
    const OmiBoardContribution *right = &bb->contributions[right_contribution];

    out->left_contribution  = left_contribution;
    out->right_contribution = right_contribution;

    /* order matters: CONS(left.car, right.cdr), not a symmetric combination */
    out->resolved_word = omi_cons_fold(left->car, right->cdr, resolver_profile);

    /* pi(): project the full resolved word onto the 256-position plane */
    out->visible_coordinate = (uint8_t)(out->resolved_word & 0xFFu);

    omi_board256_and(&out->overlap_board, &left->board, &right->board);
    out->conflict = omi_board256_popcount(&out->overlap_board) > 0;

    return OMI_OK;
}

/* ============================================================================
 * 7. VALIDATION AND EQUIVALENCE  (# 24, # 39)
 * ----------------------------------------------------------------------------
 * Validation is a structural law over resolved CONS values, scope, and
 * resolver compatibility. It authorizes equivalence; it does not merge
 * anything by itself. Only a `valid == true` result may be passed to
 * omi_blackboard_union, which is the sole caller of omi_union_validated.
 * ============================================================================
 */

static omi_status omi_blackboard_validate_equivalence(OmiCoproductBlackboard *bb,
                                                        OmiContributionRef left,
                                                        OmiContributionRef right,
                                                        OmiValidationResult *out) {
    memset(out, 0, sizeof(*out));

    if (left.scope != right.scope) {
        out->valid = false;
        out->reason = OMI_VALID_REASON_SCOPE_MISMATCH;
        return OMI_OK;
    }
    if (left.resolver_profile != right.resolver_profile) {
        out->valid = false;
        out->reason = OMI_VALID_REASON_RESOLVER_MISMATCH;
        return OMI_OK;
    }

    (void)bb;
    uint32_t resolved_left  = omi_cons_fold(left.car,  left.cdr,  left.resolver_profile);
    uint32_t resolved_right = omi_cons_fold(right.car, right.cdr, right.resolver_profile);

    out->resolved_left  = resolved_left;
    out->resolved_right = resolved_right;

    if (resolved_left == resolved_right) {
        out->valid  = true;
        out->reason = OMI_VALID_REASON_RESOLVED_MATCH;
    } else {
        out->valid  = false;
        out->reason = OMI_VALID_REASON_NO_MATCH;
    }
    return OMI_OK;
}

static omi_status omi_blackboard_union(OmiCoproductBlackboard *bb,
                                        uint32_t left_contribution,
                                        uint32_t right_contribution,
                                        const OmiValidationResult *validation) {
    if (!validation->valid) return OMI_ERROR_NOT_VALIDATED;
    if (left_contribution >= bb->contribution_count ||
        right_contribution >= bb->contribution_count) {
        return OMI_ERROR_INVALID_INDEX;
    }
    bool ok = omi_union_validated(&bb->equivalence, left_contribution, right_contribution, validation);
    return ok ? OMI_OK : OMI_ERROR_NOT_VALIDATED;
}

/* ============================================================================
 * 8. VERIFICATION HARNESS
 * ============================================================================
 */

static OmiBoardContribution omi_make_contribution(uint32_t source_id,
                                                   uint32_t car,
                                                   uint32_t cdr,
                                                   uint8_t scope,
                                                   uint16_t resolver_profile,
                                                   uint8_t single_bit_position) {
    OmiBoardContribution c;
    memset(&c, 0, sizeof(c));
    c.source_id = source_id;
    c.car = car;
    c.cdr = cdr;
    c.scope = scope;
    c.resolver_profile = resolver_profile;
    c.contribution_type = 0;
    omi_board256_clear(&c.board);
    omi_board256_set(&c.board, single_bit_position);
    return c;
}

int main(void) {
    printf("====================================================================\n");
    printf("OMNICRON COPRODUCT PARTITION: VERIFICATION ARTIFACT\n");
    printf("====================================================================\n\n");

    OmiCoproductBlackboard bb;
    omi_blackboard_init(&bb);

    /* --- Section 1: two origin-distinct sources both claim 0x48 (# 1, # 8) --- */
    printf("[1] Injecting RULES.o and FACTS.o, both claiming coordinate 0x48:\n");

    OmiBoardContribution rules = omi_make_contribution(
        /*source_id*/ 0x52554C45u /* 'RULE' */, 0x12345678u, 0x89ABCDEFu,
        /*scope FS*/ 0, /*resolver*/ 1, /*bit*/ 0x48u);
    OmiBoardContribution facts = omi_make_contribution(
        /*source_id*/ 0x46414354u /* 'FACT' */, 0x11223344u, 0x55667788u,
        /*scope FS*/ 0, /*resolver*/ 1, /*bit*/ 0x48u);

    uint32_t rules_idx, facts_idx;
    omi_status st;

    st = omi_blackboard_inject(&bb, &rules, &rules_idx);
    printf("  Injected RULES.o at contribution index %u (status=%d)\n", rules_idx, st);

    st = omi_blackboard_inject(&bb, &facts, &facts_idx);
    printf("  Injected FACTS.o at contribution index %u (status=%d)\n\n", facts_idx, st);

    /* --- Section 2: fiber at 0x48 preserves both, does not collapse (# 14) --- */
    printf("[2] Inspecting the blackboard fiber at 0x48:\n");
    const OmiBlackboardFiber *fiber = &bb.fibers[0x48];
    printf("  Contribution count at 0x48: %u\n", fiber->contribution_count);
    for (uint32_t i = 0; i < fiber->contribution_count; i++) {
        const OmiBoardContribution *c = &bb.contributions[fiber->contributor_index[i]];
        printf("    origin 0x%08X  car=0x%08X  cdr=0x%08X\n",
               c->source_id, c->car, c->cdr);
    }
    printf("\n");

    /* --- Section 3: occupancy vs. conflict (# 7, # 15) --- */
    printf("[3] Occupancy and conflict boards:\n");
    printf("  Occupancy popcount: %u (expected 1 -- same visible byte, two origins)\n",
           omi_board256_popcount(&bb.occupancy));
    printf("  Conflict popcount:  %u (expected 1 -- 0x48 is contested)\n\n",
           omi_board256_popcount(&bb.conflict));

    /* --- Section 4: CONS composition is order-sensitive, not OR (# 5, # 6) --- */
    printf("[4] CONS(RULES, FACTS) vs CONS(FACTS, RULES):\n");
    OmiConsResult cons_rf, cons_fr;
    omi_blackboard_cons(&bb, rules_idx, facts_idx, /*resolver*/ 1, &cons_rf);
    omi_blackboard_cons(&bb, facts_idx, rules_idx, /*resolver*/ 1, &cons_fr);
    printf("  CONS(RULES,FACTS) resolved=0x%08X  visible=0x%02X\n",
           cons_rf.resolved_word, cons_rf.visible_coordinate);
    printf("  CONS(FACTS,RULES) resolved=0x%08X  visible=0x%02X\n",
           cons_fr.resolved_word, cons_fr.visible_coordinate);
    printf("  Order-sensitivity confirmed: %s\n\n",
           (cons_rf.resolved_word != cons_fr.resolved_word) ? "TRUE" : "FALSE");

    /* --- Section 5: validation gates equivalence; union-find only maintains it --- */
    printf("[5] Validating equivalence between RULES.o and FACTS.o contributors:\n");
    OmiContributionRef rules_ref = {
        .source_id = rules.source_id, .car = rules.car, .cdr = rules.cdr,
        .resolver_profile = rules.resolver_profile, .scope = rules.scope, .flags = 0
    };
    OmiContributionRef facts_ref = {
        .source_id = facts.source_id, .car = facts.car, .cdr = facts.cdr,
        .resolver_profile = facts.resolver_profile, .scope = facts.scope, .flags = 0
    };

    OmiValidationResult validation;
    omi_blackboard_validate_equivalence(&bb, rules_ref, facts_ref, &validation);
    printf("  valid=%s  reason=%d  resolved_left=0x%08X  resolved_right=0x%08X\n",
           validation.valid ? "true" : "false", validation.reason,
           validation.resolved_left, validation.resolved_right);

    omi_status union_status = omi_blackboard_union(&bb, rules_idx, facts_idx, &validation);
    printf("  omi_blackboard_union status=%d (%s)\n",
           union_status, union_status == OMI_OK ? "UNIFIED" : "REJECTED -- not validated");
    printf("  find(RULES)=%u  find(FACTS)=%u  same class=%s\n\n",
           omi_find(&bb.equivalence, rules_idx),
           omi_find(&bb.equivalence, facts_idx),
           omi_find(&bb.equivalence, rules_idx) == omi_find(&bb.equivalence, facts_idx)
               ? "true" : "false");

    /* --- Section 6: a second pair that DOES resolve equal, to show a lawful union --- */
    printf("[6] A second pair engineered to validate, to show a lawful union:\n");
    OmiBoardContribution combinators = omi_make_contribution(
        0x434F4D42u /* 'COMB' */, 0xAAAAAAAAu, 0x55555555u, /*scope*/ 1, /*resolver*/ 2, 0x10u);
    OmiBoardContribution closures = combinators; /* identical car/cdr/scope/resolver -> resolves equal */
    closures.source_id = 0x434C4F53u; /* 'CLOS' */

    uint32_t comb_idx, clos_idx;
    omi_blackboard_inject(&bb, &combinators, &comb_idx);
    omi_blackboard_inject(&bb, &closures, &clos_idx);

    OmiContributionRef comb_ref = {
        .source_id = combinators.source_id, .car = combinators.car, .cdr = combinators.cdr,
        .resolver_profile = combinators.resolver_profile, .scope = combinators.scope, .flags = 0
    };
    OmiContributionRef clos_ref = {
        .source_id = closures.source_id, .car = closures.car, .cdr = closures.cdr,
        .resolver_profile = closures.resolver_profile, .scope = closures.scope, .flags = 0
    };

    OmiValidationResult validation2;
    omi_blackboard_validate_equivalence(&bb, comb_ref, clos_ref, &validation2);
    omi_status union_status2 = omi_blackboard_union(&bb, comb_idx, clos_idx, &validation2);
    printf("  valid=%s  reason=%d\n", validation2.valid ? "true" : "false", validation2.reason);
    printf("  omi_blackboard_union status=%d (%s)\n",
           union_status2, union_status2 == OMI_OK ? "UNIFIED" : "REJECTED");
    printf("  find(COMBINATORS)=%u  find(CLOSURES)=%u  same class=%s\n\n",
           omi_find(&bb.equivalence, comb_idx),
           omi_find(&bb.equivalence, clos_idx),
           omi_find(&bb.equivalence, comb_idx) == omi_find(&bb.equivalence, clos_idx)
               ? "true" : "false");

    /* --- Section 7: low/high mirror sanity check (# 3) --- */
    printf("[7] Low/high 0x80 mirror involution check:\n");
    uint8_t sample = 0x48u;
    uint8_t mirrored = omi_plane_mirror(sample);
    uint8_t restored = omi_plane_mirror(mirrored);
    printf("  m(0x%02X) = 0x%02X, m(m(0x%02X)) = 0x%02X  (%s)\n\n",
           sample, mirrored, sample, restored, restored == sample ? "PASS" : "FAIL");

    printf("====================================================================\n");
    printf("COPRODUCT REMAINS ORIGIN-PRESERVING: %u total contributions retained\n",
           bb.contribution_count);
    printf("====================================================================\n");
    return 0;
}
