#include "Input.h"
#include "Mesh.h"
#include "Output.h"
#include "GeomKind.h"
#include "KineticsSet.h"
#include "additionalPrintFuncs.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;
using namespace HelperTools;

void Input::getArguments(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Missing input arguments!" << std::endl;
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
		m_reactor.setLogLevel(out.getLevel());
	}
	else
	{
		std::cout << "Too many input arguments!" << std::endl;
		exit(-1);
	}
	
}

void Input::printData()
{
	out.print(TraceLevel::CRITICAL, "Input file: {}/{}",  out.getInputPath(), out.getInputName());
	out.print(TraceLevel::CRITICAL, "Output file: {} \n", out.getOutputName());
}

void Input::storeInput()
{
	std::ifstream inFile;
	inFile.open(m_inputPath);
	if (!inFile) 
	{
		out.print(TraceLevel::CRITICAL, "Unable to open file: {}", m_inputPath); 
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
    }

	inFile.close();
}

void Input::readData()
{
    storeInput();
	setSolvers();

	// Check if geometry or mesh need to be set before anything else
	// this is done to set them only once, independently of the number of 
	// different solvers requested
    if(isElementHere(m_solvers, SolverKind::TRANSPORT) || 
	   isElementHere(m_solvers, SolverKind::DIFFUSION) || 
	   isElementHere(m_solvers, SolverKind::HEAT))
	{
		setGeometryKind();
	    setMesh();
	}

	setSolverProperties("accuracy");
	setSolverProperties("max_iteration_number");
	setSolverProperties("albedo", SolverKind::TRANSPORT);
	setSolverProperties("albedo", SolverKind::DIFFUSION);
	setSolverProperties("heat_boundary_conditions", SolverKind::HEAT);
	setSolverProperties("energies", SolverKind::TRANSPORT);
	setSolverProperties("energies", SolverKind::DIFFUSION);

	if((isElementHere(m_solvers, SolverKind::TRANSPORT) || isElementHere(m_solvers, SolverKind::DIFFUSION))
	&& isElementHere(m_solvers, SolverKind::HEAT) 
	&& isElementHere(m_solvers, SolverKind::COUPLED))
	{
		setSolverProperties("relaxation_parameter", SolverKind::COUPLED);
	}

	for(auto i : m_solvers)
	{
		if((i.getKind() == SolverKind::TRANSPORT) || (i.getKind() == SolverKind::DIFFUSION))
		{
			setMaterials(i.getKind());
		}
		else if(i.getKind() == SolverKind::KINETICS)
		{
			setKineticsParameters();
		}
		else if(i.getKind() == SolverKind::HEAT)
		{
			if(isElementHere(m_solvers, SolverKind::TRANSPORT) || isElementHere(m_solvers, SolverKind::DIFFUSION))
			{	
				setThermalPower();
			}	
			else
			{
				setHeatSources();
			}

			setMaterials(i.getKind());
			setTemperatures();
		}
		else
		{
		}
	}
}

