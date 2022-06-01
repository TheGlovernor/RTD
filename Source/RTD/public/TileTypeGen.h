// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GridsHex.h"
#include "GridsCore.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "cmath"
#include "TileTypeGen.generated.h"

UENUM(BlueprintType, meta = (ToolTip = ""))
enum class ETileTypes : uint8 {
	Tile_Home			UMETA(DisplayName = "Home"), //0
	Tile_Gate			UMETA(DisplayName = "Gate"), //1
	Tile_Wall			UMETA(DisplayName = "Wall"), //2
	Tile_Grass			UMETA(DisplayName = "Grass"), //3
	Tile_Path			UMETA(DisplayName = "Path"), //4
	Tile_PathHead		UMETA(DisplayName = "PathHead"), //4
	Tile_Portal			UMETA(DisplayName = "Portal") //5
};


/**
 * 
 */
UCLASS(Blueprintable)
class RTD_API UTileTypeGen : public UObject
{
	GENERATED_BODY()

	UTileTypeGen();

public:

	UPROPERTY()
		int seed = 0;
	UPROPERTY()
		int paths;
	UPROPERTY()
		bool pathSet = false;
	UPROPERTY()
		FOffsetCoords origin = FOffsetCoords(0, 0);

	UPROPERTY()
	FOffsetCoords currentCoords = FOffsetCoords(0, 0);



	UPROPERTY(BlueprintReadWrite)
		TMap<FOffsetCoords, ETileTypes> typeMap;

	UPROPERTY(BlueprintReadWrite)
		TMap<FOffsetCoords, float> costMap;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOffsetCoords> grid;

	UPROPERTY(BlueprintReadWrite)
		TSet<FOffsetCoords> blockedMobs;
	
	UPROPERTY(BlueprintReadWrite)
		TSet<FOffsetCoords> blockedToPath;

	UPROPERTY(BlueprintReadWrite)
		TSet<FOffsetCoords> headMap;



	UFUNCTION(BlueprintCallable)
	TArray<FOffsetCoords> getNs(FOffsetCoords c);

	UFUNCTION(BlueprintCallable)
		TArray<FOffsetCoords> getPathableNs(FOffsetCoords c);

	UFUNCTION(BlueprintCallable)
		void clearMap();

	//UFUNCTION(BlueprintCallable)
	//	void initMap(int p, int s, UFastNoiseWrapper* FNW);

	UFUNCTION(BlueprintCallable)
		ETileTypes getType(FOffsetCoords coords);

	UFUNCTION()
		int getx(FOffsetCoords c);

	UFUNCTION()
		int gety(FOffsetCoords c);

	UFUNCTION()
		bool canBePath(FOffsetCoords c);

	UFUNCTION()
		FOffsetCoords CtoO(FVector v);

	UFUNCTION()
		FVector OtoC(FOffsetCoords c);

	UFUNCTION()
		int randIndex(int arrLen);

	UFUNCTION()
		void buildPath(FOffsetCoords c);

	UFUNCTION()
		FOffsetCoords makePortal(FOffsetCoords c);

	UFUNCTION(BlueprintCallable)
		void init(int s, int p);
	UFUNCTION()
		void initPaths(int p);
	UFUNCTION()
		void initCostMap(FOffsetCoords vector);
	UFUNCTION()
		FOffsetCoords nextHexInDirection(FOffsetCoords to, FOffsetCoords from, int distance);
	UFUNCTION()
		void blockNs(FOffsetCoords c);

private:
	UFUNCTION()
		int min(int x, int y);
	UFUNCTION()
		int max(int x, int y);

};
