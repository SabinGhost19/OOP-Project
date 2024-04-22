#pragma once
class ServerLogger
{
	static ServerLogger* instance;
	char* LoggFilename;
	ServerLogger(const char* LoggerFilename);
	ServerLogger(ServerLogger& obj) = delete;
	ServerLogger(ServerLogger&& obj) = delete;
public:
	static ServerLogger* getInstance(const char* filename);
	void loggAction(const char* action);
	~ServerLogger();
};

