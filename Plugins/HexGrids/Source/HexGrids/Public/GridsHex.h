// Copyright 2017 Daniel Orchard. All Rights Reserved.

#pragma once

#include "HexGrids.h"
#include "OffsetCoords.h"
#include "GridsCore.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GridsHex.generated.h"

//struct FOffsetCoords;
//struct FVisitedNode;


//----------------------------//
// Enums
//----------------------------//

/** Enum for selecting neighbouring tiles */
UENUM(BlueprintType, meta = (ToolTip = "Enum for Hex Tiles, note that this enum should not be exposed to end users as text (Will appear differently in packaged builds)"))
enum class EHexNeighbours : uint8
{
	HexGrids_NeighbourTopRight		UMETA(DisplayName = "Top Right (Neighbour)"),
	HexGrids_NeighbourRight			UMETA(DisplayName = "Right (Neighbour)"),
	HexGrids_NeighbourBottomRight	UMETA(DisplayName = "Bottom Right (Neighbour)"),
	HexGrids_NeighbourBottomLeft	UMETA(DisplayName = "Bottom Left (Neighbour)"),
	HexGrids_NeighbourLeft			UMETA(DisplayName = "Left (Neighbour)"),
	HexGrids_NeighbourTopLeft		UMETA(DisplayName = "Top Left (Neighbour)"),
};

/** Enum for selecting diagonal tiles */
UENUM(BlueprintType, meta = (ToolTip = "Enum for Hex Tiles, note that this enum should not be exposed to end users as text (Will appear differently in packaged builds)"))
enum class EHexDiagonals : uint8
{
	HexGrids_DiagonalTop			UMETA(DisplayName = "Top (Diagonal)"),
	HexGrids_DiagonalTopRight		UMETA(DisplayName = "Top Right (Diagonal)"),
	HexGrids_DiagonalBottomRight	UMETA(DisplayName = "Bottom Right (Diagonal)"),
	HexGrids_DiagonalBottom			UMETA(DisplayName = "Bottom (Diagonal)"),
	HexGrids_DiagonalBottomLeft		UMETA(DisplayName = "Bottom Left (Diagonal)"),
	HexGrids_DiagonalTopLeft		UMETA(DisplayName = "Top Left (Diagonal)"),
};

/** Enum for selecting a generation type */
UENUM(BlueprintType, meta = (ToolTip = "Utility enum for choosing a generation shape"))
enum class EHexGridShape : uint8
{
	HexGrids_Rectangle				UMETA(DisplayName = "Rectangle"),
	HexGrids_Hexagon				UMETA(DisplayName = "Hexagon"),
	HexGrids_Triangle				UMETA(DisplayName = "Triangle"),
	HexGrids_Parallelogram			UMETA(DisplayName = "Parallelogram"),
};

/** Enum for selecting a meshing type */
UENUM(BlueprintType, meta = (ToolTip = "Utility enum for choosing a generation shape"))
enum class EHexGridMeshType : uint8
{
	HexGrids_StaticMeshes		UMETA(DisplayName = "Static Meshes"),
	HexGrids_InstanceMeshes		UMETA(DisplayName = "Instance Mesh Component"),
	HexGrids_Blueprints			UMETA(DisplayName = "Blueprints (Runtime Only)"),
	HexGrids_Custom				UMETA(DisplayName = "Custom"),
};



// Main function library for grid code directly relating to hexagonal grids.
UCLASS()
class HEXGRIDS_API UGridsHex : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// ctor - blank
	UGridsHex();

