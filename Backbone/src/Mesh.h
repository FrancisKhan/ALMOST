#ifndef MESH_H
#define MESH_H

#include "GeomKind.h"
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
	unsigned getCellsNumber(){return m_meshNumber;}
	Eigen::VectorXd getVolumes(std::string dim);
	double getSurface(std::string dim);
	void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
	unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}
	void setAlbedo(double albedo){m_albedo = albedo;}
	double getAlbedo(){return m_albedo;}
	void setMaterials(){};

	void setTemperatures(std::vector<double> &temperatures);
	Eigen::VectorXd getTemperatures(std::string dim);

	void setHeatSources(std::vector<double> &sources);
	Eigen::VectorXd getHeatSources(){return m_heatSources;}

	void setHeatBoundaryConditions(std::vector<double> &boundaries);
	Eigen::VectorXd getHeatBoundaryConditions(){return m_heatBoundaryConditions;}
	
private:
	Eigen::VectorXd m_boundaries;
	std::shared_ptr<AbstractGeometry> pm_abGeom;
	GeomKind m_mode;
	unsigned m_meshNumber;
	unsigned m_energyGroupsNumber;
	double m_albedo;
	Eigen::VectorXd m_temperatures;
	Eigen::VectorXd m_heatSources;
	Eigen::VectorXd m_heatBoundaryConditions;
};

#endif