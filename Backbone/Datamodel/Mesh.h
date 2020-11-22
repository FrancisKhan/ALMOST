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
	void setBoundaries(Eigen::VectorXd &boundaries);
	void setBoundaries(double meshes, unsigned meshNumber);
	Eigen::VectorXd getBoundaries(std::string dim);
	Eigen::VectorXd getCellSizes(std::string dim);
	unsigned getCellsNumber(){return m_meshNumber;}
	Eigen::VectorXd getVolumes(std::string dim);
	Eigen::VectorXd getSurfaces(std::string dim);
	double getExternalSurface(std::string dim);
	void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
	unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}

	void createMaterials(std::vector<std::string> materialMap);
	std::vector< std::shared_ptr<Material> > getMaterials() {return m_materials;}
	std::shared_ptr<Material> getMaterial(unsigned i) {return m_materials.at(i);}
	Eigen::VectorXd getMeshMiddlePoints();

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

    void setScattMatrices(Numerics::Tensor3d &scattMatrices);

	Eigen::MatrixXd getChis();
	Eigen::MatrixXd getNis();
	Eigen::MatrixXd getFissionXSs();
	Eigen::MatrixXd getTotalXSs();
	Eigen::MatrixXd getAbsXSs();
	Eigen::MatrixXd getDiffusionConstants();
	Eigen::MatrixXd getRemovalXSs();
	Numerics::Tensor3d getScattMatrices();
	
private:
	Eigen::VectorXd m_boundaries;
	std::shared_ptr<AbstractGeometry> pm_abGeom;
	GeomKind m_mode;
	unsigned m_meshNumber;
	unsigned m_energyGroupsNumber;
	Eigen::VectorXd m_heatBoundaryConditions;
    std::vector< std::shared_ptr<Material> > m_materials;
};

#endif