#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);

    out.print(TraceLevel::CRITICAL, "Total XS:");
    for(size_t i = 0; i < m_temperatures.size(); i++)
    {
        out.print(TraceLevel::CRITICAL, "Temperature: {}", m_totXS[i].first);
        PrintFuncs::printVector(m_totXS[i].second, out, TraceLevel::CRITICAL);
    }
}