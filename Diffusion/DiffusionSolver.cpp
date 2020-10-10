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

    MatrixXd MMatrix = diffCode->calcMMatrix();
    MatrixXd FMatrix = diffCode->calcFMatrix();

    diffCode->applyBoundaryConditions(MMatrix);

    Numerics::SourceIterResults result = Numerics::sourceIteration(MMatrix, FMatrix, max_iter_number, accuracy, "diffusion");
    diffCode->setNewHeatSource(result);
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
    out.print(level, "K-factor:  {:7.6e} \n", m_reactor.getKFactor());
	out.print(level, "Neutron Flux [1/(cm2*s)]:");

	printMatrix(m_reactor.getMesh().getNeutronFluxes(), out, level, true);
	
	VectorXd powerDistribution = m_reactor.getMesh().getHeatSources().cwiseProduct(m_reactor.getMesh().getVolumes("cm"));

	if (powerDistribution.maxCoeff() > 0.0)
	{
		out.print(level, "Thermal Power [W]:");
		printVector(powerDistribution, out, level);
	}
}