void Input::removeExtraSpaces(const std::string &input, std::string &output)
{
    output.clear();  // unless you want to add at the end of existing string...
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
        if(itemLine.front() == '%') continue; // remove comments

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
		out.print(TraceLevel::CRITICAL, "{} is missing from the input!", toSearch);
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

void Input::setSolvers()
{
	std::vector<SolverData> solvers;
    std::string solverStr;
	std::vector<std::string> values = readManyParameters("solvers");

    for(auto i : values)
	{
		if(i == "transport")  
		{
			SolverData solver(SolverKind::TRANSPORT);
			solvers.push_back(solver);
			solverStr += "transport ";
		}
		else if(i == "kinetics")
		{
			SolverData solver(SolverKind::KINETICS);
			solvers.push_back(solver);
			solverStr += "kinetics ";
		}
		else if(i == "heat")
		{
			SolverData solver(SolverKind::HEAT);
			solvers.push_back(solver);
			solverStr += "heat ";
		}
		else if(i == "diffusion")
		{
			SolverData solver(SolverKind::DIFFUSION);
			solvers.push_back(solver);
			solverStr += "diffusion ";
		}
		else
		{
			out.print(TraceLevel::CRITICAL, "{} solver kind not recognized!", i);
	    	exit(-1);
		}
	}

    out.print(TraceLevel::CRITICAL, "Solvers: {}\n", solverStr);

	// add coupled solver if coupled calculation
	if(solvers.size() >= 2)
	{
		SolverData solver(SolverKind::COUPLED);
		solvers.push_back(solver);
	}

	m_solvers = solvers;
	m_reactor.setSolvers(solvers);
}

void Input::setGeometryKind()
{ 
   std::string geometry = readOneParameter("geometry");
   
   if(geometry == "cylinder") 
	{
	   m_mesh.setMeshKind(GeomKind::CYLINDER);
	   out.print(TraceLevel::CRITICAL, "Geometry: Cylindrical \n");
	}
	else if(geometry == "sphere") 
	{
	   m_mesh.setMeshKind(GeomKind::SPHERE);
	   out.print(TraceLevel::CRITICAL, "Geometry: Spherical \n");
	}
	else if(geometry == "slab") 
	{
	   m_mesh.setMeshKind(GeomKind::SLAB);
	   out.print(TraceLevel::CRITICAL, "Geometry: Cartesian \n");
	}
	else
	{
	   out.print(TraceLevel::CRITICAL, "Geometry: {} not recognized!", geometry);
	   exit(-1);
	}
} 

void Input::setThermalPower()
{
	std::string power = readOneParameter("thermal_power");
	m_reactor.setThermalPower(std::stod(power));
    std::string numberString = stringFormat(power, "%7.6e");
	out.print(TraceLevel::CRITICAL, "\nInput thermal power [W]: {} \n", numberString);
}

void Input::setMesh()
{ 
    std::vector<std::string> values = readManyParameters("mesh");
   
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

	out.print(TraceLevel::CRITICAL, "Input boundaries [m]:");
	printVector(boundaries, out, TraceLevel::CRITICAL);
	m_mesh.setBoundaries(boundaries);

    Eigen::VectorXd volumes = m_mesh.getVolumes("m");
	out.print(TraceLevel::CRITICAL, "Input volumes [m3]:");
    printVector(volumes, out, TraceLevel::CRITICAL);

	for(size_t i = 1; i < regionNumber.size(); i++)
	{
		for(size_t j = 0; j < regionNumber[i]; j++)
	    {
		  m_materialMap.push_back(regionMaterial[i - 1]);
		}
	}

	m_mesh.createMaterials(m_materialMap);

	out.print(TraceLevel::CRITICAL, "Input meshes:");
	printVector(m_materialMap, out, TraceLevel::CRITICAL, false);

	out.print(TraceLevel::CRITICAL, "\nMesh middle points [m]:");
    printVector(m_mesh.getMeshMiddlePoints(), out, TraceLevel::CRITICAL);

	std::sort(regionMaterial.begin(), regionMaterial.end());
    regionMaterial.erase(std::unique(regionMaterial.begin(), 
                         regionMaterial.end()), regionMaterial.end());

	m_materialList = regionMaterial;
}  

void Input::setMaterials(SolverKind solver)
{ 
   	m_cells    = m_mesh.getCellsNumber();
	m_energies = m_mesh.getEnergyGroupsNumber();

	if((solver == SolverKind::TRANSPORT))
	{
		setXS("ni", "\nInput ni:");
   		setXS("chi", "\nInput chi:");
   		setXS("fission", "\nInput fission XS [1/cm]:");
   		setXS("total", "\nInput total XS [1/cm]:");	

		Tensor3d scattMatrices = setMatrixXS("scattMatrix", "\nInput scattering matrix [1/cm]:");
		m_mesh.setScattMatrices(scattMatrices);
	}
	else if(solver == SolverKind::DIFFUSION)
	{
		setXS("ni", "\nInput ni:");
   		setXS("chi", "\nInput chi:");
   		setXS("fission", "\nInput fission XS [1/cm]:");
   		setXS("total", "\nInput total XS [1/cm]:");	
		setXS("diffCoeff", "\nInput diffusion coefficients [cm]:");	

		Tensor3d scattMatrices = setMatrixXS("scattMatrix", "\nInput scattering matrix [1/cm]:");
		m_mesh.setScattMatrices(scattMatrices);
	}
   	else if(solver == SolverKind::HEAT)
   	{
	   	setMaterialProperties("thermal_conductivity");

		if(isElementHere(m_solvers, SolverKind::TRANSPORT))
		{
			setXSThermalDependence("thermal_xs_dependence", "\nInput thermal XS dependence:");	
		}
   	}
	else {;}
}

void Input::setMaterialProperties(std::string name)
{
	if(name == "thermal_conductivity")
	{
		out.print(TraceLevel::CRITICAL, "Input thermal conductivity [W/(m*K)]:");
	}
	else
	{
		out.print(TraceLevel::CRITICAL, "{} is not a material property", name);
   		exit(-1);
	}

	for (auto matListItem : m_materialList)
    {
        std::string matStr = "material";
	    readOneParameter(matStr + " " + matListItem);
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
			if (m_materialMap[m] != matListItem) continue;

			std::vector<std::string> values = splitLine(findKeyword(name, matBlock.first, matBlock.second));

			if(name == "thermal_conductivity")
			{
				setThermalConductivity(values, m);
			}
			else
			{
				out.print(TraceLevel::CRITICAL, "{} is not a material property", name);
	    		exit(-1);
			}
			
		}
	}
}

