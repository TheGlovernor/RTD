// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OffsetCoords.h"
#include "Engine/DataAsset.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "HexGridDataAssetBase.generated.h"

/**
 * Base class for holding all manner of Hex Grid info. Subclass this in blueprint (not via data asset misc), to add your own data
 */
UCLASS(abstract, Blueprintable)
class HEXGRIDS_API UHexGridDataAssetBase : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Global")
	bool IsInstanceSystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Global")
	struct FOffsetCoords Coordinate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Global")
	FTransform Transform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Global")
	UStaticMesh* StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Static Mesh Mode", meta = (EditCondition = "!IsInstanceSystem"))
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Static Mesh Mode", meta = (EditCondition = "!IsInstanceSystem", Keywords="DMI, Material Instance, Dynamic Material"))
	UMaterialInstanceDynamic* MID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Instance Mode", meta = (EditCondition = "IsInstanceSystem"))
	int32 InstanceID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Instance Mode", meta = (EditCondition = "IsInstanceSystem"))
	UInstancedStaticMeshComponent* ISM_Component;

	// Reference to the blueprint tile, if created in Blueprint Mode.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Blueprint Mode")
	TObjectPtr<AActor> BlueprintTile;
	
};
