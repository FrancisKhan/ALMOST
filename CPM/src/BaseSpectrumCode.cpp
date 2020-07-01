#include "BaseSpectrumCode.h"
#include "numeric_tools.h"
#include "Output.h"

#include <iostream>
#include <iomanip>

using namespace Eigen;

const double BaseSpectrumCode::abscissa[8] = {0.0446339553, 0.1443662570, 0.2868247571,
                                              0.4548133152, 0.6280678354, 0.7856915206,
									   	      0.9086763921, 0.9822200849};
										  
const double BaseSpectrumCode::weights[8] = {0.0032951914, 0.0178429027, 0.0454393195,
                                             0.0791995995, 0.1060473594, 0.1125057995,
										     0.0911190236, 0.0445508044};


void BaseSpectrumCode::particleBalanceCheck(Tensor3d &gcpm)
{
	VectorXd check = VectorXd::Zero(m_cells);
	
	for(int h = 0; h < m_energies; h++)
	{
		out.getLogger()->debug("Particles Balance Check for Group: {}", h + 1);
		
		for(int i = 0; i < m_cells; i++)
        {
			check(i) = 0.0;
	        for(int j = 0; j < m_cells; j++)
	        {
				check(i) += gcpm(i, j, h) * m_totalXS(h, j);
			}
			
			out.getLogger()->debug("check: {} {:7.6e}", i + 1, check(i));
		}
	}
}

MatrixXd BaseSpectrumCode::calcCPMMatrix(Tensor3d &gcpm)
{
   // final collision probability matrix calculation (form gcpm to cpm)

   MatrixXd cpm = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);
   
   for(int k = 0; k < m_energies; k++)
    {
	    for(int j = k * m_cells; j < (k + 1) * m_cells; j++)
        {
	        for(int i = k * m_cells; i < (k + 1) * m_cells; i++)
	        {
	      	    cpm(i, j) = gcpm(i - k * m_cells, j - k * m_cells, k);
		    }
	    }
	}
   
   out.getLogger()->debug("\nCPM matrix");
   printMatrix(cpm, out, TraceLevel::DEBUG);

   return cpm;
}

MatrixXd BaseSpectrumCode::calcMMatrix(MatrixXd &cpm)
{
    MatrixXd MMatrix = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

	Tensor3d scattMatrix = m_library.getCrossSectionSet().getScattMatrix();
	
	// scattering matrix generation
	
	for(int k = 0; k < m_energies; k++)
    {
	    for(int j = 0; j < m_energies; j++)
        {
	        for(int i = 0; i < m_cells; i++)
	        {
	      	    MMatrix(i + (k + j) % m_energies * m_cells, i + j * m_cells) = 
				scattMatrix(j % m_energies, (k + j) % m_energies, i);
		    }
	    }
	}
	
    MMatrix = -cpm * MMatrix; // the minus sign!
   
    for(int i = 0; i < m_cells * m_energies; i++)
    {
	   MMatrix(i, i) += 1.0;
    }
   
	out.getLogger()->debug("MMatrix");
    printMatrix(MMatrix, out, TraceLevel::DEBUG);

	return MMatrix;
}

MatrixXd BaseSpectrumCode::calcFMatrix(MatrixXd &cpm)
{
    MatrixXd FMatrix = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

	MatrixXd fissXS = m_library.getCrossSectionSet().getFission();
	MatrixXd chiXS  = m_library.getCrossSectionSet().getChi();
	MatrixXd niXS   = m_library.getCrossSectionSet().getNi();
	
	VectorXd chiMatrix = VectorXd::Zero(m_cells * m_energies);
	
	// diagonal elements generation
	for(int j = 0; j < m_energies; j++)
    {
	    for(int i = 0; i < m_cells; i++)
	    {
            FMatrix(i + j * m_cells, i + j * m_cells) = fissXS(j, i) * niXS(j, i);
            chiMatrix(i + j * m_cells)                = chiXS(j, i);
		}
	}

    for(int n = 0; n < m_energies; n++)
    {
	    for(int k = 0; k < m_energies; k++)
	    {
			for(int i = k * m_cells; i < (k + 1) * m_cells; i++)
			{
				for(int j = n * m_cells; j < (n + 1) * m_cells; j++)
				{
					FMatrix(i, j) = FMatrix(i + (n - k) * m_cells, j);
				}
			}
		}
	}
   
    for(int i = 0; i < m_cells * m_energies; i++)
    {
	    for(int j = 0; j < m_cells * m_energies; j++)
	    {
			FMatrix(i, j) *= chiMatrix(i);
		}
	}
   
   FMatrix = cpm * FMatrix;
   
   out.getLogger()->debug("FMatrix");
   printMatrix(FMatrix, out, TraceLevel::DEBUG);

   return FMatrix;
}

void BaseSpectrumCode::sourceIteration(Eigen::MatrixXd &Mmatrix, 
					   Eigen::MatrixXd &Fmatrix, 
                       int max_iter_number, double accuracy)
{
	diagonalDominanceCheck(Mmatrix);
	
	if(Mmatrix.size() != Fmatrix.size())
	{
		out.getLogger()->error(" MMatrix has a different number of elements than FMatrix!");
		exit(-1);
	}
	
	unsigned size = sqrt(Mmatrix.size());
	
	Eigen::VectorXd source1      = Eigen::VectorXd::Zero(size);
	Eigen::VectorXd source2      = Eigen::VectorXd::Ones(size);	
	Eigen::VectorXd neutronFlux1 = Eigen::VectorXd::Ones(size);
	Eigen::VectorXd neutronFlux2 = Eigen::VectorXd::Zero(size);
	
	double kFactor1 = 1.0;
	double kFactor2 = 0.0;
	
	int h;
	
	Eigen::ColPivHouseholderQR<Eigen::MatrixXd> CPHQR;
	CPHQR.compute(Mmatrix);
	
	for(h = 0; h < max_iter_number; h++)
	{
		neutronFlux2 = CPHQR.solve(source2);
		
		source1 = Fmatrix * neutronFlux1;
		source2 = Fmatrix * neutronFlux2;
		
		double sum1 = std::inner_product(source1.begin(), source1.end(), source2.begin(), 0.0);
		double sum2 = std::inner_product(source2.begin(), source2.end(), source2.begin(), 0.0);
		
		kFactor2 = kFactor1 * (sum2 / sum1);
		
		source2 /= kFactor2;
		
		// exit condition
		if (fabs((kFactor2 - kFactor1) / kFactor2) < accuracy) break;
		
		kFactor1     = kFactor2;
		neutronFlux1 = neutronFlux2;
	}
	
	Eigen::VectorXd neutronFlux = neutronFlux2 / neutronFlux2.sum(); 
	double kFactor = kFactor2;
	
	out.getLogger()->info("K-factor:  {:7.6e} \n", kFactor);
	out.getLogger()->info("Number of iterations: {} \n", h + 1);
	out.getLogger()->info("Neutron Flux [1/(cm2*s)]:");
	printVector(neutronFlux, out, TraceLevel::INFO);
}
