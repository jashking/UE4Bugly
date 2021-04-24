// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GenericBugly.h"

class FIOSBugly : public FGenericBugly
{
public:
	FIOSBugly();
	virtual ~FIOSBugly();

	virtual void OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug) override;
	virtual void OnShutdown() override;

	virtual void TestJavaCrash() override;
	virtual void TestANRCrash() override;
	virtual void TestNativeCrash() override;

	virtual void SetUserId(const FString& InUserId) override;
	virtual void SetUserSceneTag(int32 InSceneTag) override;
	virtual void PutUserData(const FString& InKey, const FString& InValue) override;
	virtual void LogVerbose(const FString& InTag, const FString& InLog) override;
	virtual void LogDebug(const FString& InTag, const FString& InLog) override;
	virtual void LogInfo(const FString& InTag, const FString& InLog) override;
	virtual void LogWarning(const FString& InTag, const FString& InLog) override;
	virtual void LogError(const FString& InTag, const FString& InLog) override;
	virtual void SetLogCache(int32 ByteSize) override;
};
