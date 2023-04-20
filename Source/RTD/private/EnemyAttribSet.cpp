// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAttribSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UEnemyAttribSet::UEnemyAttribSet()
{
	// Default constructor
}

void UEnemyAttribSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UEnemyAttribSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

    if (Data.EvaluatedData.Attribute == GetFleshAttribute()) {
         SetFlesh(FMath::Clamp(GetFlesh(), 0.f, GetMaxFlesh()));
    }
    else if (Data.EvaluatedData.Attribute == GetDarkFleshAttribute()) {
        SetDarkFlesh(FMath::Clamp(GetDarkFlesh(), 0.f, GetMaxDarkFlesh()));
    }
    else if (Data.EvaluatedData.Attribute == GetClothAttribute()) {
        SetCloth(FMath::Clamp(GetCloth(), 0.f, GetMaxCloth()));
    }
    else if (Data.EvaluatedData.Attribute == GetMetalAttribute()) {
        SetMetal(FMath::Clamp(GetMetal(), 0.f, GetMaxMetal()));
    }
    else if (Data.EvaluatedData.Attribute == GetPlantAttribute()) {
        SetPlant(FMath::Clamp(GetPlant(), 0.f, GetMaxPlant()));
    }
    else if (Data.EvaluatedData.Attribute == GetMagicAttribute()) {
        SetMagic(FMath::Clamp(GetMagic(), 0.f, GetMaxMagic()));
    }
    else if (Data.EvaluatedData.Attribute == GetDarkMagicAttribute()) {
        SetDarkMagic(FMath::Clamp(GetDarkMagic(), 0.f, GetMaxDarkMagic()));
    }
    else if (Data.EvaluatedData.Attribute == GetMoveSpeedAttribute()) {
        SetMoveSpeed(FMath::Clamp(GetMoveSpeed(), 0.f, 10000));
    }
    else if (Data.EvaluatedData.Attribute == GetKillValueAttribute()) {
        SetKillValue(FMath::Clamp(GetKillValue(), 0.f, 1000000000));
    }
    else if (Data.EvaluatedData.Attribute == GetHomeDamageAmountAttribute()) {
        SetHomeDamageAmount(FMath::Clamp(GetHomeDamageAmount(), 0.f, 10000));
    }
    else if (Data.EvaluatedData.Attribute == GetDamTakenModifierAttribute()) {
        SetDamTakenModifier(FMath::Clamp(GetDamTakenModifier(), 0.f, 10000));
    }
}

void UEnemyAttribSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Flesh, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxFlesh, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, DarkFlesh, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxDarkFlesh, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Cloth, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxCloth, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Metal, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxMetal, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Plant, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxPlant, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Magic, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxMagic, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, DarkMagic, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MaxDarkMagic, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, MoveSpeed, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, SpeedModifier, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, KillValue, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, HomeDamageAmount, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, DamTakenModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Visible, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, Hexed, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, PhysicalModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, BleedModifier , COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, FireModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, FrostModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, ShockModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, BlessedModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, CursedModifier, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, ItemDropChance, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, EntangledPower, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UEnemyAttribSet, EntangledBleed, COND_None, REPNOTIFY_Always);
}

void UEnemyAttribSet::OnRep_Flesh(const FGameplayAttributeData& OldFlesh)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Flesh, OldFlesh);
}

void UEnemyAttribSet::OnRep_MaxFlesh(const FGameplayAttributeData& OldMaxFlesh)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxFlesh, OldMaxFlesh);
}

void UEnemyAttribSet::OnRep_DarkFlesh(const FGameplayAttributeData& OldDarkFlesh)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, DarkFlesh, OldDarkFlesh);
}

void UEnemyAttribSet::OnRep_MaxDarkFlesh(const FGameplayAttributeData& OldMaxDarkFlesh)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxDarkFlesh, OldMaxDarkFlesh);
}

void UEnemyAttribSet::OnRep_Cloth(const FGameplayAttributeData& OldCloth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Cloth, OldCloth);
}

