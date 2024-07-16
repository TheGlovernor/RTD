// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UTowerAttributeSet::UTowerAttributeSet()
{
	// Default constructor
}

void UTowerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    // Set adjust code here
    //
    // Example:
    //
    // If a Max value changes, adjust current to keep Current % of Current to Max
    //
    // if (Attribute == GetMaxHealthAttribute())
    // {
    //     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    // }
}

void UTowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FGSCAttributeSetExecutionData ExecutionData;
    GetExecutionDataFromMod(Data, ExecutionData);

    // Set clamping or handling or "meta" attributes here (like damages)

    // Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     HandleHealthAttribute(ExecutionData);
    // }

    // Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    // }
}

void UTowerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, Level, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, Range, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, CurrentTargets, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, MaxTargets, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EffectPower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EffectChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EffectDuration, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, CritChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, CritX, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, MaxItems, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, BuyValue, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, UpgradeValue, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, SellValue, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, TargetHidden, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, Reloads, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, MagSize, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, ReloadInterval, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, AmmoConsumption, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, AmmoRegenRate, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, TimeSlow, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, FrostSlow, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, FrostDuration, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, FrostChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EntangleSlow, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EntangleDuration, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EntangleChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EntanglePower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, BleedPower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, BleedChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EngulfPower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, EngulfChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, StunDuration, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, StunChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, SpotPower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, SpotDuration, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, ProjectileSpeed, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, ExplosionRadius, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, BountyMultiplier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, ItemChanceMultiplier, COND_None, REPNOTIFY_Always);
}

void UTowerAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, Level, OldLevel);
}

void UTowerAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, AttackPower, OldAttackPower);
}

void UTowerAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UTowerAttributeSet::OnRep_Range(const FGameplayAttributeData& OldRange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, Range, OldRange);
}

void UTowerAttributeSet::OnRep_CurrentTargets(const FGameplayAttributeData& OldCurrentTargets)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, CurrentTargets, OldCurrentTargets);
}

void UTowerAttributeSet::OnRep_MaxTargets(const FGameplayAttributeData& OldMaxTargets)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, MaxTargets, OldMaxTargets);
}

void UTowerAttributeSet::OnRep_EffectPower(const FGameplayAttributeData& OldEffectPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EffectPower, OldEffectPower);

}

void UTowerAttributeSet::OnRep_EffectChance(const FGameplayAttributeData& OldEffectChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EffectChance, OldEffectChance);

}

void UTowerAttributeSet::OnRep_EffectDuration(const FGameplayAttributeData& OldEffectDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EffectDuration, OldEffectDuration);

}

void UTowerAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldCritChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, CritChance, OldCritChance);

}

void UTowerAttributeSet::OnRep_CritX(const FGameplayAttributeData& OldCritX)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, CritX, OldCritX);
}

void UTowerAttributeSet::OnRep_MaxItems(const FGameplayAttributeData& OldMaxItems)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, MaxItems, OldMaxItems);
}

void UTowerAttributeSet::OnRep_BuyValue(const FGameplayAttributeData& OldBuyValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, BuyValue, OldBuyValue);
}

void UTowerAttributeSet::OnRep_UpgradeValue(const FGameplayAttributeData& OldUpgradeValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, UpgradeValue, OldUpgradeValue);
}

void UTowerAttributeSet::OnRep_SellValue(const FGameplayAttributeData& OldSellValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, SellValue, OldSellValue);
}

void UTowerAttributeSet::OnRep_TargetHidden(const FGameplayAttributeData& OldTargetHidden)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, TargetHidden, OldTargetHidden);
}

void UTowerAttributeSet::OnRep_Reloads(const FGameplayAttributeData& OldReloads)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, Reloads, OldReloads);
}

void UTowerAttributeSet::OnRep_MagSize(const FGameplayAttributeData& OldMagSize)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, MagSize, OldMagSize);
}

void UTowerAttributeSet::OnRep_ReloadInterval(const FGameplayAttributeData& OldReloadInterval)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, ReloadInterval, OldReloadInterval);
}

void UTowerAttributeSet::OnRep_AmmoConsumption(const FGameplayAttributeData& OldAmmoConsumption)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, AmmoConsumption, OldAmmoConsumption);
}

void UTowerAttributeSet::OnRep_AmmoRegenRate(const FGameplayAttributeData& OldAmmoRegenRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, AmmoRegenRate, OldAmmoRegenRate);
}

void UTowerAttributeSet::OnRep_TimeSlow(const FGameplayAttributeData& OldTimeSlow)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, TimeSlow , OldTimeSlow);
}

void UTowerAttributeSet::OnRep_FrostSlow(const FGameplayAttributeData& OldFrostSlow)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, FrostSlow, OldFrostSlow);
}

void UTowerAttributeSet::OnRep_FrostDuration(const FGameplayAttributeData& OldFrostDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, FrostDuration, OldFrostDuration);
}

void UTowerAttributeSet::OnRep_FrostChance(const FGameplayAttributeData& OldFrostChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, FrostChance, OldFrostChance);
}

void UTowerAttributeSet::OnRep_EntangleSlow(const FGameplayAttributeData& OldEntangleSlow)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EntangleSlow, OldEntangleSlow);
}

void UTowerAttributeSet::OnRep_EntangleDuration(const FGameplayAttributeData& OldEntangleDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EntangleDuration, OldEntangleDuration);
}

void UTowerAttributeSet::OnRep_EntangleChance(const FGameplayAttributeData& OldEntangleChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EntangleChance, OldEntangleChance);
}

void UTowerAttributeSet::OnRep_EntanglePower(const FGameplayAttributeData& OldEntanglePower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EntanglePower, OldEntanglePower);
}

void UTowerAttributeSet::OnRep_BleedPower(const FGameplayAttributeData& OldBleedPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, BleedPower, OldBleedPower);
}

void UTowerAttributeSet::OnRep_BleedChance(const FGameplayAttributeData& OldBleedChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, BleedChance, OldBleedChance);
}

void UTowerAttributeSet::OnRep_EngulfPower(const FGameplayAttributeData& OldEngulfPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EngulfPower, OldEngulfPower);
}

void UTowerAttributeSet::OnRep_EngulfChance(const FGameplayAttributeData& OldEngulfChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, EngulfChance, OldEngulfChance);
}

void UTowerAttributeSet::OnRep_StunDuration(const FGameplayAttributeData& OldStunDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, StunDuration, OldStunDuration);
}

void UTowerAttributeSet::OnRep_StunChance(const FGameplayAttributeData& OldStunChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, StunChance, OldStunChance);
}

void UTowerAttributeSet::OnRep_SpotPower(const FGameplayAttributeData& OldSpotPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, SpotPower, OldSpotPower);
}

void UTowerAttributeSet::OnRep_SpotDuration(const FGameplayAttributeData& OldSpotDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, SpotDuration, OldSpotDuration);
}

void UTowerAttributeSet::OnRep_ProjectileSpeed(const FGameplayAttributeData& OldProjectileSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, ProjectileSpeed, OldProjectileSpeed);
}

void UTowerAttributeSet::OnRep_ExplosionRadius(const FGameplayAttributeData& OldExplosionRadius)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, ExplosionRadius, OldExplosionRadius);
}

void UTowerAttributeSet::OnRep_BountyMultiplier(const FGameplayAttributeData& OldBountyMultiplier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, BountyMultiplier, OldBountyMultiplier);
}

void UTowerAttributeSet::OnRep_ItemChanceMultiplier(const FGameplayAttributeData& OldItemChanceMultiplier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, ItemChanceMultiplier, OldItemChanceMultiplier);
}
