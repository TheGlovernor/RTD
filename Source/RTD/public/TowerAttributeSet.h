// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "TowerAttributeSet.generated.h"

UCLASS()
class RTD_API UTowerAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UTowerAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Level)
    FGameplayAttributeData Level = 1.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, Level)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_AttackPower)
    FGameplayAttributeData AttackPower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, AttackPower)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_AttackSpeed)
    FGameplayAttributeData AttackSpeed = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, AttackSpeed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Range)
    FGameplayAttributeData Range = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, Range)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CurrentTargets)
    FGameplayAttributeData CurrentTargets = 1.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, CurrentTargets)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxTargets)
    FGameplayAttributeData MaxTargets = 1.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, MaxTargets)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EffectPower)
    FGameplayAttributeData EffectPower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EffectPower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EffectChance)
    FGameplayAttributeData EffectChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EffectChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EffectDuration)
    FGameplayAttributeData EffectDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EffectDuration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CritChance)
    FGameplayAttributeData CritChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, CritChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CritX)
    FGameplayAttributeData CritX = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, CritX)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxItems)
    FGameplayAttributeData MaxItems = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, MaxItems)    

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BuyValue)
    FGameplayAttributeData BuyValue = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, BuyValue)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_UpgradeValue)
    FGameplayAttributeData UpgradeValue = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, UpgradeValue)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SellValue)
    FGameplayAttributeData SellValue = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, SellValue)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_TargetHidden)
    FGameplayAttributeData TargetHidden = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, TargetHidden)    

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Reloads)
    FGameplayAttributeData Reloads = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, Reloads)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MagSize)
    FGameplayAttributeData MagSize = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, MagSize)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ReloadInterval)
    FGameplayAttributeData ReloadInterval = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, ReloadInterval)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_AmmoConsumption)
    FGameplayAttributeData AmmoConsumption = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, AmmoConsumption)

protected:
    
    UFUNCTION()
    virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

    UFUNCTION()
    virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

    UFUNCTION()
    virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

    UFUNCTION()
    virtual void OnRep_Range(const FGameplayAttributeData& OldRange);

    UFUNCTION()
    virtual void OnRep_CurrentTargets(const FGameplayAttributeData& OldCurrentTargets);

    UFUNCTION()
    virtual void OnRep_MaxTargets(const FGameplayAttributeData& OldMaxTargets);

    UFUNCTION()
    virtual void OnRep_EffectPower(const FGameplayAttributeData& OldEffectPower);
    
    UFUNCTION()
    virtual void OnRep_EffectChance(const FGameplayAttributeData& OldEffectChance);
    
    UFUNCTION()
    virtual void OnRep_EffectDuration(const FGameplayAttributeData& OldEffectDuration);

    UFUNCTION()
    virtual void OnRep_CritChance(const FGameplayAttributeData& OldCritChance);

    UFUNCTION()
    virtual void OnRep_CritX(const FGameplayAttributeData& OldCritX);

    UFUNCTION()
    virtual void OnRep_MaxItems(const FGameplayAttributeData& OldMaxItems);

    UFUNCTION()
    virtual void OnRep_BuyValue(const FGameplayAttributeData& OldBuyValue);

    UFUNCTION()
    virtual void OnRep_UpgradeValue(const FGameplayAttributeData& OldUpgradeValue);

    UFUNCTION()
    virtual void OnRep_SellValue(const FGameplayAttributeData& OldSellValue);

    UFUNCTION()
    virtual void OnRep_TargetHidden(const FGameplayAttributeData& OldTargetHidden);

    UFUNCTION()
    virtual void OnRep_Reloads(const FGameplayAttributeData& OldReloads);

    UFUNCTION()
    virtual void OnRep_MagSize(const FGameplayAttributeData& OldMagSize);

    UFUNCTION()
    virtual void OnRep_ReloadInterval(const FGameplayAttributeData& OldReloadInterval);

    UFUNCTION()
    virtual void OnRep_AmmoConsumption(const FGameplayAttributeData& OldAmmoConsumption);
};
