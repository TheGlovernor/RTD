// Fill out your copyright notice in the Description page of Project Settings.


#include "OffsetCoordCustomization.h"

#define LOCTEXT_NAMESPACE "FOffsetCoordStructCustomization"




#undef LOCTEXT_NAMESPACE

TSharedRef<IPropertyTypeCustomization> FOffsetCoordCustomization::MakeInstance()
{
	return MakeShareable(new FOffsetCoordCustomization);
}

void FOffsetCoordCustomization::GetSortedChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, TArray<TSharedRef<IPropertyHandle>>& OutChildren)
{
	static const FName ColName("Col");
	static const FName RowName("Row");

	TSharedPtr<IPropertyHandle> ColumnRowChildren[2];

	uint32 NumChildren;
	StructPropertyHandle->GetNumChildren(NumChildren);

	for (uint32 ChildIndex = 0; ChildIndex < NumChildren; ++ChildIndex)
	{
		TSharedRef<IPropertyHandle> ChildHandle = StructPropertyHandle->GetChildHandle(ChildIndex).ToSharedRef();
		const FName PropertyName = ChildHandle->GetProperty()->GetFName();

		if (PropertyName == ColName)
		{
			ColumnRowChildren[0] = ChildHandle;
		}
		else
		{
			check(PropertyName == RowName);
			ColumnRowChildren[1] = ChildHandle;
		}
	}

	OutChildren.Add(ColumnRowChildren[0].ToSharedRef());
	OutChildren.Add(ColumnRowChildren[1].ToSharedRef());

}

