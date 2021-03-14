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
    unsigned valuesNumber = getNumberOfValuesToRead(lineNumber);
    return ceil(valuesNumber / 5.0);
}

void NuclideBlock::setName()
{
    m_name = InputParser::getLine(m_xsDataLines, 1);   
}

void NuclideBlock::setAWR()
{
    m_awr = std::stod(InputParser::getLine(m_xsDataLines, 10));   
}

void NuclideBlock::setTemperatures()
{
    unsigned initialLine = 11;
    unsigned linesNumber = getNumberOfLinesToRead(initialLine);
    std::vector<std::string> tempStringsFinal;
    std::vector<std::string> tempStrings;
    initialLine++;

    for(unsigned i = initialLine + 1; i <= initialLine + linesNumber; i++)
    {
        tempStrings = InputParser::splitLine(InputParser::getLine(m_xsDataLines, i));
        tempStringsFinal.insert(tempStringsFinal.end(), tempStrings.begin(), tempStrings.end());     
    } 

    m_temperatures = InputParser::fromStringVecToDoubleVec(tempStringsFinal);
}