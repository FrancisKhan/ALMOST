#include "Output.h"

#include <stdio.h>
#include <iostream>
#include <experimental/filesystem>

Output out;

namespace fs = std::experimental::filesystem;

void Output::printStart()
{
	out.getLogger()->set_pattern("[%D %T] [%n] %v");
	out.getLogger()->critical("Start simulation \n");
	out.getLogger()->set_pattern("%v");
}

void Output::printEnd()
{
	out.getLogger()->set_pattern("[%D %T] [%n] %v");
	out.getLogger()->critical("End simulation");
}

void Output::setLevel(std::string level) 
{
	if(level == "CRITICAL")
	{
		mp_logger->set_level(spdlog::level::critical);
		m_logLevel = TraceLevel::CRITICAL;
	}
	else if(level == "ERROR")    
	{
		mp_logger->set_level(spdlog::level::err);
		m_logLevel = TraceLevel::ERROR;
	}
	else if(level == "WARN")
	{
		mp_logger->set_level(spdlog::level::warn);
		m_logLevel = TraceLevel::WARN;
	}     
	else if(level == "INFO")    
	{
		mp_logger->set_level(spdlog::level::info);
		m_logLevel = TraceLevel::INFO;
	} 
	else if(level == "DEBUG")    
	{
		mp_logger->set_level(spdlog::level::debug);
		m_logLevel = TraceLevel::DEBUG;
	}
	else if(level == "TRACE")    
	{
		mp_logger->set_level(spdlog::level::trace);
		m_logLevel = TraceLevel::TRACE;
	}
	else 
	{
		out.print(TraceLevel::CRITICAL, "Trace Level not recognized");
		out.print(TraceLevel::CRITICAL, "Please use capital letters: CRITICAL, ERROR, WARN, INFO, DEBUG or TRACE");
		out.print(TraceLevel::CRITICAL, "Trace Level defaulted to CRITICAL \n");
		mp_logger->set_level(spdlog::level::critical);
		m_logLevel = TraceLevel::CRITICAL;
	}
}

std::shared_ptr<spdlog::logger> Output::getLogger() 
{
	if (mp_logger == nullptr)
		std::cout << "getLogger() nullprt!!" << std::endl;
	
	return mp_logger;
}

void Output::setInputPath(std::string inputPathName)
{
	std::size_t found = inputPathName.find_last_of("/\\");
	
	if (found != std::string::npos)
	{
		m_inputPath = inputPathName.substr(0, found);
		m_inputName = inputPathName.substr(found + 1);
	}
}

void Output::setOutputPath(std::string outputPathName)
{
	std::size_t found = outputPathName.find_last_of("/\\");
	
	if (found != std::string::npos)
	{
		m_outputPath = outputPathName.substr(0, found);
		m_outputName = outputPathName.substr(found + 1);
	}
	
	m_outputFullName = outputPathName;
	
	removeOldOutputFile();
}

void Output::createLogger(std::string loggerName)
{
	mp_logger = spdlog::basic_logger_mt(loggerName, m_outputFullName);
	mp_logger->flush_on(spdlog::level::info);
}

void Output::removeOldOutputFile()
{
	if (fs::exists(m_outputFullName))
	{
		std::remove(m_outputFullName.c_str());
	}
}

void Output::print(TraceLevel level, std::string str)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input);
	else {}
}

void Output::print(TraceLevel level, std::string str, double input)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input);
	else {}
}

void Output::print(TraceLevel level, std::string str, std::string input)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input1, double input2)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2);
	else {}
}

void Output::print(TraceLevel level, std::string str, std::string input1, std::string input2)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input1, double input2, double input3)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2, input3);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2, input3);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2, input3);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2, input3);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2, input3);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2, input3);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input1, int input2, int input3, double input4)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2, input3, input4);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2, input3, input4);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2, input3, input4);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2, input3, input4);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2, input3, input4);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2, input3, input4);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input1, int input2, int input3, int input4, double input5)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2, input3, input4, input5);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2, input3, input4, input5);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2, input3, input4, input5);
	else {}
}

void Output::print(TraceLevel level, std::string str, int input1, int input2, int input3, double input4, double input5)
{
	if (level == TraceLevel::CRITICAL)
		out.getLogger()->critical(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::ERROR)
		out.getLogger()->error(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::WARN)
		out.getLogger()->warn(str, input1, input2, input3, input4, input5);
	else if (level == TraceLevel::INFO)
		out.getLogger()->info(str, input1, input2, input3, input4, input5);
	else if(level == TraceLevel::DEBUG)
		out.getLogger()->debug(str, input1, input2, input3, input4, input5);
	else if(level == TraceLevel::TRACE)
		out.getLogger()->trace(str, input1, input2, input3, input4, input5);
	else {}
}