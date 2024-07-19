// Copyright 2017 Daniel Orchard. All Rights Reserved.
#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "OffsetCoords.h"
#include "GridsMathLibrary.generated.h"

// Function Library for exposing FOffsetCoords operators to blueprint.
UCLASS()
class UGridsMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Equal (Offset)", CompactNodeTitle = "==", Keywords = "= equal", ToolTip = "Returns true if A is equal to B (A == B)" ))
	static bool Equal_OffsetOffset(FOffsetCoords A, FOffsetCoords B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Not Equal (Offset)", CompactNodeTitle = "!=", Keywords = "!= notequal", Tooltip = "Returns true is A is not equal to B (A != B)" ))
	static bool NotEqual_OffsetOffset(FOffsetCoords A, FOffsetCoords B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset * Float", CompactNodeTitle = "*", Keywords = "* multiply float", Tooltip = "Scale Offset by Float (A * B)" ))
	static FOffsetCoords Multiply_OffsetFloat(FOffsetCoords A, float B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset * Int", CompactNodeTitle = "*", Keywords = "* multiply int", Tooltip = "Scale Offset by Int (A * B)" ))
	static FOffsetCoords Multiply_OffsetInt(FOffsetCoords A, int B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset * Offset", CompactNodeTitle = "*", Keywords = "* multiply", Tooltip = "Scale Offset by Offset (A * B)" ))
	static FOffsetCoords Multiply_OffsetOffset(FOffsetCoords A, FOffsetCoords B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset * Vector2D", CompactNodeTitle = "*", Keywords = "* multiply vector", Tooltip = "Scale per Channel Offset by Vector2D ((A.Col * B.Y) , (A.Row * B.X))"))
	static FOffsetCoords Multiply_OffsetVector2D(FOffsetCoords A, FVector2D B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset - Offset", CompactNodeTitle = "-", Keywords = "- subtract", Tooltip = "Subtract Offset from Offset (A - B)" ))
	static FOffsetCoords Subtract_OffsetOffset(FOffsetCoords A, FOffsetCoords B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset - Float", CompactNodeTitle = "-", Keywords = "- subtract", Tooltip = "Subtract Offset from Float (A - B)" ))
	static FOffsetCoords Subtract_OffsetFloat(FOffsetCoords A, float B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset - Int", CompactNodeTitle = "-", Keywords = "- subtract", Tooltip = "Subtract Offset from Int (A - B)" ))
	static FOffsetCoords Subtract_OffsetInt(FOffsetCoords A, int B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset / Float", CompactNodeTitle = "/", Keywords = "/ divide", Tooltip = "Divide Offset by Float (A / B)" ))
	static FOffsetCoords Divide_OffsetFloat(FOffsetCoords A, float B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset + Offset", CompactNodeTitle = "+", Keywords = "+ add addition", Tooltip = "Add Offset to Offset (A + B)" ))
	static FOffsetCoords Add_OffsetOffset(FOffsetCoords A, FOffsetCoords B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset + Float", CompactNodeTitle = "+", Keywords = "+ add addition", Tooltip = "Add Offset to Float (A + B)" ))
	static FOffsetCoords Add_OffsetFloat(FOffsetCoords A, float B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths", meta = (DisplayName = "Offset + Vector2D", CompactNodeTitle = "+", Keywords = "+ add addition", Tooltip = "Add Offset to Vector2D ((A.Col + B.Y) + (A.Row + B.X))"))
	static FOffsetCoords Add_OffsetVector2D(FOffsetCoords A, FVector2D B);

	UFUNCTION(BlueprintPure, Category = "Grids|Maths|Random")
	static FOffsetCoords RandomOffsetInRange(FOffsetCoords Min, FOffsetCoords Max);

};


UGridsMathLibrary::UGridsMathLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

};

bool UGridsMathLibrary::Equal_OffsetOffset(FOffsetCoords A, FOffsetCoords B)
{
	return A == B;
}

bool UGridsMathLibrary::NotEqual_OffsetOffset(FOffsetCoords A, FOffsetCoords B)
{
	return A != B;
}

FOffsetCoords UGridsMathLibrary::Multiply_OffsetFloat(FOffsetCoords A, float B)
{
	return A * B;
}

FOffsetCoords UGridsMathLibrary::Multiply_OffsetInt(FOffsetCoords A, int B)
{
	return A * B;
}

FOffsetCoords UGridsMathLibrary::Multiply_OffsetOffset(FOffsetCoords A, FOffsetCoords B)
{
	return A * B;
}

FOffsetCoords UGridsMathLibrary::Multiply_OffsetVector2D(FOffsetCoords A, FVector2D B)
{
	return A * B;
}

FOffsetCoords UGridsMathLibrary::Subtract_OffsetOffset(FOffsetCoords A, FOffsetCoords B)
{
	return A - B;
}

FOffsetCoords UGridsMathLibrary::Subtract_OffsetFloat(FOffsetCoords A, float B)
{
	return A - B;
}

FOffsetCoords UGridsMathLibrary::Subtract_OffsetInt(FOffsetCoords A, int B)
{
	return A - B;
}

FOffsetCoords UGridsMathLibrary::Divide_OffsetFloat(FOffsetCoords A, float B)
{
	return A / B;
}

FOffsetCoords UGridsMathLibrary::Add_OffsetOffset(FOffsetCoords A, FOffsetCoords B)
{
	return A + B;
}

FOffsetCoords UGridsMathLibrary::Add_OffsetFloat(FOffsetCoords A, float B)
{
	return A + B;
}

FOffsetCoords UGridsMathLibrary::Add_OffsetVector2D(FOffsetCoords A, FVector2D B)
{
	return A + B;
}

FOffsetCoords UGridsMathLibrary::RandomOffsetInRange(FOffsetCoords Min, FOffsetCoords Max)
{
	return FOffsetCoords(FMath::RandRange(Min.Col, Max.Col), FMath::RandRange(Min.Row, Max.Row));
}

