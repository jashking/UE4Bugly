// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BuglyBlueprintLibrary.generated.h"

UCLASS()
class BUGLY_API UBuglyBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void TestJavaCrash();

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void TestANRCrash();

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void TestNativeCrash();

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void SetUserId(const FString& InUserId);

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void SetUserSceneTag(int32 InTagId);

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void PutUserData(const FString& InKey, const FString& InValue);

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void LogVerbose(const FString& InTag, const FString& InLog);
	
	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void LogDebug(const FString& InTag, const FString& InLog);
	
	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void LogInfo(const FString& InTag, const FString& InLog);
	
	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void LogWarning(const FString& InTag, const FString& InLog);
	
	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void LogError(const FString& InTag, const FString& InLog);

	UFUNCTION(BlueprintCallable, Category = "Bugly")
	static void SetLogCache(int32 ByteSize);
};
