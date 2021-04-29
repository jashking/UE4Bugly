// Fill out your copyright notice in the Description page of Project Settings.

#include "IOSBugly.h"

#include "BuglyDefines.h"
#include "BuglyModule.h"
#include "GenericBuglyDelegate.h"

#import <Bugly/Bugly.h>
#import <Bugly/BuglyConfig.h>
#import <Bugly/BuglyLog.h>

@interface FBuglyCrashDelegate : NSObject<BuglyDelegate>
@end

@implementation FBuglyCrashDelegate

- (NSString*)attachmentForException:(NSException*)exception
{
	UE_LOG(LogBugly, Error, TEXT("Bugly caught an exception!"));

	TSharedPtr<FGenericBuglyDelegate> CrashDelegate = FBuglyModule::Get().GetBugly()->GetCrashDelegate();
	const FString Logs = CrashDelegate.IsValid() ? CrashDelegate->OnCrashNotify() : TEXT("");

	NSString* LogsOC = [NSString stringWithFString : Logs];
	return LogsOC;
}

@end

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
	config.delegate = [[FBuglyCrashDelegate alloc]init];

	[Bugly startWithAppId : AppIDOC config : config];
}

void FIOSBugly::OnShutdown()
{
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

void FIOSBugly::UpdateVersion(const FString& InAppVersion)
{
	NSString* AppVersionOC = [NSString stringWithFString : InAppVersion];

	[Bugly updateAppVersion : AppVersionOC];
}
