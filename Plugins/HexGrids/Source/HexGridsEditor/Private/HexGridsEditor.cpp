// Copyright 2020 Daniel Orchard. All Rights Reserved.

#include "HexGridsEditor.h"
#include "OffsetCoordsGraphPanelNodeFactory.h"
#include "EdGraphUtilities.h"
#include "OffsetCoordCustomization.h"

#include "DetailCustomizations.h"
#include "PropertyEditorModule.h"

#include "AssetRegistry/IAssetRegistry.h"
#include "IPlacementModeModule.h"
#include "Interfaces/IPluginManager.h"
#include "ActorFactories/ActorFactoryBlueprint.h"

#define LOCTEXT_NAMESPACE "FHexGridsEditorModule"

void FHexGridsEditorModule::StartupModule()
{
	
	TSharedPtr<FOffsetCoordsGraphPanelPinFactory> OffsetCoordsGraphPanelPinFactory = MakeShareable(new FOffsetCoordsGraphPanelPinFactory());
	RegisterPropertyTypeCustomizations();
		
	FEdGraphUtilities::RegisterVisualPinFactory(OffsetCoordsGraphPanelPinFactory);

    FCoreDelegates::OnFEngineLoopInitComplete.AddRaw(this, &FHexGridsEditorModule::OnFEngineLoopInitComplete);

}

void FHexGridsEditorModule::ShutdownModule()
{
	FCoreDelegates::OnFEngineLoopInitComplete.RemoveAll(this);
}



void FHexGridsEditorModule::OnFEngineLoopInitComplete()
{
    RegisterHexGridInPlaceables();
}

void FHexGridsEditorModule::RegisterPropertyTypeCustomizations()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.RegisterCustomPropertyTypeLayout("OffsetCoords", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FOffsetCoordCustomization::MakeInstance));
}


// Disabled this system for now as not found the best way to reference our blueprint with FAssetData, will be restored in future update. 
void FHexGridsEditorModule::RegisterHexGridInPlaceables()
{
  //  // Create a custom category and register it
  //  const FPlacementCategoryInfo Info(
  //      INVTEXT("Hex Grids"),
  //      FSlateIcon(FAppStyle::GetAppStyleSetName(), "PlacementBrowser.Icons.Basic"),
  //      "HexGrids",
  //      TEXT("HexGrids"),
  //      100
  //  );

  //  IPlacementModeModule& PlacementModeModule = IPlacementModeModule::Get();
  //  PlacementModeModule.RegisterPlacementCategory(Info);

  //  TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("HexGrids"));
  //  TArray<FAssetData> OutAssets;
  //  const FString PlaceablePath = Plugin->GetContentDir();

  //  FString PackagePath;
  //  FString* OutFailureReason = nullptr;
  //  FPackageName::TryConvertFilenameToLongPackageName(PlaceablePath, PackagePath, OutFailureReason);

  //  IAssetRegistry* AssetRegistry = IAssetRegistry::Get();

  //  AssetRegistry->ScanPathsSynchronous({ PlaceablePath });
  //  AssetRegistry->GetAssetsByPath(*PackagePath, OutAssets);

  //  if (OutAssets.Num() > 0)
  //  {
		//for (const FAssetData& Asset : OutAssets)
		//{
		//	TSharedRef<FPlaceableItem> Item =
		//		MakeShared<FPlaceableItem>(
		//			*UActorFactoryBlueprint::StaticClass(),
		//			Asset
		//		);

		//	Item->DisplayName =
		//		FText::FromString(
		//			Item->DisplayName.ToString().Replace(TEXT("_"), TEXT(" "))
		//		);

		//	PlacementModeModule.RegisterPlaceableItem(Info.UniqueHandle, Item);
		//}
  //  }
}

void FHexGridsEditorModule::UnregisterHexGridInPlaceables()
{
    // Unregister the custom category when the module is shut down
    if (IPlacementModeModule::IsAvailable())
    {
        IPlacementModeModule::Get().UnregisterPlacementCategory("Hex Grids");
    }
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHexGridsEditorModule, HexGridsEditor)