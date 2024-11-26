// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.Globalization;
using System.IO;
using UnrealBuildTool;

public class Management : ModuleRules
{
    public Management(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PublicDefinitions.AddRange(new string[] { "MANAGEMENT_EXPORTS" });

        bEnableExceptions = true;

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        CopyHeaders();
        CopyLibs();
    }
    private void CopyHeaders()
    {
        string appDataPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
        string targetFolderPath = Path.Combine(appDataPath, "Management");
        string includePath = Path.Combine(targetFolderPath, "Include");


        if (!Directory.Exists(targetFolderPath))
            Directory.CreateDirectory(targetFolderPath);

        if (!Directory.Exists(includePath))
            Directory.CreateDirectory(includePath);


        File.Copy(Path.Combine(ModuleDirectory, "MANObject.h"), Path.Combine(includePath, "MANObject.h"), true);
        File.Copy(Path.Combine(ModuleDirectory, "MANWorker.h"), Path.Combine(includePath, "MANWorker.h"), true);
        File.Copy(Path.Combine(ModuleDirectory, "MANResourceNode.h"), Path.Combine(includePath, "MANResourceNode.h"), true);
    }

    private void CopyLibs()
    {
        string appDataPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
        string exitLibsPath = Path.Combine(appDataPath, "Management", "Libs");
        string rootPath = Directory.GetParent(ModuleDirectory).Parent.ToString();
        string devLib = Path.Combine(rootPath, "Binaries", "Win64", "Management.lib");
        string ueDevLib = Path.Combine(rootPath, "Intermediate", "Build", "Win64", "x64", "UnrealEditor", "Development", "Management", "UnrealEditor-Management.lib");
        string ueDevSupLib = Path.Combine(rootPath, "Intermediate", "Build", "Win64", "x64", "UnrealEditor", "Development", "Management", "UnrealEditor-Management.sup.lib");
        string shippingLib = Path.Combine(rootPath, "Binaries", "Win64", "Management-Win64-Shipping.lib");

        if (!Directory.Exists(exitLibsPath))
            Directory.CreateDirectory(exitLibsPath);

        if (File.Exists(devLib))
            File.Copy(devLib, Path.Combine(exitLibsPath, "Management.lib"), true);

        if (File.Exists(ueDevLib))
            File.Copy(ueDevLib, Path.Combine(exitLibsPath, "UnrealEditor-Management.lib"), true);

        if (File.Exists(ueDevSupLib))
            File.Copy(ueDevSupLib, Path.Combine(exitLibsPath, "UnrealEditor-Management.sup.lib"), true);

        if (File.Exists(shippingLib))
            File.Copy(shippingLib, Path.Combine(exitLibsPath, "Shipping-Management.lib"), true);
    }

}
