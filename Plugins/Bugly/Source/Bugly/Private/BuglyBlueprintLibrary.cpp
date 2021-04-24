// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyBlueprintLibrary.h"

#include "BuglyModule.h"

void UBuglyBlueprintLibrary::TestJavaCrash()
{
	FBuglyModule::Get().GetBugly()->TestJavaCrash();
}

void UBuglyBlueprintLibrary::TestANRCrash()
{
	FBuglyModule::Get().GetBugly()->TestANRCrash();
}

void UBuglyBlueprintLibrary::TestNativeCrash()
{
	FBuglyModule::Get().GetBugly()->TestNativeCrash();
}

void UBuglyBlueprintLibrary::SetUserId(const FString& InUserId)
{
	FBuglyModule::Get().GetBugly()->SetUserId(InUserId);
}

void UBuglyBlueprintLibrary::SetUserSceneTag(int32 InTagId)
{
	FBuglyModule::Get().GetBugly()->SetUserSceneTag(InTagId);
}

void UBuglyBlueprintLibrary::PutUserData(const FString& InKey, const FString& InValue)
{
	FBuglyModule::Get().GetBugly()->PutUserData(InKey, InValue);
}

void UBuglyBlueprintLibrary::LogVerbose(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetBugly()->LogVerbose(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogDebug(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetBugly()->LogDebug(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogInfo(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetBugly()->LogInfo(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogWarning(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetBugly()->LogWarning(InTag, InLog);
}

void UBuglyBlueprintLibrary::LogError(const FString& InTag, const FString& InLog)
{
	FBuglyModule::Get().GetBugly()->LogError(InTag, InLog);
}

void UBuglyBlueprintLibrary::SetLogCache(int32 ByteSize)
{
	FBuglyModule::Get().GetBugly()->SetLogCache(ByteSize);
}
