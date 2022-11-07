// Fill out your copyright notice in the Description page of Project Settings.


#include "Greenhouse.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UGreenhouse::UGreenhouse()
{
	// Default constructor
}

void UGreenhouse::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UGreenhouse::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UGreenhouse::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UGreenhouse, SpeedModifier, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UGreenhouse, Duration, COND_None, REPNOTIFY_Always);
}

void UGreenhouse::OnRep_SpeedModifier(const FGameplayAttributeData& OldSpeedModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGreenhouse, SpeedModifier, OldSpeedModifier);
}

void UGreenhouse::OnRep_Duration(const FGameplayAttributeData& OldDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGreenhouse, Duration, OldDuration);
}
