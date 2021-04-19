#ifndef CROSSSECTIONSET_H
#define CROSSSECTIONSET_H

#include "CrossSection.h"
#include "XSMatrixKind.h"
#include "XSKind.h"

#include <vector>

class CrossSectionSet
{
public:
    CrossSectionSet() {}
	CrossSectionSet(XSKind xsKind) : m_kind(xsKind) {}

    void addXS(CrossSection &xs) {m_XSSet.push_back(xs);}
    void setXS(unsigned i, CrossSection &xs) {m_XSSet[i] = xs;}
    CrossSection getXS(unsigned i) {return m_XSSet.at(i);}
    CrossSection getXS(double t, double b);
    unsigned getSize() {return m_XSSet.size();}
    XSKind getKind() {return m_kind;}
    void calcXS();

private:
    XSKind m_kind;
    std::vector<CrossSection> m_XSSet;
};

#endif