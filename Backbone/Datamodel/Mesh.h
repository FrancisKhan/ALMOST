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
	Mesh() : pm_abGeom(nullptr), m_nModes(1) {}
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
	void setEnergyGroupsNumber(unsigned n);
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

    void setNeutronFluxes(Numerics::Tensor3d& neutronFluxes);
	Numerics::Tensor3d getNeutronFluxes();
	Eigen::MatrixXd getFundamentalNeutronFluxes();

	void setAdjointFluxes(Numerics::Tensor3d& adjointFluxes);
	Numerics::Tensor3d getAdjointFluxes();
	Eigen::MatrixXd getFundamentalAdjointFluxes();

	void setExternaSourceDistribution(int cell);
	Eigen::VectorXd getExternaSourceDistribution() {return m_extSourceDistribution;}

	Eigen::MatrixXd getChis();
	Eigen::MatrixXd getNis();
	Eigen::MatrixXd getFissionXSs();
	Eigen::MatrixXd getTotalXSs();
	Eigen::MatrixXd getDiffusionConstants();
	Eigen::MatrixXd getRemovalXSs();
	Numerics::Tensor3d getScattMatrices();

	void setExtSource(std::pair<double, int>& source);
    Eigen::VectorXd getExtSourceDistribution() {return m_extSourceDistribution;}

	void setEigenmodesNumber(unsigned nModes) {m_nModes = nModes;}
    unsigned getEigenmodesNumber() {return m_nModes;}
	
private:
	Eigen::VectorXd m_boundaries;
	std::shared_ptr<AbstractGeometry> pm_abGeom;
	GeomKind m_mode;
	unsigned m_meshNumber;
	unsigned m_energyGroupsNumber;
	Eigen::VectorXd m_heatBoundaryConditions;
    std::vector< std::shared_ptr<Material> > m_materials;
	Eigen::VectorXd m_extSourceDistribution;
	unsigned m_nModes;
};

#endif