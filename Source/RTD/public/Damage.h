// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "Damage.generated.h"

UCLASS()
class RTD_API UDamage : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UDamage();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Physical = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Physical)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Bleed = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Bleed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Fire = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Fire)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Frost = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Frost)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Shock = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Shock)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Blessed = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Blessed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", meta = (HideFromLevelInfos))
    FGameplayAttributeData Hexed = 0.0;
    ATTRIBUTE_ACCESSORS(UDamage, Hexed)    

/*protected:
    
    UFUNCTION()
    virtual void OnRep_Physical(const FGameplayAttributeData& OldPhysical);

    UFUNCTION()
    virtual void OnRep_Bleed(const FGameplayAttributeData& OldBleed);

    UFUNCTION()
    virtual void OnRep_Fire(const FGameplayAttributeData& OldFire);

    UFUNCTION()
    virtual void OnRep_Frost(const FGameplayAttributeData& OldFrost);

    UFUNCTION()
    virtual void OnRep_Shock(const FGameplayAttributeData& OldShock);

    UFUNCTION()
    virtual void OnRep_Blessed(const FGameplayAttributeData& OldBlessed);

    UFUNCTION()
    virtual void OnRep_Hexed(const FGameplayAttributeData& OldHexed);*/
	
	
};
