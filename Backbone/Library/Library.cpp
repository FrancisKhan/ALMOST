#include "Library.h"
#include "Output.h"

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

void Library::readXSData()
{
    std::string inputPath = "/home/why/ALMOST_libs/draglibendfb7r0.txt";

    std::ifstream xsDataFile;
	xsDataFile.open(inputPath);
	if (!xsDataFile) 
	{
		out.print(TraceLevel::CRITICAL, "Unable to open file: {}", inputPath); 
		exit(-1);
	}
	
    std::string line;
    while (std::getline(xsDataFile, line))
    {
        m_xsDataFileLines.push_back(line);
    }

	xsDataFile.close();
}

std::vector<unsigned> Library::findRepetitiveLine(std::string key)
{
    std::vector<unsigned> result;
    unsigned lineNumber = 0;
	size_t pos = 0;
	for(auto itemLine : m_xsDataFileLines)
	{
		pos = itemLine.find(key);
		if(pos != std::string::npos) 
		{
			result.push_back(lineNumber);
		}

		lineNumber++;
	}

	return result;
}

void Library::getXSNuclides()
{
    std::string str1 = "->       1      12       0       1";
    std::vector<unsigned> lineVec = findRepetitiveLine(str1);
    std::vector<unsigned> NuclideStartLine;
    NuclideStartLine.resize(lineVec.size()); 
    std::transform(lineVec.begin(), lineVec.end(), NuclideStartLine.begin(), 
    [](auto i){return ++i;});

    for(unsigned i = 0; i < lineVec.size(); i++)
        std::cout << i  << " " << lineVec[i] << " " << NuclideStartLine[i] << std::endl;
}

void Library::funcTry()
{
    readXSData();
    getXSNuclides();
}
