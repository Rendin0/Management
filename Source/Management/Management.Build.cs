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

        string BoostPath = "O:/Programs/Boost";
        string BoostLibPath = Path.Combine(BoostPath, "stage", "lib");

        PublicSystemIncludePaths.Add(BoostPath);

        PublicAdditionalLibraries.Add(Path.Combine(BoostLibPath, "libboost_filesystem-vc143-mt-x64-1_86.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(BoostLibPath, "libboost_exception-vc143-mt-x64-1_86.lib"));
        
        bEnableExceptions = true;

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

    }
}
