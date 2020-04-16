#include "Input.h"
#include "Mesh.h"
#include "Output.h"
#include "GeomKind.h"
#include "KineticsSet.h"
#include "CrossSectionSet.h"
#include "MaterialKind.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace Eigen;

void Input::getArguments(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Missing input argument!" << std::endl;
		exit(-1);
	}
	else if(argc == 4)
	{
        std::string inputStr(argv[1]);
	    m_inputPath = inputStr;
	    out.setInputPath(m_inputPath);
		out.setOutputPath(argv[2]);
		out.createLogger();
		std::string levelStr(argv[3]);
		out.setLevel(levelStr);
	}
	else
	{
		std::cout << "Too many input arguments!" << std::endl;
		exit(-1);
	}
	
}

void Input::printData()
{
	out.getLogger()->info("Input path: {}",  out.getInputPath());
	out.getLogger()->info("Input file: {} \n",  out.getInputName());
	out.getLogger()->debug("Output file: {} \n", out.getOutputName());
}

std::string Input::readData()
{
	out.getLogger()->info("Reading the input \n");

	std::ifstream inFile;
	inFile.open(m_inputPath);
	if (!inFile) 
	{
		out.getLogger()->error("Unable to open file: {}", m_inputPath); 
		exit(-1);
	}
	
	std::string line; 
	std::string noExtraSpacesline; 
    while (std::getline(inFile, line))
    {
		// eliminating leading spaces
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), 
		std::bind1st(std::not_equal_to<char>(), ' ')));
		
		removeExtraSpaces(line, noExtraSpacesline);
		
		m_inputLines.push_back(noExtraSpacesline);	
        //std::cout << noExtraSpacesline << std::endl;
    }

	m_calculation = getCalculation();

    if(m_calculation == "neutronics")
	{
		setGeometryKind();
		setMesh();
    	setEnergies();
		setAlbedo();
		setMaterials();
	}
	else if(m_calculation == "kinetics")
	{
		setKineticsParameters();
	}
	else if(m_calculation == "heat")
	{
		setGeometryKind();
		setMesh();
		setAlbedo();
		setMaterials();
	}
	
	inFile.close();
	
	return m_calculation;
}

void Input::removeExtraSpaces(const std::string &input, std::string &output)
{
    output.clear();  // unless you want to add at the end of existing sring...
    std::unique_copy(input.begin(), input.end(), std::back_insert_iterator<std::string>(output),
                     [](char a,char b){ return isspace(a) && isspace(b);});  
 
}

std::pair<unsigned, unsigned> Input::findBlock(std::string keyOne, std::string keyTwo)
{
    unsigned lineNumber = 0;
	unsigned startLine = 0;
	unsigned endLine = 0;
	size_t pos = 0;
	for(auto itemLine : m_inputLines)
	{
	    std::transform(itemLine.begin(), itemLine.end(), itemLine.begin(), ::tolower);
	    std::transform(keyOne.begin(), keyOne.end(), keyOne.begin(), ::tolower);
		std::transform(keyTwo.begin(), keyTwo.end(), keyTwo.begin(), ::tolower);

		pos = itemLine.find(keyOne);
		if(pos != std::string::npos) 
		{
			endLine = startLine !=0 ? lineNumber : std::numeric_limits<unsigned>::max();
		}

		pos = itemLine.find(keyOne + " " + keyTwo);
		if(pos != std::string::npos) 
		{
			startLine = lineNumber;
		}

		lineNumber++;
	}

	return std::make_pair(startLine, endLine);
}

