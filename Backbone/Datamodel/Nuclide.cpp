#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

void Nuclide::setTotalXS(XSType &xs) 
{
    m_totXS = xs;
    setEnergyGroupsNumber(m_totXS[0].second.size());
}

XSType Nuclide::setXS(XSType &xs) 
{
    XSType result;

    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        size_t inputSize = xs[i].second.size(); 

        if (inputSize < getEnergyGroupsNumber())
        {
            std::vector<double> xsVec(getEnergyGroupsNumber() - inputSize, 0.0);
            xsVec.insert(xsVec.end(), xs[i].second.begin(), xs[i].second.end()); 
            result.push_back(std::make_pair(xs[i].first, xsVec));
        }
        else if(inputSize == getEnergyGroupsNumber())
        {
            result.push_back(std::make_pair(xs[i].first, xs[i].second));
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} read in the XS library!", int(inputSize));
        }
    }

    return result;
}

void Nuclide::setInelasticXS(XSType &xs) 
{
    m_inelasticXS = setXS(xs);
}

void Nuclide::setN2nXS(XSType &xs) 
{
    m_n2nXS = setXS(xs);
}

void Nuclide::setN3nXS(XSType &xs) 
{
    m_n3nXS = setXS(xs);
}

void Nuclide::setNnpXS(XSType &xs) 
{
    m_nnpXS = setXS(xs);
}

void Nuclide::setNgXS(XSType &xs) 
{
    m_ngXS = setXS(xs);
}

void Nuclide::setNpXS(XSType &xs) 
{
    m_npXS = setXS(xs);
}

void Nuclide::setNdXS(XSType &xs) 
{
    m_ndXS = setXS(xs);
}

void Nuclide::setNtXS(XSType &xs) 
{
    m_ntXS = setXS(xs);
}

void Nuclide::setNaXS(XSType &xs) 
{
    m_naXS = setXS(xs);
}

void Nuclide::setScattXS(XSType &xs) 
{
    m_scattXS = setXS(xs);
}

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    // out.print(TraceLevel::CRITICAL, "Total XS: {}", int(m_totXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_totXS[i].first);
    //     PrintFuncs::printVector(m_totXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nElastic XS: {}", int(m_elasticXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_elasticXS[i].first);
    //     PrintFuncs::printVector(m_elasticXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nInelastic XS: {}", int(m_inelasticXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_inelasticXS[i].first);
    //     PrintFuncs::printVector(m_inelasticXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nn2n XS: {}", int(m_n2nXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_n2nXS[i].first);
    //     PrintFuncs::printVector(m_n2nXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nn3n XS: {}", int(m_n3nXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_n3nXS[i].first);
    //     PrintFuncs::printVector(m_n3nXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nnnp XS: {}", int(m_nnpXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_nnpXS[i].first);
    //     PrintFuncs::printVector(m_nnpXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nng XS: {}", int(m_ngXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ngXS[i].first);
    //     PrintFuncs::printVector(m_ngXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nnp XS: {}", int(m_npXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_npXS[i].first);
    //     PrintFuncs::printVector(m_npXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nnd XS: {}", int(m_ndXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ndXS[i].first);
    //     PrintFuncs::printVector(m_ndXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nnt XS: {}", int(m_ntXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ntXS[i].first);
    //     PrintFuncs::printVector(m_ntXS[i].second, out, TraceLevel::CRITICAL);
    // }

    // out.print(TraceLevel::CRITICAL, "\n\nna XS: {}", int(m_naXS[0].second.size()));
    // for(size_t i = 0; i < m_temperatures.size(); i++)
    // {
    //     out.print(TraceLevel::CRITICAL, "Temperature: {}", m_naXS[i].first);
    //     PrintFuncs::printVector(m_naXS[i].second, out, TraceLevel::CRITICAL);
    // }

    out.print(TraceLevel::CRITICAL, "\n\nscatt XS: {}", int(m_scattXS[0].second.size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_scattXS[i].first);
        PrintFuncs::printVector(m_scattXS[i].second, out, TraceLevel::CRITICAL);
    }
}