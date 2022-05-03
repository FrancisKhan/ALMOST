#include "ADSCalculation.h"
#include "AbstractSolver.h"

using namespace Eigen;

void ADSCalculation::solve()
{
	SolverData ForwardDiff = m_solver;
	ForwardDiff.setKind(SolverKind::DIFFUSION);
	ForwardDiff.setDirection(DirectionKind::FORWARD);
	ForwardDiff.setEigenmodes(EigenmodesKind::ALL);	

    std::shared_ptr<AbstractSolver> forwardDiffSolver;

    if((ForwardDiff.getKind() == SolverKind::DIFFUSION) && 
       (ForwardDiff.getDirection() == DirectionKind::FORWARD) && 
       (ForwardDiff.getEigenmodes() == EigenmodesKind::ALL))
    {
        forwardDiffSolver = AbstractSolver::getSolver(ForwardDiff, m_reactor, m_library);
    }
    else
    {
        out.print(TraceLevel::CRITICAL, "\nFor ADS calculations the first solver has to be");
		out.print(TraceLevel::CRITICAL, "a forward all eigenmodes diffusion one");
		exit(-1);
    }

	SolverData AdjointDiff = m_solver;
	AdjointDiff.setKind(SolverKind::DIFFUSION);
	AdjointDiff.setDirection(DirectionKind::ADJOINT);
	AdjointDiff.setEigenmodes(EigenmodesKind::ALL);	

    std::shared_ptr<AbstractSolver> AdjointDiffSolver;

	// EigenmodesKind is set to ALL in order to make use of the same solver (for consistency)
	// however, we only needed the first eigenvalue
    if((AdjointDiff.getKind() == SolverKind::DIFFUSION) && 
       (AdjointDiff.getDirection() == DirectionKind::ADJOINT) &&
	   (AdjointDiff.getEigenmodes() == EigenmodesKind::ALL))
    {
        AdjointDiffSolver = AbstractSolver::getSolver(AdjointDiff, m_reactor, m_library);
    }
    else
    {
        out.print(TraceLevel::CRITICAL, "\nFor ADS calculations the second solver has to be");
		out.print(TraceLevel::CRITICAL, "an adjointdiffusion one");
		exit(-1);
    }

	forwardDiffSolver->solve(); 
	forwardDiffSolver->printResults(TraceLevel::CRITICAL);
}
