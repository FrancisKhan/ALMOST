#include "CrossSectionMatrixSet.h"
#include "additionalPrintFuncs.h"

using namespace Numerics;

CrossSectionMatrix CrossSectionMatrixSet::getXSMatrix(double t, double b)
{
    std::vector<CrossSectionMatrix>::iterator it = std::find_if(m_XSSet.begin(), m_XSSet.end(), 
    [t, b] (CrossSectionMatrix &c) 
    {return Numerics::is_equal(c.getTemperature(), t) && Numerics::is_equal(c.getBackgroundXS(), b);});

    if (it != m_XSSet.end())
        return *it;
    else
        return CrossSectionMatrix {};
}

CrossSectionMatrix CrossSectionMatrixSet::getXSMatrix(unsigned i)
{
    if(!m_XSSet.empty())
        return m_XSSet.at(i);
    else
        return CrossSectionMatrix {};
}

// void CrossSectionMatrixSet::calcXS() 
// {
// }