std::string Input::findKeyword(std::string toSearch, unsigned lowLimit, unsigned topLimit)
{
	bool keywordFound = false;
	size_t pos = 0;
	unsigned counter = 0;
	std::string line = "";
	for(auto itemLine : m_inputLines)
	{
        //if(itemLine.size() == 1)    continue; // remove empty lines
		if(itemLine.front() == '%') continue; // remove comments

	    std::transform(itemLine.begin(), itemLine.end(), itemLine.begin(), ::tolower);
	    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
		pos = itemLine.find(toSearch);
		
        if(pos != std::string::npos) keywordFound = true;

		if(pos != std::string::npos && counter >= lowLimit && counter <= topLimit) 
		{
			line = itemLine;
			break;
		}

		counter++;
	}

    if(keywordFound == false) 
	{
		out.getLogger()->error("{} is missing from the input!", toSearch);
	    exit(-1);
	}

	return line;
}

// fix it for inline comments!
std::vector<std::string> Input::splitLine(std::string line)
{ 
    std::istringstream iss(line);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
	
	return words;
} 

std::string Input::getCalculation()
{
	std::string calculation = getOneParameter("calculation");
	out.getLogger()->info("Calculation: {}\n", calculation);
	return calculation;
}

void Input::setGeometryKind()
{ 
   std::string geometry = getOneParameter("geometry");
   
   if(geometry == "cylinder") 
	{
	   m_problem.setMeshKind(GeomKind::CYLINDER);
	   out.getLogger()->info("Geometry: Cylindrical \n");
	}
	else if(geometry == "sphere") 
	{
	   m_problem.setMeshKind(GeomKind::SPHERE);
	   out.getLogger()->info("Geometry: Spherical \n");
	}
	else if(geometry == "slab") 
	{
	   m_problem.setMeshKind(GeomKind::SLAB);
	   out.getLogger()->info("Geometry: Cartesian \n");
	}
	else
	{
	   out.getLogger()->error("Geometry: {} not recognized!", geometry);
	   exit(-1);
	}
} 

void Input::setEnergies()
{
	std::string energies = getOneParameter("energies");
	m_problem.setEnergyGroupsNumber(std::stoi(energies));
	out.getLogger()->info("{} value: {} \n", "energies", energies);
}

void Input::setAlbedo()
{
	std::string albedo = getOneParameter("albedo");
	m_problem.setAlbedo(std::stod(albedo));
	out.getLogger()->info("{} value: {} \n", "albedo", albedo);
}

void Input::setMesh()
{ 
    std::vector<std::string> values = getManyParameter("mesh");
   
    std::vector<unsigned> regionNumber = {0};
	std::vector<double> regionDistance = {0.0};
	std::vector<std::string> regionMaterial;

	for(size_t i = 0; i < values.size(); i++)
	{
      switch (i % 3)
	  {
		  case 0:
		  	regionNumber.push_back(std::stoi(values[i]));
		  	break;
		  case 1:
		  	regionDistance.push_back(std::stod(values[i]));
		  	break;
		  case 2:
		  	regionMaterial.push_back(values[i]);
		  	break;
	  }
	}

	int maxNumberMeshes = std::accumulate(regionNumber.begin(), regionNumber.end(), 0);
	Eigen::VectorXd boundaries = Eigen::VectorXd::Zero(maxNumberMeshes + 1);

    double distanceSum  = 0.0;
	size_t indexCounter = 0;

	for(size_t i = 1; i < regionNumber.size(); i++)
	{
      size_t lastValue = 1 ? i == regionNumber.size() - 1 : 0;

		for(size_t j = 0; j < regionNumber[i] + lastValue; j++)
		{
		  boundaries(indexCounter) = j * regionDistance[i] / regionNumber[i] + distanceSum;
		  indexCounter++;
		}
		  
		distanceSum += regionDistance[i];
	}

	out.getLogger()->info("Boundaries:");
	printVector(boundaries, out, TraceLevel::INFO);
	m_problem.setBoundaries(boundaries);

    Eigen::VectorXd volumes = m_problem.getVolumes();
	out.getLogger()->info("Volumes:");
    printVector(volumes, out, TraceLevel::INFO);

	for(size_t i = 1; i < regionNumber.size(); i++)
	{
		for(size_t j = 0; j < regionNumber[i]; j++)
	    {
		  m_materialMap.push_back(regionMaterial[i - 1]);
		}
	}

	out.getLogger()->info("Meshes:");
	printVector(m_materialMap, out, TraceLevel::INFO);

	std::sort(regionMaterial.begin(), regionMaterial.end());
    regionMaterial.erase(std::unique(regionMaterial.begin(), 
                         regionMaterial.end()), regionMaterial.end());

	m_materialList = regionMaterial;
}  

