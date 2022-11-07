// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "StatusEffect.generated.h"

UCLASS()
class RTD_API UStatusEffect : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UStatusEffect();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_BleedChance)
    FGameplayAttributeData BleedChance = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, BleedChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_BleedPower)
    FGameplayAttributeData BleedPower = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, BleedPower)

    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_EngulfChance)
    FGameplayAttributeData EngulfChance = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, EngulfChance)

    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_EngulfPower)
    FGameplayAttributeData EngulfPower = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, EngulfPower)
    
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_StunChance)
    FGameplayAttributeData StunChance = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, StunChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_StunDuration)
    FGameplayAttributeData StunDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, StunDuration)
    
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_EntangleChance)
    FGameplayAttributeData EntangleChance = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, EntangleChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Status", ReplicatedUsing = OnRep_EntangleDuration)
    FGameplayAttributeData EntangleDuration = 0.0;
    ATTRIBUTE_ACCESSORS(UStatusEffect, EntangleDuration)    

protected:
    
    UFUNCTION()
    virtual void OnRep_BleedChance(const FGameplayAttributeData& OldBleedChance);

    UFUNCTION()
    virtual void OnRep_BleedPower(const FGameplayAttributeData& OldBleedPower);

    UFUNCTION()
    virtual void OnRep_EngulfChance(const FGameplayAttributeData& OldEngulfChance);

    UFUNCTION()
    virtual void OnRep_EngulfPower(const FGameplayAttributeData& OldEngulfPower);

    UFUNCTION()
    virtual void OnRep_StunChance(const FGameplayAttributeData& OldStunChance);

    UFUNCTION()
    virtual void OnRep_StunDuration(const FGameplayAttributeData& OldStunDuration);

    UFUNCTION()
    virtual void OnRep_EntangleChance(const FGameplayAttributeData& OldEntangleChance);

    UFUNCTION()
    virtual void OnRep_EntangleDuration(const FGameplayAttributeData& OldEntangleDuration);
	
	
};