void UEnemyAttribSet::OnRep_MaxCloth(const FGameplayAttributeData& OldMaxCloth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxCloth, OldMaxCloth);
}

void UEnemyAttribSet::OnRep_Metal(const FGameplayAttributeData& OldMetal)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Metal, OldMetal);
}

void UEnemyAttribSet::OnRep_MaxMetal(const FGameplayAttributeData& OldMaxMetal)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxMetal, OldMaxMetal);
}

void UEnemyAttribSet::OnRep_Plant(const FGameplayAttributeData& OldPlant)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Plant, OldPlant);
}

void UEnemyAttribSet::OnRep_MaxPlant(const FGameplayAttributeData& OldMaxPlant)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxPlant, OldMaxPlant);
}

void UEnemyAttribSet::OnRep_Magic(const FGameplayAttributeData& OldMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Magic, OldMagic);
}

void UEnemyAttribSet::OnRep_MaxMagic(const FGameplayAttributeData& OldMaxMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxMagic, OldMaxMagic);
}

void UEnemyAttribSet::OnRep_DarkMagic(const FGameplayAttributeData& OldDarkMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, DarkMagic, OldDarkMagic);
}

void UEnemyAttribSet::OnRep_MaxDarkMagic(const FGameplayAttributeData& OldMaxDarkMagic)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MaxDarkMagic, OldMaxDarkMagic);
}

void UEnemyAttribSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, MoveSpeed, OldMoveSpeed);
}

void UEnemyAttribSet::OnRep_SpeedModifier(const FGameplayAttributeData& OldSpeedModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, SpeedModifier, OldSpeedModifier);
}

void UEnemyAttribSet::OnRep_KillValue(const FGameplayAttributeData& OldKillValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, KillValue, OldKillValue);
}

void UEnemyAttribSet::OnRep_HomeDamageAmount(const FGameplayAttributeData& OldHomeDamageAmount)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, HomeDamageAmount, OldHomeDamageAmount);
}

void UEnemyAttribSet::OnRep_DamTakenModifier(const FGameplayAttributeData& OldDamTakenModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, DamTakenModifier, OldDamTakenModifier);
}

void UEnemyAttribSet::OnRep_Visible(const FGameplayAttributeData& OldVisible)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Visible, OldVisible);
}

void UEnemyAttribSet::OnRep_Hexed(const FGameplayAttributeData& OldHexed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, Hexed, OldHexed);
}

void UEnemyAttribSet::OnRep_PhysicalModifier(const FGameplayAttributeData& OldPhysicalModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, PhysicalModifier, OldPhysicalModifier);
}

void UEnemyAttribSet::OnRep_BleedModifier(const FGameplayAttributeData& OldBleedModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, BleedModifier, OldBleedModifier);
}

void UEnemyAttribSet::OnRep_FireModifier(const FGameplayAttributeData& OldFireModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, FireModifier, OldFireModifier);
}

void UEnemyAttribSet::OnRep_FrostModifier(const FGameplayAttributeData& OldFrostModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, FrostModifier, OldFrostModifier);
}

void UEnemyAttribSet::OnRep_ShockModifier(const FGameplayAttributeData& OldShockModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, ShockModifier, OldShockModifier);
}

void UEnemyAttribSet::OnRep_BlessedModifier(const FGameplayAttributeData& OldBlessedModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, BlessedModifier, OldBlessedModifier);
}

void UEnemyAttribSet::OnRep_CursedModifier(const FGameplayAttributeData& OldCursedModifier)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, CursedModifier, OldCursedModifier);
}

void UEnemyAttribSet::OnRep_ItemDropChance(const FGameplayAttributeData& OldItemDropChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, ItemDropChance, OldItemDropChance);
}

void UEnemyAttribSet::OnRep_EntangledPower(const FGameplayAttributeData& OldEntangledPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, EntangledPower, OldEntangledPower);
}

void UEnemyAttribSet::OnRep_EntangledBleed(const FGameplayAttributeData& OldEntangledBleed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UEnemyAttribSet, EntangledBleed, OldEntangledBleed);
}
