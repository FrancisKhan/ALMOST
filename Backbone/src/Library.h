#ifndef LIBRARY_H
#define LIBRARY_H

#include "KineticsSet.h"
#include "CrossSectionSet.h"
#include "AbstractMaterial.h"

class Library
{
public:
	Library(){}
	void setCrossSectionSet(CrossSectionSet &crossSectionSet) 
	{m_crossSectionSet = crossSectionSet;}

	CrossSectionSet getCrossSectionSet() {return m_crossSectionSet;}

	void setKineticsSet(KineticsSet &kineticsSet) 
	{m_kineticsSet = kineticsSet;}

    KineticsSet getKineticsSet() {return m_kineticsSet;}

	void setMatProperties(std::vector<MaterialKind> &matProperties);
	
private:
	CrossSectionSet m_crossSectionSet;
	KineticsSet m_kineticsSet;
};

#endif