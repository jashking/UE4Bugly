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
	config.channel = AppVersionOC;
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

void FIOSBugly::LogVerbose(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelVerbose tag : TagOC log : @"%@",LogOC];
}

void FIOSBugly::LogDebug(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelDebug tag : TagOC log : @"%@",LogOC];
}

void FIOSBugly::LogInfo(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelInfo tag : TagOC log : @"%@",LogOC];
}

void FIOSBugly::LogWarning(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelWarn tag : TagOC log : @"%@",LogOC];
}

void FIOSBugly::LogError(const FString& InTag, const FString& InLog)
{
	NSString* TagOC = [NSString stringWithFString : InTag];
	NSString* LogOC = [NSString stringWithFString : InLog];

	[BuglyLog level : BuglyLogLevelError tag : TagOC log : @"%@",LogOC];
}

void FIOSBugly::SetLogCache(int32 ByteSize)
{

}
