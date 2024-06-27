// Copyright 2017 Daniel Orchard. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class HEXGRIDS_API FHexGridsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};