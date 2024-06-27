// Copyright 2017 Daniel Orchard. All Rights Reserved.

#include "GridsHex.h"
#include "OffsetCoords.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "GridsCore.h"

UGridsHex::UGridsHex()
{

}


const TArray<FVector> UGridsHex::Neighbours_Hex()
{
	const TArray<FVector> N = { FVector(1, 0, -1), FVector(1, -1, 0), FVector(0, -1, 1), FVector(-1, 0, 1), FVector(-1, 1, 0), FVector(0, 1, -1) };
	return N;
}

const TArray<FVector> UGridsHex::Diagonals_Hex()
{
	const TArray<FVector> D = { FVector(1, 1, -2), FVector(2, -1, -1), FVector(1, -2, 1), FVector(-1, -1, 2), FVector(-2, 1, 1), FVector(-1, 2, -1) };
	return D;
}

const TArray<FVector> UGridsHex::RotateTowardsNeighbourAxis_Hex()
{
	const TArray<FVector> R = { FVector(1,0.58,0), FVector(0,1,0), FVector(-1,0.58,0), FVector(-1,-0.58,0),FVector(0,-1,0), FVector(1,-0.58,0) };
	return R;
}

const TArray<FVector> UGridsHex::RotateTowardsDiagonalAxis_Hex()
{
	const TArray<FVector> R = { FVector(1,0,0), FVector(0.57,1,0), FVector(-0.57,1,0), FVector(-1,0,0), FVector(-0.57,-1,0), FVector(0.57,-1,0) };
	return R;
}

const TArray<FVector> UGridsHex::RotateTowardsNeighbourOrDiagonal_Hex()
{
	TArray<FVector> R = RotateTowardsNeighbourAxis_Hex();
	R.Append(RotateTowardsDiagonalAxis_Hex());
	return R;
}

const TArray<FVector> UGridsHex::NeighboursAndDiagonals_Hex()
{
	TArray<FVector> ND = Neighbours_Hex();
	ND.Append(Diagonals_Hex());
	return ND;
}

//----------------------------//
// Neighbour Code
//----------------------------//

FVector UGridsHex::GetHexNeighbour(FOffsetCoords Origin, int Direction, FOffsetCoords& Offset)
{
	if (UGridsHex::Neighbours_Hex().IsValidIndex(Direction))
	{
		FVector cube = UGridsCore::Conv_OffsetToCube(Origin);
		FVector n = cube + UGridsHex::Neighbours_Hex()[Direction];
		Offset = UGridsCore::Conv_CubeToOffset(n);
		return n;
	}
	return FVector::ZeroVector;
}

TArray<FVector> UGridsHex::GetHexNeighbours(FOffsetCoords Origin)
{
	FVector c = UGridsCore::Conv_OffsetToCube(Origin);
	TArray<FVector> myNeighbours;

	for (auto& n : Neighbours_Hex())
	{
		myNeighbours.Emplace(n + c);
	}

	return myNeighbours;
}

FVector UGridsHex::GetHexDiagonal(FOffsetCoords Origin, int Direction, FOffsetCoords& Offset)
{
	if (Diagonals_Hex().IsValidIndex(Direction))
	{
		FVector cube = UGridsCore::Conv_OffsetToCube(Origin);
		FVector diag = cube + Diagonals_Hex()[Direction];
		Offset = UGridsCore::Conv_CubeToOffset(diag);
		return diag;
	}
	return FVector::ZeroVector;
}

FVector UGridsHex::GetHexDiagonal(FOffsetCoords Origin, int Direction)
{
	if (Diagonals_Hex().IsValidIndex(Direction))
	{
		FVector Cube = UGridsCore::Conv_OffsetToCube(Origin);
		FVector Diag = Cube + Diagonals_Hex()[Direction];
		return Diag;
	}
	return FVector::ZeroVector;
}

TArray<FVector> UGridsHex::GetHexDiagonals(FOffsetCoords Origin)
{
	FVector C = UGridsCore::Conv_OffsetToCube(Origin);
	TArray<FVector> myDiagonals;
	for (auto& n : Diagonals_Hex())
	{
		myDiagonals.Emplace(n + C);
	}
	return myDiagonals;
}

