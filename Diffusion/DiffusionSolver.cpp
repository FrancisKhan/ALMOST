#include "BaseDiffusionCode.h"
#include "DiffusionCodeFactory.h"
#include "DiffusionSolver.h"

#include <iostream>

using namespace Eigen;
using namespace PrintFuncs;

void DiffusionSolver::solve()
{
    std::shared_ptr<BaseDiffusionCode> heatCode = DiffusionCodeFactory::setDiffusionCode(m_reactor, m_library);

    m_oldTemperatures = m_mesh.getTemperatures("C");

    VectorXd oldTemps = VectorXd::Ones(m_mesh.getCellsNumber());
    VectorXd newTemps = VectorXd::Zero(m_mesh.getCellsNumber());

    int i;
    
    for(i = 0; i < m_solverData.getMaxIterNumber(); i++)
    {
        auto [T, source]   = heatCode->setupSystem();	
        auto [Tb, sourceb] = heatCode->applyBoundaryConditions(T, source);
        heatCode->solveSystem(Tb, sourceb);

        newTemps = m_mesh.getTemperatures("C");

        out.print(TraceLevel::DEBUG, "within solver temperatures [C]:");
        printVector(m_mesh.getMeshMiddlePoints(), out, TraceLevel::DEBUG);

        // max difference between new and old temperatures
        double maxValue = 0.0;
        for(int i = 0; i < newTemps.size(); i++)
        {
           double diff = fabs(newTemps(i) - oldTemps(i));
           if (diff > maxValue) maxValue = diff;
        }

        // exit condition
		if (maxValue < m_solverData.getAccuracy()) break;

        oldTemps = newTemps;
    }

    out.print(TraceLevel::DEBUG, "Number of heat iteration: {}", i + 1);

    if(i + 1 > m_solverData.getMaxIterNumber())
	{
		out.print(TraceLevel::CRITICAL, "Number of heat iteration: {}", i + 1);
		out.print(TraceLevel::CRITICAL, "The heat calculation did not converge!");
		exit(-1);
	}
}

void DiffusionSolver::relaxResults(double param)
{
    VectorXd relaxedTemps = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newTemps = m_mesh.getTemperatures("C");

    relaxedTemps = newTemps * param + m_oldTemperatures * (1.0 - param);

    m_mesh.setTemperatures(relaxedTemps);

    out.print(TraceLevel::INFO, "Relaxed temperatures [C]:");
    printVector(m_mesh.getTemperatures("C"), out, TraceLevel::INFO);
}

void DiffusionSolver::printResults(TraceLevel level)
{
    out.print(level, "Final temperatures [C]:");
    printVector(m_mesh.getTemperatures("C"), out, level);
}