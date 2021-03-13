#include "NuclideBlock.h"
#include "inputParser.h"
#include "Output.h"

#include <iostream>
#include <fstream>

void NuclideBlock::setName()
{
    m_name = InputParser::getLine(m_xsDataLines, 1);   
}

void NuclideBlock::setAWR()
{
    m_awr = std::stod(InputParser::getLine(m_xsDataLines, 10));   
}