public:

	//----------------------------//
	// Const Values
	//----------------------------//

	/**
	*	Cube Coordinate Neighbour
	*	TopRight, Right, BottomRight, BottomLeft,Left,TopLeft
	*/
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> Neighbours_Hex();

	/**
	*	Cube Coordinate Diagonals
	*	TopRight, Right, BottomRight, BottomLeft,Left,TopLeft
	*/
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> Diagonals_Hex();

	/**
	*	Cube Coordinate Neighbour and diagonal combined
	*	Neighbour + Diagonal
	*/
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> NeighboursAndDiagonals_Hex();

	/** To be used with RotatorFromAxisAndAngle */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> RotateTowardsNeighbourAxis_Hex();

	/** To be used with RotatorFromAxisAndAngle */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> RotateTowardsDiagonalAxis_Hex();

	/** To be used with RotatorFromAxisAndAngle */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional|Constants")
	static const TArray<FVector> RotateTowardsNeighbourOrDiagonal_Hex();

	//----------------------------//
	// Neighbour Code
	//----------------------------//

	/** Get Cube Neighbour based of origin */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static FVector GetHexNeighbour(FOffsetCoords Origin, int Direction, FOffsetCoords& Offset);

	/** Return an array of all tile Neighbours */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static TArray<FVector> GetHexNeighbours(FOffsetCoords Origin);

	/** Get Cube Diagonal based of origin, also returns as Offset */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static FVector GetHexDiagonal(FOffsetCoords Origin, int Direction, FOffsetCoords& Offset);

	/** Get Cube Diagonal based of origin. Overload for no Offset*/
	static FVector GetHexDiagonal(FOffsetCoords Origin, int Direction);

	/** Contains all diagonal directions */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static TArray<FVector> GetHexDiagonals(FOffsetCoords Origin);

	/** 
	*	Get the tile corner. The tile height must be the actual size of your tile Y. You can check this in the static mesh editor with the approx size stats (top left of viewport)
		@param TileHeight - Height (Y) of the hexagon.
		@param GridScale - Needs to be both Axis of the grid Scale. Recommended you use the GridScaleCaculated value.
		@param Slide - Lerps from Origin to Corner. Generally you want a value of 1, going beyond 1 will push out of the corner.
	*/
	UFUNCTION(BlueprintPure, Category = "Grids|Directional", meta=(ReturnDisplayName = "Relative Location"))
	static FVector2D GetHexCorner(FOffsetCoords Origin, int Direction, float TileHeight, FVector2D GridScale, float& ZRotationToCenter, float Slide = 1.0);

	/** Get the tile neighbours via enum neighbours */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static FVector GetHexNeighboursByEnum(FOffsetCoords Origin, EHexNeighbours Selected, FOffsetCoords& Offset);

	/** Get the tile diagonals via enum diagonals */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static FVector GetHexDiagonalsByEnum(FOffsetCoords Origin, EHexDiagonals Selected, FOffsetCoords& Offset);

	/** Using a origin and a target, return which direction target is from origin. */
	UFUNCTION(BlueprintPure, Category = "Grids|Directional")
	static bool FindNeighbourFromAdjacentOffsets(FOffsetCoords Origin, FOffsetCoords Target, bool bAllowDiagonal, int& Direction);

	//----------------------------//
	// Generators
	//----------------------------//

	/** Generate coordinates in a rectangle shape */
	UFUNCTION(BlueprintCallable, Category = "Grids|Generators", meta = (Keyword = "generator square"))
	static TArray<FOffsetCoords> BuildRectangleArray(FOffsetCoords Size, bool bCenterGrid);

	/** Generate coordinates in a hexagonal shape */
	UFUNCTION(BlueprintCallable, Category = "Grids|Generators", meta = (Keyword = "generator"))
	static TArray<FOffsetCoords> BuildHexagonArray(FOffsetCoords Size);

	/** Generate coordinates in a parallelogram shape */
	UFUNCTION(BlueprintCallable, Category = "Grids|Generators", meta = (Keyword = "generator diamond rhombus "))
	static TArray<FOffsetCoords> BuildParallelogramArray(FOffsetCoords Size, bool bCenterGrid);

	/** Generate coordinates in a triangle shape */
	UFUNCTION(BlueprintCallable, Category = "Grids|Generators", meta = (Keyword = "generator"))
	static TArray<FOffsetCoords> BuildTriangleArray(FOffsetCoords Size);

	//----------------------------//
	// Utility
	//----------------------------//

	/** Generate Hex width from Height */
	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static void HexWidth(float Height, float& Width);

	/** Round the vector and compare offsets, to shift value back onto the correct tile. Has a slight bias to help generate straight lines */
	UFUNCTION(BlueprintCallable, Category = "Grids|Utility")
	static FVector RoundHex(FVector a);

	/** Take a coordinate grid, and scale the grid by tile size, so it can be used as a location.  */
	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static FOffsetCoords ScaleAndOffset(FOffsetCoords GridTile, FVector2D GridScale, UPARAM(DisplayName = "RelativeLocation") FVector2D& Precise);

	/** Overload of ScaleAndOffset to not return a FVector2D */
	static FOffsetCoords ScaleAndOffset(FOffsetCoords GridTile, FVector2D GridScale);

	/** Overload of ScaleAndOffset to take in a FVector2D */
	static FVector2D ScaleAndOffset(FVector2D GridTile, FVector2D GridScale);

	/** Combines vector into a single length */
	UFUNCTION()
	static int HexLength(FVector hex);

	/** Get the Manhattan Distance (Walks along the grid) between A and B. */
	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static int ManhattanDistanceCube(FVector a, FVector b);

	/** Get the Manhattan Distance (Walks along the grid) between A and B. */
	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static int ManhattanDistanceOffset(FOffsetCoords a, FOffsetCoords b);

	/** Rotates a tile around a pivot at 60 degree increments */
	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static void RotateAroundPoint(FOffsetCoords Pivot, FOffsetCoords Tile, bool bClockwise, FOffsetCoords& Coords, FVector& Cube);

	//----------------------------//
	// Core
	//----------------------------//

	/** Draw a line between start and goal, walking across the tiles. */
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void LineDraw(FOffsetCoords Start, FOffsetCoords Goal, TArray<FOffsetCoords>& Offset);

	/** Return all tiles within a radius of tile. */
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void MovementRange(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset);

	/** Return all coordinates in a ring shape at a radial distance from tile */
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void SingleRing(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset);

	/** Return all coordinates in a ring shape at a radial distance from tile. Also includes info about rotation and corners */
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void SingleRingExtended(FOffsetCoords Origin, int Radius, float SwizzleRotation, TArray<FOffsetCoords>& Ring, TArray<float>& RotationInfo, TArray<bool>& bIsCornerTile);


	/** Return all coordinates in a spiral ring shape at a radial distance from tile.
	*   This is functionally the same as MovementRange, but the order and method differ.
	*   It is best used when you are looping through with a delay so the different order is useful.
	*/
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void SpiralRing(FOffsetCoords Origin, int Radius, TArray<FOffsetCoords>& Offset);

	/** Return all coordinates in a spiral ring shape at a radial distance from tile.
	*   This is functionally the same as MovementRange, but the order and method differ.
	*	Also includes info about rotation and corners
	*   It is best used when you are looping through with a delay so the different order is useful.
	*/
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static void SpiralRingExtended(FOffsetCoords Origin, int Radius, float SwizzleRotation, TArray<FOffsetCoords>& Ring, TArray<float>& RotationInfo, TArray<bool>& bIsCornerTile);


	/**
	* Flood Fill.
	@Param origin - Starting location to flood from.
	@Param MaxCost - The maximum cost any path can reach.
	@Param grid - The generated map coordinates to search through.
	@Param Visited - The visited tiles for reconstructing a path to a point
	@Param TraveledMap - Mostly for debugging, shows how the flood fill expanded.
	*/
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions", meta = (AutoCreateRefTerm = "CostMap,BlockedTiles"))
	static TArray<FOffsetCoords> FloodFill(FOffsetCoords Origin, float MaxCost, TArray<FOffsetCoords> Grid, TMap<FOffsetCoords, FVisitedNode>& Visited, TSet<FOffsetCoords> BlockedTiles, TMap<FOffsetCoords, float> CostMap);

	/** Traverses the Flood Fill visited map to generate a path from the FloodFill. */
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static TArray<FOffsetCoords> FindPathFromFloodFill(FOffsetCoords Goal, TMap<FOffsetCoords, FVisitedNode> Visited, bool& PathFound);

	//----------------------------//
	// A* Pathfinding
	//----------------------------//

	/**
	* A Star pathfinding implementation.
	@Param StartPoint - Starting location for pathfinding.
	@Param EndPoint - Desired destination to path too.
	@Param MaxSize - Currently not implemented.
	@Param AllowInexact - If a complete path cannot be achieved, should return the closest path found? If using this, you should not use the Success bool.
	@Param bSuccess - Was a complete path found (or closest available if incomplete is true).
	@Param Results - The reconstructed path.
	*/
	UFUNCTION(BlueprintCallable, Category = "Grids|Functions", meta = (AutoCreateRefTerm = "Cost,Blocked"))
	static void AStarPathfinding(FOffsetCoords StartPoint, FOffsetCoords EndPoint, TArray<FOffsetCoords> Grid, TMap<FOffsetCoords, float> Cost, TSet<FOffsetCoords> Blocked, FOffsetCoords MaxSize, bool bAllowInexact, bool bAllowDiagonal, bool& bSuccess, UPARAM(DisplayName = "Cube Coord Results") TArray<FVector>& Results);

	UFUNCTION(BlueprintCallable, Category = "Grids|Functions")
	static TArray<FVector> AStarToWorldCoordinates(TArray<FVector> Results, FVector2D GridScale, AActor* GridActor);
	
}; // End UGridHex

// Wrapper class to allow for the Pathfinding to work with a function library
class AStarWrapper
{
public:
	// Pointers
	TMap<FOffsetCoords, float>* Cost;
	TSet<FVector>* Blocked;
	bool bAllowDiagonal;
	TArray<FOffsetCoords>* Grid;

	AStarWrapper(TMap<FOffsetCoords, float>* InCost, TSet<FVector>* InBlocked, bool bInAllowDiagonal, TArray<FOffsetCoords>* InGrid) : Cost(InCost), Blocked(InBlocked), bAllowDiagonal(bInAllowDiagonal), Grid(InGrid) {};

	typedef FVector FNodeRef;
	int32 GetNeighbourCount(const FNodeRef NodeRef) const;
	bool IsValidRef(const FNodeRef NodeRef) const;
	FNodeRef GetNeighbour(const FNodeRef NodeRef, const int32 NeighbourIndex) const;
};