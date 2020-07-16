#ifndef REACTOR_H
#define REACTOR_H

#include "numeric_tools.h"
#include "KineticsSet.h"
#include "Mesh.h"

#include <vector>
#include <string>

class Reactor
{
public:
	Reactor() {}
	void setKineticsSet(KineticsSet &kineticsSet) 
	{m_kineticsSet = kineticsSet;}

    KineticsSet getKineticsSet() {return m_kineticsSet;}

    void setKFactor(double kFactor) {m_kFactor = kFactor;}
	double getKFactor() {return m_kFactor;}

	Mesh& getMesh() {return m_mesh;}

private:
	KineticsSet m_kineticsSet;
	Mesh m_mesh;
	double m_kFactor;
};

#endif