


#include "DisableAnalogInput.h"

void UDisableAnalogInput::ChangeAnalogInputEnabled(bool bEnable) {
	if (FSlateApplication::IsInitialized()) {
		TSharedRef<FNavigationConfig> currentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		currentNavConfig->bAnalogNavigation = bEnable;
		FSlateApplication::Get().SetNavigationConfig(currentNavConfig);
	}
}
