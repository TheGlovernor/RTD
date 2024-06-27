// Copyright 2017 Daniel Orchard. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class HexGridsEditor : ModuleRules
{
	public HexGridsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {}
			);
			
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"HexGrids",

            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"UnrealEd",
				"Slate",
				"SlateCore",
				"InputCore",
				"EditorStyle",
				"GraphEditor",
                "Kismet",
                "KismetCompiler",
				"BlueprintGraph",
				"DetailCustomizations",
				"PropertyEditor",
                "PlacementMode",
				"AssetRegistry",
				"Projects"

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
