// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWidget.h"
#include "SGraphPin.h"

//UCLASS()
class HEXGRIDSEDITOR_API SGraphPinOffsetCoord : public SGraphPin
{
	SLATE_BEGIN_ARGS(SGraphPinOffsetCoord) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj);

protected:

	/**
	 *	Function to create class specific widget.
	 *
	 *	@return Reference to the newly created widget object
	 */
	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;

private:

	// Enum values to identify text boxes.
	enum EOffsetCoordTextBoxIndex
	{
		TextBox_C,
		TextBox_R
	};

	FString GetCurrentValue_C() const;
	FString GetCurrentValue_R() const;
	FString GetValue(EOffsetCoordTextBoxIndex Index) const;

	void OnChangedValueTextBox_C(int NewValue, ETextCommit::Type CommitInfo);

	/*
	 *	Function to store value when text box 1 value in modified
	 *
	 *	@param 0: Updated Float Value
	 */
	void OnChangedValueTextBox_R(int NewValue, ETextCommit::Type CommitInfo);
};
