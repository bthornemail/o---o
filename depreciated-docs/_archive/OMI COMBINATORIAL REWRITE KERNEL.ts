/**
 * OMI COMBINATORIAL REWRITE KERNEL
 * -----------------------------------------------------------------------
 * Core structural mechanisms for mapping finite geometries and designs
 * into deterministic, serializable runtime transformations.
 */

// =======================================================================
// 1. Core Structural Primitives & Type Definitions
// =======================================================================

export type Bitboard = bigint; // Pure binary surface mapping point membership
export type Vec3 = [number, number, number]; // Homogeneous coordinates for projective spaces
export type BTDBlock = Map<number, number>; // Multiset block tracking (point -> multiplicity)

/**
 * Fast population count for dynamic 64-bit address spaces
 * Computes the absolute weight (number of active points) of a rewrite surface.
 */
export function popcount(surface: Bitboard): number {
  let x = surface;
  let count = 0;
  while (x > 0n) {
    count += Number(x & 1n);
    x >>= 1n;
  }
  return count;
}

/**
 * Preserves structural entropy via cyclic bitwise left rotation.
 * Ensures nothing falls off the edge of the address space wheel.
 */
export function rotateLeft32(mask: number, shift: number, width: number): number {
  const boundedShift = shift % width;
  const activeBitsMask = (1 << width) - 1;
  const cleanedMask = mask & activeBitsMask;
  const rotated = (cleanedMask << boundedShift) | (cleanedMask >>> (width - boundedShift));
  return rotated & activeBitsMask;
}

// =======================================================================
// 2. Projective Matrix Layer: The Fano Plane & Difference Sets
// =======================================================================

export class ProjectiveSeedEngine {
  /**
   * Canonically generates the Fano Plane PG(2,2) lines from the (7,3,1) difference set
   * Translates are calculated using cyclic bitwise shifting over 7 active states.
   */
  static generateFanoLines(): number[] {
    const differenceSet = [1, 2, 4]; // Foundational (7,3,1) seed
    return Array.from({ length: 7 }, (_, index) =>
      differenceSet.reduce((mask, diff) => mask | (1 << ((index + diff) % 7)), 0)
    );
  }

  /**
   * Determines if three projective coordinates converge onto a singular collinear line
   */
  static areCollinear(lines: number[], p: number, q: number, r: number): boolean {
    return lines.some(line => 
      ((line & (1 << p)) !== 0) && 
      ((line & (1 << q)) !== 0) && 
      ((line & (1 << r)) !== 0)
    );
  }

  /**
   * Executes a Galois Field 2 (GF(2)) dot product for projective point-line incidence
   */
  static gf2Dot(a: Vec3, b: Vec3): number {
    return (a[0] * b[0]) ^ (a[1] * b[1]) ^ (a[2] * b[2]); // XOR acts as addition over GF(2)
  }

  /**
   * Develops any cyclic difference set (v, k, lambda) into a full symmetric matrix
   */
  static developDifferenceSet(set: number[], v: number): number[] {
    const baseMask = set.reduce((mask, element) => mask | (1 << element), 0);
    return Array.from({ length: v }, (_, shift) => rotateLeft32(baseMask, shift, v));
  }
}

// =======================================================================
// 3. Symmetric Validation Layer (BIBD & SBIBD Matrices)
// =======================================================================

export class BalancedDesignValidator {
  /**
   * Evaluates if a given set of Bitboards satisfies 2-(v, k, lambda) balance
   */
  static validateBIBD(v: number, k: number, lambda: number, blocks: Bitboard[]): boolean {
    const b = blocks.length;
    if (b < v) return false; // Fisher's Inequality rule constraint

    const r = (lambda * (v - 1)) / (k - 1);
    if (!Number.isInteger(r)) return false;

    // Verify replication constraint across all points
    for (let point = 0; point < v; point++) {
      const pointMask = 1n << BigInt(point);
      const replicationCount = blocks.filter(block => (block & pointMask) !== 0n).length;
      if (replicationCount !== r) return false;
    }

    // Verify pair coverage constraint across all pairings
    for (let i = 0; i < v; i++) {
      for (let j = i + 1; j < v; j++) {
        const pairMask = (1n << BigInt(i)) | (1n << BigInt(j));
        const pairingCoverage = blocks.filter(block => (block & pairMask) === pairMask).length;
        if (pairingCoverage !== lambda) return false;
      }
    }

    return true;
  }

