// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GridsHex.h"
#include "GridsCore.h"
#include <cmath>
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TileHandler.generated.h"

UENUM(BlueprintType, meta = (ToolTip = ""))
enum class ETileTypes2 : uint8 {
	player_base			UMETA(DisplayName = "Base"),
	player_gate			UMETA(DisplayName = "Gate"),
	player_wall			UMETA(DisplayName = "Wall"),
	path				UMETA(DisplayName = "Path")
};

/**
 * 
 */
UCLASS(Blueprintable)
class RTD_API UTileHandler : public UObject
{
	GENERATED_BODY()
	UTileHandler();

public:
	UPROPERTY(BlueprintReadWrite)
	TMap<FOffsetCoords, ETileTypes2> pathMap;
	UPROPERTY(BlueprintReadWrite)
	TMap<FOffsetCoords, float> costMap;
	UPROPERTY(BlueprintReadWrite)
	TArray<FOffsetCoords> grid;
	UPROPERTY(BlueprintReadWrite)
	TArray<FOffsetCoords> headMap;

	UPROPERTY(BlueprintReadWrite)
	TSet<FOffsetCoords> blockedToPathing;

	UPROPERTY()
	int seed = 0;
	UPROPERTY()
	int paths;
	UPROPERTY()
	FOffsetCoords origin = FOffsetCoords(0, 0);

	UFUNCTION(BlueprintCallable)
	void init(int s, int p);

	UFUNCTION(BlueprintCallable)
	void initCostMap(FOffsetCoords center);

	UFUNCTION(Blueprintcallable)
	void initPaths(int p);

	UFUNCTION(BlueprintCallable)
	TArray<FOffsetCoords> nbrs(FOffsetCoords c);

	UFUNCTION(BlueprintCallable)
	TArray<FOffsetCoords> pnbrs(FOffsetCoords c);

	UFUNCTION()
	FOffsetCoords buildPath(FOffsetCoords pathHead);







	UFUNCTION(BlueprintCallable)
	int randIndex(int arrLen);
	UFUNCTION(BlueprintCallable)
	int min(int x, int y);
	UFUNCTION(BlueprintCallable)
	int max(int x, int y);
};
