// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "PropertyHandle.h"
#include "Customizations/MathStructCustomizations.h"

class HEXGRIDSEDITOR_API FOffsetCoordCustomization : public FMathStructCustomization
{
public:	
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

private:

	/** FMathStructCustomization interface */
	virtual void GetSortedChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, TArray<TSharedRef<IPropertyHandle>>& OutChildren) override;

};
