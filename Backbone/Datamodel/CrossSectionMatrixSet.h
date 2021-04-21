#ifndef CROSSSECTIONMATRIXSET_H
#define CROSSSECTIONMATRIXSET_H

#include "CrossSectionMatrix.h"
#include "XSMatrixKind.h"

class CrossSectionMatrixSet
{
public:
    CrossSectionMatrixSet() {}
	CrossSectionMatrixSet(XSMatrixKind xsKind) : m_kind(xsKind) {}

    void addXS(CrossSectionMatrix &xs) {m_XSSet.push_back(xs);}
    void setXS(unsigned i, CrossSectionMatrix &xs) {m_XSSet[i] = xs;}
    CrossSectionMatrix getXSMatrix(unsigned i) {return m_XSSet.at(i);}
    CrossSectionMatrix getXSMatrix(double t, double b);
    unsigned getSize() {return m_XSSet.size();}
    XSMatrixKind getKind() {return m_kind;}
    //void calcXS();

private:
    XSMatrixKind m_kind;
    std::vector<CrossSectionMatrix> m_XSSet;
};

#endif