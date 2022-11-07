// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "Greenhouse.generated.h"

UCLASS()
class RTD_API UGreenhouse : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UGreenhouse();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SpeedModifier)
    FGameplayAttributeData SpeedModifier = 0.0;
    ATTRIBUTE_ACCESSORS(UGreenhouse, SpeedModifier)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Duration)
    FGameplayAttributeData Duration = 0.0;
    ATTRIBUTE_ACCESSORS(UGreenhouse, Duration)    

protected:
    
    UFUNCTION()
    virtual void OnRep_SpeedModifier(const FGameplayAttributeData& OldSpeedModifier);

    UFUNCTION()
    virtual void OnRep_Duration(const FGameplayAttributeData& OldDuration);
	
	
};
