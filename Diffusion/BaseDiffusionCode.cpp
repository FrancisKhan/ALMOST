#include "BaseDiffusionCode.h"

using namespace Eigen;

MatrixXd BaseDiffusionCode::getInterfaceDiffusionConstants()
{
    MatrixXd materialD  = m_mesh.getDiffusionConstants();
    MatrixXd interfaceD = m_mesh.getDiffusionConstants();
    VectorXd cellSizes  = m_mesh.getCellSizes("m");

    for(int m = 1; m < materialD.cols() - 1; m++)
    {   
        for(int i = 0; i < materialD.rows(); i++)
        {
            interfaceD(i, m) = (materialD(i, m) + materialD(i, m -  1)) / 2.0;
        } 
    }

    return interfaceD;
}

void BaseDiffusionCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    VectorXd temperatures = VectorXd::Zero(source.size());
    temperatures = T.colPivHouseholderQr().solve(source);
    m_mesh.setTemperatures(temperatures);
}

void BaseDiffusionCode::setNewHeatSource(Numerics::SourceIterResults result)
{
	MatrixXd meshNeutronFluxes = MatrixXd::Zero(m_energies, m_cells);

	for(int i = 0; i < m_cells; i++)
		for(int j = 0; j < m_energies; j++)
				meshNeutronFluxes(j, i) = result.getNeutronFLux()(i + j * m_cells);

	m_mesh.setNeutronFluxes(meshNeutronFluxes);
	m_reactor.setKFactor(result.getKFactor());

	//VectorXd powerDistribution = calcFissionPowerDistribution();
	//m_mesh.setHeatSources(powerDistribution.cwiseQuotient(m_volumes));
}