void Input::setThermalConductivity(std::vector<std::string> &values, unsigned index)
{
	if(values.size() < 2) 
	{
		out.print(TraceLevel::CRITICAL, "{} has no parameters!", values[0]);
	    exit(-1);
	}
	else if(values.size() >= 2 && values.size() < 5) 
	{
		std::vector<std::string> numberVec = std::vector<std::string>(values.begin() + 1, values.end());
		m_mesh.setThermalConductivityLaw(index, numberVec);
		printVector(numberVec, out, TraceLevel::CRITICAL, false);
	}
	else
	{
		out.print(TraceLevel::CRITICAL, "{} number of parameters exceeded!", values[0]);
		exit(-1);
	}
}

void Input::setXSThermalDependence(std::string name, std::string outputName)
{
	out.print(TraceLevel::CRITICAL, outputName);

	for (auto matListItem : m_materialList)
    {
        std::string matStr = "material";
	    readOneParameter(matStr + " " + matListItem);
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
			if (m_materialMap[m] != matListItem) continue;

			for (unsigned i = 1; i <= m_energies; i++)
   			{
				std::string str = name + "(" + std::to_string(i) + ")";
				std::vector<std::string> values = splitLine(findKeyword(str, matBlock.first, matBlock.second));
				std::vector<std::string> numberVec = std::vector<std::string>(values.begin() + 1, values.end());
				m_mesh.getMaterial(m)->setThermalXSDependenceLaws(numberVec);
				printVector(numberVec, out, TraceLevel::CRITICAL, false);
			}
			
			out.print(TraceLevel::CRITICAL, " ");
		}
	}
}

