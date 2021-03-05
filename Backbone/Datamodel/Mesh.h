#ifndef MESH_H
#define MESH_H

#include "GeomKind.h"
#include "Material.h"
#include "AbstractGeometry.h"

#include <Eigen/Dense>
#include <vector>

class Mesh
{
public:
	Mesh() : pm_abGeom(nullptr){}
	void setMeshKind(GeomKind kind);
	GeomKind getGeometry() {return m_mode;}
	void setRadialBoundaries(Eigen::VectorXd &boundaries);
	void setRadialBoundaries(double meshes, unsigned meshNumber);
	void setVerticalBoundaries(Eigen::VectorXd &boundaries);
	Eigen::VectorXd getRadialBoundaries(std::string dim);
	Eigen::VectorXd getVerticalBoundaries(std::string dim);
	Eigen::VectorXd getRadialCellSizes(std::string dim);
	unsigned getRadialCellsNumber(){return m_radialMeshNumber;}
	unsigned getVerticalCellsNumber(){return m_verticalMeshNumber;}
	unsigned getCellsNumber(){return m_meshNumber;}
	Eigen::VectorXd getVolumes(std::string dim);
	Eigen::VectorXd getSurfaces(std::string dim);
	double getRadialExternalSurface(std::string dim);
	void setEnergyGroupsNumber(unsigned n);
	unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}

	void createMaterials(std::vector<std::string> materialMap);
	std::vector< std::shared_ptr<Material> > getMaterials() {return m_materials;}
	std::shared_ptr<Material> getMaterial(unsigned i) {return m_materials.at(i);}
	Eigen::VectorXd getRadialMeshMiddlePoints();

	void setTemperatures(std::vector<double> &temperatures);
	void setTemperatures(Eigen::VectorXd &temperatures);
	Eigen::VectorXd getTemperatures(std::string dim);

	void setHeatSources(const Eigen::VectorXd &sources);
	void setHeatSources(std::vector<double> &sources);
	Eigen::VectorXd getHeatSources();

	void setThermalConductivityLaw(unsigned i, std::vector<std::string> &strVec);
	Eigen::VectorXd getThermalConductivities();

    void setNeutronFluxes(Eigen::MatrixXd &neutronFluxes);
	Eigen::MatrixXd getNeutronFluxes();

	Eigen::MatrixXd getChis();
	Eigen::MatrixXd getNis();
	Eigen::MatrixXd getFissionXSs();
	Eigen::MatrixXd getTotalXSs();
	Eigen::MatrixXd getDiffusionConstants();
	Eigen::MatrixXd getRemovalXSs();
	Numerics::Tensor3d getScattMatrices();
	
private:
	Eigen::VectorXd m_radialBoundaries;
	Eigen::VectorXd m_verticalBoundaries;
	std::shared_ptr<AbstractGeometry> pm_abGeom;
	GeomKind m_mode;
	unsigned m_radialMeshNumber;
	unsigned m_verticalMeshNumber;
	unsigned m_meshNumber;
	unsigned m_energyGroupsNumber;
	Eigen::VectorXd m_heatBoundaryConditions;
    std::vector< std::shared_ptr<Material> > m_materials;
};

#endif