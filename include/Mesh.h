#ifndef MESH_H
#define MESH_H

#include "GeomKind.h"
#include "AbstractGeometry.h"

#include <vector>

class Mesh
{
public:
	Mesh() : pm_abGeom(nullptr){}
	void setMeshKind(GeomKind kind);
	GeomKind getGeometry() {return m_mode;}
	void setBoundaries(std::vector<double> &boundaries);
	void setBoundaries(double meshes, int meshNumber);
	std::vector<double> getBoundaries(){return m_boundaries;}
	int getCellsNumber(){return (int)m_boundaries.size() - 1;}
	void calcVolumes();
	std::vector<double> getVolumes(){return m_volumes;}
	void calcSurface();
	double getSurface(){return m_surface;}
	void setEnergyGroupsNumber(int n) {m_energyGroupsNumber = n;}
	int getEnergyGroupsNumber() {return m_energyGroupsNumber;}
	void setMaterials(){};
	
private:
	std::vector<double> m_boundaries;
	std::vector<double> m_volumes;
	double m_surface;
	AbstractGeometry *pm_abGeom;
	GeomKind m_mode;
	int m_meshNumber;
	int m_energyGroupsNumber;
};

#endif