FVector2D UGridsHex::GetHexCorner(FOffsetCoords Origin, int Direction, float TileHeight, FVector2D GridScale, float& ZRotationToCenter, float Slide)
{
	const FVector2D ScaledCoords = UGridsCore::Conv_OffsetToVector2D(ScaleAndOffset(Origin, GridScale));
	const FVector ScaledCoord3D = FVector(ScaledCoords, 0);

	FVector2D Position, ReturnPosition;
	ZRotationToCenter = 0.0;

	float StartAngle = 0.5; // 0 for flat topped hex.
	float angle = 2.0 * PI * (StartAngle - Direction) / 6;
	Position.X = ScaledCoords.X + (TileHeight * cos(angle) / 2);
	Position.Y = ScaledCoords.Y + (TileHeight * sin(angle) / 2);

	const FVector Position3D = FVector(Position, 0);

	//FRotator SlideDirection = UKismetMathLibrary::FindLookAtRotation(FVector(RelativePosition, 0.0), FVector(ScaledCoords, 0));
	ReturnPosition = FVector2D(UKismetMathLibrary::VLerp(ScaledCoord3D, Position3D, Slide));

	ZRotationToCenter = UKismetMathLibrary::FindLookAtRotation(ScaledCoord3D, Position3D).Yaw;
	return ReturnPosition;
	
}

FVector UGridsHex::GetHexNeighboursByEnum(FOffsetCoords Origin, EHexNeighbours Selected, FOffsetCoords& Offset)
{
	FVector cube = UGridsCore::Conv_OffsetToCube(Origin);
	FVector n = cube + Neighbours_Hex()[int(Selected)];
	Offset = UGridsCore::Conv_CubeToOffset(n);
	return n;
}

FVector UGridsHex::GetHexDiagonalsByEnum(FOffsetCoords Origin, EHexDiagonals Selected, FOffsetCoords& Offset)
{
	FVector cube = UGridsCore::Conv_OffsetToCube(Origin);
	FVector diag = cube + Diagonals_Hex()[int(Selected)];
	Offset = UGridsCore::Conv_CubeToOffset(diag);
	return diag;
}

bool UGridsHex::FindNeighbourFromAdjacentOffsets(FOffsetCoords Origin, FOffsetCoords Target, bool bAllowDiagonal, int& Direction)
{
	FVector OriginCube = UGridsCore::Conv_OffsetToCube(Origin);
	FVector TargetCube = UGridsCore::Conv_OffsetToCube(Target);

	int LoopCount = 0;
	for (FVector i : GetHexNeighbours(Origin))
	{
		if (i == TargetCube)
		{
			Direction = LoopCount;
			return true;
		}
		LoopCount++;
	}

	for (FVector j : GetHexDiagonals(Origin))
	{
		if (j == TargetCube)
		{
			Direction = LoopCount;
			return true;
		}
		LoopCount++;
	}

	Direction = -1;
	return false;
}

//----------------------------//
// Generators
//----------------------------//

TArray<FOffsetCoords> UGridsHex::BuildRectangleArray(FOffsetCoords Size, bool bCenterGrid)
{
	TArray<FOffsetCoords> results;

	int xMin, xMax, yMin, yMax;
	
	if (bCenterGrid)
	{
		xMin = FMath::CeilToInt(float(-Size.Col) / 2.0);
		xMax = FMath::CeilToInt(float(Size.Col) / 2.0);
		yMin = FMath::CeilToInt(float(-Size.Row) / 2.0);
		yMax = FMath::CeilToInt(float(Size.Row) / 2.0);
	}
	else
	{
		xMin = 0;
		xMax = Size.Col;
		yMin = 0;
		yMax = Size.Row;
	}
	
	for (int i = xMin; i < xMax; i++)
	{
		for (int j = yMin; j < yMax; j++)
		{
			FOffsetCoords coord;
			coord.Col = i;
			coord.Row = j;
			results.Emplace(coord);
		};
	};
	return results;
};

TArray<FOffsetCoords> UGridsHex::BuildHexagonArray(FOffsetCoords Size)
{
	TArray<FOffsetCoords> resultsOffset = {};
	int radius = Size.Col;

	for (int i = -radius; i <= radius; i++)
	{
		int r1 = FMath::Max(-radius, -i - radius);
		int r2 = FMath::Min(radius, -i + radius);
		for (int j = r1; j <= r2; j++)
		{
			FVector tile = (FVector(j, i, -i - j));
			resultsOffset.Emplace(UGridsCore::Conv_CubeToOffset(tile));
		}
	}
	return resultsOffset;
}

