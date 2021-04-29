#pragma once

#include "CoreMinimal.h"

class BUGLY_API FGenericBuglyDelegate
{
public:
	FGenericBuglyDelegate();
	virtual ~FGenericBuglyDelegate();

public:
	// please make crash callback simple and clean
	virtual FString OnCrashNotify();
};
