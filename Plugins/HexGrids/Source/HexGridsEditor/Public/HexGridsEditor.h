// Copyright 2020 Daniel Orchard. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class HEXGRIDSEDITOR_API FHexGridsEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

	// We setup some elements after engine is fully loaded, ie Placement mode. 
	void OnFEngineLoopInitComplete();
	void RegisterPropertyTypeCustomizations();
	void RegisterHexGridInPlaceables();
	void UnregisterHexGridInPlaceables();
};