#include "CrossSectionMatrixSet.h"
#include "additionalPrintFuncs.h"

using namespace Numerics;

void CrossSectionMatrixSet::calcXS() 
{
    for(unsigned i = 0; i < getSize(); i++)
    {
        double sigma0 = getXSMatrix(i).getBackgroundXS();
        double temp   = getXSMatrix(i).getTemperature();

        if(not_equal(sigma0, DINF))
        {
            Eigen::MatrixXd infValues = getXSMatrix(temp, DINF).getValues();
            Eigen::MatrixXd dilValues = getXSMatrix(i).getValues();
            Eigen::MatrixXd newValues = infValues + dilValues;

            //debugCalcXS(newValues, infValues, dilValues, temp, sigma0);

            CrossSectionMatrix matrix(temp, sigma0, newValues);
            setXS(i, matrix);
        }
    }
}

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