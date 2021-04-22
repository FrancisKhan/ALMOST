#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"



CrossSectionSet Nuclide::populateXS(CrossSectionSet &xsSet) 
{
    CrossSectionSet crossSectionSet(xsSet.getKind());

    for(size_t i = 0; i < getXSsNumber(); i++)
    {
        size_t inputSize = xsSet.getXS(i).getSize(); 

        if (inputSize < getEnergyGroupsNumber())
        {
            std::vector<double> xsVec(getEnergyGroupsNumber() - inputSize, 0.0);
            std::vector<double> xsInputVec(xsSet.getXS(i).getValues());

            xsVec.insert(xsVec.end(), xsInputVec.begin(), xsInputVec.end()); 
            CrossSection crossSection(xsSet.getXS(i).getTemperature(), xsSet.getXS(i).getBackgroundXS(), xsVec);
            crossSectionSet.addXS(crossSection);
        }
        else if(inputSize == getEnergyGroupsNumber())
        {
            std::vector<double> xsVec = xsSet.getXS(i).getValues();
            CrossSection crossSection(xsSet.getXS(i).getTemperature(), xsSet.getXS(i).getBackgroundXS(), xsVec);
            crossSectionSet.addXS(crossSection);
        }
        else
        {
            out.print(TraceLevel::CRITICAL, "Error {} read in the XS library!", int(inputSize));
            exit(-1);
        }
    }

    return crossSectionSet;
}

void Nuclide::setXS(CrossSectionSet &xsSet) 
{
    switch(xsSet.getKind()) 
    {
        case XSKind::NTOT0:
            setEnergyGroupsNumber(xsSet.getXS(0).getSize());
            m_totXS = populateXS(xsSet);
            m_totXS.calcXS();
            break;
        case XSKind::NINEL:
            m_inelasticXS = populateXS(xsSet);
            m_inelasticXS.calcXS();
            break;
        case XSKind::N2N:
            m_n2nXS = populateXS(xsSet);
            m_n2nXS.calcXS();
            break;
        case XSKind::N3N:
            m_n3nXS = populateXS(xsSet);
            m_n3nXS.calcXS();
            break;
        case XSKind::NNP:
            m_nnpXS = populateXS(xsSet);
            m_nnpXS.calcXS();
            break;
        case XSKind::NG:
            m_ngXS = populateXS(xsSet);
            m_ngXS.calcXS();
            break;
        case XSKind::NP:
            m_npXS = populateXS(xsSet);
            m_npXS.calcXS();
            break;
        case XSKind::ND:
            m_ndXS = populateXS(xsSet);
            m_ndXS.calcXS();
            break;
        case XSKind::NT:
            m_ntXS = populateXS(xsSet);
            m_ntXS.calcXS();
            break;
        case XSKind::NA:
            m_naXS = populateXS(xsSet);
            m_naXS.calcXS();
            break;
        default:
            out.print(TraceLevel::CRITICAL, "Error {} XS not recognized!", get_name(xsSet.getKind()));
            exit(-1);
    }
}

void Nuclide::setXSMatrix(CrossSectionMatrixSet &xsMatrixSet) 
{
    switch(xsMatrixSet.getKind()) 
    {
        case XSMatrixKind::SCAT00:
            m_scattMatrix00 = xsMatrixSet;
            break;
        case XSMatrixKind::SCAT01:
            m_scattMatrix01 = xsMatrixSet;
            break;
        default:
            out.print(TraceLevel::CRITICAL, "Error {} XS matrix not recognized!", get_name(xsMatrixSet.getKind()));
            exit(-1);
    }
}

CrossSectionSet Nuclide::getXSSet(XSKind kind) 
{
    switch(kind) 
    {
        case XSKind::NTOT0:  return m_totXS;
        case XSKind::NINEL:  return m_inelasticXS;
        case XSKind::N2N:    return m_n2nXS;
        case XSKind::N3N:    return m_n3nXS;
        case XSKind::NNP:    return m_nnpXS;
        case XSKind::NG:     return m_ngXS;
        case XSKind::NP:     return m_npXS;
        case XSKind::ND:     return m_ndXS;
        case XSKind::NT:     return m_ntXS;
        case XSKind::NA:     return m_naXS;
        default: return CrossSectionSet {};
    }
}

CrossSectionMatrixSet Nuclide::getXSMatrixSet(XSMatrixKind kind) 
{
    switch(kind) 
    {
        case XSMatrixKind::SCAT00:  return m_scattMatrix00;
        case XSMatrixKind::SCAT01:  return m_scattMatrix01;
        default: return CrossSectionMatrixSet {};
    }
}

void Nuclide::printXSs(XSKind xsKind)
{
    for(size_t i = 0; i < getXSsNumber(); i++)
    {
        out.print(TraceLevel::CRITICAL, "{} XS: {}",  get_name(xsKind), getXSSet(xsKind).getXS(0).getSize());
        out.print(TraceLevel::CRITICAL, "Temperature: {}, Background XS: {}", 
        getXSSet(xsKind).getXS(i).getTemperature(), getXSSet(xsKind).getXS(i).getBackgroundXS());

        PrintFuncs::printVector(getXSSet(xsKind).getXS(i).getValues(), out, TraceLevel::CRITICAL);
    }
}

void Nuclide::printMatrixXSs(XSMatrixKind xsKind)
{
    for(size_t i = 0; i < getXSsNumber(); i++)
    {
        out.print(TraceLevel::CRITICAL, "{} XS Matrix: {}",  get_name(xsKind), getXSMatrixSet(xsKind).getXSMatrix(0).getSize());
        out.print(TraceLevel::CRITICAL, "Temperature: {}, Background XS: {}", 
        getXSMatrixSet(xsKind).getXSMatrix(i).getTemperature(), getXSMatrixSet(xsKind).getXSMatrix(i).getBackgroundXS());

        PrintFuncs::printMatrix(getXSMatrixSet(xsKind).getXSMatrix(i).getValues(), out, TraceLevel::CRITICAL);
    }
}

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Is nuclide resonant: {}", isResonant());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    out.print(TraceLevel::CRITICAL, "getXSsNumber(): {}", int(getXSsNumber()));
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    // for (const auto& xsKind : XSKind())
    //     printXSs(xsKind);

    for (const auto& xsKind : XSMatrixKind())
        printMatrixXSs(xsKind);
}