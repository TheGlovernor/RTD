

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "GameDirector.generated.h"

UCLASS()
class RTD_API UGameDirector : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UGameDirector();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MultipleRollChance)
    FGameplayAttributeData MultipleRollChance = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, MultipleRollChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Quick)
    FGameplayAttributeData Quick = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, Quick)    

protected:
    
    UFUNCTION()
    virtual void OnRep_MultipleRollChance(const FGameplayAttributeData& OldMultipleRollChance);

    UFUNCTION()
    virtual void OnRep_Quick(const FGameplayAttributeData& OldQuick);
	
	
};
