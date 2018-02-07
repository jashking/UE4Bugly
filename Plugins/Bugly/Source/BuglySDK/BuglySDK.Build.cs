// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class BuglySDK : ModuleRules
{
	public BuglySDK(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicAdditionalFrameworks.Add(new UEBuildFramework("Bugly", "iOS/Bugly.embeddedframework.zip"));

			PublicFrameworks.Add("SystemConfiguration");
			PublicFrameworks.Add("Security");

			PublicAdditionalLibraries.Add("z");
			PublicAdditionalLibraries.Add("c++");
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "BuglySDK_UPL.xml")));
		}
	}
}
