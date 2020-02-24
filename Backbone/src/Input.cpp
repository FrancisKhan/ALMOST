#include "Input.h"
#include "Mesh.h"
#include "Output.h"
#include "GeomKind.h"
#include "numeric_tools.h"
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

void Input::readData()
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
	
	setGeometryKind();
	setMesh();
	setEnergies();
	setAlbedo();
	setMaterials();
	
	inFile.close();
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

void Input::setGeometryKind()
{ 
   std::vector<std::string> words = splitLine(findKeyword("geometry"));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameter!", words[0]);
	   exit(-1);
   }
   else if(words.size() == 2)
   {
	   if(words[1] == "cylinder") 
	   {
		   m_problem.setMeshKind(GeomKind::CYLINDER);
	   	   out.getLogger()->info("Geometry: Cylindrical \n");
	   }
	   else if(words[1] == "sphere") 
	   {
		   m_problem.setMeshKind(GeomKind::SPHERE);
	   	   out.getLogger()->info("Geometry: Spherical \n");
	   }
	   else if(words[1] == "slab") 
	   {
		   m_problem.setMeshKind(GeomKind::SLAB);
	   	   out.getLogger()->info("Geometry: Cartesian \n");
	   }
	   else
	   {
	   	   out.getLogger()->error("Geometry: {} not recognized!", words[1]);
		   exit(-1);
	   }
   }
   else
   {
	   out.getLogger()->error("{}  has too many parameters!", words[0]);
	   exit(-1);
   }
} 

bool Input::isFloat(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	auto dotFound = std::find_if(s.begin(), s.end(), [](char c) {return c == '.';});

	if(dotFound != s.end()) 
	{
		std::string beforeDot = std::string(s.begin(), dotFound);
		std::string afterDot  = std::string(dotFound + 2, s.end());

		auto isDigitLambda = [](char c){return std::isdigit(c);};
		if (std::all_of(beforeDot.begin(), beforeDot.end(), isDigitLambda) &&
		    std::all_of(afterDot.begin(), afterDot.end(), isDigitLambda))
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}

	return result;
}