  /**
   * Transposes a square incidence matrix stored as an array of BigInt bitboards
   */
  static transposeIncidenceMatrix(matrix: Bitboard[], dimension: number): Bitboard[] {
    const transposed: Bitboard[] = Array(dimension).fill(0n);
    for (let row = 0; row < dimension; row++) {
      for (let col = 0; col < dimension; col++) {
        if (((matrix[row] >> BigInt(col)) & 1n) !== 0n) {
          transposed[col] |= 1n << BigInt(row);
        }
      }
    }
    return transposed;
  }

  /**
   * Checks if an array of bitboards forms a fully self-dual symmetric structure
   */
  static isSymmetricDesign(matrix: Bitboard[], v: number, lambda: number): boolean {
    if (matrix.length !== v) return false;

    // Verify block intersections match lambda values
    for (let i = 0; i < v; i++) {
      for (let j = i + 1; j < v; j++) {
        if (popcount(matrix[i] & matrix[j]) !== lambda) return false;
      }
    }
    return true;
  }
}

// =======================================================================
// 4. Matrix Partitioning Layer (Latin Squares & Resolvability)
// =======================================================================

export class SquarePartitionEngine {
  /**
   * Validates an n x n grid using bitmask tracking to ensure no symbol collisions occur
   */
  static isValidLatinSquare(grid: number[][], n: number): boolean {
    const fullSymbolsMask = (1 << n) - 1; // Generates target validation mask
    for (let i = 0; i < n; i++) {
      let rowSymbolsAccumulator = 0;
      let colSymbolsAccumulator = 0;
      for (let j = 0; j < n; j++) {
        rowSymbolsAccumulator |= 1 << grid[i][j];
        colSymbolsAccumulator |= 1 << grid[j][i];
      }
      if (rowSymbolsAccumulator !== fullSymbolsMask || colSymbolsAccumulator !== fullSymbolsMask) {
        return false;
      }
    }
    return true;
  }

  /**
   * Validates a parallel class partition where the bitwise XOR completely satisfies the mask
   */
  static isValidParallelClass(blocks: Bitboard[], v: number): boolean {
    const targetPointsMask = (1n << BigInt(v)) - 1n;
    
    // Ensure all blocks in this partition space are perfectly disjoint
    for (let i = 0; i < blocks.length; i++) {
      for (let j = i + 1; j < blocks.length; j++) {
        if ((blocks[i] & blocks[j]) !== 0n) return false;
      }
    }

    // Verify complete structural union coverage across the points space
    const structuralUnion = blocks.reduce((union, block) => union | block, 0n);
    return structuralUnion === targetPointsMask;
  }
}

// =======================================================================
// 5. Higher-Order Uniformity & Uniform Coverage Layers
// =======================================================================

export class UniformCoverageEngine {
  /**
   * Evaluates if a specific t-subset index is fully covered inside a target block
   */
  static isSubsetInBlock(subsetMask: Bitboard, blockMask: Bitboard): boolean {
    return (blockMask & subsetMask) === subsetMask;
  }

  /**
   * Validates a Youden Square configuration by analyzing row-wise symbol completion
   */
  static verifyYoudenRows(grid: number[][], k: number, v: number): boolean {
    const targetSymbolMask = (1 << v) - 1;
    return grid.every(row => {
      const rowMask = row.reduce((mask, symbol) => mask | (1 << symbol), 0);
      return rowMask === targetSymbolMask;
    });
  }
}