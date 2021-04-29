// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GenericBugly.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

class FAndroidBugly : public FGenericBugly
{
public:
	FAndroidBugly();
	virtual ~FAndroidBugly();

	virtual void OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug) override;
	virtual void OnShutdown() override;
	virtual void SetUserId(const FString& InUserId) override;
	virtual void SetUserSceneTag(int32 InSceneTag) override;
	virtual void PutUserData(const FString& InKey, const FString& InValue) override;
	virtual void LogVerbose(const FString& InLog, const FString& InTag = TEXT("")) override;
	virtual void LogDebug(const FString& InLog, const FString& InTag = TEXT("")) override;
	virtual void LogInfo(const FString& InLog, const FString& InTag = TEXT("")) override;
	virtual void LogWarning(const FString& InLog, const FString& InTag = TEXT("")) override;
	virtual void LogError(const FString& InLog, const FString& InTag = TEXT("")) override;
	virtual void SetLogCache(int32 ByteSize) override;
	virtual void UpdateVersion(const FString& InAppVersion) override;

	// JNI Methods
	static jmethodID InitCrashReportMethod;
	static jmethodID SetUserIdMethod;
	static jmethodID SetUserSceneTagMethod;
	static jmethodID PutUserDataMethod;
	static jmethodID LogVerboseMethod;
	static jmethodID LogDebugMethod;
	static jmethodID LogInfoMethod;
	static jmethodID LogWarningMethod;
	static jmethodID LogErrorMethod;
	static jmethodID SetLogCacheMethod;
	static jmethodID UpdateAppVersionMethod;
};