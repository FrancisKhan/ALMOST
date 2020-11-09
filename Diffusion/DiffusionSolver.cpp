#include "BaseDiffusionCode.h"
#include "DiffusionCodeFactory.h"
#include "DiffusionSolver.h"

#include <iostream>

using namespace Eigen;
using namespace PrintFuncs;

void DiffusionSolver::solve()
{
    m_oldPowerDensities = m_mesh.getHeatSources();
    std::shared_ptr<BaseDiffusionCode> diffCode = DiffusionCodeFactory::setDiffusionCode(m_reactor, m_library, m_solverData);

    MatrixXd DMatrix  = diffCode->calcDiffOperatorMatrix();
    MatrixXd DMatrix2 = diffCode->applyBoundaryConditions(DMatrix);
    MatrixXd MMatrix  = diffCode->calcMMatrix(DMatrix2);
    MatrixXd FMatrix  = diffCode->calcFMatrix();

    Numerics::SourceIterResults result = Numerics::sourceIteration(MMatrix, FMatrix, 
                                         m_solverData, m_reactor.getMesh().getVolumes("cm"));
    diffCode->setNewHeatSource(result);
}

void DiffusionSolver::relaxResults(double par)
{
    VectorXd relaxedPowerDensities = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newDenss = m_mesh.getHeatSources();

    relaxedPowerDensities = newDenss * par + m_oldPowerDensities * (1.0 - par);

    m_mesh.setHeatSources(relaxedPowerDensities);

	out.print(TraceLevel::INFO, "Relaxed power densities [W/m3]:");
    printVector(m_mesh.getHeatSources(), out, TraceLevel::INFO);
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