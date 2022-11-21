#pragma once
#include<iostream>
using namespace std;
#include <stdio.h>
#include <mutex>
#define LOG_FILE "log.txt"
#include <fstream>

enum LogPriority
{
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

ofstream file(LOG_FILE);


class Logger
{
private:
	static LogPriority priority;
//	FILE *file;
//	file=fopen("log.txt","w+");


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
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
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
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
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
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
			printf("\n");
			file<<"\tTIME:"<<__TIME__<<"\tFILENAME:"<<__FILE__<<"\tFUNCTIONNAME:"<<__func__<<message<<"\tLINE NUMBER:"<<__LINE__;
			cout<<endl;
		}
	}

	template<typename... Args>
	static void Warn(const char* message, Args... args)
	{
		if (priority <= WarnPriority)
		{
			
			printf("[Warn]\t");
			printf(message, args...);
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
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
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
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
			printf("[%s] [%s] [%s] [line:%d] ",__TIME__,__FILE__,__func__,__LINE__);
			printf("\n");
		}
	}
};

LogPriority Logger::priority = InfoPriority;
