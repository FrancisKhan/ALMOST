#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

class TestHelper
{
public:
    TestHelper(const std::string &codePath, const std::string &inputPath, 
               const std::string &outputPath, const std::string &traceLevel) :
               m_codePath(codePath), m_inputPath(inputPath), 
               m_outputPath(outputPath), m_traceLevel(traceLevel) {}

	void runCode()
    {
        const std::string prePath = getPrePath();

        const std::string finalStr = prePath + m_codePath + " " +
        prePath + m_inputPath + " " + prePath +
        m_outputPath + " " + m_traceLevel;

        if(!system(finalStr.c_str()))
        {
            readOutput(prePath + m_outputPath);
        }
        else
        {
            std::cout << "Error: run code command not successful!" << std::endl;
            std::cout << "Command: " << finalStr << std::endl;
            exit(-1);
        }
    }

    void readOutput(std:: string filename)
    {
        std::ifstream inFile(filename);

	    if (!inFile.is_open()) 
	    {
		    std::cout << "Unable to open file: " << m_outputPath << std::endl; 
            exit(-1);
	    }

        std::string line; 
        while (std::getline(inFile, line))
        {
            m_outputLines.push_back(line);	
        }

        inFile.close();
    }

    std::vector<std::string> splitLine(std::string line)
    { 
        std::istringstream iss(line);
        std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
	
	    return words;
    } 

    double getKEff()
    {
        const std::string pattern = "K-factor";

        for(auto itemLine : m_outputLines)
	    {
		    size_t pos = itemLine.find(pattern);

		    if(pos != std::string::npos) 
            {
                std::vector<std::string> words = splitLine(itemLine);
                return std::stod(words[1]);
            }
	    }

        return -1.0;
    }

    std::vector<double> getNeutronFlux()
    {
        const std::string pattern = "Neutron Flux";

        unsigned keywordLineNumber = std::numeric_limits<unsigned>::max();

        std::vector<double> result;

        for(size_t i = 0; i < m_outputLines.size(); i++)
	    {
		    size_t pos = m_outputLines[i].find(pattern);

		    if(pos != std::string::npos) 
            {
                keywordLineNumber = i;
            }

            if(i > keywordLineNumber)
            {
                 if(m_outputLines[i] == " ") break;
                 std::vector<std::string> words = splitLine(m_outputLines[i]);
                 result.push_back(std::stod(words[0]));
            }
	    }

        return result;
    }
   
std::vector<double> getVector(std::string keyword)
{
    unsigned keywordLineNumber = std::numeric_limits<unsigned>::max();

    std::vector<double> result;

    for(size_t i = 0; i < m_outputLines.size(); i++)
    {
	    size_t pos = m_outputLines[i].find(keyword);

	    if(pos != std::string::npos) 
        {
            keywordLineNumber = i;
        }

        if(i > keywordLineNumber)
        {
            if(m_outputLines[i] == " ") break;
            std::vector<std::string> words = splitLine(m_outputLines[i]);
            result.push_back(std::stod(words[0]));
        }
	}

    return result;
}
    std::string getCurrentWorkingDir() 
    {
	    char buff[FILENAME_MAX];
	    getcwd(buff, FILENAME_MAX);
	    std::string current_working_dir(buff);
	    return current_working_dir;
    }
  
    // This method is needed because Visual Studio Code runs the tests from 
    // the ALMOST folder, while make or ctest run from from the tests folder.
    // Absolute path seem not to work with WLS
    std::string getPrePath() 
    {
        std::string path = getCurrentWorkingDir();

        if(path.substr(path.size() -5, path.size()) == "tests")
        {
            return "./../";
        }
        else
        {
            return "./";
        }
    }

private:
    const std::string &m_codePath; 
    const std::string &m_inputPath; 
    const std::string &m_outputPath; 
    const std::string &m_traceLevel;
    std::vector<std::string> m_outputLines;
};


#endif