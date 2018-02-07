// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyBlueprintLibrary.h"

#include "Bugly.h"

void UBuglyBlueprintLibrary::TestJavaCrash()
{
	FBuglyModule::Get().GetAgent()->TestJavaCrash();
}

void UBuglyBlueprintLibrary::TestANRCrash()
{
	FBuglyModule::Get().GetAgent()->TestANRCrash();
}

void UBuglyBlueprintLibrary::TestNativeCrash()
{
	FBuglyModule::Get().GetAgent()->TestNativeCrash();
}

void UBuglyBlueprintLibrary::SetUserId(const FString& InUserId)
{
	FBuglyModule::Get().GetAgent()->SetUserId(InUserId);
}

void UBuglyBlueprintLibrary::SetUserSceneTag(int32 InTagId)
{
	FBuglyModule::Get().GetAgent()->SetUserSceneTag(InTagId);
}

void UBuglyBlueprintLibrary::PutUserData(const FString& InKey, const FString& InValue)
{
	FBuglyModule::Get().GetAgent()->PutUserData(InKey, InValue);
}

void UBuglyBlueprintLibrary::LogVerbose(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetAgent()->LogVerbose(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogDebug(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetAgent()->LogDebug(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogInfo(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetAgent()->LogInfo(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogWarning(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetAgent()->LogWarning(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogError(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetAgent()->LogError(InTag, InLog);
}

void UBuglyBlueprintLibrary::SetLogCache(int32 ByteSize)
{
	FBuglyModule::Get().GetAgent()->SetLogCache(ByteSize);
}
