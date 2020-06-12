#include "Mesh.h"
#include "numeric_tools.h"

#include <algorithm>
#include <iostream>

using namespace Eigen;

void Mesh::setMeshKind(GeomKind kind)
{
	m_mode = kind;
	pm_abGeom = AbstractGeometry::setGeometry(kind);
}

// From cm to m
void Mesh::setBoundaries(VectorXd &boundaries)
{
	m_boundaries = boundaries;
	m_meshNumber = m_boundaries.size() - 1;
}

// From cm to m
void Mesh::setBoundaries(double cellSide, unsigned meshNumber)
{	
    m_boundaries = VectorXd::Zero(meshNumber + 1);
	
	for(unsigned i = 0; i <= meshNumber; i++)
	{
		m_boundaries(i) = i * (cellSide / meshNumber);
	}
	
	m_meshNumber = meshNumber;
}

VectorXd Mesh::getVolumes(std::string dim)
{
	VectorXd empty = VectorXd::Zero(1);
	
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->volumes(m_boundaries, dim);
	}
	else
	{
		return empty;
	}
}

double Mesh::getSurface(std::string dim)
{
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->surface(m_boundaries, dim);
	}
	else
	{
		return 0.0;
	}
}

void Mesh::setTemperatures(std::vector<double> &temperatures)
{
    for(size_t i = 0; i < temperatures.size(); i++)
	{
		 m_materials[i]->setTemperature(temperatures[i]);
	}
}

void Mesh::setTemperatures(VectorXd &temperatures)
{
    for(int i = 0; i < temperatures.size(); i++)
	{
		m_materials[i]->setTemperature(temperatures[i]);
	}
}

VectorXd Mesh::getTemperatures(std::string dim)
{
    VectorXd result = VectorXd::Zero(m_meshNumber);

    for(size_t i = 0; i < m_meshNumber; i++)
	{
		result[i] = m_materials[i]->getTemperature();
	}

    if(dim == "C")
	{
		return result;
	}
	else if(dim == "K")
	{
        return result + 273.15; 
	} 
	else
	{
		return result * -1.0;
	}
}

void Mesh::setHeatSources(std::vector<double> &sources)
{
    for(size_t i = 0; i < sources.size(); i++)
	{
		 m_materials[i]->setHeatSource(sources[i]);
	}
}

VectorXd Mesh::getHeatSources()
{
    VectorXd result = VectorXd::Zero(m_meshNumber);

    for(size_t i = 0; i < m_meshNumber; i++)
	{
		result[i] = m_materials[i]->getHeatSource();
	}

	return result;
}

void Mesh::setHeatBoundaryConditions(std::vector<double> &boundaries)
{
    Map<VectorXd> eigenVec(&boundaries[0], boundaries.size());
	m_heatBoundaryConditions = eigenVec;
}

VectorXd Mesh::getBoundaries(std::string dim)
{
	if(dim == "m")  
		return m_boundaries;
	else if(dim == "cm") 
		return m_boundaries * 100.0;
	else
		return m_boundaries * -1.0;
}

VectorXd Mesh::getMeshMiddlePoints()
{
	VectorXd result = VectorXd::Zero(m_boundaries.size() - 1);

	for(int i = 0; i < result.size(); i++)
		result(i) = (m_boundaries(i) + m_boundaries(i + 1)) / 2.0;
   
    return result;
}

void Mesh::createMaterials(std::vector<std::string> materialMap)
{
	m_materials.resize(m_meshNumber);

	for(unsigned i = 0; i < m_meshNumber; i++)
	{
		m_materials[i] = std::make_shared<Material>(materialMap[i]);
	}
}

void Mesh::setThermalConductivityLaw(unsigned i, std::vector<std::string> &strVec)
{
    m_materials[i]->setThermalConductivityLaw(strVec);
}

Eigen::VectorXd Mesh::getThermalConductivities()
{
	VectorXd result = VectorXd::Zero(m_meshNumber);

    for(size_t i = 0; i < m_meshNumber; i++)
	{
		result[i] = m_materials[i]->getThermalConductivity();
	}

	return result;
}