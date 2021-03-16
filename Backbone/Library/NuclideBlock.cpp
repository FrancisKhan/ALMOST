#include "NuclideBlock.h"
#include "inputParser.h"
#include "Output.h"

#include <iostream>

unsigned NuclideBlock::getNumberOfValuesToRead(unsigned lineNumber)
{
    std::string line = InputParser::getLine(m_xsDataLines, lineNumber);   
    std::vector<std::string> lineVec = InputParser::splitLine(line);
    return std::stoi(lineVec.back());
}

unsigned NuclideBlock::getNumberOfLinesToRead(unsigned lineNumber)
{
    // Five is the maximun number of floats in a line for a text DRAGLIB format library
    return ceil(getNumberOfValuesToRead(lineNumber) / 5.0);
}

std::vector<double> NuclideBlock::readParameters(const std::string &key)
{
    std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, key);
    unsigned linesToRead = getNumberOfLinesToRead(lines.front() - 1);

    std::vector<std::string> resultStringsFinal;
    std::vector<std::string> resultStrings;

    for(unsigned i = lines.front() + 1; i <= lines.front() + linesToRead; i++)
    {
        resultStrings = InputParser::splitLine(InputParser::getLine(m_xsDataLines, i));
        resultStringsFinal.insert(resultStringsFinal.end(), resultStrings.begin(), resultStrings.end());     
    } 

    return InputParser::fromStringVecToDoubleVec(resultStringsFinal);
}

void NuclideBlock::setName()
{
    m_name = InputParser::getLine(m_xsDataLines, 1);   
}

void NuclideBlock::setAWR()
{
    const std::string key = "AWR"; 
    std::vector<double> results = readParameters(key);
    m_awr = results.front();   
}

void NuclideBlock::setTemperatures()
{
    const std::string key = "TEMPERATURE"; 
    m_temperatures = readParameters(key);
}