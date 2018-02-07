// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuglySettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class BUGLY_API UBuglySettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, config, Category = "Android")
	FString AndroidAppID;
	
	UPROPERTY(EditAnywhere, config, Category = "Android")
	FString AndroidAppKey;

	UPROPERTY(EditAnywhere, config, Category = "iOS")
	FString IOSAppID;

	UPROPERTY(EditAnywhere, config, Category = "iOS")
	FString IOSAppKey;
};
