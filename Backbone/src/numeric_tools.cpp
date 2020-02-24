#include "numeric_tools.h"

#include <boost/math/quadrature/tanh_sinh.hpp>
#include <boost/math/constants/constants.hpp>
#include <unsupported/Eigen/Polynomials>
#include <iostream>

double bickley3f(double x)
{
   auto f = [&x](double t) {return exp(-x / sin(t)) * sin(t) * sin(t);};
   boost::math::quadrature::tanh_sinh<double> integrator;
   return integrator.integrate(f, 0.0, boost::math::constants::half_pi<double>());
}

double delk(int a, int b)
{
	return a == b ? 1.0 : 0.0;
} 

// Floating Point Equal to

bool equality(double a, double b)
{
	double eps = 10.0 * std::numeric_limits<double>::epsilon();
	return abs(a - b) <= (fabs(a) * eps);  // a is approximately equal to b
}

// Floating Point Lower Than

bool fplt(double x, double y)
{
	double eps = 10.0 * std::numeric_limits<double>::epsilon();
	return (x - y) >= (fabs(x) * eps); // y is definitely less than x
}

// Floating Point greater Than

bool fpgt(double x, double y)
{
	double eps = 10.0 * std::numeric_limits<double>::epsilon();
    return (x - y) >= (fabs(x) * eps); // x is definitely greater than y
}

void printMatrix(Tensor3d A, Output output, TraceLevel level, std::string str)
{
	auto dims = A.dimensions();
	
	if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::Tensor3d nullptr!" << std::endl;
		return;
	}
	
	std::string finStr = str + ": {}";
	
	for(int h = 0; h < dims[2]; h++)
    {
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical(finStr, h + 1);	
		else if (level == TraceLevel::ERROR)
			output.getLogger()->error(finStr, h + 1);
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn(finStr, h + 1);
		else if (level == TraceLevel::INFO)
			output.getLogger()->info(finStr, h + 1);
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug(finStr, h + 1);
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace(finStr, h + 1);
		else {}
		
        for(int i = 0; i < dims[1]; i++)
		{
			std::string msg;
		
			for(int j = 0; j < dims[0]; j++)
			{
				msg += std::to_string(A(i, j, h)) + " ";
			}
		
			if (level == TraceLevel::CRITICAL)
				output.getLogger()->critical(msg);
			else if (level == TraceLevel::ERROR)
				output.getLogger()->error(msg);
			else if (level == TraceLevel::WARN)
				output.getLogger()->warn(msg);
			else if (level == TraceLevel::INFO)
				output.getLogger()->info(msg);
			else if(level == TraceLevel::DEBUG)
				output.getLogger()->debug(msg);
			else if(level == TraceLevel::TRACE)
				output.getLogger()->trace(msg);
			else {}
		}	
	}

	if (level == TraceLevel::CRITICAL)
		output.getLogger()->critical(" ");	
	else if (level == TraceLevel::ERROR)
		output.getLogger()->error(" ");
	else if (level == TraceLevel::WARN)
		output.getLogger()->warn(" ");
	else if (level == TraceLevel::INFO)
		output.getLogger()->info(" ");
	else if(level == TraceLevel::DEBUG)
		output.getLogger()->debug(" ");
	else if(level == TraceLevel::TRACE)
		output.getLogger()->trace(" ");
	else {}
}

void printMatrix(Eigen::MatrixXd A, Output output, TraceLevel level)
{
	if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::MatrixXd nullptr!" << std::endl;
		return;
	}
	
    for(int i = 0; i < A.rows(); i++)
    {
		std::string msg;
		
	    for(int j = 0; j < A.cols(); j++)
	    {
			msg += std::to_string(A(i, j)) + " ";
	    }
		
	    if (level == TraceLevel::CRITICAL)
		    output.getLogger()->critical(msg);
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error(msg);
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn(msg);
		else if (level == TraceLevel::INFO)
			output.getLogger()->info(msg);
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug(msg);
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace(msg);
		else {}
    }	

	if (level == TraceLevel::CRITICAL)
		output.getLogger()->critical(" ");	
	else if (level == TraceLevel::ERROR)
		output.getLogger()->error(" ");
	else if (level == TraceLevel::WARN)
		output.getLogger()->warn(" ");
	else if (level == TraceLevel::INFO)
		output.getLogger()->info(" ");
	else if(level == TraceLevel::DEBUG)
		output.getLogger()->debug(" ");
	else if(level == TraceLevel::TRACE)
		output.getLogger()->trace(" ");
	else {}
}

void printVector(Eigen::VectorXd vec, Output output, TraceLevel level)
{	
    if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::VectorXd nullptr!" << std::endl;
		return;
	}

	for(int i = 0; i < vec.size(); i++)
	{
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{:5.4f}", vec(i));
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{:5.4f}", vec(i));
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{:5.4f}", vec(i));
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{:5.4f}", vec(i));
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{:5.4f}", vec(i));
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{:5.4f}", vec(i));
		else {}
	}

	if (level == TraceLevel::CRITICAL)
		output.getLogger()->critical(" ");	
	else if (level == TraceLevel::ERROR)
		output.getLogger()->error(" ");
	else if (level == TraceLevel::WARN)
		output.getLogger()->warn(" ");
	else if (level == TraceLevel::INFO)
		output.getLogger()->info(" ");
	else if(level == TraceLevel::DEBUG)
		output.getLogger()->debug(" ");
	else if(level == TraceLevel::TRACE)
		output.getLogger()->trace(" ");
	else {}
}