TArray<FOffsetCoords> UGridsHex::BuildTriangleArray(FOffsetCoords Size)
{
	TArray<FOffsetCoords> results = {};
	int iSize = Size.Col;

	for (int i = 0; i < iSize; i++)
	{
		for (int j = 0; j < (iSize - i); j++)
		{
			FVector a = FVector(j, i, -i - j);
			results.Emplace(UGridsCore::Conv_CubeToOffset(a));
		}
	}
	return results;
}

TArray<FOffsetCoords> UGridsHex::BuildParallelogramArray(FOffsetCoords Size, bool bCenterGrid)
{
	TArray<FOffsetCoords> results;

	int xMin, xMax, yMin, yMax;

	if (bCenterGrid)
	{
		xMin = FMath::CeilToInt(float(-Size.Col) / 2.0);
		xMax = FMath::CeilToInt(float(Size.Col) / 2.0);
		yMin = FMath::CeilToInt(float(-Size.Row) / 2.0);
		yMax = FMath::CeilToInt(float(Size.Row) / 2.0);
	}
	else
	{
		xMin = 0;
		xMax = Size.Col;
		yMin = 0;
		yMax = Size.Row;
	}

	for (int Col = xMin; Col <= xMax; Col++)
	{
		for (int Row = yMin; Row <= yMax; Row++)
		{
			FVector a = FVector(Row, Col, -Col - Row);
			results.Emplace(UGridsCore::Conv_CubeToOffset(a));
		}
	}
	return results;
}

//----------------------------//
// Utility
//----------------------------//

void UGridsHex::HexWidth(float Height, float& Width)
{
	static const float sqrt3over2 = sqrt(3)/2;
	Width = sqrt3over2 * Height;
}

FVector UGridsHex::RoundHex(FVector a)
{
	int q = int(round(a.X));
	int r = int(round(a.Y));
	int s = int(round(a.Z));

	float q_diff = FMath::Abs(q - a.X);
	float r_diff = FMath::Abs(r - a.Y);
	float s_diff = FMath::Abs(s - a.Z);

	if (q_diff > r_diff && q_diff > s_diff)
	{
		q = -r - s;
	}

	else if (r_diff > s_diff)
	{
		r = -q - s;
	}

	else
	{
		s = -q - r;
	}
	return FVector(q, r, s);
}

FOffsetCoords UGridsHex::ScaleAndOffset(FOffsetCoords GridTile, FVector2D GridScale, FVector2D& precise)
{
	float y = (GridTile.Col * GridScale.Y) + ((GridScale.Y / 2) * (GridTile.Row & 1));
	float x = GridTile.Row * GridScale.X;

	FOffsetCoords coord;
	coord.Col = int(x), coord.Row = int(y);
	precise.X = y, precise.Y = x;
	return coord;
}

FOffsetCoords UGridsHex::ScaleAndOffset(FOffsetCoords GridTile, FVector2D GridScale)
{
	float y = (GridTile.Col * GridScale.Y) + ((GridScale.Y / 2) * (GridTile.Row & 1));
	float x = GridTile.Row * GridScale.X;

	FOffsetCoords coord;
	coord.Col = int(x), coord.Row = int(y);
	return coord;
}

FVector2D UGridsHex::ScaleAndOffset(FVector2D GridTile, FVector2D GridScale)
{
	float y = (GridTile.Y * GridScale.Y) + ((GridScale.Y / 2) * (int(GridTile.X) & 1));
	float x = GridTile.X * GridScale.X;

	FOffsetCoords coord;
	coord.Col = int(x), coord.Row = int(y);
	return FVector2D(y, x);
}

int UGridsHex::HexLength(FVector hex)
{
	return int((FMath::Abs(hex.X) + FMath::Abs(hex.Y) + FMath::Abs(hex.Z)) / 2);
}

int UGridsHex::ManhattanDistanceCube(FVector a, FVector b)
{
	return HexLength(a - b);
}

int UGridsHex::ManhattanDistanceOffset(FOffsetCoords a, FOffsetCoords b)
{
	return HexLength(UGridsCore::Conv_OffsetToCube(a) - UGridsCore::Conv_OffsetToCube(b));
}

