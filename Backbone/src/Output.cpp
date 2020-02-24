#include "Output.h"

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <experimental/filesystem>

Output out;

namespace fs = std::experimental::filesystem;

void Output::printStart()
{
	out.getLogger()->set_pattern("[%D %T] [%n] %v");
	out.getLogger()->info("Start Neutronics \n");
	out.getLogger()->set_pattern("%v");
}

void Output::printEnd()
{
	out.getLogger()->set_pattern("[%D %T] [%n] %v");
	out.getLogger()->info("End Neutronics");
}

void Output::setLevel(std::string level) 
{
	     if(level == "CRITICAL") mp_logger->set_level(spdlog::level::critical);
	else if(level == "ERROR")    mp_logger->set_level(spdlog::level::err);
	else if(level == "WARN")     mp_logger->set_level(spdlog::level::warn);
	else if(level == "INFO")     mp_logger->set_level(spdlog::level::info);
	else if(level == "DEBUG")    mp_logger->set_level(spdlog::level::debug);
	else if(level == "TRACE")    mp_logger->set_level(spdlog::level::trace);
	else 
	{
		out.getLogger()->warn("Trace Level not recognized");
		out.getLogger()->warn("Please use capital letters: CRITICAL, ERROR, WARN, INFO, DEBUG or TRACE");
		out.getLogger()->warn("Trace Level defaulted to INFO \n");
		mp_logger->set_level(spdlog::level::info);
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

std::string Output::GetCurrentWorkingDir() 
{
	char buff[FILENAME_MAX];
	getcwd(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

void Output::removeOldOutputFile()
{
	//std::string outputPath = GetCurrentWorkingDir() + "/" + m_outputName;
	
	if (fs::exists(m_outputFullName))
	{
		std::remove(m_outputFullName.c_str());
	}
}