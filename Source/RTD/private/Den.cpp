


#include "Den.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UDen::UDen()
{
	// Default constructor
}

void UDen::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UDen::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UDen::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, T1Weight, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, T1IncreaseRate, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, T2Weight, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, T2IncreaseRate, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, NormalCooldownRate, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UDen, BossCooldownRate, COND_None, REPNOTIFY_Always);
}

void UDen::OnRep_T1Weight(const FGameplayAttributeData& OldT1Weight)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, T1Weight, OldT1Weight);
}

void UDen::OnRep_T1IncreaseRate(const FGameplayAttributeData& OldT1IncreaseRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, T1IncreaseRate, OldT1IncreaseRate);
}

void UDen::OnRep_T2Weight(const FGameplayAttributeData& OldT2Weight)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, T2Weight, OldT2Weight);
}

void UDen::OnRep_T2IncreaseRate(const FGameplayAttributeData& OldT2IncreaseRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, T2IncreaseRate, OldT2IncreaseRate);
}

void UDen::OnRep_NormalCooldownRate(const FGameplayAttributeData& OldNormalCooldownRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, NormalCooldownRate, OldNormalCooldownRate);
}

void UDen::OnRep_BossCooldownRate(const FGameplayAttributeData& OldBossCooldownRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDen, BossCooldownRate, OldBossCooldownRate);
}
