#include "BaseDiffusionCode.h"
#include "DiffusionCodeFactory.h"
#include "DiffusionSolver.h"

#include <iostream>

using namespace Eigen;
using namespace PrintFuncs;

void DiffusionSolver::solve()
{
    m_oldPowerDensities = m_mesh.getHeatSources();
    std::shared_ptr<BaseDiffusionCode> diffCode = DiffusionCodeFactory::setDiffusionCode(m_reactor, m_library);

    int max_iter_number = m_solverData.getMaxIterNumber();
	double accuracy     = m_solverData.getAccuracy();

    MatrixXd MMatrix = diffCode->createMMatrix();
}

void DiffusionSolver::relaxResults(double param)
{
    // VectorXd relaxedTemps = VectorXd::Zero(m_mesh.getCellsNumber());
    // VectorXd newTemps = m_mesh.getTemperatures("C");

    // relaxedTemps = newTemps * param + m_oldTemperatures * (1.0 - param);

    // m_mesh.setTemperatures(relaxedTemps);

    // out.print(TraceLevel::INFO, "Relaxed temperatures [C]:");
    // printVector(m_mesh.getTemperatures("C"), out, TraceLevel::INFO);
}

void DiffusionSolver::printResults(TraceLevel level)
{
    // out.print(level, "Final temperatures [C]:");
    // printVector(m_mesh.getTemperatures("C"), out, level); 
}