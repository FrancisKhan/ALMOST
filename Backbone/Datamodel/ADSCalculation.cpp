#include "ADSCalculation.h"
#include "DiffusionSolver.h"

using namespace Eigen;

void ADSCalculation::solve()
{
	SolverData ForwardDiff = m_solver;
	ForwardDiff.setKind(SolverKind::DIFFUSION);
	ForwardDiff.setDirection(DirectionKind::FORWARD);
	ForwardDiff.setEigenmodes(EigenmodesKind::ALL);	

    DiffusionSolver forwardDiffSolver(m_reactor, m_library, ForwardDiff);

    // EigenmodesKind is set to ALL in order to make use of the same solver (for consistency)
	// however, we only need the first eigenvalue
	SolverData AdjointDiff = m_solver;
	AdjointDiff.setKind(SolverKind::DIFFUSION);
	AdjointDiff.setDirection(DirectionKind::ADJOINT);
	AdjointDiff.setEigenmodes(EigenmodesKind::ALL);	

    DiffusionSolver AdjointDiffSolver(m_reactor, m_library, AdjointDiff);

	forwardDiffSolver.solve(); 
	forwardDiffSolver.printEigenmodesResults(TraceLevel::CRITICAL);

    AdjointDiffSolver.solve(); 
	AdjointDiffSolver.printResults(TraceLevel::CRITICAL);
}
