// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyAgent.h"
#include "Bugly.h"

#if !PLATFORM_IOS && !PLATFORM_ANDROID

FBuglyAgent::FBuglyAgent()
{
}

FBuglyAgent::~FBuglyAgent()
{
}

void FBuglyAgent::OnStartup()
{
}

void FBuglyAgent::OnShutdown()
{

}

void FBuglyAgent::TestJavaCrash()
{
	UE_LOG(LogBugly, Display, TEXT("TestJavaCrash not implement."));
}

void FBuglyAgent::TestANRCrash()
{
	UE_LOG(LogBugly, Display, TEXT("TestANRCrash not implement."));
}

void FBuglyAgent::TestNativeCrash()
{
	UE_LOG(LogBugly, Display, TEXT("TestNativeCrash not implement."));
}

void FBuglyAgent::SetUserId(const FString& InUserId)
{

}

void FBuglyAgent::SetUserSceneTag(int32 InSceneTag)
{

}

void FBuglyAgent::PutUserData(const FString& InKey, const FString& InValue)
{

}

void FBuglyAgent::LogVerbose(const FString& InTag, const FString& InLog)
{

}

void FBuglyAgent::LogDebug(const FString& InTag, const FString& InLog)
{

}

void FBuglyAgent::LogInfo(const FString& InTag, const FString& InLog)
{

}

void FBuglyAgent::LogWarning(const FString& InTag, const FString& InLog)
{

}

void FBuglyAgent::LogError(const FString& InTag, const FString& InLog)
{

}

void FBuglyAgent::SetLogCache(int32 ByteSize)
{

}

#endif // !PLATFORM_IOS && !PLATFORM_ANDROID
