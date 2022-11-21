// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
#if UE_5_0_OR_LATER
using EpicGames.Core;
#else
using Tools.DotNETCommon;
#endif

public class Bugly : ModuleRules
{
	public Bugly(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

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

			// Fetch bugly so version from environment
			//string VersionDisplayNameInEnv = System.Environment.GetEnvironmentVariable("PACKAGE_BASE_VERSION");
			//string VersionNoStrInEnv = System.Environment.GetEnvironmentVariable("PACKAGE_BUILD_NO");
			//if (!string.IsNullOrEmpty(VersionDisplayNameInEnv) && !string.IsNullOrEmpty(VersionNoStrInEnv))
			//{
			//	string BuglySoVersion = string.Format("BUGLY_SO_VERSION=\"{0}.{1}\"", VersionDisplayNameInEnv, VersionNoStrInEnv);

			//	Log.TraceInformation("Append bugly so version in source: {0}", BuglySoVersion);
			//	PrivateDefinitions.Add(string.Format("{0}", BuglySoVersion));
			//}
		}
	}
}
