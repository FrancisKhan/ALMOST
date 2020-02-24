#ifndef LIBRARY_H
#define LIBRARY_H

#include "CrossSectionSet.h"

class Library
{
public:
	Library(){}
	void setCrossSectionSet(CrossSectionSet &crossSectionSet) 
	{m_crossSectionSet = crossSectionSet;}
	
	CrossSectionSet getCrossSectionSet() {return m_crossSectionSet;}
	
private:
	CrossSectionSet m_crossSectionSet;
};

#endif