void Input::setXS(std::string name, std::string outputName)
{
	VectorXd energyVec = VectorXd::Zero(m_energies);

	out.print(TraceLevel::CRITICAL, outputName);

	for (auto matListItem : m_materialList)
    {
        std::string matStr = "material";
	    readOneParameter(matStr + " " + matListItem);
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, matListItem);

		for(unsigned m = 0; m < m_cells; m++)
    	{
			if (m_materialMap[m] != matListItem) continue;

			for (unsigned i = 1; i <= m_energies; i++)
   			{
				std::string str = name + "(" + std::to_string(i) + ")";
				std::vector<std::string> values = splitLine(findKeyword(str, matBlock.first, matBlock.second));
				energyVec(i - 1) = std::stod(values[1]);
			}

            if(name == "ni") 
				m_mesh.getMaterial(m)->setNi(energyVec);
			else if(name == "chi") 
				m_mesh.getMaterial(m)->setChi(energyVec);
			else if(name == "fission") 
				m_mesh.getMaterial(m)->setFissionXS(energyVec);
			else if(name == "total") 
				m_mesh.getMaterial(m)->setTotalXS(energyVec);
			else if(name == "absorption") 
				m_mesh.getMaterial(m)->setAbsXS(energyVec);
			else if(name == "diffCoeff") 
				m_mesh.getMaterial(m)->setDiffusionConstants(energyVec);
			else {;}
		}
	}

	for(unsigned m = 0; m < m_cells; m++)
    {
        if(name == "ni") 
			printVector(m_mesh.getMaterial(m)->getNi(), out, TraceLevel::CRITICAL, false , false);
		else if(name == "chi") 
			printVector(m_mesh.getMaterial(m)->getChi(), out, TraceLevel::CRITICAL, false , false);
		else if(name == "fission") 
			printVector(m_mesh.getMaterial(m)->getFissionXS(), out, TraceLevel::CRITICAL, false , false);
		else if(name == "total") 
			printVector(m_mesh.getMaterial(m)->getTotalXS(), out, TraceLevel::CRITICAL, false , false);
		else if(name == "absorption") 
			printVector(m_mesh.getMaterial(m)->getAbsXS(), out, TraceLevel::CRITICAL, false , false);
		else if(name == "diffCoeff") 
			printVector(m_mesh.getMaterial(m)->getDiffusionConstants(), out, TraceLevel::CRITICAL, false , false);
		else {;}
	}
}

