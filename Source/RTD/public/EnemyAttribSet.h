// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "EnemyAttribSet.generated.h"

UCLASS()
class RTD_API UEnemyAttribSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UEnemyAttribSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Flesh)
    FGameplayAttributeData Flesh = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Flesh)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxFlesh)
    FGameplayAttributeData MaxFlesh = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxFlesh)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_DarkFlesh)
    FGameplayAttributeData DarkFlesh = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, DarkFlesh)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxDarkFlesh)
    FGameplayAttributeData MaxDarkFlesh = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxDarkFlesh)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_Cloth)
    FGameplayAttributeData Cloth = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Cloth)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxCloth)
    FGameplayAttributeData MaxCloth = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxCloth)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_Metal)
    FGameplayAttributeData Metal = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Metal)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxMetal)
    FGameplayAttributeData MaxMetal = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxMetal)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_Plant)
    FGameplayAttributeData Plant = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Plant)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxPlant)
    FGameplayAttributeData MaxPlant = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxPlant)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_Magic)
    FGameplayAttributeData Magic = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Magic)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxMagic)
    FGameplayAttributeData MaxMagic = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxMagic)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_DarkMagic)
    FGameplayAttributeData DarkMagic = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, DarkMagic)    
    
    UPROPERTY(BlueprintReadOnly, Category = "health", ReplicatedUsing = OnRep_MaxDarkMagic)
    FGameplayAttributeData MaxDarkMagic = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MaxDarkMagic)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MoveSpeed)
    FGameplayAttributeData MoveSpeed = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, MoveSpeed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpeedModifier)
    FGameplayAttributeData SpeedModifier = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, SpeedModifier)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_KillValue)
    FGameplayAttributeData KillValue = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, KillValue)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HomeDamageAmount)
    FGameplayAttributeData HomeDamageAmount = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, HomeDamageAmount)    

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_DamTakenModifier)
    FGameplayAttributeData DamTakenModifier = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, DamTakenModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Visible)
    FGameplayAttributeData Visible = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Visible)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Hexed)
    FGameplayAttributeData Hexed = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Hexed)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_PhysicalModifier)
    FGameplayAttributeData PhysicalModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, PhysicalModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BleedModifier)
    FGameplayAttributeData BleedModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, BleedModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_FireModifier)
    FGameplayAttributeData FireModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, FireModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_FrostModifier)
    FGameplayAttributeData FrostModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, FrostModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ShockModifier)
    FGameplayAttributeData ShockModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, ShockModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BlessedModifier)
    FGameplayAttributeData BlessedModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, BlessedModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CursedModifier)
    FGameplayAttributeData CursedModifier = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, CursedModifier)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ItemDropChance)
    FGameplayAttributeData ItemDropChance = 1.0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, ItemDropChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntangledPower)
    FGameplayAttributeData EntangledPower = 0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, EntangledPower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntangledBleed)
    FGameplayAttributeData EntangledBleed = 0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, EntangledBleed)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Offspring)
    FGameplayAttributeData Offspring = 0;
    ATTRIBUTE_ACCESSORS(UEnemyAttribSet, Offspring)

protected:
    
    UFUNCTION()
    virtual void OnRep_Flesh(const FGameplayAttributeData& OldFlesh);

    UFUNCTION()
    virtual void OnRep_MaxFlesh(const FGameplayAttributeData& OldMaxFlesh);

    UFUNCTION()
    virtual void OnRep_DarkFlesh(const FGameplayAttributeData& OldDarkFlesh);

    UFUNCTION()
    virtual void OnRep_MaxDarkFlesh(const FGameplayAttributeData& OldMaxDarkFlesh);

    UFUNCTION()
    virtual void OnRep_Cloth(const FGameplayAttributeData& OldCloth);

    UFUNCTION()
    virtual void OnRep_MaxCloth(const FGameplayAttributeData& OldMaxCloth);

    UFUNCTION()
    virtual void OnRep_Metal(const FGameplayAttributeData& OldMetal);

    UFUNCTION()
    virtual void OnRep_MaxMetal(const FGameplayAttributeData& OldMaxMetal);

    UFUNCTION()
    virtual void OnRep_Plant(const FGameplayAttributeData& OldPlant);

    UFUNCTION()
    virtual void OnRep_MaxPlant(const FGameplayAttributeData& OldMaxPlant);

    UFUNCTION()
    virtual void OnRep_Magic(const FGameplayAttributeData& OldMagic);

    UFUNCTION()
    virtual void OnRep_MaxMagic(const FGameplayAttributeData& OldMaxMagic);

    UFUNCTION()
    virtual void OnRep_DarkMagic(const FGameplayAttributeData& OldDarkMagic);

    UFUNCTION()
    virtual void OnRep_MaxDarkMagic(const FGameplayAttributeData& OldMaxDarkMagic);

    UFUNCTION()
    virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed);
    
    UFUNCTION()
    virtual void OnRep_SpeedModifier(const FGameplayAttributeData& OldSpeedModifier);

    UFUNCTION()
    virtual void OnRep_KillValue(const FGameplayAttributeData& OldKillValue);

    UFUNCTION()
    virtual void OnRep_HomeDamageAmount(const FGameplayAttributeData& OldHomeDamageAmount);

    UFUNCTION()
    virtual void OnRep_DamTakenModifier(const FGameplayAttributeData& OldDamTakenModifier);
	
    UFUNCTION()
    virtual void OnRep_Visible(const FGameplayAttributeData& OldVisible);

    UFUNCTION()
    virtual void OnRep_Hexed(const FGameplayAttributeData& OldHexed);

    UFUNCTION()
    virtual void OnRep_PhysicalModifier(const FGameplayAttributeData& OldPhysicalModifier);

    UFUNCTION()
    virtual void OnRep_BleedModifier(const FGameplayAttributeData& OldBleedModifier);

    UFUNCTION()
    virtual void OnRep_FireModifier(const FGameplayAttributeData& OldFireModifier);

    UFUNCTION()
    virtual void OnRep_FrostModifier(const FGameplayAttributeData& OldFrostModifier);

    UFUNCTION()
    virtual void OnRep_ShockModifier(const FGameplayAttributeData& OldShockModifier);

    UFUNCTION()
    virtual void OnRep_BlessedModifier(const FGameplayAttributeData& OldBlessedModifier);

    UFUNCTION()
    virtual void OnRep_CursedModifier(const FGameplayAttributeData& OldCursedModifier);

    UFUNCTION()
    virtual void OnRep_ItemDropChance(const FGameplayAttributeData& OldItemDropChance);

    UFUNCTION()
    virtual void OnRep_EntangledPower(const FGameplayAttributeData& OldEntangledPower);

    UFUNCTION()
    virtual void OnRep_EntangledBleed(const FGameplayAttributeData& OldEntangledBleed);

    UFUNCTION()
    virtual void OnRep_Offspring(const FGameplayAttributeData& OldOffspring);

};
