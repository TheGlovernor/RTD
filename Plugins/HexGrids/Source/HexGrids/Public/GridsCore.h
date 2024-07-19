// Copyright 2017 Daniel Orchard. All Rights Reserved.

#pragma once

#include "OffsetCoords.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GraphAStar.h" // For Pathfinding
#include "GridsCore.generated.h"



//----------------------------//
// Structs
//----------------------------//

USTRUCT(BlueprintType)
struct FVisitedNode
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Grids")
	float Cost;

	UPROPERTY(BlueprintReadOnly, Category = "Grids")
	FOffsetCoords PreviousNode;

	FVisitedNode()
	{
		Cost = 0.0f;
		FOffsetCoords();
	};
};


// Grids Core is a function library for all functionality not directly related to hexagonal shaped grids.
UCLASS()
class HEXGRIDS_API UGridsCore : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:

	//----------------------------//
	// Checks
	//----------------------------//

	/** Returns True if float input value is odd. */
	UFUNCTION(BlueprintPure, Category = "Grids|Checks")
	static bool IsOddFloat(const float A);

	/** Returns True if int input value is odd. */
	UFUNCTION(BlueprintPure, Category = "Grids|Checks")
	static bool IsOddInt(const int A);


	//----------------------------//
	// Converters
	//----------------------------//

	/** Convert offset coordinates into cube coordinates. */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Cube (Offset)", Keywords = "convert"))
	static FVector Conv_OffsetToCube(FOffsetCoords Offset);

	/** Convert Cube coordinates into offset coordinates */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Offset (Cube)", Keywords = "convert"))
	static FOffsetCoords Conv_CubeToOffset(FVector Cube);

	/** Convert whole cube array into a offset coordinate array */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Offset Array (Cube Array)", Keywords = "convert"))
	static TArray<FOffsetCoords> Conv_CubeArrayToOffsetArray(TArray<FVector> CubeArray);

	/** Convert whole offset array into a cube coordinate array */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Cube Array (Offset Array)", Keywords = "convert"))
	static TArray<FVector> Conv_OffsetArrayToCubeArray(TArray<FOffsetCoords> OffsetArray);

	/** Convert a Vector2D to a OffsetCoord. */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "ToVector2D (OffsetCoords)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "convert"))
	static FVector2D Conv_OffsetToVector2D(FOffsetCoords Offset);

	/** Convert a OffsetCoord to a Vector2D. */
	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "ToOffsetCoords (Vector2D)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "convert"))
	static FOffsetCoords Conv_Vector2DToOffsetCoords(FVector2D Vector);

	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Vector2D Array (Offset Array)", Keywords = "convert"))
	static TArray<FVector2D> Conv_OffsetArrayToVector2DArray(TArray<FOffsetCoords> OffsetArray);

	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Offset Array (Vector2D Array)", Keywords = "convert"))
	static TArray<FOffsetCoords> Conv_Vector2DArrayToOffsetArray(TArray<FVector2D> Vector2DArray);

	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Offset Array (VisitedNodes Array)", Keywords = "convert"))
	static TArray<FOffsetCoords> Conv_VisitedNodesToOffsetArray(TArray<FVisitedNode> VisitedNodes);

	UFUNCTION(BlueprintPure, Category = "Grids|Converters", meta = (DisplayName = "To Vector (Offset)", CompactNodeTitle = "->", BlueprintAutocast, Keywords = "convert"))
	static FVector Conv_OffsetToVector(FOffsetCoords A, float Z);

	UFUNCTION(BlueprintPure, Category = "Grids|Utility")
	static FVector InvertVector(FVector InA);

	UFUNCTION(BlueprintCallable, Category = "Grids|Save")
	static TArray<FString> FindAllSaveFiles();


};