Tensor3d Input::setMatrixXS(std::string name, std::string outputName)
{
    Tensor3d matrix = Tensor3d(m_energies, m_energies, m_cells);
    matrix.setZero();

	for (auto matListItem : m_materialList)
    {
       std::string matStr = "material";
	   readOneParameter(matStr + " " + matListItem);
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

	out.print(TraceLevel::CRITICAL, outputName);
    printMatrix(matrix, out, TraceLevel::CRITICAL, "Mesh");

	return matrix;
}

std::string Input::readOneParameter(std::string name)
{
   std::string result = "";
   std::vector<std::string> words = splitLine(findKeyword(name));
   
   if(words.size() == 1)
   {
	   out.print(TraceLevel::CRITICAL, "{} is missing its parameters!", words[0]);
	   exit(-1);
   }
   else if(words.size() == 2)
   {
	   return words[1];
   }
   else
   {
	   out.print(TraceLevel::CRITICAL, "{}  has too many parameters!", words[0]);
	   exit(-1);
   }

   return result;
}

std::vector<std::string> Input::readManyParameters(std::string name)
{
   std::vector<std::string> result;
   std::vector<std::string> words = splitLine(findKeyword(name));
   
   if(words.size() == 1)
   {
	   out.print(TraceLevel::CRITICAL, "{} is missing its parameters!", words[0]);
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
    double alpha = std::stod(readOneParameter("alpha"));
    out.print(TraceLevel::CRITICAL, "Alpha [s]: {} \n", stringFormat(alpha, "%7.6e"));

    double power = std::stod(readOneParameter("power"));
    out.print(TraceLevel::CRITICAL, "Initial power [W]: {} \n", stringFormat(alpha, "%7.6e"));

    std::vector<double> lambda = setManyParameters("lambda", "Input lambdas [1/s]");
    std::vector<double> beta = setManyParameters("beta", "Input betas");
	std::vector<double> times = setManyParameters("times", "Input times [s]");
	std::vector<double> reactivities = setManyParameters("reactivities", "Input reactivities");

	if (times.size() != reactivities.size()) 
	{
		out.print(TraceLevel::CRITICAL, "times and reactivities must have equal sizes!"); 
		out.print(TraceLevel::CRITICAL, "times: {} reactivities: {}" , int(times.size()), reactivities.size());
		exit(-1);
	}

	KineticsSet kinSet;
	kinSet.setAlpha(alpha);
	kinSet.setPower(power);
	kinSet.setLambda(lambda);
	kinSet.setBeta(beta);
	kinSet.setTimes(times);
	kinSet.setReactivities(reactivities);
	m_reactor.setKineticsSet(kinSet);
} 

std::vector<double> Input::setManyParameters(std::string name, std::string outputName)
{ 

    std::vector<std::string> values = readManyParameters(name);

    std::vector<double> result(values.size(), 0.0);

    // If the values read from the input are all floats, then
	// assign one value per mesh
	if (std::all_of(values.begin(), values.end(), 
	[](std::string s) {return isFloat(s);}))
	{
		std::transform(values.begin(), values.end(), result.begin(), 
                   [](std::string &i){return std::stod(i);});

		out.print(TraceLevel::CRITICAL, "\n{}:", outputName);
	    printVector(result, out, TraceLevel::CRITICAL);
		return result;
	}

    std::vector<unsigned> submeshes;
	std::vector<double> submeshValues;

    if(isFloat(values.front()))
	{
		for(size_t i = 0; i < values.size(); i++)
		{
      		switch (i % 2)
	  		{
		  	  case 0:
		  		submeshValues.push_back(std::stod(values[i]));
		  		break;
		      case 1:
			    submeshes.push_back(std::stoi(values[i]));
		  		break;
	  		}
		}

		int totSubmeshes = std::accumulate(submeshes.begin(), submeshes.end(), 0);

		result.resize(totSubmeshes);

		size_t indexCounter = 0;

		for(size_t i = 0; i < submeshes.size(); i++)
		{
			for(size_t j = 0; j < submeshes[i]; j++)
			{
		  		result[indexCounter] = submeshValues[i];
		  		indexCounter++;
			}
		}
	}
	else
	{
        submeshes.push_back(0);
		submeshValues.push_back(0.0);

		for(size_t i = 0; i < values.size(); i++)
		{
      		switch (i % 2)
	  		{
		  	  case 0:
		  		submeshes.push_back(std::stoi(values[i]));
		  		break;
		  	  case 1:
		  		submeshValues.push_back(std::stod(values[i]));
		  		break;
	  		}
		}

		int totSubmeshes = std::accumulate(submeshes.begin(), submeshes.end(), 0);
	
		result.resize(totSubmeshes + 1);

    	double submeshValuesSum = 0.0;
		size_t indexCounter = 0;

		for(size_t i = 1; i < submeshes.size(); i++)
		{
      		size_t lastValue = 1 ? i == submeshes.size() - 1 : 0;

			for(size_t j = 0; j < submeshes[i] + lastValue; j++)
			{
		  		result[indexCounter] = j * submeshValues[i] / submeshes[i] + submeshValuesSum;
		  		indexCounter++;
			}
		  
			submeshValuesSum += submeshValues[i];
		}
	}

	out.print(TraceLevel::CRITICAL, "\n{}:", outputName);
	printVector(result, out, TraceLevel::CRITICAL);

	return result;
}

void Input::setTemperatures()
{ 
	std::vector<double> temperatures = setManyParameters("temperatures", 
														 "Input temperatures [C]");
	m_mesh.setTemperatures(temperatures);
} 

void Input::setHeatSources()
{ 
	std::vector<double> heatSources = setManyParameters("heat_sources", 
														"Input heat_sources [W/m3]");
		m_mesh.setHeatSources(heatSources);	
} 

void Input::setSolverProperties(std::string name, SolverKind inputSolver)
{
	for (auto &solver : m_solvers)
    {
		// if the property is related only to a specific solver
		if(inputSolver != SolverKind::UNDEFINED)
		{
			if(solver.getKind() != inputSolver) continue;
		}

        std::string matStr = "solver";
	    readOneParameter(matStr + " " + get_name(solver.getKind()));
	    std::pair<unsigned, unsigned> matBlock = findBlock(matStr, get_name(solver.getKind()));

		std::vector<std::string> values = splitLine(findKeyword(name, matBlock.first, matBlock.second));

		if(values.size() < 1) 
		{
			out.print(TraceLevel::CRITICAL, "{} has no parameters!", values[0]);
	    	exit(-1);
		}
		else if(values.size() == 2) 
		{
			out.print(TraceLevel::CRITICAL, "{} solver {}: {}", get_name(solver.getKind()), values[0], values[1]);

			if(values[0] == "accuracy")
				solver.setAccuracy(std::stod(values[1]));
			else if(values[0] == "max_iteration_number")
				solver.setMaxIterNumber(std::stoi(values[1]));
			else if(values[0] == "relaxation_parameter")
				solver.setRelaxationParameter(std::stod(values[1]));
			else if(values[0] == "energies")
			{
				solver.setEnergies(std::stoi(values[1]));
				m_mesh.setEnergyGroupsNumber(std::stoi(values[1]));
			}
			else if(values[0] == "albedo")
			{
				if(inputSolver == SolverKind::TRANSPORT)
				{
					std::vector<double> albedo{std::stod(values[1])}; 
					solver.setAlbedo(albedo);
				}
				else if(inputSolver == SolverKind::DIFFUSION)
				{
					if(m_mesh.getGeometry() == GeomKind::SLAB)
					{
						out.print(TraceLevel::CRITICAL, "Error setting {} for {} solver!", values[0], get_name(solver.getKind()));	
						exit(-1);
					}
					else
					{
						std::vector<double> albedo{std::stod(values[1])}; 
						solver.setAlbedo(albedo);
					}
				}
				else
				{
					out.print(TraceLevel::CRITICAL, "Error setting {} for {} solver!", values[0], get_name(solver.getKind()));
					exit(-1);
				}
				
						
			}
			else {;}
		}
		else if(values.size() == 3) 
		{
			out.print(TraceLevel::CRITICAL, "{} solver {}: {} {}", get_name(solver.getKind()), values[0], values[1], values[2]);

			if(values[0] == "albedo")
			{
				if((inputSolver == SolverKind::DIFFUSION) && (m_mesh.getGeometry() == GeomKind::SLAB))
				{
					std::vector<double> albedo{std::stod(values[1]), std::stod(values[2])}; 
					solver.setAlbedo(albedo);
				}
				else
				{
					out.print(TraceLevel::CRITICAL, "Error setting {} for {} solver!", values[0], get_name(solver.getKind()));
					exit(-1);
				}
			}
			else {;}
		}
		else if(values.size() == 4) 
		{
			out.print(TraceLevel::CRITICAL, "{} solver {}: {} {} {}", get_name(solver.getKind()), values[0], values[1], values[2], values[3]);

			if(values[0] == "heat_boundary_conditions")
			{
				if((inputSolver == SolverKind::HEAT) && (m_mesh.getGeometry() != GeomKind::SLAB))
				{
					solver.setHeatBoundaryConditions(values);
				}
				else
				{
					out.print(TraceLevel::CRITICAL, "Error setting {} for {} solver!", values[0], get_name(solver.getKind()));
					exit(-1);
				}

			}
			else {;}
		}
		else if(values.size() == 7) 
		{
			out.print(TraceLevel::CRITICAL, "{} solver {}: {} {} {} {} {} {}", get_name(solver.getKind()), values[0], values[1], values[2],
			          values[3], values[4], values[5], values[6]);

			if(values[0] == "heat_boundary_conditions")
			{
				if((inputSolver == SolverKind::HEAT) && (m_mesh.getGeometry() == GeomKind::SLAB))
				{
					solver.setHeatBoundaryConditions(values);
				}
				else
				{
					out.print(TraceLevel::CRITICAL, "Error setting {} for {} solver!", values[0], get_name(solver.getKind()));
					exit(-1);
				}

			}
			else {;}
		}
		else
		{
			out.print(TraceLevel::CRITICAL, "{} number of parameters exceeded!", values[0]);
			exit(-1);
		}
	}
}


