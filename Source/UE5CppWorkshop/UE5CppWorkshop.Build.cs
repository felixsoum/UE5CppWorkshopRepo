// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5CppWorkshop : ModuleRules
{
	public UE5CppWorkshop(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
