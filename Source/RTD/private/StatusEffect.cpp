// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffect.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UStatusEffect::UStatusEffect()
{
	// Default constructor
}

void UStatusEffect::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UStatusEffect::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UStatusEffect::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, BleedChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, BleedPower, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, EngulfChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, EngulfPower, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, StunChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, StunDuration, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, EntangleChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, EntangleDuration, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UStatusEffect, TimeDialation, COND_None, REPNOTIFY_Always);
}

void UStatusEffect::OnRep_BleedChance(const FGameplayAttributeData& OldBleedChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, BleedChance, OldBleedChance);
}

void UStatusEffect::OnRep_BleedPower(const FGameplayAttributeData& OldBleedPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, BleedPower, OldBleedPower);
}

void UStatusEffect::OnRep_EngulfChance(const FGameplayAttributeData& OldEngulfChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, EngulfChance, OldEngulfChance);
}

void UStatusEffect::OnRep_EngulfPower(const FGameplayAttributeData& OldEngulfPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, EngulfPower, OldEngulfPower);
}

void UStatusEffect::OnRep_StunChance(const FGameplayAttributeData& OldStunChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, StunChance, OldStunChance);
}

void UStatusEffect::OnRep_StunDuration(const FGameplayAttributeData& OldStunDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, StunDuration, OldStunDuration);
}

void UStatusEffect::OnRep_EntangleChance(const FGameplayAttributeData& OldEntangleChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, EntangleChance, OldEntangleChance);
}

void UStatusEffect::OnRep_EntangleDuration(const FGameplayAttributeData& OldEntangleDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, EntangleDuration, OldEntangleDuration);
}

void UStatusEffect::OnRep_TimeDialation(const FGameplayAttributeData& OldTimeDialation)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UStatusEffect, TimeDialation, OldTimeDialation);
}
