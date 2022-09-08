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
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UTowerAttributeSet, MaxItems, COND_None, REPNOTIFY_Always);
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

void UTowerAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldCritChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, CritChance, OldCritChance);
}

void UTowerAttributeSet::OnRep_MaxItems(const FGameplayAttributeData& OldMaxItems)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTowerAttributeSet, MaxItems, OldMaxItems);
}