void Input::setMaterials()
{ 
   m_cells = m_problem.getCellsNumber();

   if(m_calculation == "neutronics")
   {
		m_energies = m_problem.getEnergyGroupsNumber();

		MatrixXd ni      = getXS("ni");
   		MatrixXd chi     = getXS("chi");
   		MatrixXd fission = getXS("fission");
   		MatrixXd total   = getXS("total");	

		Tensor3d scattMatrix = getMatrixXS("scattMatrix");
		CrossSectionSet XSSet;

		XSSet.setNi(ni);
   		XSSet.setChi(chi);
   		XSSet.setFission(fission);
   		XSSet.setTotal(total);
   		XSSet.setScattMatrix(scattMatrix);
   		m_library.setCrossSectionSet(XSSet);
   }
   else if(m_calculation == "heat")
   {
		std::vector<MaterialKind> matProperties = getMatProperties();			
		m_library.setMatProperties(matProperties);
   }
}

std::vector<MaterialKind> Input::getMatProperties()
{
    std::vector<MaterialKind> result;

	for (auto matListItem : m_materialList)
    {
        std::string matStr = "material";
	    getOneParameter(matStr + " " + matListItem);
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
			if (m_materialMap[m] != matListItem) continue;

			std::string str = "properties";
			std::vector<std::string> values = splitLine(findKeyword(str, matBlock.first, matBlock.second));

			if(values[1] == "u") 
			{
	   			result.push_back(MaterialKind::U);
			}
			else
			{
	   			out.getLogger()->error("There are no material properties for {}!", values[1]);
	    		exit(-1);
			}
		}
	}

    out.getLogger()->info("Material properties");
    printVector(result, out, TraceLevel::INFO);

	return result;
}


MatrixXd Input::getXS(std::string name)
{
    MatrixXd xs = MatrixXd::Zero(m_energies, m_cells);

	for (auto matListItem : m_materialList)
    {
        std::string matStr = "material";
	    getOneParameter(matStr + " " + matListItem);
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
			if (m_materialMap[m] != matListItem) continue;

			for (unsigned i = 1; i <= m_energies; i++)
   			{
				std::string str = name + "(" + std::to_string(i) + ")";
				std::vector<std::string> values = splitLine(findKeyword(str, matBlock.first, matBlock.second));
				xs(i - 1, m) = std::stod(values[1]);
			}
		}
	}

    out.getLogger()->info(name);
    printMatrix(xs, out, TraceLevel::INFO);

	return xs;
}

Tensor3d Input::getMatrixXS(std::string name)
{
    Tensor3d matrix = Tensor3d(m_energies, m_energies, m_cells);
    matrix.setZero();

	for (auto matListItem : m_materialList)
    {
       std::string matStr = "material";
	   getOneParameter(matStr + " " + matListItem);
	   std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
        	if (m_materialMap[m] != matListItem) continue;

			for (unsigned i = 1; i <= m_energies; i++)
    		{
	    		for (unsigned j = 1; j <= m_energies; j++)
	    		{
					std::string str = name + "(" + std::to_string(i) + ", " + std::to_string(j) + ")";
					std::vector<std::string> values = splitLine(findKeyword(str, matBlock.first, matBlock.second));
					matrix(i - 1, j - 1, m) = std::stod(values[2]);
				}
			}
		}
	}

	out.getLogger()->info(name);
    printMatrix(matrix, out, TraceLevel::INFO, "Mesh");

	return matrix;
}

