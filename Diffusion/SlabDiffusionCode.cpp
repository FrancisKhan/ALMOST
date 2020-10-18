#include "BaseDiffusionCode.h"
#include "SlabDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd SlabDiffusionCode::calcMMatrix()
{
    MatrixXd M = MatrixXd::Zero(m_cells, m_cells);

    MatrixXd D         = m_mesh.getDiffusionConstants();
    MatrixXd absXS     = m_mesh.getAbsXSs();
    VectorXd cellSizes = m_mesh.getCellSizes("cm");

    out.print(TraceLevel::DEBUG, "D vector:");
    printMatrix(D, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "absXS vector:");
    printMatrix(absXS, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "cellSizes vector:");
    printVector(cellSizes, out, TraceLevel::DEBUG);

    double albedoL = m_solverData.getAlbedo()[0];
    double albedoR = m_solverData.getAlbedo()[1];

    out.print(TraceLevel::DEBUG, "albedo: {} {}\n", albedoL, albedoR);

    double A, B;

    for(int i = 0; i < m_cells; i++)
    {
        if(i == 0)
        {
            A = (D(0, i) * D(0, i + 1)) / (cellSizes(i) * (cellSizes(i + 1) * D(0, i) + cellSizes(i) * D(0, i + 1)));
            B = D(0, i) * (1.0 - albedoL) / (cellSizes(i) * (4.0 * D(0, i) * (1.0 + albedoL) + cellSizes(i) * (1.0 - albedoL)));
            //B = D(0, i) / pow(cellSizes(i), 2);        
            M(i, i + 1) = - 2.0 * A;
        }
        else if (i == m_cells - 1)
        {
            A = D(0, i) * (1.0 - albedoR) / (cellSizes(i) * (4.0 * D(0, i) * (1.0 + albedoR) + cellSizes(i) * (1.0 - albedoR)));
            //A = D(0, i) / pow(cellSizes(i), 2);
            B = (D(0, i) * D(0, i - 1)) / (cellSizes(i) * (cellSizes(i) * D(0, i - 1) + cellSizes(i - 1) * D(0, i)));             
            M(i, i - 1) = - 2.0 * B;
        }
        else
        {
            A = (D(0, i) * D(0, i + 1)) / (cellSizes(i) * (cellSizes(i + 1) * D(0, i) + cellSizes(i) * D(0, i + 1)));
            B = (D(0, i) * D(0, i - 1)) / (cellSizes(i) * (cellSizes(i) * D(0, i - 1) + cellSizes(i - 1) * D(0, i)));         
            M(i, i - 1) = - 2.0 * B;
            M(i, i + 1) = - 2.0 * A;
        }

        M(i, i) = + 2.0 * (A + B + 0.5 * absXS(0, i)); 
    }
        

    out.print(TraceLevel::DEBUG, "M matrix []:");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}

MatrixXd SlabDiffusionCode::calcFMatrix()
{
    MatrixXd F = MatrixXd::Zero(m_cells, m_cells);

    MatrixXd Ni     = m_mesh.getNis();
    MatrixXd fissXS = m_mesh.getFissionXSs();

    out.print(TraceLevel::DEBUG, "Ni vector:");
    printMatrix(Ni, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "fissXS vector:");
    printMatrix(fissXS, out, TraceLevel::DEBUG);

    for(int i = 0; i < m_cells; i++)
    {
        F(i, i) = Ni(0, i) * fissXS(0, i);                  
    }  

    out.print(TraceLevel::DEBUG, "F matrix []:");
    printMatrix(F, out, TraceLevel::DEBUG);

    return F;
}