// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;

public class Bugly : ModuleRules
{
	public Bugly(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.Add("Bugly/Public");
		PrivateIncludePaths.Add("Bugly/Private");
		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PrivateIncludePaths.Add("Bugly/Private/IOS");
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateIncludePaths.Add("Bugly/Private/Android");
		}
		else
		{
			PrivateIncludePaths.Add("Bugly/Private/Dummy");
		}

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				// ... add private dependencies that you statically link with here ...	
				"BuglySDK",
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
		}
	}
}
