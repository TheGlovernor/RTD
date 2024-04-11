

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "EnemyAbility.generated.h"

UCLASS()
class RTD_API UEnemyAbility : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UEnemyAbility();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Cooldown)
    FGameplayAttributeData Cooldown = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, Cooldown)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Duration)
    FGameplayAttributeData Duration = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, Duration)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Range)
    FGameplayAttributeData Range = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, Range)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HealthRegen)
    FGameplayAttributeData HealthRegen = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, HealthRegen)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ShieldRegen)
    FGameplayAttributeData ShieldRegen = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, ShieldRegen)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ArmorRegen)
    FGameplayAttributeData ArmorRegen = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, ArmorRegen)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpeedIncrease)
    FGameplayAttributeData SpeedIncrease = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, SpeedIncrease)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MitigationIncrease)
    FGameplayAttributeData MitigationIncrease = 0.0;
    ATTRIBUTE_ACCESSORS(UEnemyAbility, MitigationIncrease)

protected:
    
    UFUNCTION()
    virtual void OnRep_Cooldown(const FGameplayAttributeData& OldCooldown);
    
    UFUNCTION()
    virtual void OnRep_Duration(const FGameplayAttributeData& OldDuration);
    
    UFUNCTION()
    virtual void OnRep_Range(const FGameplayAttributeData& OldRange);
    
    UFUNCTION()
    virtual void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen);
    
    UFUNCTION()
    virtual void OnRep_ShieldRegen(const FGameplayAttributeData& OldShieldRegen);
    
    UFUNCTION()
    virtual void OnRep_ArmorRegen(const FGameplayAttributeData& OldArmorRegen);
    
    UFUNCTION()
    virtual void OnRep_SpeedIncrease(const FGameplayAttributeData& OldSpeedIncrease);
    
    UFUNCTION()
    virtual void OnRep_MitigationIncrease(const FGameplayAttributeData& OldMitigationIncrease);
	
};
