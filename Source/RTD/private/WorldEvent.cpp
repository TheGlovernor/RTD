


#include "WorldEvent.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UWorldEvent::UWorldEvent()
{
	// Default constructor
}

void UWorldEvent::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UWorldEvent::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UWorldEvent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, Duration, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, HealthChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, HealthRegenChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, HealthRegenDelayChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ShieldChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ShieldRegenChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ShieldRegenDelayChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ArmorChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ArmorRegenChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, ArmorRegenDelayChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, DamageChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, SpeedChange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UWorldEvent, BountyChange, COND_None, REPNOTIFY_Always);
}

void UWorldEvent::OnRep_Duration(const FGameplayAttributeData& OldDuration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, Duration, OldDuration);
}

void UWorldEvent::OnRep_HealthChange(const FGameplayAttributeData& OldHealthChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, HealthChange, OldHealthChange);
}

void UWorldEvent::OnRep_HealthRegenChange(const FGameplayAttributeData& OldHealthRegenChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, HealthRegenChange, OldHealthRegenChange);
}

void UWorldEvent::OnRep_HealthRegenDelayChange(const FGameplayAttributeData& OldHealthRegenDelayChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, HealthRegenDelayChange, OldHealthRegenDelayChange);
}

void UWorldEvent::OnRep_ShieldChange(const FGameplayAttributeData& OldShieldChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ShieldChange, OldShieldChange);
}

void UWorldEvent::OnRep_ShieldRegenChange(const FGameplayAttributeData& OldShieldRegenChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ShieldRegenChange, OldShieldRegenChange);
}

void UWorldEvent::OnRep_ShieldRegenDelayChange(const FGameplayAttributeData& OldShieldRegenDelayChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ShieldRegenDelayChange, OldShieldRegenDelayChange);
}

void UWorldEvent::OnRep_ArmorChange(const FGameplayAttributeData& OldArmorChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ArmorChange, OldArmorChange);
}

void UWorldEvent::OnRep_ArmorRegenChange(const FGameplayAttributeData& OldArmorRegenChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ArmorRegenChange, OldArmorRegenChange);
}

void UWorldEvent::OnRep_ArmorRegenDelayChange(const FGameplayAttributeData& OldArmorRegenDelayChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, ArmorRegenDelayChange, OldArmorRegenDelayChange);
}

void UWorldEvent::OnRep_DamageChange(const FGameplayAttributeData& OldDamageChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, DamageChange, OldDamageChange);
}

void UWorldEvent::OnRep_SpeedChange(const FGameplayAttributeData& OldSpeedChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, SpeedChange, OldSpeedChange);
}

void UWorldEvent::OnRep_BountyChange(const FGameplayAttributeData& OldBountyChange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UWorldEvent, BountyChange, OldBountyChange);
}
