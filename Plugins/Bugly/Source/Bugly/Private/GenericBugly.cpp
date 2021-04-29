#include "GenericBugly.h"

FGenericBugly::FGenericBugly()
{
	CrashDelegate = MakeShared<FGenericBuglyDelegate>();
}

FGenericBugly::~FGenericBugly()
{

}

void FGenericBugly::OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug)
{

}

void FGenericBugly::OnShutdown()
{
	CrashDelegate.Reset();
}

void FGenericBugly::SetCrashDelegate(TSharedPtr<FGenericBuglyDelegate> InCrashDelegate)
{
	CrashDelegate = InCrashDelegate;
}

TSharedPtr<FGenericBuglyDelegate> FGenericBugly::GetCrashDelegate()
{
	return CrashDelegate;
}

void FGenericBugly::TestNativeCrash()
{
#if !UE_BUILD_SHIPPING
	int* NullPointer = nullptr;

	*NullPointer = 0;
#endif // !UE_BUILD_SHIPPING
}

void FGenericBugly::SetUserId(const FString& InUserId)
{

}

void FGenericBugly::SetUserSceneTag(int32 InSceneTag)
{

}

void FGenericBugly::PutUserData(const FString& InKey, const FString& InValue)
{

}

void FGenericBugly::LogVerbose(const FString& InLog, const FString& InTag)
{

}

void FGenericBugly::LogDebug(const FString& InLog, const FString& InTag)
{

}

void FGenericBugly::LogInfo(const FString& InLog, const FString& InTag)
{

}

void FGenericBugly::LogWarning(const FString& InLog, const FString& InTag)
{

}

void FGenericBugly::LogError(const FString& InLog, const FString& InTag)
{

}

void FGenericBugly::SetLogCache(int32 ByteSize)
{

}

void FGenericBugly::UpdateVersion(const FString& InAppVersion)
{

}
