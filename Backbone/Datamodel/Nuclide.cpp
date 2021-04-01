#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

CrossSectionSet Nuclide::populateXS(XSKind xsKind, CrossSectionSet &xsSet) 
{
    CrossSectionSet crossSectionSet(xsKind);

    //for(size_t i = 0; i < m_temperatures.size(); i++)
    for(size_t i = 0; i < 1; i++)
    {
        size_t inputSize = xsSet.getXS(i).getSize(); 

        if (inputSize < getEnergyGroupsNumber())
        {
            std::vector<double> xsVec(getEnergyGroupsNumber() - inputSize, 0.0);
            std::vector<double> xsInputVec(xsSet.getXS(i).getValues());

            xsVec.insert(xsVec.end(), xsInputVec.begin(), xsInputVec.end()); 
            CrossSection crossSection(xsSet.getXS(i).getTemperature(), 0.0, xsVec);
            crossSectionSet.addXS(crossSection);
        }
        else if(inputSize == getEnergyGroupsNumber())
        {
            std::vector<double> xsVec = xsSet.getXS(i).getValues();
            CrossSection crossSection(xsSet.getXS(i).getTemperature(), 0.0, xsVec);
            crossSectionSet.addXS(crossSection);
        }
        else
        {
            //out.print(TraceLevel::CRITICAL, "Error {} read in the XS library!", int(inputSize));
            std::vector<double> xsVec = xsSet.getXS(i).getValues();
            CrossSection crossSection(xsSet.getXS(i).getTemperature(), 0.0, xsVec);
            crossSectionSet.addXS(crossSection);
        }
    }

    return crossSectionSet;
}

void Nuclide::setXS(XSKind kind, CrossSectionSet &xsSet) 
{
    switch(kind) 
    {
        case XSKind::NTOT0:
            setEnergyGroupsNumber(xsSet.getXS(0).getSize());
            m_totXS = populateXS(kind, xsSet);
            break;
        case XSKind::NELAS:
            m_elasticXS = populateXS(kind, xsSet);
            break;
        case XSKind::NINEL:
            m_inelasticXS = populateXS(kind, xsSet);
            break;
        case XSKind::N2N:
            m_n2nXS = populateXS(kind, xsSet);
            break;
        case XSKind::N3N:
            m_n3nXS = populateXS(kind, xsSet);
            break;
        case XSKind::NNP:
            m_nnpXS = populateXS(kind, xsSet);
            break;
        case XSKind::NG:
            m_ngXS = populateXS(kind, xsSet);
            break;
        case XSKind::NP:
            m_npXS = populateXS(kind, xsSet);
            break;
        case XSKind::ND:
            m_ndXS = populateXS(kind, xsSet);
            break;
        case XSKind::NT:
            m_ntXS = populateXS(kind, xsSet);
            break;
        case XSKind::NA:
            m_naXS = populateXS(kind, xsSet);
            break;
        case XSKind::SCAT00:
            m_scattXS = populateXS(kind, xsSet);
            break;
        default:
            out.print(TraceLevel::CRITICAL, "Error {} XS not recognized!", get_name(kind));
            exit(-1);
    }
    
}

CrossSectionSet Nuclide::getXSSet(XSKind kind) 
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
        default: return CrossSectionSet {};
    }
}

void Nuclide::printXSs(XSKind xsKind)
{
    out.print(TraceLevel::CRITICAL, "{} XS: {}",  get_name(xsKind), getXSSet(xsKind).getXS(0).getSize());
    //for(size_t i = 0; i < m_temperatures.size(); i++)
    for(size_t i = 0; i < 1; i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", getXSSet(xsKind).getXS(i).getTemperature());
        PrintFuncs::printVector(getXSSet(xsKind).getXS(i).getValues(), out, TraceLevel::CRITICAL);
    }
}

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Is nuclide resonant: {}", isResonant());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    for (const auto& xsKind : XSKind())
        printXSs(xsKind);
}