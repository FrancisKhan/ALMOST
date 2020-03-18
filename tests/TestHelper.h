#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

class TestHelper
{
public:
    TestHelper(const std::string &codePath, const std::string &inputPath, 
               const std::string &outputPath, const std::string &traceLevel) :
               m_codePath(codePath), m_inputPath(inputPath), m_outputPath(outputPath),
               m_traceLevel(traceLevel), m_isFileOpened(false) {}

	void runCode()
    {
        const std::string finalStr = "./" + m_codePath + " " 
        + m_inputPath + " " + m_outputPath + " " + m_traceLevel;

        system(finalStr.c_str());

        m_isFileOpened = readOutput();
    }

    bool readOutput()
    {
        std::ifstream inFile;
	    inFile.open(m_outputPath);
	    if (!inFile) 
	    {
		    std::cout << "Unable to open file: " << m_outputPath << std::endl; 
            m_isFileOpened = false;
            return false;
	    }

        std::string line; 
        while (std::getline(inFile, line))
        {
            m_outputLines.push_back(line);	
        }

        m_isFileOpened = true;
        inFile.close();
        return true;
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

        if (!m_isFileOpened) return -1.0;

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

        if (!m_isFileOpened) return result;

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

    if (!m_isFileOpened) return result;

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

private:
    const std::string &m_codePath; 
    const std::string &m_inputPath; 
    const std::string &m_outputPath; 
    const std::string &m_traceLevel;
    std::vector<std::string> m_outputLines;
    bool m_isFileOpened;
};


#endif