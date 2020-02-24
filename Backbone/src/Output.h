#ifndef OUTPUT_H
#define OUTPUT_H

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

enum TraceLevel {CRITICAL  = 0, ERROR, WARN, INFO, DEBUG, TRACE};

class Output
{
public:
    Output() : mp_logger(nullptr), m_outputName(""), 
	m_inputPath(""), m_inputName("") {}

    void printStart();
	void printEnd();
	void createLogger(std::string loggerName = "ALMOST");
	std::shared_ptr<spdlog::logger> getLogger();
	void setInputPath(std::string inputPath);
	void setOutputPath(std::string ioutputPathName);
	void setLevel(std::string level);
	std::string getInputPath() {return m_inputPath;}
	std::string getInputName() {return m_inputName;}
	std::string getOutputName() {return m_outputName;}
	static std::string GetCurrentWorkingDir();

private: 
	void removeOldOutputFile();

	std::shared_ptr<spdlog::logger> mp_logger;
	std::string m_outputPath;
	std::string m_outputName;
	std::string m_inputPath;
	std::string m_inputName;
	std::string m_outputFullName;
};

extern Output out;

#endif

// trace
// debug
// info
// warn
// error
// critical