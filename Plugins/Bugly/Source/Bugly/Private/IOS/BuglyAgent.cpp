// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyAgent.h"

#include "Misc/ConfigCacheIni.h"

#include <Bugly/Bugly.h>

FBuglyAgent::FBuglyAgent()
{
}

FBuglyAgent::~FBuglyAgent()
{
}

void FBuglyAgent::OnStartup()
{
	FString AppID;

	if (GConfig)
	{
		GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("IOSAppID"), AppID, GGameIni);
	}

	const bool bDebug = !UE_BUILD_SHIPPING;

	NSString* AppIDOC = [NSString stringWithFString : AppID];

	[Bugly startWithAppId : AppIDOC developmentDevice : bDebug config : nil];
}

void FBuglyAgent::OnShutdown()
{
}

void FBuglyAgent::TestJavaCrash()
{

}

void FBuglyAgent::TestANRCrash()
{

}

void FBuglyAgent::TestNativeCrash()
{
	// Raise native crash
	int* NullPointer = nullptr;

	*NullPointer = 0;
}

void FBuglyAgent::SetUserId(const FString& InUserId)
{
	NSString* UserIdOC = [NSString stringWithFString : InUserId];

	[Bugly setUserIdentifier : UserIdOC];
}

void FBuglyAgent::SetUserSceneTag(int32 InSceneTag)
{
	[Bugly setTag:InSceneTag];
}

void FBuglyAgent::PutUserData(const FString& InKey, const FString& InValue)
{
	NSString* KeyOC = [NSString stringWithFString : InKey];
	NSString* ValueOC = [NSString stringWithFString : InValue];

	[Bugly setUserValue : ValueOC forKey : KeyOC];
}

void FBuglyAgent::LogVerbose(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelVerbose tag : TagOC log : @"%@",LogOC];
}

void FBuglyAgent::LogDebug(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelDebug tag : TagOC log : @"%@",LogOC];
}

void FBuglyAgent::LogInfo(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelInfo tag : TagOC log : @"%@",LogOC];
}

void FBuglyAgent::LogWarning(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelWarn tag : TagOC log : @"%@",LogOC];
}

void FBuglyAgent::LogError(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelError tag : TagOC log : @"%@",LogOC];
}

void FBuglyAgent::SetLogCache(int32 ByteSize)
{

}
