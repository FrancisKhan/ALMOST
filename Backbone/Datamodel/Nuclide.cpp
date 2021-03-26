#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

XSSetType Nuclide::populateXS(XSSetType &xs) 
{
    XSSetType result;

    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        size_t inputSize = xs[i].getSize(); 

        if (inputSize < getEnergyGroupsNumber())
        {
            std::vector<double> xsVec(getEnergyGroupsNumber() - inputSize, 0.0);
            std::vector<double> xsInputVec(xs[i].getValues());

            xsVec.insert(xsVec.end(), xsInputVec.begin(), xsInputVec.end()); 
            CrossSection crossSection(xs[i].getTemperature(), 0.0, xsVec);
            result.push_back(crossSection);
        }
        else if(inputSize == getEnergyGroupsNumber())
        {
            std::vector<double> xsVec = xs[i].getValues();
            CrossSection crossSection(xs[i].getTemperature(), 0.0, xsVec);
            result.push_back(crossSection);
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} read in the XS library!", int(inputSize));
        }
    }

    return result;
}

void Nuclide::setXS(XSKind kind, XSSetType &xs) 
{
    switch(kind) 
    {
        case XSKind::NTOT0:
            m_totXS = xs;
            setEnergyGroupsNumber(m_totXS[0].getSize());
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

XSSetType Nuclide::getXS(XSKind kind) 
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
        default: return XSSetType {};
    }
}

std::vector<double> Nuclide::getXS(XSKind kind, unsigned tempIndex) 
{
    XSSetType selectedXS = getXS(kind);

    auto it = std::find_if(selectedXS.begin(), selectedXS.end(), 
        [this, tempIndex] (auto& c) {return c.getTemperature() == getTemperature(tempIndex);});

    if(it != selectedXS.end())
        return it->getValues();
    else
        return std::vector<double> {};
}

double Nuclide::getXSTemp(XSKind kind, unsigned tempIndex) 
{
    XSSetType selectedXS = getXS(kind);

    auto it = std::find_if(selectedXS.begin(), selectedXS.end(), 
        [this, tempIndex] (auto& c) {return c.getTemperature() == getTemperature(tempIndex);});

    if(it != selectedXS.end())
        return it->getTemperature();
    else
        return 0.0;
}

void Nuclide::printXS(XSKind xsKind)
{
    out.print(TraceLevel::CRITICAL, "{} XS: {}", get_name(xsKind), int(getXS(xsKind, 0).size()));
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", getXSTemp(xsKind, i));
        PrintFuncs::printVector(getXS(xsKind, i), out, TraceLevel::CRITICAL);
    }
}

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    for (const auto& xsKind : XSKind())
        printXS(xsKind);
}