std::string Input::getOneParameter(std::string name)
{
   std::string result = "";
   std::vector<std::string> words = splitLine(findKeyword(name));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else if(words.size() == 2)
   {
	   return words[1];
   }
   else
   {
	   out.getLogger()->error("{}  has too many parameters!", words[0]);
	   exit(-1);
   }

   return result;
}

std::vector<std::string> Input::getManyParameter(std::string name)
{
   std::vector<std::string> result;
   std::vector<std::string> words = splitLine(findKeyword(name));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else
   {
	   result = std::vector<std::string>(words.begin() + 1, words.end());
   }

   return result;
}

void Input::setKineticsParameters()
{ 
    double alpha = std::stod(getOneParameter("alpha"));
    out.getLogger()->info("Alpha: {}", alpha);

    double power = std::stod(getOneParameter("power"));
    out.getLogger()->debug("Initial power: {}", power);

    std::vector<std::string> lambdaStr = getManyParameter("lambda");
    std::vector<double> lambda(lambdaStr.size());
    std::transform(lambdaStr.begin(), lambdaStr.end(), lambda.begin(), 
                   [](std::string &i){return std::stod(i);});
    out.getLogger()->debug("Lambda: ");
    printVector(lambda, out, TraceLevel::DEBUG);

    std::vector<std::string> betaStr = getManyParameter("beta");
    std::vector<double> beta(lambdaStr.size());
    std::transform(betaStr.begin(), betaStr.end(), beta.begin(), 
                   [](std::string &i){return std::stod(i);});
	out.getLogger()->debug("Beta: ");
	printVector(beta, out, TraceLevel::DEBUG);	

	std::vector<double> times = getTimes();

	std::vector<std::string> reactStr = getManyParameter("reactivities");
    std::vector<double> reacts(reactStr.size());
    std::transform(reactStr.begin(), reactStr.end(), reacts.begin(), 
                   [](std::string &i){return std::stod(i);});
    out.getLogger()->debug("Reactivities: ");
    printVector(reacts, out, TraceLevel::DEBUG);

	if (times.size() != reacts.size()) 
	{
		out.getLogger()->debug("times and reactivities must have equal sizes!"); 
		out.getLogger()->debug("times: {} reativities: {}" , times.size(), reacts.size());
		exit(-1);
	}

	KineticsSet kinSet;
	kinSet.setAlpha(alpha);
	kinSet.setPower(power);
	kinSet.setLambda(lambda);
	kinSet.setBeta(beta);
	kinSet.setTimes(times);
	kinSet.setReactivities(reacts);
	m_library.setKineticsSet(kinSet);
} 

std::vector<double> Input::getTimes()
{ 
    std::vector<std::string> values = getManyParameter("times");
   
    std::vector<unsigned> submeshes = {0};
	std::vector<double> submeshTimes = {0.0};

	for(size_t i = 0; i < values.size(); i++)
	{
      switch (i % 2)
	  {
		  case 0:
		  	submeshes.push_back(std::stoi(values[i]));
		  	break;
		  case 1:
		  	submeshTimes.push_back(std::stod(values[i]));
		  	break;
	  }
	}

	int totSubmeshes = std::accumulate(submeshes.begin(), submeshes.end(), 0);
	std::vector<double> times(totSubmeshes + 1, 0.0);

    double timeSum = 0.0;
	size_t indexCounter = 0;

	for(size_t i = 1; i < submeshes.size(); i++)
	{
      size_t lastValue = 1 ? i == submeshes.size() - 1 : 0;

		for(size_t j = 0; j < submeshes[i] + lastValue; j++)
		{
		  times[indexCounter] = j * submeshTimes[i] / submeshes[i] + timeSum;
		  indexCounter++;
		}
		  
		timeSum += submeshTimes[i];
	}

	out.getLogger()->debug("Times:");
	printVector(times, out, TraceLevel::DEBUG);

	return times;
}
