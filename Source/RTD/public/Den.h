

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "Den.generated.h"

UCLASS()
class RTD_API UDen : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UDen();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_T1Weight)
    FGameplayAttributeData T1Weight = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, T1Weight)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_T1IncreaseRate)
    FGameplayAttributeData T1IncreaseRate = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, T1IncreaseRate)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_T2Weight)
    FGameplayAttributeData T2Weight = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, T2Weight)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_T2IncreaseRate)
    FGameplayAttributeData T2IncreaseRate = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, T2IncreaseRate)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BossWeight)
    FGameplayAttributeData BossWeight = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, BossWeight)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_BossIncreaseRate)
    FGameplayAttributeData BossIncreaseRate = 0.0;
    ATTRIBUTE_ACCESSORS(UDen, BossIncreaseRate)    

protected:
    
    UFUNCTION()
    virtual void OnRep_T1Weight(const FGameplayAttributeData& OldT1Weight);

    UFUNCTION()
    virtual void OnRep_T1IncreaseRate(const FGameplayAttributeData& OldT1IncreaseRate);

    UFUNCTION()
    virtual void OnRep_T2Weight(const FGameplayAttributeData& OldT2Weight);

    UFUNCTION()
    virtual void OnRep_T2IncreaseRate(const FGameplayAttributeData& OldT2IncreaseRate);

    UFUNCTION()
    virtual void OnRep_BossWeight(const FGameplayAttributeData& OldBossWeight);

    UFUNCTION()
    virtual void OnRep_BossIncreaseRate(const FGameplayAttributeData& OldBossIncreaseRate);
	
	
};
