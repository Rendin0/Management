// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Management : ModuleRules
{
	public Management(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PublicDefinitions.AddRange(new string[] { "MANAGEMENT_EXPORTS" });

        PublicSystemIncludePaths.Add("O:/Programs/Boost");

        string BoostLibPath = Path.Combine("O:/Programs/Boost", "stage", "lib");

        PublicAdditionalLibraries.Add(Path.Combine(BoostLibPath, "libboost_filesystem-vc143-mt-x64-1_86.lib"));



        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

    }
}
