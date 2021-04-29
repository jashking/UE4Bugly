#include "GenericBuglyDelegate.h"

#include "GenericPlatform/GenericPlatformOutputDevices.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/FileHelper.h"
#include "Misc/OutputDeviceFile.h"
#include "Serialization/BufferWriter.h"

#if PLATFORM_ANDROID
const static int32 BUGLY_LOG_LIMIT_SIZE = 30000; // 30k
#elif PLATFORM_IOS
const static int32 BUGLY_LOG_LIMIT_SIZE = 100000; // 100k
#else
const static int32 BUGLY_LOG_LIMIT_SIZE = 30000;
#endif

const static int32 LOG_IMPORTANT_HEAD_SIZE = 10000; // 10k

FGenericBuglyDelegate::FGenericBuglyDelegate()
{

}

FGenericBuglyDelegate::~FGenericBuglyDelegate()
{

}

FString FGenericBuglyDelegate::OnCrashNotify()
{
	FString Logs;

	if (GLog)
	{
		GLog->PanicFlushThreadedLogs();
	}

	FOutputDevice* LogDevice = FGenericPlatformOutputDevices::GetLog();
	if (LogDevice)
	{
		if (LogDevice->IsMemoryOnly())
		{
			void* DefaultBuffer = FMemory::Malloc(1024);

			FBufferWriter BufferWriter(DefaultBuffer, 1024, EBufferWriterFlags::TakeOwnership | EBufferWriterFlags::AllowResize);
			LogDevice->Dump(BufferWriter);
			const void* WriterData = BufferWriter.GetWriterData();

			FFileHelper::BufferToString(Logs, (const uint8*)WriterData, (int32)BufferWriter.Tell());
		}
		else
		{
			FOutputDeviceFile* LogDeviceFile = static_cast<FOutputDeviceFile*>(LogDevice);
			if (LogDeviceFile)
			{
				FFileHelper::LoadFileToString(Logs, LogDeviceFile->GetFilename(), FFileHelper::EHashOptions::None, FILEREAD_AllowWrite);
			}
		}
	}

	if (Logs.Len() > BUGLY_LOG_LIMIT_SIZE)
	{
		Logs.RemoveAt(LOG_IMPORTANT_HEAD_SIZE, Logs.Len() - BUGLY_LOG_LIMIT_SIZE, true);
	}

	return Logs;
}
