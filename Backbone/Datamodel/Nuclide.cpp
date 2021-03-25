#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

XSType Nuclide::populateXS(XSType &xs) 
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

void Nuclide::setXS(XSKind kind, XSType &xs) 
{
    switch(kind) 
    {
        case XSKind::NTOT0:
            m_totXS = xs;
            setEnergyGroupsNumber(m_totXS[0].second.size());
            break;
        case XSKind::NELAS:
            m_elasticXS = populateXS(xs);
            break;
        case XSKind::NINEL:
            m_inelasticXS = populateXS(xs);
            break;
        case XSKind::N2N:
            m_n2nXS = populateXS(xs);
            break;
        case XSKind::N3N:
            m_n3nXS = populateXS(xs);
            break;
        case XSKind::NNP:
            m_nnpXS = populateXS(xs);
            break;
        case XSKind::NG:
            m_ngXS = populateXS(xs);
            break;
        case XSKind::NP:
            m_npXS = populateXS(xs);
            break;
        case XSKind::ND:
            m_ndXS = populateXS(xs);
            break;
        case XSKind::NT:
            m_ntXS = populateXS(xs);
            break;
        case XSKind::NA:
            m_naXS = populateXS(xs);
            break;
        case XSKind::SCAT00:
            m_scattXS = populateXS(xs);
            break;
        default:
            out.print(TraceLevel::CRITICAL, "Error {} XS not recognized!", get_name(kind));
            exit(-1);
    }
    
}

XSType Nuclide::getXS(XSKind kind) 
{
    switch(kind) 
    {
        case XSKind::NTOT0:  return m_totXS;
        case XSKind::NELAS:  return m_elasticXS;
        case XSKind::NINEL:  return m_inelasticXS;
        case XSKind::N2N:    return m_n2nXS;
        case XSKind::N3N:    return m_n3nXS;
        case XSKind::NNP:    return m_nnpXS;
        case XSKind::NG:     return m_ngXS;
        case XSKind::NP:     return m_npXS;
        case XSKind::ND:     return m_ndXS;
        case XSKind::NT:     return m_ntXS;
        case XSKind::NA:     return m_naXS;
        case XSKind::SCAT00: return m_scattXS;
        default: return XSType {};
    }
}

std::vector<double> Nuclide::getXS(XSKind kind, unsigned tempIndex) 
{
    XSType selectedXS = getXS(kind);

    auto it = std::find_if(selectedXS.begin(), selectedXS.end(), 
        [this, tempIndex] (const auto& p) {return p.first == getTemperatures()[tempIndex];});

    if(it != selectedXS.end())
        return it->second;
    else
        return std::vector<double> {};
}

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    out.print(TraceLevel::CRITICAL, "Total XS: {}", int(getXS(XSKind::NTOT0, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_totXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NTOT0, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nElastic XS: {}", int(getXS(XSKind::NELAS, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_elasticXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NELAS, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nInelastic XS: {}", int(getXS(XSKind::NINEL, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_inelasticXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NINEL, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nn2n XS: {}", int(getXS(XSKind::N2N, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_n2nXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::N2N, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nn3n XS: {}", int(getXS(XSKind::N3N, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_n3nXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::N3N, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nnnp XS: {}", int(getXS(XSKind::NNP, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_nnpXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NNP, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nng XS: {}", int(getXS(XSKind::NG, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ngXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NG, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nnp XS: {}", int(getXS(XSKind::NP, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_npXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NP, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nnd XS: {}", int(getXS(XSKind::ND, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ndXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::ND, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nnt XS: {}", int(getXS(XSKind::NT, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_ntXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NT, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nna XS: {}", int(getXS(XSKind::NA, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_naXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::NA, i), out, TraceLevel::CRITICAL);
    }

    out.print(TraceLevel::CRITICAL, "\n\nscatt XS: {}", int(getXS(XSKind::SCAT00, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_scattXS[i].first);
        PrintFuncs::printVector(getXS(XSKind::SCAT00, i), out, TraceLevel::CRITICAL);
    }
}