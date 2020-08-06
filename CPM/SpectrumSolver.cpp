#include "BaseSpectrumCode.h"
#include "SpectrumCodeFactory.h"
#include "SpectrumSolver.h"

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

void SpectrumSolver::solve(int max_iter_number, double accuracy)
{
	 m_oldPowerDensities = m_mesh.getHeatSources();

	std::shared_ptr<BaseSpectrumCode> spectrumCode = SpectrumCodeFactory::setSpectrumCode(m_reactor, m_library);
	std::pair<Tensor3d, Tensor4d> trackData = spectrumCode->calcTracks();
	Tensor3d gcpm = spectrumCode->calcCPs(trackData);
	spectrumCode->applyBoundaryConditions(gcpm);
	spectrumCode->particleBalanceCheck(gcpm);
	MatrixXd cpm = spectrumCode->calcCPMMatrix(gcpm);
	MatrixXd MMatrix = spectrumCode->calcMMatrix(cpm);
	MatrixXd FMatrix = spectrumCode->calcFMatrix(cpm);
	spectrumCode->sourceIteration(MMatrix, FMatrix, max_iter_number, accuracy);
}

void SpectrumSolver::relaxResults(double par)
{
    VectorXd relaxedPowerDensities = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newDenss = m_mesh.getHeatSources();

    relaxedPowerDensities = newDenss * par + m_oldPowerDensities * (1.0 - par);

    m_mesh.setHeatSources(relaxedPowerDensities);

	out.print(TraceLevel::INFO, "Relaxed power densities [W/m3]:");
    printVector(m_mesh.getHeatSources(), out, TraceLevel::INFO);
}

void SpectrumSolver::printResults(TraceLevel level)
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