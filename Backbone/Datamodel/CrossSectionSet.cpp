#include "CrossSectionSet.h"
#include "numeric_tools.h"
#include "additionalPrintFuncs.h"

using namespace Numerics;

#include <algorithm>

CrossSection CrossSectionSet::getXS(double t, double b)
{
    std::vector<CrossSection>::iterator it = std::find_if(m_XSSet.begin(), m_XSSet.end(), 
    [t, b] (CrossSection &c) 
    {return Numerics::is_equal(c.getTemperature(), t) && Numerics::is_equal(c.getBackgroundXS(), b);});

    if (it != m_XSSet.end())
        return *it;
    else
        return CrossSection {};
}

void CrossSectionSet::calcXS() 
{
    for(unsigned i = 0; i < getSize(); i++)
    {
        double sigma0 = getXS(i).getBackgroundXS();
        double temp   = getXS(i).getTemperature();

        if(not_equal(sigma0, DINF))
        {
            std::vector<double> infValues = getXS(temp, DINF).getValues();
            std::vector<double> dilValues = getXS(i).getValues();
            std::vector<double> newValues = infValues + dilValues;

            auto it = std::find_if(newValues.begin(), newValues.end(), [] (auto &v) {return is_lower(v, 0.0);});
            if (it != newValues.end())
            {
                out.print(TraceLevel::CRITICAL, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
                out.print(TraceLevel::CRITICAL, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
                out.print(TraceLevel::CRITICAL, "XS kind: {}", get_name(getKind()));
                out.print(TraceLevel::CRITICAL, "Temperature: {}", temp);
                out.print(TraceLevel::CRITICAL, "Background XS: {}", sigma0);

                out.print(TraceLevel::CRITICAL, "\nInfinite XS:");
                PrintFuncs::printVector(infValues, out, TraceLevel::CRITICAL);

                out.print(TraceLevel::CRITICAL, "Diluted XS:");
                PrintFuncs::printVector(dilValues, out, TraceLevel::CRITICAL);

                out.print(TraceLevel::CRITICAL, "New XS:");
                PrintFuncs::printVector(newValues, out, TraceLevel::CRITICAL);

                exit(-1);
            }

            CrossSection xs(temp, sigma0, newValues);
            setXS(i, xs);
        }
    }
}