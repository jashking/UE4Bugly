// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BuglyEditor.h"
#include "ISettingsModule.h"

#include "BuglySettings.h"

#define LOCTEXT_NAMESPACE "FBuglyEditorModule"

void FBuglyEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Bugly",
			LOCTEXT("BuglySettingsName", "Bugly"),
			LOCTEXT("BuglySettingsDescroption", "Configure the Bugly plugin"),
			GetMutableDefault<UBuglySettings>());
	}
}

void FBuglyEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Bugly");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBuglyEditorModule, BuglyEditor)