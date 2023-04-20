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

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_AmmoRegenRate)
    FGameplayAttributeData AmmoRegenRate = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, AmmoRegenRate)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_TimeSlow)
    FGameplayAttributeData TimeSlow = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, TimeSlow)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_FrostSlow)
    FGameplayAttributeData FrostSlow = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, FrostSlow)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_FrostDuration)
    FGameplayAttributeData FrostDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, FrostDuration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_FrostChance)
    FGameplayAttributeData FrostChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, FrostChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntangleSlow)
    FGameplayAttributeData EntangleSlow = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EntangleSlow)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntangleDuration)
    FGameplayAttributeData EntangleDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EntangleDuration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntangleChance)
    FGameplayAttributeData EntangleChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EntangleChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EntanglePower)
    FGameplayAttributeData EntanglePower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EntanglePower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BleedPower)
    FGameplayAttributeData BleedPower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, BleedPower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BleedChance)
    FGameplayAttributeData BleedChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, BleedChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EngulfPower)
    FGameplayAttributeData EngulfPower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EngulfPower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EngulfChance)
    FGameplayAttributeData EngulfChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, EngulfChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_StunDuration)
    FGameplayAttributeData StunDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, StunDuration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_StunChance)
    FGameplayAttributeData StunChance = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, StunChance)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpotPower)
    FGameplayAttributeData SpotPower = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, SpotPower)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpotDuration)
    FGameplayAttributeData SpotDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, SpotDuration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ProjectileSpeed)
    FGameplayAttributeData ProjectileSpeed = 0.0;
    ATTRIBUTE_ACCESSORS(UTowerAttributeSet, ProjectileSpeed)

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

    UFUNCTION()
    virtual void OnRep_AmmoRegenRate(const FGameplayAttributeData& OldAmmoRegenRate);

    UFUNCTION()
    virtual void OnRep_TimeSlow(const FGameplayAttributeData& OldTimeSlow);

    UFUNCTION()
    virtual void OnRep_FrostSlow(const FGameplayAttributeData& OldFrostSlow);

    UFUNCTION()
    virtual void OnRep_FrostDuration(const FGameplayAttributeData& OldFrostDuration);

    UFUNCTION()
    virtual void OnRep_FrostChance(const FGameplayAttributeData& OldFrostChance);

    UFUNCTION()
    virtual void OnRep_EntangleSlow(const FGameplayAttributeData& OldEntangleSlow);

    UFUNCTION()
    virtual void OnRep_EntangleDuration(const FGameplayAttributeData& OldEntangleDuration);

    UFUNCTION()
    virtual void OnRep_EntangleChance(const FGameplayAttributeData& OldEntangleChance);

    UFUNCTION()
    virtual void OnRep_EntanglePower(const FGameplayAttributeData& OldEntanglePower);

    UFUNCTION()
    virtual void OnRep_BleedPower(const FGameplayAttributeData& OldBleedPower);

    UFUNCTION()
    virtual void OnRep_BleedChance(const FGameplayAttributeData& OldBleedChance);

    UFUNCTION()
    virtual void OnRep_EngulfPower(const FGameplayAttributeData& OldEngulfPower);

    UFUNCTION()
    virtual void OnRep_EngulfChance(const FGameplayAttributeData& OldEngulfChance);

    UFUNCTION()
    virtual void OnRep_StunDuration(const FGameplayAttributeData& OldStunDuration);

    UFUNCTION()
    virtual void OnRep_StunChance(const FGameplayAttributeData& OldStunChance);

    UFUNCTION()
    virtual void OnRep_SpotPower(const FGameplayAttributeData& OldSpotPower);

    UFUNCTION()
    virtual void OnRep_SpotDuration(const FGameplayAttributeData& OldSpotDuration);

    UFUNCTION()
    virtual void OnRep_ProjectileSpeed(const FGameplayAttributeData& OldProjectileSpeed);
};