void UGridsHex::RotateAroundPoint(FOffsetCoords Pivot, FOffsetCoords Tile, bool bClockwise, FOffsetCoords& Coords, FVector& Cube)
{
	FVector c = UGridsCore::Conv_OffsetToCube(Pivot);
	FVector p = UGridsCore::Conv_OffsetToCube(Tile);
	FVector pc = p - c;
	FVector rc = (!bClockwise) ? FVector(-pc.Z, -pc.X, -pc.Y) : FVector(-pc.Y, -pc.Z, -pc.X);
	FVector r = rc + c;

	Coords = UGridsCore::Conv_CubeToOffset(r);
	Cube = r;
}

// -----------------------------------------------------------//
// Core Functions
// -----------------------------------------------------------//

void UGridsHex::LineDraw(FOffsetCoords Start, FOffsetCoords Goal, TArray<FOffsetCoords>& Offset)
{
	FVector a = UGridsCore::Conv_OffsetToCube(Start);
	FVector b = UGridsCore::Conv_OffsetToCube(Goal);
	int n = ManhattanDistanceCube(a, b);

	FVector a_nudge = FVector(a.X + 0.000001, a.Y + 0.000001, a.Z + 0.000002);
	FVector b_nudge = FVector(b.X + 0.000001, b.Y + 0.000001, b.Z + 0.000002);
	float step = 1.0 / FMath::Max(n, 1);
	TArray<FVector> cubeResults;

	for (int i = 0; i <= n; i++)
	{
		FVector cube = (RoundHex(FMath::Lerp(a_nudge, b_nudge, step * i)));
		cubeResults.Emplace(cube);
		Offset.Emplace(UGridsCore::Conv_CubeToOffset(cube));
	}
}

void UGridsHex::MovementRange(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset)
{
	TArray<FOffsetCoords> results = {};
	FVector cube = UGridsCore::Conv_OffsetToCube(Origin);
	for (int dx = -Radius; dx <= Radius; dx++)
	{
		int r1 = FMath::Max(-Radius, -dx - Radius);
		int r2 = FMath::Min(Radius, -dx + Radius);
		for (int dy = r1; dy <= r2; dy++)
		{
			int dz = -dx - dy;
			FVector cubeCoord = cube + FVector(dx, dy, dz);
			results.Emplace(UGridsCore::Conv_CubeToOffset(cubeCoord));
		}
	}
	Offset = results;
}

void UGridsHex::SingleRing(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset)
{
	TArray<FOffsetCoords> results = {};
	if (Radius > 0)
	{
		FVector o = UGridsCore::Conv_OffsetToCube(Origin);
		FVector cube = o + (Neighbours_Hex()[4] * Radius);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < (Radius); j++)
			{
				results.Emplace(UGridsCore::Conv_CubeToOffset(cube));
				cube = cube + Neighbours_Hex()[i];
			}
		}
	}
	Offset = results;
}

void UGridsHex::SingleRingExtended(FOffsetCoords Origin, int Radius, float SwizzleRotation, TArray<FOffsetCoords>& Ring, TArray<float>& RotationInfo, TArray<bool>& bIsCornerTile)
{
	Ring.Empty();
	RotationInfo.Empty();
	bIsCornerTile.Empty();
	if (Radius > 0)
	{
		FVector CubeCoord = UGridsCore::Conv_OffsetToCube(Origin);
		FVector cube = CubeCoord + (Neighbours_Hex()[4] * Radius);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < (Radius); j++)
			{
				RotationInfo.Emplace(60 * i - SwizzleRotation);
				Ring.Emplace(UGridsCore::Conv_CubeToOffset(cube));
				cube += Neighbours_Hex()[i];
				bIsCornerTile.Emplace(j == 0 || j == Radius);
			}
		}
	}
}

void UGridsHex::SpiralRing(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset)
{
	TArray<FOffsetCoords> OffsetHolder;
	for (int i = 0; i <= Radius; i++)
	{
		SingleRing(Origin, i, OffsetHolder);
		Offset.Append(OffsetHolder);
	}
}

void UGridsHex::SpiralRingExtended(FOffsetCoords Origin, int Radius, float SwizzleRotation, TArray<FOffsetCoords>& Ring, TArray<float>& RotationInfo, TArray<bool>& bIsCornerTile)
{
	Ring.Empty();
	RotationInfo.Empty();
	bIsCornerTile.Empty();

	TArray<FOffsetCoords> OffsetHolder;
	for (int i = 0; i <= Radius; i++)
	{
		TArray<FOffsetCoords> RingIteration;
		TArray<float> RotationIteration;
		TArray<bool> CornerIteration;

		SingleRingExtended(Origin, i, SwizzleRotation, RingIteration, RotationIteration, CornerIteration);

		Ring.Append(RingIteration);
		RotationInfo.Append(RotationIteration);
		bIsCornerTile.Append(CornerIteration);
	}
}

