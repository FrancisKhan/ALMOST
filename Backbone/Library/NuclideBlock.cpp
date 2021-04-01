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
    std::vector<double> result;

    std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, key, lowerBound, upperBound);

    if (lines.size() > 0)
    {
        unsigned linesToRead = getNumberOfLinesToRead(lines.front() - 1);

        std::vector<std::string> resultStringsFinal;
        std::vector<std::string> resultStrings;

        for(unsigned i = lines.front() + 1; i <= lines.front() + linesToRead; i++)
        {
            resultStrings = InputParser::splitLine(InputParser::getLine(m_xsDataLines, i));
            resultStringsFinal.insert(resultStringsFinal.end(), resultStrings.begin(), resultStrings.end());     
        } 

        result = InputParser::fromStringVecToDoubleVec(resultStringsFinal);
    }

    return result;
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
    std::vector<unsigned> tempBlocklines;

    for(unsigned i = 0; i < readTemperatures().size(); i++)
    {
        std::string compositeKey = key + PrintFuncs::stringFormat(i + 1, "%04d"); 
        std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, compositeKey);

        if(lines.size() == 1)
        {
            tempBlocklines.push_back(lines.front());
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} seems to repeat in the XS library!", key);
            exit(-1);
        }
    }

    std::vector< std::pair<unsigned, unsigned> > blockLinesVec;

    for(size_t i = 0; i < tempBlocklines.size() - 1; i++)
        blockLinesVec.push_back(std::make_pair(tempBlocklines[i], tempBlocklines[i + 1]));

    blockLinesVec.push_back(std::make_pair(tempBlocklines[tempBlocklines.size() - 1], m_xsDataLines.size()));

    return blockLinesVec;
}

std::vector<double> NuclideBlock::readDilutions(unsigned firstLine, unsigned lastLine)
{
    const std::string key = "DILUTION"; 
    std::vector<double> v = readParameters(key, firstLine, lastLine);
    m_nuclide.setDilutions(v);
    return v;
}

std::vector< std::pair<unsigned, unsigned> > 
NuclideBlock::readDilutionBlocks(std::pair<unsigned, unsigned> &block)
{
    const std::string key = "SUBMAT"; 
    std::vector<unsigned> dilBlocklines;

    for(unsigned i = 0; i < readDilutions(block.first, block.second).size(); i++)
    {
        std::string compositeKey = key + PrintFuncs::stringFormat(i + 1, "%04d"); 
        std::vector<unsigned> lines = InputParser::findLine(m_xsDataLines, compositeKey, block.first, block.second);

        if(lines.size() == 1)
        {
            dilBlocklines.push_back(lines.front());
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} seems to repeat in the XS library!", key);
            exit(-1);
        }
    }

    std::vector< std::pair<unsigned, unsigned> > blockLinesVec;

    for(size_t i = 0; i < dilBlocklines.size() - 1; i++)
        blockLinesVec.push_back(std::make_pair(dilBlocklines[i], dilBlocklines[i + 1]));

    blockLinesVec.push_back(std::make_pair(dilBlocklines[dilBlocklines.size() - 1], m_xsDataLines.size()));
    
    return blockLinesVec;
}

CrossSectionSet NuclideBlock::readXS(XSKind xsKind)
{
    std::vector< std::pair<unsigned, unsigned> > temps = readTemperatureBlocks();
    std::vector<double> temperatures = m_nuclide.getTemperatures();
    CrossSectionSet crossSectionSet(xsKind);

    if(m_nuclide.isResonant())
    {
        std::cout <<  m_nuclide.getName() <<  " is resonant!" << std::endl;

        std::vector< std::pair<unsigned, unsigned> > dilutions = readDilutionBlocks(temps.front());

        std::vector<double> xsVec = readParameters(get_name(xsKind), dilutions[0].first, dilutions[0].second);
        CrossSection crossSection(temperatures[0], 0.0, xsVec);
        crossSectionSet.addXS(crossSection);
    }
    else
    {
        for(size_t i = 0; i < temperatures.size(); i++)
        {
            std::vector<double> xsVec = readParameters(get_name(xsKind), temps[i].first, temps[i].second);
            CrossSection crossSection(temperatures[i], 0.0, xsVec);
            crossSectionSet.addXS(crossSection);
        }
    }
    
    return crossSectionSet;
}

void NuclideBlock::readGroupConstants()
{
    for (const auto& xsKind : XSKind())
    {
        CrossSectionSet xs = readXS(xsKind);
        m_nuclide.setXS(xsKind, xs);
    }
}

void NuclideBlock::isNuclideResonant()
{
    const std::string key = "DILUTION"; 
    std::vector<double> parVec = readParameters(key);
    bool value = parVec.size() > 0 ? true : false;
    m_nuclide.setIsResonant(value);
}

Nuclide* NuclideBlock::getNuclide()
{
    readName();
    readAWR();
    isNuclideResonant();
	readTemperatureBlocks();
	readGroupConstants();
    return &m_nuclide;
}