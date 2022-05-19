#include "ADSCalculation.h"
#include "DiffusionSolver.h"

using namespace Eigen;
using namespace Numerics;

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

	std::tuple<double, unsigned, unsigned> q = m_reactor.getExtSource();
	Tensor3d forwardModes = m_reactor.getMesh().getNeutronFluxes();
	Tensor3d adjointModes = m_reactor.getMesh().getAdjointFluxes();
	VectorXd volumes = m_reactor.getMesh().getVolumes("cm");

	// Calculate <q x adjoint>
	unsigned sourceEnergy   = std::get<2>(q) - 1;
	unsigned sourcePosition = std::get<1>(q) - 1;
	Tensor2d qAdjointModes2T = adjointModes.chip(sourceEnergy, 0);
	Tensor1d qAdjointModes1T = qAdjointModes2T.chip(sourcePosition, 0);
	VectorXd qAdjointModes1 = fromTensor1dToMatrixXd(qAdjointModes1T);

	//q_x needs to be multiplied by the cell volume

}
