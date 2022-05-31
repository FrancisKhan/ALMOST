#ifndef OUTPUT_H
#define OUTPUT_H

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "TraceLevel.h"

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
	TraceLevel getLevel() {return m_logLevel;}
	std::string getInputPath() {return m_inputPath;}
	std::string getInputName() {return m_inputName;}
	std::string getInputNameNoExt();
	std::string getOutputName() {return m_outputName;}

	void print(TraceLevel level, std::string str);
	void print(TraceLevel level, std::string str, int input);
	void print(TraceLevel level, std::string str, double input);
	void print(TraceLevel level, std::string str, std::string input);
	void print(TraceLevel level, std::string str, int input, std::string input1);
	void print(TraceLevel level, std::string str, std::string input1, int input2);
	void print(TraceLevel level, std::string str, int input1, double input2);
	void print(TraceLevel level, std::string str, double input1, double input2);
	void print(TraceLevel level, std::string str, std::string input1, std::string input2);
	void print(TraceLevel level, std::string str, int input1, double input2, double input3);
	void print(TraceLevel level, std::string str, std::string input1, std::string input2, std::string input3);
	void print(TraceLevel level, std::string str, int input1, int input2, int input3, double input4);
	void print(TraceLevel level, std::string str, std::string input1, std::string input2, std::string input3, std::string input4);
	void print(TraceLevel level, std::string str, std::string input1, std::string input2, std::string input3, 
			   std::string input4, std::string input5);
	void print(TraceLevel level, std::string str, int input1, int input2, int input3, int input4, double input5);
	void print(TraceLevel level, std::string str, int input1, int input2, int input3, double input4, double input5);
	void print(TraceLevel level, std::string str, std::string input1, std::string input2, std::string input3, 
			   std::string input4, std::string input5, std::string input6, std::string input7, std::string input8);

private: 
	void removeOldOutputFile();

	std::shared_ptr<spdlog::logger> mp_logger;
	std::string m_outputPath;
	std::string m_outputName;
	std::string m_inputPath;
	std::string m_inputName;
	std::string m_outputFullName;
	TraceLevel m_logLevel;
};

extern Output out;

#endif

// trace
// debug
// info
// warn
// error
// critical