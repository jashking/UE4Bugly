// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "GenericBuglyDelegate.h"

class BUGLY_API FGenericBugly
{
public:
	FGenericBugly();
	virtual ~FGenericBugly();

	virtual void OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug);
	virtual void OnShutdown();
	virtual void SetCrashDelegate(TSharedPtr<FGenericBuglyDelegate> InCrashDelegate);
	virtual TSharedPtr<FGenericBuglyDelegate> GetCrashDelegate();
	virtual void TestNativeCrash();
	virtual void SetUserId(const FString& InUserId);
	virtual void SetUserSceneTag(int32 InSceneTag);
	virtual void PutUserData(const FString& InKey, const FString& InValue);
	virtual void LogVerbose(const FString& InLog, const FString& InTag = TEXT(""));
	virtual void LogDebug(const FString& InLog, const FString& InTag = TEXT(""));
	virtual void LogInfo(const FString& InLog, const FString& InTag = TEXT(""));
	virtual void LogWarning(const FString& InLog, const FString& InTag = TEXT(""));
	virtual void LogError(const FString& InLog, const FString& InTag = TEXT(""));
	virtual void SetLogCache(int32 ByteSize);
	virtual void UpdateVersion(const FString& InAppVersion);

protected:
	TSharedPtr<FGenericBuglyDelegate> CrashDelegate;
};