bool Input::isInteger(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	if (std::all_of(s.begin(), s.end(), [](char c){return std::isdigit(c);}))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Input::isString(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	if (isalpha(s.front()))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

void Input::setMesh()
{ 
   std::vector<std::string> words = splitLine(findKeyword("mesh"));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else
   {
      int maxNumberMeshes = 0;
      
	  for(auto i : words)
	  {
		  if(isInteger(i)) maxNumberMeshes += std::stoi(i); 
	  }

      std::vector<unsigned> regionNumber = {0};
	  std::vector<double> regionDistance = {0.0};
	  std::vector<std::string> regionMaterial;

	  for(size_t i = 1; i < words.size(); i++)
	  {
		  if(isInteger(words[i])) regionNumber.push_back(std::stoi(words[i]));
		  if(isFloat(words[i]))  regionDistance.push_back(std::stod(words[i]));
		  if(isString(words[i])) regionMaterial.push_back(words[i]);
	  }

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
} 

void Input::setEnergies()
{ 
   std::vector<std::string> words = splitLine(findKeyword("energies"));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else if(words.size() == 2)
   {
       unsigned energies = std::stoi(words[1]);
	   m_problem.setEnergyGroupsNumber(energies);
	   out.getLogger()->info("Energy groups: {} \n", energies);
   }
   else
   {
	   out.getLogger()->error("{}  has too many parameters!", words[0]);
	   exit(-1);
   }
} 

void Input::setAlbedo()
{ 
   std::vector<std::string> words = splitLine(findKeyword("albedo"));
   
   if(words.size() == 1)
   {
	   out.getLogger()->error("{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else if(words.size() == 2)
   {
	   double albedo = std::stod(words[1]);
	   m_problem.setAlbedo(std::stod(words[1]));
	   out.getLogger()->info("Albedo factor: {} \n", albedo);
   }
   else
   {
	   out.getLogger()->error("{}  has too many parameters!", words[0]);
	   exit(-1);
   }
} 

void Input::setMaterials()
{ 
   unsigned energies = m_problem.getEnergyGroupsNumber();
   unsigned cells    = m_problem.getCellsNumber();
   
   CrossSectionSet XSSet;
   
   MatrixXd ni      = MatrixXd::Zero(energies, cells);
   MatrixXd chi     = MatrixXd::Zero(energies, cells);
   MatrixXd fission = MatrixXd::Zero(energies, cells);
   MatrixXd total   = MatrixXd::Zero(energies, cells);

   std::vector<MaterialKind> matProperties;
   
   Tensor3d scattMatrix = Tensor3d(energies, energies, cells);
   scattMatrix.setZero();
   
   std::vector<std::string> words;

   for (auto matListItem : m_materialList)
   {
	   std::string matStr = "material";
	   words = splitLine(findKeyword(matStr + " " + matListItem));
       std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

       if(words.size() == 2)
       {
		  // out.getLogger()->info("Material: {} found", words[1]);
       }
       else
       {
		   out.getLogger()->error("{} has too many parameters!", words[0]);
	       exit(-1);
       }
   
       for(unsigned m = 0; m < cells; m++)
       {
            if (m_materialMap[m] != matListItem) continue;

			std::string propertiesStr = "properties";
	        std::vector<std::string> propertiess = splitLine(findKeyword(propertiesStr, matBlock.first, matBlock.second));

            if (propertiess[1] == "u")
			{
				matProperties.push_back(MaterialKind::U);
			}
			else
			{
				out.getLogger()->error("There are no material properties for {}!", propertiess[1]);
	            exit(-1);
			}
   
            for (unsigned i = 1; i <= energies; i++)
            {
	            std::string niStr = "ni(" + std::to_string(i) + ")";
	            std::vector<std::string> nis = splitLine(findKeyword(niStr, matBlock.first, matBlock.second));
	            ni(i - 1, m) = std::stod(nis[1]);
	   
	            std::string chiStr = "chi(" + std::to_string(i) + ")";
	            std::vector<std::string> chis = splitLine(findKeyword(chiStr, matBlock.first, matBlock.second));
	            chi(i - 1, m) = std::stod(chis[1]);
	   
	            std::string fissionStr = "fission(" + std::to_string(i) + ")";
	            std::vector<std::string> fissions = splitLine(findKeyword(fissionStr, matBlock.first, matBlock.second));
	            fission(i - 1, m) = std::stod(fissions[1]);
	   
	            std::string totalStr = "total(" + std::to_string(i) + ")";
	            std::vector<std::string> totals = splitLine(findKeyword(totalStr, matBlock.first, matBlock.second));
	            total(i - 1, m) = std::stod(totals[1]);
	        }

			for (unsigned i = 1; i <= energies; i++)
            {
	            for (unsigned j = 1; j <= energies; j++)
	            {	
	                std::string scattStr = "scattMatrix(" + std::to_string(i) + ", " + std::to_string(j) + ")";
	                std::vector<std::string> scatts = splitLine(findKeyword(scattStr, matBlock.first, matBlock.second));

					scattMatrix(i - 1, j - 1, m) = std::stod(scatts[2]);			
	            }
            }
       }    
   }
   
   out.getLogger()->info("Ni");
   printMatrix(ni, out, TraceLevel::INFO);
   
   out.getLogger()->info("Chi");
   printMatrix(chi, out, TraceLevel::INFO);
	
   out.getLogger()->info("Fission");
   printMatrix(fission, out, TraceLevel::INFO);
	
   out.getLogger()->info("Total");
   printMatrix(total, out, TraceLevel::INFO);
   
   out.getLogger()->info("Scattering Matrix");
   printMatrix(scattMatrix, out, TraceLevel::INFO, "Mesh");
   
   XSSet.setNi(ni);
   XSSet.setChi(chi);
   XSSet.setFission(fission);
   XSSet.setTotal(total);
   XSSet.setScattMatrix(scattMatrix);
	
   m_library.setCrossSectionSet(XSSet);

   m_library.setMatProperties(matProperties);
}