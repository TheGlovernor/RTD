

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "TDPlayer.generated.h"

UCLASS()
class RTD_API UTDPlayer : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UTDPlayer();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Money)
    FGameplayAttributeData Money = 0.0;
    ATTRIBUTE_ACCESSORS(UTDPlayer, Money)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Scouts)
    FGameplayAttributeData Scouts = 0.0;
    ATTRIBUTE_ACCESSORS(UTDPlayer, Scouts)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Money(const FGameplayAttributeData& OldMoney);

    UFUNCTION()
    virtual void OnRep_Scouts(const FGameplayAttributeData& OldScouts);
	
	
};
