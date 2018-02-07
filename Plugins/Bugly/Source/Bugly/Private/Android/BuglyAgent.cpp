// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyAgent.h"

#include "Misc/ConfigCacheIni.h"

#include "Bugly.h"

jmethodID FBuglyAgent::InitCrashReportMethod;
jmethodID FBuglyAgent::TestJavaCrashMethod;
jmethodID FBuglyAgent::TestANRCrashMethod;
jmethodID FBuglyAgent::TestNativeCrashMethod;
jmethodID FBuglyAgent::SetUserIdMethod;
jmethodID FBuglyAgent::SetUserSceneTagMethod;
jmethodID FBuglyAgent::PutUserDataMethod;
jmethodID FBuglyAgent::LogVerboseMethod;
jmethodID FBuglyAgent::LogDebugMethod;
jmethodID FBuglyAgent::LogInfoMethod;
jmethodID FBuglyAgent::LogWarningMethod;
jmethodID FBuglyAgent::LogErrorMethod;
jmethodID FBuglyAgent::SetLogCacheMethod;

FBuglyAgent::FBuglyAgent()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		InitCrashReportMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Bugly_InitCrashReport", "(Ljava/lang/String;Z)V", false);
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

FBuglyAgent::~FBuglyAgent()
{
}

void FBuglyAgent::OnStartup()
{
	FString AppID;

	if (GConfig)
	{
		GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("AndroidAppID"), AppID, GGameIni);
	}

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bDebug = !UE_BUILD_SHIPPING;

		jstring AppIDJava = Env->NewStringUTF(TCHAR_TO_UTF8(*AppID));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, InitCrashReportMethod, AppIDJava, bDebug);

		Env->DeleteLocalRef(AppIDJava);
	}

	UE_LOG(LogBugly, Display, TEXT("Bugly for android startup, AppID[%s]."), *AppID);
}

void FBuglyAgent::OnShutdown()
{
}

void FBuglyAgent::TestJavaCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestJavaCrashMethod);
	}
}

void FBuglyAgent::TestANRCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestANRCrashMethod);
	}
}

void FBuglyAgent::TestNativeCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, TestNativeCrashMethod);
	}
}

void FBuglyAgent::SetUserId(const FString& InUserId)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring UserIdJava = Env->NewStringUTF(TCHAR_TO_UTF8(*InUserId));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetUserIdMethod, UserIdJava);

		Env->DeleteLocalRef(UserIdJava);
	}
}

void FBuglyAgent::SetUserSceneTag(int32 InSceneTag)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetUserSceneTagMethod, InSceneTag);
	}
}

void FBuglyAgent::PutUserData(const FString& InKey, const FString& InValue)
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

void FBuglyAgent::LogVerbose(const FString& InTag, const FString& InLog)
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

void FBuglyAgent::LogDebug(const FString& InTag, const FString& InLog)
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

void FBuglyAgent::LogInfo(const FString& InTag, const FString& InLog)
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

void FBuglyAgent::LogWarning(const FString& InTag, const FString& InLog)
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

void FBuglyAgent::LogError(const FString& InTag, const FString& InLog)
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

void FBuglyAgent::SetLogCache(int32 ByteSize)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetLogCacheMethod, ByteSize);
	}
}
