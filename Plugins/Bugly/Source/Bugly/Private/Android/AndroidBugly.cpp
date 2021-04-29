// Fill out your copyright notice in the Description page of Project Settings.

#include "AndroidBugly.h"

#include "Android/AndroidJavaEnv.h"

#include "BuglyDefines.h"
#include "BuglyModule.h"
#include "GenericBuglyDelegate.h"

jmethodID FAndroidBugly::InitCrashReportMethod;
jmethodID FAndroidBugly::SetUserIdMethod;
jmethodID FAndroidBugly::SetUserSceneTagMethod;
jmethodID FAndroidBugly::PutUserDataMethod;
jmethodID FAndroidBugly::LogVerboseMethod;
jmethodID FAndroidBugly::LogDebugMethod;
jmethodID FAndroidBugly::LogInfoMethod;
jmethodID FAndroidBugly::LogWarningMethod;
jmethodID FAndroidBugly::LogErrorMethod;
jmethodID FAndroidBugly::SetLogCacheMethod;
jmethodID FAndroidBugly::UpdateAppVersionMethod;

//#ifdef BUGLY_SO_VERSION
//#define BUGLY_STR_HELPER(x) #x
//#define BUGLY_STR(x) BUGLY_STR_HELPER(x)
//extern "C" const char SO_FILE_VERSION[] __attribute__((section(".bugly_version"))) = BUGLY_STR(BUGLY_SO_VERSION);
//#endif // BUGLY_SO_VERSION

JNI_METHOD jstring Java_com_epicgames_ue4_GameActivity_nativeOnCrashNotify(JNIEnv* jenv, jobject thiz)
{
	UE_LOG(LogBugly, Error, TEXT("Bugly caught an exception!"));

	TSharedPtr<FGenericBuglyDelegate> CrashDelegate = FBuglyModule::Get().GetBugly()->GetCrashDelegate();
	const FString Logs = CrashDelegate.IsValid() ? CrashDelegate->OnCrashNotify() : TEXT("");

	jstring LogsJava = jenv->NewStringUTF(TCHAR_TO_UTF8(*Logs));

	return LogsJava;
}

FAndroidBugly::FAndroidBugly()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		InitCrashReportMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_InitCrashReport", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", false);
		SetUserIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetUserId", "(Ljava/lang/String;)V", false);
		SetUserSceneTagMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetUserSceneTag", "(I)V", false);
		PutUserDataMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_PutUserData", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogVerboseMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogVerbose", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogDebugMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogDebug", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogInfoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogInfo", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogWarningMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogWarning", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogErrorMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogError", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		SetLogCacheMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetLogCache", "(I)V", false);
		UpdateAppVersionMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_UpdateAppVersion", "(Ljava/lang/String;)V", false);
	}
}

FAndroidBugly::~FAndroidBugly()
{
}

void FAndroidBugly::OnStartup(const FString& InAppId, const FString& InAppVersion, const FString& InAppChanenl, bool bDebug)
{
	UE_LOG(LogBugly, Display, TEXT("Bugly for android startup, AppID[%s], AppVersion[%s], AppChannel[%s]."), *InAppId, *InAppVersion, *InAppChanenl);

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto AppIDJava = FJavaHelper::ToJavaString(Env, InAppId);
		auto AppVersionJava = FJavaHelper::ToJavaString(Env, InAppVersion);
		auto AppChannelJava = FJavaHelper::ToJavaString(Env, InAppChanenl);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, InitCrashReportMethod, *AppIDJava, *AppVersionJava, *AppChannelJava, bDebug);
	}
}

void FAndroidBugly::OnShutdown()
{
}

void FAndroidBugly::SetUserId(const FString& InUserId)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto UserIdJava = FJavaHelper::ToJavaString(Env, InUserId);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetUserIdMethod, *UserIdJava);
	}
}

void FAndroidBugly::SetUserSceneTag(int32 InSceneTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetUserSceneTagMethod, InSceneTag);
	}
}

void FAndroidBugly::PutUserData(const FString& InKey, const FString& InValue)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto KeyJava = FJavaHelper::ToJavaString(Env, InKey);
		auto ValueJava = FJavaHelper::ToJavaString(Env, InValue);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PutUserDataMethod, *KeyJava, *ValueJava);
	}
}

void FAndroidBugly::LogVerbose(const FString& InLog, const FString& InTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto TagJava = FJavaHelper::ToJavaString(Env, InTag);
		auto LogJava = FJavaHelper::ToJavaString(Env, InLog);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogVerboseMethod, *TagJava, *LogJava);
	}
}

void FAndroidBugly::LogDebug(const FString& InLog, const FString& InTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto TagJava = FJavaHelper::ToJavaString(Env, InTag);
		auto LogJava = FJavaHelper::ToJavaString(Env, InLog);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogDebugMethod, *TagJava, *LogJava);
	}
}

void FAndroidBugly::LogInfo(const FString& InLog, const FString& InTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto TagJava = FJavaHelper::ToJavaString(Env, InTag);
		auto LogJava = FJavaHelper::ToJavaString(Env, InLog);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogInfoMethod, *TagJava, *LogJava);
	}
}

void FAndroidBugly::LogWarning(const FString& InLog, const FString& InTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto TagJava = FJavaHelper::ToJavaString(Env, InTag);
		auto LogJava = FJavaHelper::ToJavaString(Env, InLog);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogWarningMethod, *TagJava, *LogJava);
	}
}

void FAndroidBugly::LogError(const FString& InLog, const FString& InTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto TagJava = FJavaHelper::ToJavaString(Env, InTag);
		auto LogJava = FJavaHelper::ToJavaString(Env, InLog);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogErrorMethod, *TagJava, *LogJava);
	}
}

void FAndroidBugly::SetLogCache(int32 ByteSize)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetLogCacheMethod, ByteSize);
	}
}

void FAndroidBugly::UpdateVersion(const FString& InAppVersion)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto AppVersionJava = FJavaHelper::ToJavaString(Env, InAppVersion);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, UpdateAppVersionMethod, *AppVersionJava);
	}
}
