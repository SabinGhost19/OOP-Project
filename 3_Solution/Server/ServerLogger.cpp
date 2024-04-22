#define _CRT_SECURE_NO_WARNINGS
#include "ServerLogger.h"
#include "Exception.h"
#include <cstring>
#include <fstream>
#include <ctime>

ServerLogger* ServerLogger::instance = nullptr;

ServerLogger::ServerLogger(const char* LoggerFilename)
{
	instance = nullptr;

	this->LoggFilename = new char[strlen(LoggerFilename)+1];
	strcpy(this->LoggFilename, LoggerFilename);
	
	std::ofstream loggFile;
	loggFile.open(LoggerFilename, std::ios_base::app);
	
	if (!loggFile.is_open())
	{
		throw "ERROR WHILE OPENING THE LOGG FILE!";
		return;
	}
	loggFile.close();
}

ServerLogger* ServerLogger::getInstance(const char* filename)
{
	if (instance == nullptr)
	{
		instance = new ServerLogger(filename);
		return instance;
	}
	if (strcmp(instance->LoggFilename, filename) == 0)
		return instance;
	delete instance;
	instance = new ServerLogger(filename);
	return instance;
}

void ServerLogger::loggAction(const char* action)
{
	time_t currTime = time(0);
	std::string currTimeString(ctime(&currTime));

	currTimeString[strlen(currTimeString.c_str()) - 1] = '\0';

	std::ofstream loggFile;
	loggFile.open(this->LoggFilename, std::ios_base::app);
	loggFile << currTimeString << " : " << action << "\n";
	loggFile.close();
}

ServerLogger::~ServerLogger()
{
	delete[] instance->LoggFilename;
}
