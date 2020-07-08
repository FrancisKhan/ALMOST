#include "BaseSpectrumCode.h"
#include "SpectrumCodeFactory.h"
#include "SpectrumSolver.h"

#include <iostream>

using namespace Eigen;
using namespace Numerics;

void SpectrumSolver::solve(int max_iter_number, double accuracy)
{
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