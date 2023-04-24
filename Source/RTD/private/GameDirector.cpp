


#include "GameDirector.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UGameDirector::UGameDirector()
{
	// Default constructor
}

void UGameDirector::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UGameDirector::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UGameDirector::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UGameDirector, MultipleRollChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UGameDirector, Quick, COND_None, REPNOTIFY_Always);
}

void UGameDirector::OnRep_MultipleRollChance(const FGameplayAttributeData& OldMultipleRollChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGameDirector, MultipleRollChance, OldMultipleRollChance);
}

void UGameDirector::OnRep_Quick(const FGameplayAttributeData& OldQuick)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGameDirector, Quick, OldQuick);
}
