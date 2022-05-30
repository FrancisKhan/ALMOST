#include "BaseDiffusionCode.h"
#include "DiffusionCodeFactory.h"
#include "DiffusionSolver.h"
#include "plot.h"

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

    if(m_solverData.getDirection() == DirectionKind::FORWARD)
    {
        diffCode->setNewHeatSource(result);
    }
    else if(m_solverData.getDirection() == DirectionKind::ADJOINT)
    {
        diffCode->setAdjointModes(result);
    }
    else{;}

    PlotFuncs::generatePlots(Input::getPlots(), m_reactor);
}

void DiffusionSolver::relaxResults(double par)
{
    VectorXd relaxedPowerDensities = VectorXd::Zero(m_mesh.getCellsNumber());
    VectorXd newDenss = m_mesh.getHeatSources();

    relaxedPowerDensities = newDenss * par + m_oldPowerDensities * (1.0 - par);

    m_mesh.setHeatSources(relaxedPowerDensities);

	out.print(TraceLevel::INFO, "Relaxed power densities [W/m3]:");
    printVector(m_reactor.getMesh().getHeatSources(), out, TraceLevel::INFO);
}

void DiffusionSolver::printResults(TraceLevel level)
{
    if(m_solverData.getDirection() == DirectionKind::FORWARD)
    {
        out.print(level, "K-factor: {:7.6e} \n", m_reactor.getKFactor());
        out.print(level, "Neutron Flux [1/(cm2*s)]:");
        printMatrix(m_reactor.getMesh().getFundamentalNeutronFluxes(), out, level, true);
    }
    else if(m_solverData.getDirection() == DirectionKind::ADJOINT)
    {
        out.print(level, "K-factor: {:7.6e} \n", m_reactor.getAdjointKFactor());
        out.print(level, "Adjoint Flux [arbitrary]:");
        printMatrix(m_reactor.getMesh().getFundamentalAdjointFluxes(), out, level, true);
    }
    else{;}
	
    VectorXd powerDistribution = m_reactor.getMesh().getHeatSources();

	if(Numerics::is_greater(powerDistribution.maxCoeff(), 0.0))
	{
		out.print(level, "Thermal power density [W/m3]:");
        printVector(powerDistribution, out, level);
	}
}

void DiffusionSolver::printEigenmodesResults(TraceLevel level)
{
    Numerics::Tensor3d modeFluxes;
    std::vector<double> eigenvalues;

    if(m_solverData.getDirection() == DirectionKind::FORWARD)
    {
        modeFluxes  = m_reactor.getMesh().getNeutronFluxes();
        eigenvalues = m_reactor.getForwardEigenValues();
    }
    else if(m_solverData.getDirection() == DirectionKind::ADJOINT)
    {
        modeFluxes = m_reactor.getMesh().getAdjointFluxes();
        eigenvalues = m_reactor.getAdjointEigenValues();
    }
    else{;}

    for(unsigned n = 0; n < modeFluxes.dimension(2); n++)
    {
		MatrixXd matrixFluxes = Numerics::fromTensor2dToMatrixXd(modeFluxes.chip(n, 2));

        out.print(level, "\nEigenvalue {:3d}: {:7.6e} \n", int(n + 1), eigenvalues[n]);

        if(m_solverData.getDirection() == DirectionKind::FORWARD)
        {
            out.print(level, "Neutron Flux [1/(cm2*s)]:");
        }
        else if(m_solverData.getDirection() == DirectionKind::ADJOINT)
        {
            out.print(level, "Adjoint Flux [arbitrary]:");
        }
        else{;}

        printMatrix(matrixFluxes, out, level, true);
    }
}