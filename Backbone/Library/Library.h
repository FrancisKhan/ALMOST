#ifndef LIBRARY_H
#define LIBRARY_H

#include "KineticsSet.h"

class Library
{
public:
	Library(){}

	void setKineticsSet(KineticsSet &kineticsSet) 
	{m_kineticsSet = kineticsSet;}

    KineticsSet getKineticsSet() {return m_kineticsSet;}

	//void setMatProperties(std::vector<MaterialKind> &matProperties);
	//std::vector< std::shared_ptr<AbstractMaterial> > getMatProperties() {return m_matProperties;};
	
private:
	//std::vector< std::shared_ptr<AbstractMaterial> > m_matProperties;
	KineticsSet m_kineticsSet;
};

#endif