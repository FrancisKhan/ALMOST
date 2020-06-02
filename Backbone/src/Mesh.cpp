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
	VectorXd empty_vec(1); empty_vec << 0.0;
	
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->volumes(m_boundaries, dim);
	}
	else
	{
		return empty_vec;
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
    Map<VectorXd> eigenVec(&temperatures[0], temperatures.size());
	m_temperatures = eigenVec;
}

VectorXd Mesh::getTemperatures(std::string dim)
{
    if(dim == "C")  
		return m_temperatures;
	else if(dim == "K")
	{
        return m_temperatures + 273.15; 
	} 
	else
		return m_temperatures * -1.0;
}

void Mesh::setHeatSources(std::vector<double> &sources)
{
    Map<VectorXd> eigenVec(&sources[0], sources.size());
	m_heatSources = eigenVec;
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