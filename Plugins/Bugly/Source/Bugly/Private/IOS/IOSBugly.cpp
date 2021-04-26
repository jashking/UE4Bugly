// Fill out your copyright notice in the Description page of Project Settings.

#include "IOSBugly.h"

#include "BuglyDefines.h"

#import <Bugly/Bugly.h>
#import <Bugly/BuglyConfig.h>
#import <Bugly/BuglyLog.h>

FIOSBugly::FIOSBugly()
{
}

FIOSBugly::~FIOSBugly()
{
}

void FIOSBugly::OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug)
{
	UE_LOG(LogBugly, Display, TEXT("Bugly for ios startup, AppID[%s], AppVersion[%s], AppChannel[%s]."), *InAppId, *InAppVersion, *InAppChanenl);

	NSString* AppIDOC = [NSString stringWithFString : InAppId];
	NSString* AppVersionOC = [NSString stringWithFString : InAppVersion];
	NSString* AppChannelOC = [NSString stringWithFString : InAppChanenl];

	BuglyConfig* config = [[BuglyConfig alloc]init];
	config.reportLogLevel = BuglyLogLevelVerbose;
	config.version = AppVersionOC;
	config.channel = AppChannelOC;
	config.debugMode = bDebug;

	[Bugly startWithAppId : AppIDOC config : config];
}

void FIOSBugly::OnShutdown()
{
}

void FIOSBugly::TestJavaCrash()
{

}

void FIOSBugly::TestANRCrash()
{

}

void FIOSBugly::TestNativeCrash()
{
	// Raise native crash
	int* NullPointer = nullptr;

	*NullPointer = 0;
}

void FIOSBugly::SetUserId(const FString& InUserId)
{
	NSString* UserIdOC = [NSString stringWithFString : InUserId];

	[Bugly setUserIdentifier : UserIdOC];
}

void FIOSBugly::SetUserSceneTag(int32 InSceneTag)
{
	[Bugly setTag:InSceneTag];
}

void FIOSBugly::PutUserData(const FString& InKey, const FString& InValue)
{
	NSString* KeyOC = [NSString stringWithFString : InKey];
	NSString* ValueOC = [NSString stringWithFString : InValue];

	[Bugly setUserValue : ValueOC forKey : KeyOC];
}

void FIOSBugly::LogVerbose(const FString& InLog, const FString& InTag)
{
	NSString* LogOC = [NSString stringWithFString : InLog];

	BLYLogVerbose(@"%@", LogOC);
}

void FIOSBugly::LogDebug(const FString& InLog, const FString& InTag)
{
	NSString* LogOC = [NSString stringWithFString : InLog];

	BLYLogDebug(@"%@", LogOC);
}

void FIOSBugly::LogInfo(const FString& InLog, const FString& InTag)
{
	NSString* LogOC = [NSString stringWithFString : InLog];

	BLYLogInfo(@"%@", LogOC);
}

void FIOSBugly::LogWarning(const FString& InLog, const FString& InTag)
{
	NSString* LogOC = [NSString stringWithFString : InLog];

	BLYLogWarn(@"%@", LogOC);
}

void FIOSBugly::LogError(const FString& InLog, const FString& InTag)
{
	NSString* LogOC = [NSString stringWithFString : InLog];

	BLYLogError(@"%@", LogOC);
}

void FIOSBugly::SetLogCache(int32 ByteSize)
{

}
