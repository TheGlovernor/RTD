

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "HomeBase.generated.h"

UCLASS()
class RTD_API UHomeBase : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UHomeBase();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health = 0.0;
    ATTRIBUTE_ACCESSORS(UHomeBase, Health)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth = 0.0;
    ATTRIBUTE_ACCESSORS(UHomeBase, MaxHealth)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_HealthRegen)
    FGameplayAttributeData HealthRegen = 0.0;
    ATTRIBUTE_ACCESSORS(UHomeBase, HealthRegen)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_RegenInterval)
    FGameplayAttributeData RegenInterval = 0.0;
    ATTRIBUTE_ACCESSORS(UHomeBase, RegenInterval)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

    UFUNCTION()
    virtual void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen);

    UFUNCTION()
    virtual void OnRep_RegenInterval(const FGameplayAttributeData& OldRegenInterval);
	
	
};
