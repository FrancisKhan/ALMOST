#include "BaseSpectrumCode.h"
#include "SpectrumCodeFactory.h"
#include "SpectrumSolver.h"

using namespace Eigen;
using namespace PrintFuncs;

void SpectrumSolver::solve()
{
	 m_oldPowerDensities = m_mesh.getHeatSources();

	std::shared_ptr<BaseSpectrumCode> spectrumCode = SpectrumCodeFactory::setSpectrumCode(m_reactor, m_library, m_solverData);
	std::pair<Numerics::Tensor3d, Numerics::Tensor4d> trackData = spectrumCode->calcTracks();
	Numerics::Tensor3d gcpm = spectrumCode->calcCPs(trackData);
	spectrumCode->applyBoundaryConditions(gcpm);
	spectrumCode->particleBalanceCheck(gcpm);
	MatrixXd cpm = spectrumCode->calcCPMMatrix(gcpm);
	MatrixXd MMatrix = spectrumCode->calcMMatrix(cpm);
	MatrixXd FMatrix = spectrumCode->calcFMatrix(cpm);
 
	eigenmodesResults result;

    if(m_solverData.getEigenmodes() == EigenmodesKind::FUNDAMENTAL)
    {
        result = Numerics::sourceIteration(MMatrix, FMatrix, m_solverData);
    }
    else if(m_solverData.getEigenmodes() == EigenmodesKind::ALL)
    {
        result = Numerics::GeneralizedEigenSolver(MMatrix, FMatrix, m_solverData);
    }
    else{;}

    spectrumCode->setNewHeatSource(result);
}

void SpectrumSolver::relaxResults(double par)
{
    VectorXd relaxedPowerDensities = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newDenss = m_mesh.getHeatSources();

    relaxedPowerDensities = newDenss * par + m_oldPowerDensities * (1.0 - par);

    m_mesh.setHeatSources(relaxedPowerDensities);

	out.print(TraceLevel::INFO, "Relaxed power densities [W/m3]:");
    printVector(m_reactor.getMesh().getHeatSources(), out, TraceLevel::INFO);
}

void SpectrumSolver::printResults(TraceLevel level)
{
    out.print(level, "Fundamental K-factor: {:7.6e} \n", m_reactor.getKFactor());
    out.print(level, "Fundamental Neutron Flux [1/(cm2*s)]:");
    printMatrix(m_reactor.getMesh().getFundamentalNeutronFluxes(), out, level, true);
	
    VectorXd powerDistribution = m_reactor.getMesh().getHeatSources();

	if(Numerics::is_greater(powerDistribution.maxCoeff(), 0.0))
	{
		out.print(level, "Thermal power density [W/m3]:");
        printVector(powerDistribution, out, level);
	}
}

void SpectrumSolver::printEigenmodesResults(TraceLevel level)
{
    Numerics::Tensor3d modeFluxes;
    std::vector<double> eigenvalues;

    modeFluxes  = m_reactor.getMesh().getNeutronFluxes();
    eigenvalues = m_reactor.getForwardEigenValues();

    if(modeFluxes.dimension(2) <= 1) return;

    for(unsigned n = 0; n < modeFluxes.dimension(2); n++)
    {
		MatrixXd matrixFluxes = Numerics::fromTensor2dToMatrixXd(modeFluxes.chip(n, 2));

        out.print(level, "\nEigenvalue {}: {:7.6e} \n", int(n + 1), eigenvalues[n]);

        out.print(level, "Neutron Flux {} {}", int(n + 1), " [1/(cm2*s)]:");

        printMatrix(matrixFluxes, out, level, true);
    }
}