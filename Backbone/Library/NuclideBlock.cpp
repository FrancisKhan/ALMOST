#include "NuclideBlock.h"
#include "inputParser.h"
#include "Output.h"

#include <iostream>
#include <fstream>

void NuclideBlock::setName()
{
    m_name = InputParser::getLine(m_xsDataLines, 0);   
}