#include "numeric_tools.h"

#include <boost/math/quadrature/tanh_sinh.hpp>
#include <boost/math/constants/constants.hpp>
#include <unsupported/Eigen/Polynomials>
#include <iostream>

namespace Numerics
{
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

	double bickley3f_old(const double x)
	{
		double intValue = 0.0;
		int N = 200;

    	if(is_lower_equal(x, 0.0)) 
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

	Eigen::VectorXd tridiag_solver(const Eigen::VectorXd &a, 
	                               const Eigen::VectorXd &b, 
	              	               const Eigen::VectorXd &c, 
								   const Eigen::VectorXd &d)
	{
	   int n = d.size();
	   Eigen::VectorXd result = Eigen::VectorXd::Zero(n); 
	   Eigen::VectorXd P = Eigen::VectorXd::Zero(n);   
	   Eigen::VectorXd Q = Eigen::VectorXd::Zero(n);   
	   result = P;

	   // Forward pass
	   P(0) = -c(0) / b(0);
	   Q(0) =  d(0) / b(0);

	   for (int i = 1; i < n; i++)
	   {
	      double denominator = b(i) + a(i - 1) * P(i - 1);
	      P(i) = -c(i - 1)                    / denominator;
	      Q(i) = (d(i) - a(i - 1) * Q(i - 1)) / denominator;
	   }

	   // Backward pass
	   result(n - 1) = Q(n - 1);
	   for (int i = n - 2; i >= 0; i--) 
	      result(i) = P(i) * result(i + 1) + Q(i);

	    return result;
	}
}