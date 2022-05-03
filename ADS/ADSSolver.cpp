#include "BaseADSCode.h"
#include "ADSCodeFactory.h"
#include "ADSSolver.h"

#include <iostream>

using namespace Eigen;
using namespace PrintFuncs;

void ADSSolver::solve()
{
    m_oldPowerDensities = m_mesh.getHeatSources();
    std::shared_ptr<BaseADSCode> adsCode = ADSCodeFactory::setADSCode(m_reactor, m_library, m_solverData);

    MatrixXd DMatrix  = adsCode->calcDiffOperatorMatrix();
    MatrixXd DMatrix2 = adsCode->applyBoundaryConditions(DMatrix);
    MatrixXd MMatrix  = adsCode->calcMMatrix(DMatrix2);
    MatrixXd FMatrix  = adsCode->calcFMatrix();

    Numerics::eigenmodesResults result;

    if(m_solverData.getEigenmodes() == EigenmodesKind::FUNDAMENTAL)
    {
        result = Numerics::sourceIteration(MMatrix, FMatrix, m_solverData);
    }
    else if(m_solverData.getEigenmodes() == EigenmodesKind::ALL)
    {
        result = Numerics::GeneralizedEigenSolver(MMatrix, FMatrix);
    }
    else{;}

    adsCode->setNewHeatSource(result);
}

void ADSSolver::relaxResults(double par)
{
    VectorXd relaxedPowerDensities = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newDenss = m_mesh.getHeatSources();

    relaxedPowerDensities = newDenss * par + m_oldPowerDensities * (1.0 - par);

    m_mesh.setHeatSources(relaxedPowerDensities);

	out.print(TraceLevel::INFO, "Relaxed power densities [W/m3]:");
    printVector(m_reactor.getMesh().getHeatSources(), out, TraceLevel::INFO);
}

void ADSSolver::printResults(TraceLevel level)
{
    out.print(level, "K-factor: {:7.6e} \n", m_reactor.getKFactor());
	out.print(level, "Neutron Flux [1/(cm2*s)]:");

	printMatrix(m_reactor.getMesh().getNeutronFluxes(), out, level, true);
	
    VectorXd powerDistribution = m_reactor.getMesh().getHeatSources();

	if(Numerics::is_greater(powerDistribution.maxCoeff(), 0.0))
	{
		out.print(level, "Thermal power density [W/m3]:");
        printVector(powerDistribution, out, level);
	}
}