#include "ADSCalculation.h"
#include "DiffusionSolver.h"
#include "additionalPrintFuncs.h"
#include "plot.h"

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

void ADSCalculation::solve()
{
	SolverData ForwardDiffSolverData = m_solver;
	ForwardDiffSolverData.setKind(SolverKind::DIFFUSION);
	ForwardDiffSolverData.setDirection(DirectionKind::FORWARD);
	ForwardDiffSolverData.setEigenmodes(EigenmodesKind::ALL);	

    DiffusionSolver forwardDiffSolver(m_reactor, m_library, ForwardDiffSolverData);

	SolverData AdjointDiffSolverData = m_solver;
	AdjointDiffSolverData.setKind(SolverKind::DIFFUSION);
	AdjointDiffSolverData.setDirection(DirectionKind::ADJOINT);
	AdjointDiffSolverData.setEigenmodes(EigenmodesKind::ALL);

    DiffusionSolver AdjointDiffSolver(m_reactor, m_library, AdjointDiffSolverData);

	forwardDiffSolver.solve(); 
	forwardDiffSolver.printEigenmodesResults(TraceLevel::CRITICAL);

    AdjointDiffSolver.solve(); 
	AdjointDiffSolver.printEigenmodesResults(TraceLevel::CRITICAL);

	// Calculate <adjoint x q>
	std::tuple<double, unsigned, unsigned> q = m_reactor.getExtSource();
	unsigned sourceStrength = std::get<0>(q);
	unsigned sourcePosition = std::get<1>(q) - 1;
	unsigned sourceEnergy   = std::get<2>(q) - 1;

	VectorXd volumes = m_reactor.getMesh().getVolumes("cm");

	Tensor3d adjointModes = m_reactor.getMesh().getAdjointFluxes();
	Tensor2d adjointModes2T = adjointModes.chip(sourceEnergy, 0);
	Tensor1d adjointModes1T = adjointModes2T.chip(sourcePosition, 0);
	VectorXd adjointModes1 = fromTensor1dToVectorXd(adjointModes1T);

	VectorXd adjoint_q = sourceStrength * volumes(sourcePosition) * adjointModes1;
	out.print(TraceLevel::CRITICAL, "adjoint_q:");
    printVector(adjoint_q, out, TraceLevel::CRITICAL);

	// Calculate <adjoint x P x forward>
	Tensor3d forwardModes = m_reactor.getMesh().getNeutronFluxes();
	
	MatrixXd P = m_reactor.getMesh().getProductionOperator();

	VectorXd adjoint_P_forward = VectorXd::Zero(adjoint_q.size());

	for(unsigned n = 0; n < forwardModes.dimension(2); n++)
		for(unsigned m = 0; m < forwardModes.dimension(1); m++)
			for(unsigned e = 0; e < forwardModes.dimension(0); e++)
				adjoint_P_forward(n) += adjointModes(e, m, n) * P(e, m) * 
				                        forwardModes(e, m, n) * volumes(m);

	out.print(TraceLevel::CRITICAL, "adjoint_P_forward:");
    printVector(adjoint_P_forward, out, TraceLevel::CRITICAL);

	// ratio <adjoint x q> / <adjoint x P x forward>
	VectorXd ratio = adjoint_q.cwiseQuotient(adjoint_P_forward);

	out.print(TraceLevel::CRITICAL, "ratio:");
    printVector(ratio, out, TraceLevel::CRITICAL);

	// total fluxes
	std::vector<double> forwardEigenvalues = m_reactor.getForwardEigenValues();
	
	MatrixXd totalFluxes = MatrixXd::Zero(forwardModes.dimension(0), forwardModes.dimension(1));

	for(unsigned e = 0; e < forwardModes.dimension(0); e++)
		for(unsigned m = 0; m < forwardModes.dimension(1); m++)
			for(unsigned n = 0; n < forwardModes.dimension(2); n++)
				totalFluxes(e, m) += (forwardEigenvalues[n] / (1.0 - forwardEigenvalues[n])) * 
									ratio(n) * forwardModes(e, m, n);

	out.print(TraceLevel::CRITICAL, "Total Flux:");
    printMatrix(totalFluxes, out, TraceLevel::CRITICAL, true);

	PlotFuncs::generatePlots(Input::getPlots(), m_reactor);
}
