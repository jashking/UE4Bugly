// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
#if UE_5_0_OR_LATER
using EpicGames.Core;
#else
using Tools.DotNETCommon;
#endif
using System.IO;

public class BuglySDK : ModuleRules
{
	public BuglySDK(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		PublicDefinitions.Add("WITH_BUGLY=1");

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			string BuglyFrameworkPath = Path.Combine(ModuleDirectory, "iOS/Bugly.embeddedframework.zip");
			PublicAdditionalFrameworks.Add(new Framework("Bugly", BuglyFrameworkPath));

			Log.TraceInformation("Add bugly framework: {0}", BuglyFrameworkPath);

			PublicFrameworks.Add("SystemConfiguration");
			PublicFrameworks.Add("Security");

			PublicSystemLibraries.Add("c++");
			PublicSystemLibraries.Add("z");
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "BuglySDK_UPL.xml"));
		}
	}
}
