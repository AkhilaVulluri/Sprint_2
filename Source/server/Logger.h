#pragma once

#include <stdio.h>
#include <mutex>


enum LogPriority
{
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
	static LogPriority priority;

public:
	static void set_priority(LogPriority new_priority)
	{
		priority = new_priority;
	}

	template<typename... Args>
	static void Trace(const char* message, Args... args)
	{
		if (priority <= TracePriority)
		{
	
			printf("[Trace]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Debug(const char* message, Args... args)
	{
		if (priority <= DebugPriority)
		{
		
			printf("[Debug]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Info(const char* message, Args... args)
	{
		if (priority <= InfoPriority)
		{

			printf("[Info]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Warn(const char* message, Args... args)
	{
		if (priority <= WarnPriority)
		{
			
			printf("[Warn]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Error(const char* message, Args... args)
	{
		if (priority <= ErrorPriority)
		{
		
			printf("[Error]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Critical(const char* message, Args... args)
	{
		if (priority <= CriticalPriority)
		{
		
			printf("[Critical]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",_TIME,FILE,func,LINE_);
			printf("\n");
		}
	}
};

LogPriority Logger::priority = InfoPriority;
