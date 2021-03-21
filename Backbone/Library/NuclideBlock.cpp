#include "NuclideBlock.h"
#include "inputParser.h"
#include "Output.h"
#include "additionalPrintFuncs.h"
#include "numeric_tools.h"

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

std::vector<double> NuclideBlock::readParameters(const std::string &key, unsigned lowerBound, unsigned upperBound)
{
    std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, key, lowerBound, upperBound);

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

void NuclideBlock::readName()
{
    m_nuclide.setName(InputParser::getLine(m_xsDataLines, 1));   
}

void NuclideBlock::readAWR()
{
    const std::string key = "AWR"; 
    std::vector<double> results = readParameters(key);
    m_nuclide.setAWR(results.front());   
}

std::vector<double> NuclideBlock::readTemperatures()
{
    const std::string key = "TEMPERATURE"; 
    std::vector<double> v = readParameters(key);
    m_nuclide.setTemperatures(v);
    return v;
}

std::vector< std::pair<unsigned, unsigned> > NuclideBlock::readTemperatureBlocks()
{
    const std::string key = "SUBTMP"; 
    std::vector<unsigned> tempBLocklines;

    for(unsigned i = 0; i < readTemperatures().size(); i++)
    {
        std::string compositeKey = key + PrintFuncs::stringFormat(i + 1, "%04d"); 
        std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, compositeKey);

        if(lines.size() == 1)
        {
            tempBLocklines.push_back(lines.front());
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} seems to repeat in the XS library!", key);
        }

    }

    std::vector< std::pair<unsigned, unsigned> > blockLinesVec;

    for(size_t i = 0; i < tempBLocklines.size() - 1; i++)
        blockLinesVec.push_back(std::make_pair(tempBLocklines[i], tempBLocklines[i + 1]));

    blockLinesVec.push_back(std::make_pair(tempBLocklines[tempBLocklines.size() - 1], m_xsDataLines.size()));

    return blockLinesVec;
}

XSType NuclideBlock::readXS(std::string key)
{
    std::vector< std::pair<unsigned, unsigned> > temps = NuclideBlock::readTemperatureBlocks();
    std::vector<double> temperatures = m_nuclide.getTemperatures();
    std::vector< std::pair<double, std::vector<double> > > tempXSVec;

    for(size_t i = 0; i < temperatures.size(); i++)
    {
        std::vector<double> xsVec = readParameters(key, temps[i].first, temps[i].second);
        tempXSVec.push_back(std::make_pair(temperatures[i], xsVec));
    }
    
    return tempXSVec;
}

void NuclideBlock::readGroupConstants()
{
    XSType totXS = readXS("NTOT0");
    m_nuclide.setTotalXS(totXS);
}

Nuclide* NuclideBlock::getNuclide()
{
    readName();
    readAWR();
	readTemperatureBlocks();
	readGroupConstants();
    return &m_nuclide;
}