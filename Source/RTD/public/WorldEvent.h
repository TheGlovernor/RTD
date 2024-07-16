

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "WorldEvent.generated.h"

UCLASS()
class RTD_API UWorldEvent : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UWorldEvent();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Duration)
    FGameplayAttributeData Duration = 60.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, Duration)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HealthChange)
    FGameplayAttributeData HealthChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, HealthChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HealthRegenChange)
    FGameplayAttributeData HealthRegenChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, HealthRegenChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HealthRegenDelayChange)
    FGameplayAttributeData HealthRegenDelayChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, HealthRegenDelayChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ShieldChange)
    FGameplayAttributeData ShieldChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ShieldChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ShieldRegenChange)
    FGameplayAttributeData ShieldRegenChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ShieldRegenChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ShieldRegenDelayChange)
    FGameplayAttributeData ShieldRegenDelayChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ShieldRegenDelayChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ArmorChange)
    FGameplayAttributeData ArmorChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ArmorChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ArmorRegenChange)
    FGameplayAttributeData ArmorRegenChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ArmorRegenChange)

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_ArmorRegenDelayChange)
    FGameplayAttributeData ArmorRegenDelayChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, ArmorRegenDelayChange)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_DamageChange)
    FGameplayAttributeData DamageChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, DamageChange)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpeedChange)
    FGameplayAttributeData SpeedChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, SpeedChange)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BountyChange)
    FGameplayAttributeData BountyChange = 0.0;
    ATTRIBUTE_ACCESSORS(UWorldEvent, BountyChange)

protected:
    
    UFUNCTION()
    virtual void OnRep_Duration(const FGameplayAttributeData& OldDuration);

    UFUNCTION()
    virtual void OnRep_HealthChange(const FGameplayAttributeData& OldHealthChange);

    UFUNCTION()
    virtual void OnRep_HealthRegenChange(const FGameplayAttributeData& OldHealthRegenChange);

    UFUNCTION()
    virtual void OnRep_HealthRegenDelayChange(const FGameplayAttributeData& OldHealthRegenDelayChange);

    UFUNCTION()
    virtual void OnRep_ShieldChange(const FGameplayAttributeData& OldShieldChange);

    UFUNCTION()
    virtual void OnRep_ShieldRegenChange(const FGameplayAttributeData& OldShieldRegenChange);

    UFUNCTION()
    virtual void OnRep_ShieldRegenDelayChange(const FGameplayAttributeData& OldShieldRegenDelayChange);

    UFUNCTION()
    virtual void OnRep_ArmorChange(const FGameplayAttributeData& OldArmorChange);

    UFUNCTION()
    virtual void OnRep_ArmorRegenChange(const FGameplayAttributeData& OldArmorRegenChange);

    UFUNCTION()
    virtual void OnRep_ArmorRegenDelayChange(const FGameplayAttributeData& OldArmorRegenDelayChange);

    UFUNCTION()
    virtual void OnRep_DamageChange(const FGameplayAttributeData& OldDamageChange);

    UFUNCTION()
    virtual void OnRep_SpeedChange(const FGameplayAttributeData& OldSpeedChange);

    UFUNCTION()
    virtual void OnRep_BountyChange(const FGameplayAttributeData& OldBountyChange);
	
	
};
