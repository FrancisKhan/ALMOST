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
void Mesh::setRadialBoundaries(VectorXd &boundaries)
{
	m_radialBoundaries = boundaries;
	m_meshNumber = m_radialBoundaries.size() - 1;
}

// From cm to m
void Mesh::setRadialBoundaries(double cellSide, unsigned meshNumber)
{	
    m_radialBoundaries = VectorXd::Zero(meshNumber + 1);
	
	for(unsigned i = 0; i <= meshNumber; i++)
	{
		m_radialBoundaries(i) = i * (cellSide / meshNumber);
	}
	
	m_meshNumber = meshNumber;
}

VectorXd Mesh::getVolumes(std::string dim)
{
	VectorXd empty = VectorXd::Zero(1);
	
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->volumes(m_radialBoundaries, dim);
	}
	else
	{
		return empty;
	}
}

VectorXd Mesh::getSurfaces(std::string dim)
{
	VectorXd empty = VectorXd::Zero(1);
	
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->surfaces(m_radialBoundaries, dim);
	}
	else
	{
		return empty;
	}
}

double Mesh::getRadialExternalSurface(std::string dim)
{
	if(pm_abGeom != nullptr)
	{
		return pm_abGeom->externalSurface(m_radialBoundaries, dim);
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

void Mesh::setHeatSources(const VectorXd &sources)
{
    for(int i = 0; i < sources.size(); i++)
	{
		 m_materials[i]->setHeatSource(sources(i));
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

VectorXd Mesh::getRadialBoundaries(std::string dim)
{
	if(dim == "m")  
		return m_radialBoundaries;
	else if(dim == "cm") 
		return m_radialBoundaries * 100.0;
	else
		return m_radialBoundaries * -1.0;
}

VectorXd Mesh::getRadialMeshMiddlePoints()
{
	VectorXd result = VectorXd::Zero(m_radialBoundaries.size() - 1);

	for(int i = 0; i < result.size(); i++)
		result(i) = (m_radialBoundaries(i) + m_radialBoundaries(i + 1)) / 2.0;
   
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

void Mesh::setEnergyGroupsNumber(unsigned n)
{
	m_energyGroupsNumber = n;
	for(unsigned i = 0; i < m_meshNumber; i++)
	{
		m_materials[i]->setEnergies(n);
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

VectorXd Mesh::getRadialCellSizes(std::string dim)
{
	VectorXd result = VectorXd::Zero(m_meshNumber);

	for(size_t i = 0; i < m_meshNumber; i++)
	{
		result[i] = m_radialBoundaries[i + 1] - m_radialBoundaries[i];
	}

	if(dim == "m")  
		return result;
	else if(dim == "cm") 
		return result * 100.0;
	else
		return result * -1.0;
}

MatrixXd Mesh::getNis()
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

MatrixXd Mesh::getChis()
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

MatrixXd Mesh::getTotalXSs()
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

MatrixXd Mesh::getDiffusionConstants()
{
    MatrixXd diffs = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd diff  = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		diff = m_materials[m]->getDiffusionConstants();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			diffs(i, m) = diff(i);
		}
	}

	return diffs;
}

MatrixXd Mesh::getFissionXSs()
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

MatrixXd Mesh::getRemovalXSs()
{
	MatrixXd rem = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);

    MatrixXd tot   = getTotalXSs();
	Tensor3d scatt = getScattMatrices();

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			rem(i, m) = tot(i, m) - scatt(i, i, m);
		}
	}

	return rem;
}

Tensor3d Mesh::getScattMatrices()
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

void Mesh::setNeutronFluxes(Eigen::MatrixXd &neutronFluxes)
{
    for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		m_materials[m]->setNeutronFlux(neutronFluxes.col(m));
	}
}

MatrixXd Mesh::getNeutronFluxes()
{
    MatrixXd neutronFluxes = MatrixXd::Zero(m_energyGroupsNumber, m_meshNumber);
	VectorXd neutronFlux   = VectorXd::Zero(m_energyGroupsNumber);

	for(int m = 0; m < static_cast<int>(m_meshNumber); m++)
	{
		neutronFlux = m_materials[m]->getNeutronFlux();

		for(int i = 0; i < static_cast<int>(m_energyGroupsNumber); i++)
		{
			neutronFluxes(i, m) = neutronFlux(i);
		}
	}

	return neutronFluxes;
}