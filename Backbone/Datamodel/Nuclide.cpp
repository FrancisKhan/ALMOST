#include "Nuclide.h"
#include "Output.h"
#include "additionalPrintFuncs.h"

void Nuclide::printDebugData()
{
    out.print(TraceLevel::CRITICAL, "Nuclide name: {}", getName());
    out.print(TraceLevel::CRITICAL, "Nuclide AWR: {}", getAWR());
    out.print(TraceLevel::CRITICAL, "Temperatures:");
    PrintFuncs::printVector(getTemperatures(), out, TraceLevel::CRITICAL);
}