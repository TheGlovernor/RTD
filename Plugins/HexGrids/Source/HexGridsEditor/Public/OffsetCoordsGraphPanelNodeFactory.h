// Copyright 2020 Daniel Orchard. All Rights Reserved.

#pragma once
#include "SlateBasics.h"
//#include "GAGlobalTypes.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_K2.h"
//#include "GAAttributePanelGraphPinFactory.h"
//#include "GAAttributePin.h"
#include "EdGraphUtilities.h"

#include "SGraphPinOffsetCoord.h"
#include "OffsetCoords.h"

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "EdGraphUtilities.h"
#include "SGraphNode.h"

class FOffsetCoordsGraphPanelPinFactory : public FGraphPanelPinFactory
{
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* InPin) const override
	{
		const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
		
		// Check if pin is struct, and then check if that pin is of struct type we want customize
		if (InPin->PinType.PinCategory == K2Schema->PC_Struct && InPin->PinType.PinSubCategoryObject == FOffsetCoords::StaticStruct())
		{
			return SNew(SGraphPinOffsetCoord, InPin); //and return our customized pin widget ;).
		}
		return nullptr;
	}
};