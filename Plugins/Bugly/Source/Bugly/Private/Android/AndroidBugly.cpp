// Fill out your copyright notice in the Description page of Project Settings.

#include "AndroidBugly.h"

#include "BuglyDefines.h"

jmethodID FAndroidBugly::InitCrashReportMethod;
jmethodID FAndroidBugly::TestJavaCrashMethod;
jmethodID FAndroidBugly::TestANRCrashMethod;
jmethodID FAndroidBugly::TestNativeCrashMethod;
jmethodID FAndroidBugly::SetUserIdMethod;
jmethodID FAndroidBugly::SetUserSceneTagMethod;
jmethodID FAndroidBugly::PutUserDataMethod;
jmethodID FAndroidBugly::LogVerboseMethod;
jmethodID FAndroidBugly::LogDebugMethod;
jmethodID FAndroidBugly::LogInfoMethod;
jmethodID FAndroidBugly::LogWarningMethod;
jmethodID FAndroidBugly::LogErrorMethod;
jmethodID FAndroidBugly::SetLogCacheMethod;

FAndroidBugly::FAndroidBugly()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		InitCrashReportMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_InitCrashReport", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", false);
		TestJavaCrashMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_TestJavaCrash", "()V", false);
		TestANRCrashMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_TestANRCrash", "()V", false);
		TestNativeCrashMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_TestNativeCrash", "()V", false);

		SetUserIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetUserId", "(Ljava/lang/String;)V", false);
		SetUserSceneTagMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetUserSceneTag", "(I)V", false);
		PutUserDataMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_PutUserData", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogVerboseMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogVerbose", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogDebugMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogDebug", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogInfoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogInfo", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogWarningMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogWarning", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		LogErrorMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_LogError", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		SetLogCacheMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_SetLogCache", "(I)V", false);
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
		jstring AppIDJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InAppId));
		jstring AppVersionJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InAppVersion));
		jstring AppChannelJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InAppChanenl));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, InitCrashReportMethod, AppIDJava, AppVersionJava, AppChannelJava, bDebug);

		Env->DeleteLocalRef(AppIDJava);
		Env->DeleteLocalRef(AppVersionJava);
		Env->DeleteLocalRef(AppChannelJava);
	}
}

void FAndroidBugly::OnShutdown()
{
}

void FAndroidBugly::TestJavaCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestJavaCrashMethod);
	}
}

void FAndroidBugly::TestANRCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestANRCrashMethod);
	}
}

void FAndroidBugly::TestNativeCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestNativeCrashMethod);
	}
}

void FAndroidBugly::SetUserId(const FString& InUserId)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring UserIdJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InUserId));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetUserIdMethod, UserIdJava);

		Env->DeleteLocalRef(UserIdJava);
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
		jstring KeyJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InKey));
		jstring ValueJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InValue));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PutUserDataMethod, KeyJava, ValueJava);

		Env->DeleteLocalRef(KeyJava);
		Env->DeleteLocalRef(ValueJava);
	}
}

void FAndroidBugly::LogVerbose(const FString& InTag, const FString& InLog)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring TagJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InTag));
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InLog));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogVerboseMethod, TagJava, LogJava);

		Env->DeleteLocalRef(TagJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void FAndroidBugly::LogDebug(const FString& InTag, const FString& InLog)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring TagJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InTag));
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InLog));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogDebugMethod, TagJava, LogJava);

		Env->DeleteLocalRef(TagJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void FAndroidBugly::LogInfo(const FString& InTag, const FString& InLog)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring TagJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InTag));
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InLog));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogInfoMethod, TagJava, LogJava);

		Env->DeleteLocalRef(TagJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void FAndroidBugly::LogWarning(const FString& InTag, const FString& InLog)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring TagJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InTag));
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InLog));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogWarningMethod, TagJava, LogJava);

		Env->DeleteLocalRef(TagJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void FAndroidBugly::LogError(const FString& InTag, const FString& InLog)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring TagJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InTag));
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InLog));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, LogErrorMethod, TagJava, LogJava);

		Env->DeleteLocalRef(TagJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void FAndroidBugly::SetLogCache(int32 ByteSize)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetLogCacheMethod, ByteSize);
	}
}
