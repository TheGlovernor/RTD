


#include "EnemyAbility.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UEnemyAbility::UEnemyAbility()
{
	// Default constructor
}

void UEnemyAbility::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UEnemyAbility::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UEnemyAbility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, Cooldown, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, Duration, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, Range, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, HealthRegen, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, ShieldRegen, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, ArmorRegen, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, SpeedIncrease, COND_None, REPNOTIFY_Always);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAbility, MitigationIncrease, COND_None, REPNOTIFY_Always);
}

void UEnemyAbility::OnRep_Cooldown(const FGameplayAttributeData& OldCooldown)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, Cooldown, OldCooldown);
}

void UEnemyAbility::OnRep_Duration(const FGameplayAttributeData& OldDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, Duration, OldDuration);
}

void UEnemyAbility::OnRep_Range(const FGameplayAttributeData& OldRange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, Range, OldRange);
}

void UEnemyAbility::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, HealthRegen, OldHealthRegen);
}

void UEnemyAbility::OnRep_ShieldRegen(const FGameplayAttributeData& OldShieldRegen)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, ShieldRegen, OldShieldRegen);
}

void UEnemyAbility::OnRep_ArmorRegen(const FGameplayAttributeData& OldArmorRegen)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, ArmorRegen, OldArmorRegen);
}

void UEnemyAbility::OnRep_SpeedIncrease(const FGameplayAttributeData& OldSpeedIncrease)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, SpeedIncrease, OldSpeedIncrease);
}

void UEnemyAbility::OnRep_MitigationIncrease(const FGameplayAttributeData& OldMitigationIncrease)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAbility, MitigationIncrease, OldMitigationIncrease);
}
