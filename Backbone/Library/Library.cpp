#include "Library.h"
#include "Output.h"
#include "inputParser.h"
#include "NuclideBlock.h"
#include "numeric_tools.h"

#include <iostream>
#include <fstream>

// void Library::setMatProperties(std::vector<MaterialKind> &matProperties) 
// {
//     for(const auto & mat : matProperties)
//     {
//         std::shared_ptr<AbstractMaterial> pMat = AbstractMaterial::setMaterial(mat);
//         m_matProperties.push_back(pMat);
//     }
// }

std::vector<std::string> Library::readXSFile(std::string &input)
{
	std::vector<std::string> data;

    std::ifstream xsDataFile;
	xsDataFile.open(input);
	if (!xsDataFile) 
	{
		out.print(TraceLevel::CRITICAL, "Unable to open file: {}", input); 
		exit(-1);
	}
	
    std::string line;
	std::string noExtraSpacesline;
    while (std::getline(xsDataFile, line))
    {
        data.push_back(InputParser::removeTrailingSpaces(line));
    }

	xsDataFile.close();
	return data;
}


void Library::findNuclideBLocks()
{
    std::string str1 = "->       1      12       0       1";
    m_xsNuclideBlocks = InputParser::findLine(m_xsDataFileLines, str1);

    for(unsigned i = 0; i < m_xsNuclideBlocks.size() - 1; i++)
        m_xsNuclides.push_back(m_xsDataFileLines[m_xsNuclideBlocks[i] + 1]);
}

std::pair<unsigned, unsigned> Library::getXSNuclideBLock(const std::string &nuclide)
{
    std::vector<unsigned> lines;
	std::pair<unsigned, unsigned> blockLines(0, 0);

    auto it = std::find(m_xsNuclides.begin(), m_xsNuclides.end(), nuclide); 
    if (it != m_xsNuclides.end())
    {
        lines = InputParser::findLine(m_xsDataFileLines, nuclide);
    }
    else
    {
        out.print(TraceLevel::CRITICAL, "{} nuclide not found!", nuclide);
	    exit(-1);
    } 

    if (lines.size() == 1)
    {
        for(size_t i = 0; i < m_xsNuclideBlocks.size(); i++)
            if (lines.front() > m_xsNuclideBlocks[i])
            {
				blockLines = std::make_pair(m_xsNuclideBlocks[i], m_xsNuclideBlocks[i + 1]);
                std::cout << "m_xsNuclideBlocks[i + 1] " << m_xsNuclideBlocks[i + 1] << std::endl;
                break;
            }
    }
	else
    {
        out.print(TraceLevel::CRITICAL, "Error in reading the {} nuclide data block!", nuclide);
	    exit(-1);
    } 

	return blockLines;
}

void Library::getNuclides()
{
	std::string inputPath = "/home/why/ALMOST_libs/draglibendfb7r0.txt";
    m_xsDataFileLines = readXSFile(inputPath);
    findNuclideBLocks();

    std::vector<std::string> nucVec = {"La139", "U235"};

	for(const auto &nuc : nucVec)
	{
		std::pair<unsigned, unsigned> blockLines = getXSNuclideBLock(nuc);
		std::vector<std::string> dataVec = Numerics::slice(m_xsDataFileLines, blockLines.first, blockLines.second);
		NuclideBlock nuclideBlock(dataVec);
	}
}
