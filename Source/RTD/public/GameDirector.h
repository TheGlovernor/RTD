

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
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_EnemyScalar)
    FGameplayAttributeData EnemyScalar = 1.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, EnemyScalar)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SplitChance)
    FGameplayAttributeData SplitChance = 1.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, SplitChance)
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MultipleRollChance)
    FGameplayAttributeData MultipleRollChance = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, MultipleRollChance)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Quick)
    FGameplayAttributeData Quick = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, Quick)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Heavy)
    FGameplayAttributeData Heavy = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, Heavy)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Bounty)
    FGameplayAttributeData Bounty = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, Bounty)
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Shielded)
    FGameplayAttributeData Shielded = 0.0;
    ATTRIBUTE_ACCESSORS(UGameDirector, Shielded)

protected:
    
    UFUNCTION()
    virtual void OnRep_EnemyScalar(const FGameplayAttributeData& OldScalar);
    
    UFUNCTION()
    virtual void OnRep_SplitChance(const FGameplayAttributeData& OldSplitChance);
    
    UFUNCTION()
    virtual void OnRep_MultipleRollChance(const FGameplayAttributeData& OldMultipleRollChance);

    UFUNCTION()
    virtual void OnRep_Quick(const FGameplayAttributeData& OldQuick);

    UFUNCTION()
    virtual void OnRep_Heavy(const FGameplayAttributeData& OldHeavy);

    UFUNCTION()
    virtual void OnRep_Bounty(const FGameplayAttributeData& OldBounty);

    UFUNCTION()
    virtual void OnRep_Shielded(const FGameplayAttributeData& OldShielded);
	
};
