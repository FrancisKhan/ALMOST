#include <iostream>
#include <Eigen/Dense>
#include <boost/math/special_functions/expint.hpp>
#include <unsupported/Eigen/CXX11/Tensor>
#include <fstream>

using namespace Eigen;
using namespace std;

typedef Eigen::Tensor<double, 3> Tensor3d;

void try1()
{
  MatrixXd m = MatrixXd::Random(3,3);
  m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
  cout << "m =" << endl << m << endl;
  VectorXd v(3);
  v << 1, 2, 3;
  cout << "m * v =" << endl << m * v << endl;
}

void try2()
{
  double x = 1.5;
  cout << "x: " << boost::math::expint(3, x) << endl;
}

void try3()
{
	int energies = 4;
	int cells    = 3;
	
	Tensor3d scattMatrix = Tensor3d(energies, energies, cells);
	scattMatrix.setZero();
	
	// self scattering 0 <-> 0
	
	scattMatrix(0, 0, 0) = 9.9;
	scattMatrix(0, 0, 1) = 9.9;
	scattMatrix(0, 0, 2) = 9.9;
	
	// self scattering 1 <-> 1
	
	scattMatrix(1, 1, 0) = 1.1;
	scattMatrix(1, 1, 1) = 1.1;
	scattMatrix(1, 1, 2) = 1.1;
	
	// self scattering 2 <-> 2
	
	scattMatrix(2, 2, 0) = 2.2;
	scattMatrix(2, 2, 1) = 2.2;
	scattMatrix(2, 2, 2) = 2.2;
	
	// self scattering 3 <-> 3
	
	scattMatrix(3, 3, 0) = 3.3;
	scattMatrix(3, 3, 1) = 3.3;
	scattMatrix(3, 3, 2) = 3.3;
	
	// down scattering 0 -> 1
	
	scattMatrix(0, 1, 0) = 0.1;
	scattMatrix(0, 1, 1) = 0.1;
	scattMatrix(0, 1, 2) = 0.1;
	
	// down scattering 1 -> 2
	
	scattMatrix(1, 2, 0) = 1.2;
	scattMatrix(1, 2, 1) = 1.2;
	scattMatrix(1, 2, 2) = 1.2;
	
	// down scattering 2 -> 3
	
	scattMatrix(2, 3, 0) = 2.3;
	scattMatrix(2, 3, 1) = 2.3;
	scattMatrix(2, 3, 2) = 2.3;
	
	// down scattering 0 -> 2
	
	scattMatrix(0, 2, 0) = 0.2;
	scattMatrix(0, 2, 1) = 0.2;
	scattMatrix(0, 2, 2) = 0.2;
	
	// down scattering 1 -> 3
	
	scattMatrix(1, 3, 0) = 1.3;
	scattMatrix(1, 3, 1) = 1.3;
	scattMatrix(1, 3, 2) = 1.3;
	
	// down scattering 0 -> 3
	
	scattMatrix(0, 3, 0) = 0.3;
	scattMatrix(0, 3, 1) = 0.3;
	scattMatrix(0, 3, 2) = 0.3;
	
	// up scattering 1 -> 0
	
	scattMatrix(1, 0, 0) = 1.0;
	scattMatrix(1, 0, 1) = 1.0;
	scattMatrix(1, 0, 2) = 1.0;
	
	// up scattering 2 -> 1
	
	scattMatrix(2, 1, 0) = 2.1;
	scattMatrix(2, 1, 1) = 2.1;
	scattMatrix(2, 1, 2) = 2.1;
	
	// up scattering 3 -> 2
	
	scattMatrix(3, 2, 0) = 3.2;
	scattMatrix(3, 2, 1) = 3.2;
	scattMatrix(3, 2, 2) = 3.2;
	
	// up scattering 2 -> 0
	
	scattMatrix(2, 0, 0) = 2.0;
	scattMatrix(2, 0, 1) = 2.0;
	scattMatrix(2, 0, 2) = 2.0;
	
	// up scattering 3 -> 1
	
	scattMatrix(3, 1, 0) = 3.1;
	scattMatrix(3, 1, 1) = 3.1;
	scattMatrix(3, 1, 2) = 3.1;
	
	// up scattering 3 -> 0
	
	scattMatrix(3, 0, 0) = 3.0;
	scattMatrix(3, 0, 1) = 3.0;
	scattMatrix(3, 0, 2) = 3.0;
	
	MatrixXd Mmatrix = MatrixXd::Zero(cells * energies, cells * energies);
	
  	for(int k = 0; k < energies; k++)
    {
	    for(int j = 0; j < energies; j++)
        {
	        for(int i = 0; i < cells; i++)
	        {
	      	    Mmatrix(i + (k + j) % energies * cells, i + j * cells) = 
				scattMatrix(j % energies, (k + j) % energies, i);
		    }
	    }
	}
	
	ofstream myfile;
    myfile.open ("out.txt");
	
	myfile << std::fixed;
	myfile << std::setprecision(1);
	
    for(int i = 0; i < Mmatrix.rows(); i++)
    {
	    for(int j = 0; j < Mmatrix.cols(); j++)
	    {
			myfile << Mmatrix(i, j) << " ";
	    }
	    myfile << "" << std::endl;
    }	
	
    myfile.close();
}