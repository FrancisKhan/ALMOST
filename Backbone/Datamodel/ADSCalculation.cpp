#include "ADSCalculation.h"
#include "DiffusionSolver.h"

using namespace Eigen;

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

	// Eigen::VectorXd q = m_reactor.getMesh().getExtSourceDistribution();

	// // Calculate <q adjoint>
	// double qAdjointN = 0;
	// unsigned cells = m_reactor.getMesh().getCellsNumber();

	// for(size_t n = 0; n < m_reactor.getMesh().getForwardEigenmodes().size(); n++)
	// 	for(size_t c = 0; c < cells; c++)
	// 		for(size_t e = 0; e < m_reactor.getMesh().getEnergyGroupsNumber(); e++)
	// 			qAdjointN = q(c + e * cells)


}
