// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * TODO:
 * 1. Set app channel
 * 2. Set app version
 * 3. Set app package name
 */
class BUGLY_API IBuglyAgentInterface
{
public:
	virtual void OnStartup() = 0;
	virtual void OnShutdown() = 0;

	virtual void TestJavaCrash() = 0;
	virtual void TestANRCrash() = 0;
	virtual void TestNativeCrash() = 0;

	virtual void SetUserId(const FString& InUserId) = 0;
	virtual void SetUserSceneTag(int32 InSceneTag) = 0;
	virtual void PutUserData(const FString& InKey, const FString& InValue) = 0;
	virtual void LogVerbose(const FString& InTag, const FString& InLog) = 0;
	virtual void LogDebug(const FString& InTag, const FString& InLog) = 0;
	virtual void LogInfo(const FString& InTag, const FString& InLog) = 0;
	virtual void LogWarning(const FString& InTag, const FString& InLog) = 0;
	virtual void LogError(const FString& InTag, const FString& InLog) = 0;
	virtual void SetLogCache(int32 ByteSize) = 0;
};