void printVector(std::vector<std::string> vec, Output output, TraceLevel level)
{	
    if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::Vector nullptr!" << std::endl;
		return;
	}

	for(unsigned i = 0; i < vec.size(); i++)
	{
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{}: {}", i + 1, vec[i]);
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{}: {}", i + 1, vec[i]);
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{}: {}", i + 1, vec[i]);
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{}: {}", i + 1, vec[i]);
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{}: {}", i + 1, vec[i]);
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{}: {}", i + 1, vec[i]);
		else {}
	}

	if (level == TraceLevel::CRITICAL)
		output.getLogger()->critical(" ");	
	else if (level == TraceLevel::ERROR)
		output.getLogger()->error(" ");
	else if (level == TraceLevel::WARN)
		output.getLogger()->warn(" ");
	else if (level == TraceLevel::INFO)
		output.getLogger()->info(" ");
	else if(level == TraceLevel::DEBUG)
		output.getLogger()->debug(" ");
	else if(level == TraceLevel::TRACE)
		output.getLogger()->trace(" ");
	else {}
}

void diagonalDominanceCheck(Eigen::MatrixXd &matrix)
{
	Eigen::VectorXd rowSum = Eigen::VectorXd::Zero(matrix.rows());
	
	for(unsigned i = 0; i < rowSum.size(); i++)
	{
		for(unsigned j = 0; j < rowSum.size(); j++)
	    {
		    rowSum(i) += fabs(matrix(i, j));
		}
	}
	
	for(unsigned i = 0; i < rowSum.size(); i++)
	{
		if(matrix(i, i) < (rowSum(i) - matrix(i, i))) // comparing two floating numbers!!
		{
			out.getLogger()->warn("The convergence is not guaranteed, the matrix is not strictly diagonally dominant");
		}
	}
}

void sourceIteration(Eigen::MatrixXd &Mmatrix, Eigen::MatrixXd &Fmatrix, 
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
	
	out.getLogger()->info("K-factor:  {} \n", kFactor);
	out.getLogger()->info("Number of iterations: {} \n", h + 1);
	out.getLogger()->info("Neutron Flux:");
	printVector(neutronFlux, out, TraceLevel::INFO);
}

double bickley3f_old(const double x)
{
	double intValue = 0.0;
	int N = 200;

    if(fplt(0.0, x)) 
	{
		intValue = M_PI / 4.0;
	}
	else
	{
		for(int i = -N; i < N; i++)
		{
			double step = 1.0 / 100.0;
			double abscissa = 1.0 - 0.25 * pow((tanh(0.5 * M_PI * sinh(i * step)) + 1.0), 2);
			double func = exp(-x / sqrt(abscissa)) * sqrt(abscissa);
			double weight = 0.5 * step * M_PI * cosh(i * step) / pow(cosh(0.5 * M_PI * sinh(i * step)), 2);
			intValue = weight * func / 2.0 + intValue;
		}
	}
	return intValue;
}

// https://www.geeksforgeeks.org/multiply-two-polynomials-2/
std::vector<double> multiply_poly(std::vector<double> &a, 
                                  std::vector<double> &b)
{
   size_t m = a.size();
   size_t n = b.size();

   std::vector<double> result(m + n - 1, 0.0);
  
   for (size_t i = 0; i < m; i++) 
     for (size_t j = 0; j < n; j++) 
           result[i + j] += a[i] * b[j];

   return result; 
}

// product of (a1 + x)(a2 + x)(a3 + x)... 
std::vector<double> prod_poly(std::vector<double> &a)
{
    std::vector<double> result = {1.0};

	for(auto & a_i : a)
	{
        std::vector<double> temp = {a_i, 1.0};
		result = multiply_poly(result, temp);
	}

	return result;
}

std::vector<double> prod_poly_i(std::vector<double> &a, size_t i)
{
    std::vector<double> result = {1.0};

	for(size_t j = 0; j < a.size(); j++)
	{
		if (j == i) continue;
        std::vector<double> temp = {a[j], 1.0};
		result = multiply_poly(result, temp);
	}

	return result;
}

// http://www.ce.unipr.it/people/medici/eigen-poly.html
std::vector<double> poly_roots(std::vector<double> &p)
{
	std::vector<double> result;
	
	Eigen::PolynomialSolver<double, Eigen::Dynamic> solver;
	Eigen::VectorXd coeff = Eigen::VectorXd::Zero(p.size());
	
	for(size_t i = 0; i < p.size(); i++)
    	coeff[i] = p[i];
	
	solver.compute(coeff);
	
	const Eigen::PolynomialSolver<double, Eigen::Dynamic>::RootsType & r = solver.roots();

	for(unsigned i = 0; i < r.rows(); i++)
		result.push_back(r[i].real());

	return result;
}
