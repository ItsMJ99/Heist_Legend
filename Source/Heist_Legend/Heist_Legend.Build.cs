// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Heist_Legend : ModuleRules
{
	public Heist_Legend(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