TArray<FOffsetCoords> UGridsHex::FloodFill(FOffsetCoords Origin, float MaxCost, TArray<FOffsetCoords> Grid, TMap<FOffsetCoords, FVisitedNode>& Visited, TSet<FOffsetCoords> BlockedTiles, TMap<FOffsetCoords, float> CostMap)
{
	TArray<FVisitedNode> TraveledMap;
	Visited.Empty();
	TArray<FOffsetCoords> SearchList = { Origin }; // Create the Search List with the origin as the only element

	FVisitedNode x;
	x.Cost = 0.0, x.PreviousNode = Origin;
	Visited.Emplace(Origin, x);

	TArray<FOffsetCoords> newSearch;
	while (SearchList.Num()) // While there's things to search;
	{
		newSearch.Empty();
		for (auto& SearchNode : SearchList)
		{
			FVisitedNode NewTravelEntry;
			NewTravelEntry.Cost = Visited[SearchNode].Cost;
			NewTravelEntry.PreviousNode = SearchNode;
			TraveledMap.Emplace(NewTravelEntry); // Traveled map is mostly for debugging how the fill expands.
			
			for (auto& NeighbourNode : GetHexNeighbours(SearchNode))
			{
				if (BlockedTiles.Contains(UGridsCore::Conv_CubeToOffset (NeighbourNode)))
				{
					continue;
				}

				float TransitionCost = CostMap.Find(UGridsCore::Conv_CubeToOffset(NeighbourNode)) ? CostMap[UGridsCore::Conv_CubeToOffset(NeighbourNode)] : 1.0f;
				float NewCost = Visited[SearchNode].Cost + TransitionCost; // Calculate cost to reach new node
				
				if (!Visited.Contains(UGridsCore::Conv_CubeToOffset(NeighbourNode))) // if we haven't visited and the new cost to reach the node is within max cost
				{
					if (NewCost <= MaxCost)
					{
						FVisitedNode updateVisited;
						updateVisited.Cost = NewCost, updateVisited.PreviousNode = SearchNode;
						Visited.Emplace(UGridsCore::Conv_CubeToOffset(NeighbourNode), updateVisited);
						newSearch.Emplace(UGridsCore::Conv_CubeToOffset(NeighbourNode));
					}
				}
				else if (NewCost < Visited[UGridsCore::Conv_CubeToOffset(NeighbourNode)].Cost) // Visited wouldn't exist if it wasn't currently within tolerance
				{
					Visited[UGridsCore::Conv_CubeToOffset(NeighbourNode)].Cost = NewCost;
					Visited[UGridsCore::Conv_CubeToOffset(NeighbourNode)].PreviousNode = SearchNode; // Check with Dave on this node as well.
					newSearch.Emplace(UGridsCore::Conv_CubeToOffset(NeighbourNode)); // Run the search on this node again as it may cause new paths to be cheaper
				}
			}
		}
		SearchList = newSearch;
		SearchList.Sort([&Visited](const FOffsetCoords& A, const FOffsetCoords& B)
		{
			return Visited[A].Cost < Visited[B].Cost;
		});
	}
	TArray<FOffsetCoords> finalArray;
	Visited.GenerateKeyArray(finalArray);
	return finalArray;
}

TArray<FOffsetCoords> UGridsHex::FindPathFromFloodFill(FOffsetCoords Goal, TMap<FOffsetCoords, FVisitedNode> Visited, bool& PathFound)
{
	FOffsetCoords CurrentNode = Goal;
	TArray<FOffsetCoords> Path = { Goal };
	if (Visited.Find(Goal))
	{
		while (CurrentNode != Visited[CurrentNode].PreviousNode)
		{
			CurrentNode = Visited[CurrentNode].PreviousNode;
			Path.Emplace(CurrentNode);
		}
		PathFound = true;
		return Path;
	}
	PathFound = false;
	return Path;
}

// -----------------------------------------------------------//
// Pathfinding
// -----------------------------------------------------------//

