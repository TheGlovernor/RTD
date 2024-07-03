

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Framework/Application/NavigationConfig.h"
#include "DisableAnalogInput.generated.h"

/**
 * 
 */
UCLASS()
class RTD_API UDisableAnalogInput : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ChangeAnalogInputEnabled"), Category = "Game Config")
	static void ChangeAnalogInputEnabled(bool bEnable);
};
