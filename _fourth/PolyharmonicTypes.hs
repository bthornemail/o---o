{-# LANGUAGE DeriveGeneric #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}

-- |
-- Module      : PolyharmonicTypes
-- Description : Types-first conformance surface for metaverse-kit, polyform, and polytron.
--
-- This module intentionally defines representation only.
-- It does not introduce a new compiler, evaluator, event store, or execution algorithm.
-- Existing implementations should be mapped to these types before behavior is ported.
module PolyharmonicTypes
  ( -- * Fixed coordinate domains
    ByteCoordinate(..)
  , LowGaugeCoordinate(..)
  , WordAxis(..)
  , TruthTableColumn(..)
  , CircularRulerIndex(..)
  , CircularRulerPosition(..)
  , AlgorithmicTick(..)

    -- * Canonical orientation
  , OminoCentroid(..)
  , Azimuth(..)
  , Orientation(..)
  , Plane(..)

    -- * Epistemic streaming cell
  , EpistemicBit(..)
  , EpistemicCell(..)
  , Scope4(..)
  , IntegritySyndrome(..)
  , SecdedOutcome(..)

    -- * Polyform geometry
  , PolyformCell(..)
  , Polyform(..)
  , CellTransform(..)
  , PolyformTransform(..)

    -- * Blackboard and projection
  , BlackboardCoordinate(..)
  , BlackboardSurface(..)
  , CanvasViewport(..)
  , SpatialVertex(..)
  , Projection(..)

    -- * Polytron execution representation
  , ProcessorMode(..)
  , ProcessorRegister(..)
  , ProcessorContext(..)

    -- * Five canonical file faces
  , CanonicalFace(..)
  , SurfaceKind(..)
  , FaceSurface(..)

    -- * Conformance ownership
  , SourceOwner(..)
  , ConformanceStatus(..)
  , ConformanceClaim(..)
  ) where

import Data.Word (Word8, Word16, Word32, Word64)
import GHC.Generics (Generic)

-- Fixed-width coordinate domains ------------------------------------------------

newtype ByteCoordinate = ByteCoordinate Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | Bounded Omicron low gauge: intended domain 0x00..0x7F.
newtype LowGaugeCoordinate = LowGaugeCoordinate Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | One self-contained 16-bit OMINO word-axis substrate.
newtype WordAxis = WordAxis Word16
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | One complete selected six-input Boolean truth-table output column.
newtype TruthTableColumn = TruthTableColumn Word64
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | Intended bounded domain: 0..71.
newtype CircularRulerIndex = CircularRulerIndex Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | Intended bounded domain: 0..59.
newtype CircularRulerPosition = CircularRulerPosition Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- | Logical, deterministic clock coordinate; not wall-clock time.
newtype AlgorithmicTick = AlgorithmicTick Word16
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

-- Canonical orientation ---------------------------------------------------------

data OminoCentroid = OminoCentroid
  { centroidPoint   :: !ByteCoordinate
  , centroidAzimuth :: !Azimuth
  } deriving (Eq, Show, Generic)

newtype Azimuth = Azimuth Word16
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

data Orientation
  = CentroidRelative
  | AntipodalRelative
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data Plane
  = LocalPlane
  | RemotePlane
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

-- Epistemic streaming cell ------------------------------------------------------

data EpistemicBit
  = LOGOS
  | NOMOS
  | FS
  | PATHOS
  | GS
  | RS
  | US
  | OMINO
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

-- | Exact bit-vector representation:
-- bit 0 LOGOS, bit 1 NOMOS, bit 2 FS, bit 3 PATHOS,
-- bit 4 GS, bit 5 RS, bit 6 US, bit 7 OMINO.
newtype EpistemicCell = EpistemicCell Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

data Scope4 = Scope4
  { scopeFS :: !Bool
  , scopeGS :: !Bool
  , scopeRS :: !Bool
  , scopeUS :: !Bool
  } deriving (Eq, Show, Generic)

newtype IntegritySyndrome = IntegritySyndrome Word8
  deriving (Eq, Ord, Show, Enum, Num, Real, Integral, Bounded)

data SecdedOutcome
  = NoDetectedError
  | InteriorSingleErrorCorrected
  | OminoSingleErrorCorrected
  | DoubleErrorDetected
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

-- Polyform geometry -------------------------------------------------------------

-- | A cell is represented by a bounded occupancy word plus an explicit local
-- origin. The exact occupancy interpretation must be mapped from the existing
-- polyform code rather than guessed here.
data PolyformCell = PolyformCell
  { cellOccupancy :: !WordAxis
  , cellOriginX   :: !Word16
  , cellOriginY   :: !Word16
  , cellOriginZ   :: !Word16
  } deriving (Eq, Show, Generic)

-- | A finite polyform is a typed collection of cells. This is a representation
-- boundary only; it does not prescribe arrays, lists, heaps, or traversal in the
-- executable core.
newtype Polyform = Polyform
  { polyformCells :: [PolyformCell]
  } deriving (Eq, Show, Generic)

data CellTransform
  = IdentityTransform
  | RotateQuarter
  | RotateHalf
  | RotateThreeQuarter
  | ReflectX
  | ReflectY
  | ReflectZ
  | CircularInvert
  | SnubTruncate
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data PolyformTransform = PolyformTransform
  { transformKind   :: !CellTransform
  , transformOffsetX :: !Word16
  , transformOffsetY :: !Word16
  , transformOffsetZ :: !Word16
  } deriving (Eq, Show, Generic)

-- Blackboard and projection ----------------------------------------------------

data BlackboardCoordinate = BlackboardCoordinate
  { boardRow :: !Word8
  , boardCol :: !Word8
  } deriving (Eq, Ord, Show, Generic)

data BlackboardSurface
  = UserLocalSurface
  | UserRemoteSurface
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data CanvasViewport
  = Resolution16x16
  | ExtendedProjection
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data SpatialVertex = SpatialVertex
  { coordinateU     :: !Word32
  , coordinateV     :: !Word32
  , projectionDepth :: !Word16
  } deriving (Eq, Show, Generic)

data Projection = Projection
  { projectionViewport    :: !CanvasViewport
  , projectionOrientation :: !Orientation
  , projectionVertex      :: !SpatialVertex
  } deriving (Eq, Show, Generic)

-- Polytron execution representation --------------------------------------------

data ProcessorMode
  = VectorScribeMode
  | ParallelTileMode
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data ProcessorRegister = ProcessorRegister
  { instructionOpcode :: !Word8
  , coreAddressLink   :: !Word32
  , clockCycleWeight  :: !Word16
  } deriving (Eq, Show, Generic)

data ProcessorContext = ProcessorContext
  { activeMetaAxis     :: !Word64
  , currentWordContext :: !Word16
  , algorithmicTick    :: !AlgorithmicTick
  , processorMode      :: !ProcessorMode
  } deriving (Eq, Show, Generic)

-- Five canonical file faces -----------------------------------------------------

data CanonicalFace
  = Rules
  | Facts
  | Closures
  | Combinators
  | Cons
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data SurfaceKind
  = UserLocalDeclaration  -- ^ .omi
  | UserRemoteDefinition -- ^ .imo
  | LocalBinaryRegister  -- ^ .o
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data FaceSurface = FaceSurface
  { face        :: !CanonicalFace
  , surfaceKind :: !SurfaceKind
  , wordAxis    :: !WordAxis
  } deriving (Eq, Show, Generic)

-- Conformance ownership ---------------------------------------------------------

data SourceOwner
  = ExistingPolyform
  | MetaverseKit
  | Polytron
  | PolyharmonicShared
  | UnresolvedOwner
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data ConformanceStatus
  = ExactMatch
  | Representable
  | RequiresAdapter
  | SemanticConflict
  | NotYetInspected
  deriving (Eq, Ord, Show, Enum, Bounded, Generic)

data ConformanceClaim = ConformanceClaim
  { claimTypeName :: !String
  , claimOwner    :: !SourceOwner
  , claimStatus   :: !ConformanceStatus
  , claimEvidence :: !String
  } deriving (Eq, Show, Generic)