int32 AStarWrapper::GetNeighbourCount(const FNodeRef NodeRef) const
{
	int x = bAllowDiagonal ? 12 : 6;
	return x;
}

bool AStarWrapper::IsValidRef(const FNodeRef NodeRef) const

{
	// Currently the checks are both done in IsTraversalAllowed. 
	return true;
}

AStarWrapper::FNodeRef AStarWrapper::GetNeighbour(const FNodeRef NodeRef, const int32 NeighbourIndex) const
{
	return NodeRef + UGridsHex::NeighboursAndDiagonals_Hex()[NeighbourIndex];
}

// A*

void UGridsHex::AStarPathfinding(FOffsetCoords StartPoint, FOffsetCoords EndPoint, TArray<FOffsetCoords> Grid, TMap<FOffsetCoords, float> Cost, TSet<FOffsetCoords> Blocked, FOffsetCoords MaxSize, bool bAllowInexact, bool bAllowDiagonal, bool& bSuccess, TArray<FVector>& Results)
{
	// Convert Blocked Offsets to Cube
	TSet<FVector> InBlocked = {};
	for (auto& i : Blocked)
	{
		InBlocked.Emplace(UGridsCore::Conv_OffsetToCube(i));
	};
	
	TArray<FOffsetCoords> InGrid = Grid;

	struct FAStarHexFilter
	{
		const bool bAllowInexact;
		const AStarWrapper& Framework;

		explicit FAStarHexFilter(const bool bExactSearch, const AStarWrapper& InFramework)
			: bAllowInexact(bExactSearch), Framework(InFramework)
		{
		}

		FORCEINLINE float GetHeuristicScale() const 
		{ 
			return 1.f; 
		}
		FORCEINLINE float GetHeuristicCost(const AStarWrapper::FNodeRef StartNodeRef, const AStarWrapper::FNodeRef EndNodeRef) const
		{
			return FVector::Dist(StartNodeRef, EndNodeRef);
		}
		FORCEINLINE float GetTraversalCost(const AStarWrapper::FNodeRef StartNodeRef, const AStarWrapper::FNodeRef EndNodeRef) const
		{
			const float* TileCostPointer = Framework.Cost->Find(UGridsCore::Conv_CubeToOffset(EndNodeRef));
			float TileCost = (TileCostPointer) ? *TileCostPointer : 1.f;
			return TileCost * FVector::Dist(StartNodeRef, EndNodeRef); // Multiply by Tile Cost
		}
		FORCEINLINE bool IsTraversalAllowed(const AStarWrapper::FNodeRef NodeA, const AStarWrapper::FNodeRef NodeB) const
		{
			// Blocked grid will be smaller, so check first. If not in blocked grid, and is in grid, traversal is allowed
			if (!Framework.Blocked->Contains(NodeB) && Framework.Grid->Contains(UGridsCore::Conv_CubeToOffset(NodeB)))
			{
				return true;
			}
			return false;
		}
		FORCEINLINE bool WantsPartialSolution() const
		{
			return bAllowInexact;
		}
	};

	AStarWrapper GridWrapper(&Cost, &InBlocked, bAllowDiagonal, &InGrid);

	FGraphAStar<AStarWrapper> PathFinder(GridWrapper);
	FAStarHexFilter HexFilter(bAllowInexact, GridWrapper);
	const EGraphAStarResult Status = PathFinder.FindPath(UGridsCore::Conv_OffsetToCube(StartPoint), UGridsCore::Conv_OffsetToCube(EndPoint), HexFilter, Results);
	bSuccess = (Status == EGraphAStarResult::SearchSuccess);




};

TArray<FVector> UGridsHex::AStarToWorldCoordinates(TArray<FVector> Results, FVector2D GridScale, AActor* GridActor)
{
	TArray<FOffsetCoords> CoordResults = UGridsCore::Conv_CubeArrayToOffsetArray(Results);
	TArray<FOffsetCoords> ScaledCoordResults;
	TArray<FVector> WorldPositions;

	for (auto& i : CoordResults)
	{
		ScaledCoordResults.Emplace(ScaleAndOffset(i, GridScale));
	}

	for (auto& j : ScaledCoordResults)
	{
		WorldPositions.Emplace(UKismetMathLibrary::TransformLocation(GridActor->GetTransform(), UGridsCore::Conv_OffsetToVector(j, 0.0)));
	}
	return WorldPositions;
}


	
