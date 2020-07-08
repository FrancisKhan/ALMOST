#include "Mesh.h"
#include "numeric_tools.h"

#include <algorithm>
#include <iostream>

using namespace Eigen;
using namespace Numerics;

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

Eigen::VectorXd Mesh::getCellSizes(std::string dim)
{
	VectorXd result = VectorXd::Zero(m_meshNumber);

	for(size_t i = 0; i < m_meshNumber; i++)
	{
		result[i] = m_boundaries[i + 1] - m_boundaries[i];
	}

	return result;
}

void Mesh::setCrossSectionData(MeshCrossSections &meshCrossSections)
{
    for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		 m_materials[m]->setNi(meshCrossSections.m_nis.col(m));
		 m_materials[m]->setChi(meshCrossSections.m_chis.col(m));
		 m_materials[m]->setFissionXS(meshCrossSections.m_fissionXSs.col(m));
		 m_materials[m]->setTotalXS(meshCrossSections.m_totalXSs.col(m));
		 m_materials[m]->setScattMatrix(meshCrossSections.m_scattMatrices.chip(m, 2));
	}
}

Eigen::MatrixXd Mesh::getNis()
{
    MatrixXd nis = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd ni  = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		ni = m_materials[m]->getNi();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			nis(i, m) = ni(i);
		}
	}

	return nis;
}

Eigen::MatrixXd Mesh::getChis()
{
    MatrixXd chis = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd chi  = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		chi = m_materials[m]->getChi();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			chis(i, m) = chi(i);
		}
	}

	return chis;
}

Eigen::MatrixXd Mesh::getTotalXSs()
{
    MatrixXd tots = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd tot  = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		tot = m_materials[m]->getTotalXS();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			tots(i, m) = tot(i);
		}
	}

	return tots;
}

Eigen::MatrixXd Mesh::getFissionXSs()
{
    MatrixXd fiss = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd fis  = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		fis = m_materials[m]->getFissionXS();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			fiss(i, m) = fis(i);
		}
	}

	return fiss;
}

Numerics::Tensor3d Mesh::getScattMatrices()
{
    Tensor3d scatts(m_energyGroupsNumber, m_energyGroupsNumber, m_meshNumber);
	MatrixXd scatt = MatrixXd::Zero(m_energyGroupsNumber, m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		scatt = m_materials[m]->getScattMatrix();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			for(int j = 0; j < static_cast<int>(m_energyGroupsNumber); j++)
			{
				scatts(i, j, m) = scatt(i, j);
			}
		}
	}

	return scatts;
}

void Mesh::setScattMatrices(Numerics::Tensor3d &scattMatrices)
{
    for(int m = 0; m < scattMatrices.dimension(2); m++)
	{
		 m_materials[m]->setScattMatrix(scattMatrices.chip(m, 2));
	}
}