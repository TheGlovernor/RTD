// Fill out your copyright notice in the Description page of Project Settings.


#include "SGraphPinOffsetCoord.h"
#include "Widgets/SBoxPanel.h"
#include "OffsetCoords.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "OffsetCoordTextBox"

class SOffsetCoordTextBox : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SOffsetCoordTextBox) {}
	SLATE_ATTRIBUTE(FString, VisibleText_C)
	SLATE_ATTRIBUTE(FString, VisibleText_R)
	SLATE_EVENT(FOnInt32ValueCommitted, OnIntCommitted_Box_C)
	SLATE_EVENT(FOnInt32ValueCommitted, OnIntCommitted_Box_R)
	SLATE_END_ARGS()

	//Construct editable text boxes with the appropriate getter & setter functions along with tool tip text
	void Construct(const FArguments& InArgs)
	{
		VisibleText_C = InArgs._VisibleText_C;
		VisibleText_R = InArgs._VisibleText_R;
		const FLinearColor LabelClr = FLinearColor(1.f, 1.f, 1.f, 0.4);

		this->ChildSlot
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(2)
					.HAlign(HAlign_Fill)
					[
						// text box 0
						SNew(SNumericEntryBox<int>)
						.LabelVAlign(VAlign_Center)
						.Label()
						[
							SNew(STextBlock)
							.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
							.Text(LOCTEXT("OffsetCoordNodeCAxisValueLabel", "Col"))
							.ColorAndOpacity(LabelClr)
						] // end numerical box label 0
						.Value(this, &SOffsetCoordTextBox::GetTypeInValue_C)
						.OnValueCommitted(InArgs._OnIntCommitted_Box_C)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.UndeterminedString(LOCTEXT("MultipleValues", "Multiple Values"))
						.ToolTipText(LOCTEXT("OffsetCoordNodeCValueLabel_ToolTip", "Column Value"))
						.EditableTextBoxStyle(&FAppStyle::GetWidgetStyle<FEditableTextBoxStyle>("Graph.VectorEditableTextBox"))
						.BorderForegroundColor(FLinearColor::White)
						.BorderBackgroundColor(FLinearColor::White)
					] // end hbox slot 1

					// Slot 2 - R value
					+ SHorizontalBox::Slot()
					.AutoWidth().Padding(2).HAlign(HAlign_Fill)
					[
						//Create Text box 1
						SNew(SNumericEntryBox<int>)
						.LabelVAlign(VAlign_Center)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("OffsetCoordNodeRAxisValueLabel", "Row"))
						.ColorAndOpacity(LabelClr)
					]
					.Value(this, &SOffsetCoordTextBox::GetTypeInValue_R)
					.OnValueCommitted(InArgs._OnIntCommitted_Box_R)
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues", "Multiple Values"))
					.ToolTipText(LOCTEXT("OffsetCoordNodeRValueLabel_ToolTip", "Row value"))
					.EditableTextBoxStyle(&FAppStyle::GetWidgetStyle<FEditableTextBoxStyle>("Graph.VectorEditableTextBox"))
					.BorderForegroundColor(FLinearColor::White)
					.BorderBackgroundColor(FLinearColor::White)
					]

				] // end vbox slot 1


			]; // end child slot

	}

private:

	//Get value for X text box
	TOptional<int> GetTypeInValue_C() const
	{
		return FCString::Atoi(*(VisibleText_C.Get()));
	}

	//Get value for Y text box
	TOptional<int> GetTypeInValue_R() const
	{
		return FCString::Atoi(*(VisibleText_R.Get()));
	}

	TAttribute< FString >	VisibleText_C;
	TAttribute< FString >	VisibleText_R;

};




void SGraphPinOffsetCoord::Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InGraphPinObj);
}

TSharedRef<SWidget> SGraphPinOffsetCoord::GetDefaultValueWidget()
{
	// Create a default Widget
	return SNew( SOffsetCoordTextBox)
		.VisibleText_C(this, &SGraphPinOffsetCoord::GetCurrentValue_C)
		.VisibleText_R(this, &SGraphPinOffsetCoord::GetCurrentValue_R)
		.Visibility(this, &SGraphPin::GetDefaultValueVisibility)
		.IsEnabled(this, &SGraphPin::GetDefaultValueIsEditable)
		.OnIntCommitted_Box_C(this, &SGraphPinOffsetCoord::OnChangedValueTextBox_C)
		.OnIntCommitted_Box_R(this, &SGraphPinOffsetCoord::OnChangedValueTextBox_R);
}

FString SGraphPinOffsetCoord::GetCurrentValue_C() const
{
	return GetValue(TextBox_C);
}

FString SGraphPinOffsetCoord::GetCurrentValue_R() const
{
	return GetValue(TextBox_R);
}

FString SGraphPinOffsetCoord::GetValue(EOffsetCoordTextBoxIndex Index) const
{
	FString DefaultString = GraphPinObj->GetDefaultAsString();
	TArray<FString> ResultString;

	FOffsetCoords Value;
	Value.InitFromString(DefaultString);

	if (Index == TextBox_C)
	{
		return FString::Printf(TEXT("%d"), Value.Col);
	}
	else
	{
		return FString::Printf(TEXT("%d"), Value.Row);
	}
}

FString MakeOffsetCoordString(const FString& C, const FString& R)
{
	return FString(TEXT("(Col=")) + C + FString(TEXT(",Row=")) + R + FString(TEXT(")"));
}

void SGraphPinOffsetCoord::OnChangedValueTextBox_C(int NewValue, ETextCommit::Type CommitInfo)
{
	if (GraphPinObj->IsPendingKill())
	{
		return;
	}

	const FString ValueStr = FString::Printf(TEXT("%d"), NewValue);
	const FString OffsetCoordString = MakeOffsetCoordString(ValueStr, GetValue(TextBox_R));

	if (GraphPinObj->GetDefaultAsString() != OffsetCoordString)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("GraphEditor", "ChangeOffsetCoordPinValue", "Change Offset Coord Pin Value"));
		GraphPinObj->Modify();

		//Set new default value
		GraphPinObj->GetSchema()->TrySetDefaultValue(*GraphPinObj, OffsetCoordString);
	}
}

void SGraphPinOffsetCoord::OnChangedValueTextBox_R(int NewValue, ETextCommit::Type CommitInfo)
{
	if (GraphPinObj->IsPendingKill())
	{
		return;
	}

	const FString ValueStr = FString::Printf(TEXT("%d"), NewValue);
	const FString OffsetCoordString = MakeOffsetCoordString(GetValue(TextBox_C), ValueStr);

	if (GraphPinObj->GetDefaultAsString() != OffsetCoordString)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("GraphEditor", "ChangeVectorPinValue", "Change Vector Pin Value"));
		GraphPinObj->Modify();

		//Set new default value
		GraphPinObj->GetSchema()->TrySetDefaultValue(*GraphPinObj, OffsetCoordString);
	}
}


#undef LOCTEXT_NAMESPACE