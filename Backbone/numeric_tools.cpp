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
                msg += stringFormat(A(i, j, h), "%7.6e") + " ";
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
			msg += stringFormat(A(i, j), "%7.6e") + " ";
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
			output.getLogger()->critical("{:7.6e}", vec(i));
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{:7.6e}", vec(i));
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{:7.6e}", vec(i));
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{:7.6e}", vec(i));
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{:7.6e}", vec(i));
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{:7.6e}", vec(i));
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
		std::cout << "PrintVector::Vector nullptr!" << std::endl;
		return;
	}

	for(unsigned i = 0; i < vec.size(); i++)
	{
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{}", vec[i]);
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{}", vec[i]);
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{}", vec[i]);
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{}", vec[i]);
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{}", vec[i]);
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{}", vec[i]);
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

void printVector(std::vector<MaterialKind> vec, Output output, TraceLevel level)
{	
    if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintVector::Vector nullptr!" << std::endl;
		return;
	}

	for(auto i : vec)
	{
        std::ostringstream stream;
		stream << i;

		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{}", stream.str());
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{}", stream.str());
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{}", stream.str());
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{}", stream.str());
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{}", stream.str());
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{}", stream.str());
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

void printVector(std::vector<double> vec, Output output, TraceLevel level)
{	
    if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintVector::Vector nullptr!" << std::endl;
		return;
	}

	for(unsigned i = 0; i < vec.size(); i++)
	{
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{:7.6e}", vec[i]);
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{:7.6e}", vec[i]);
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{:7.6e}", vec[i]);
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{:7.6e}", vec[i]);
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{:7.6e}", vec[i]);
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{:7.6e}", vec[i]);
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

bool isFloat(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	auto dotFound = std::find_if(s.begin(), s.end(), [](char c) {return c == '.';});

	if(dotFound != s.end()) 
	{
		std::string beforeDot = std::string(s.begin(), dotFound);
		std::string afterDot  = std::string(dotFound + 2, s.end());

        // It includes E e + - to account for scientific notation numbers
		auto isDigitLambda = [](char c){return (std::isdigit(c) 
		|| c =='E' || c =='e' || c =='+' || c == '-');};

		if (std::all_of(beforeDot.begin(), beforeDot.end(), isDigitLambda) &&
		    std::all_of(afterDot.begin(), afterDot.end(), isDigitLambda))
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}

	return result;
}

bool isInteger(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	if (std::all_of(s.begin(), s.end(), [](char c){return std::isdigit(c);}))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool isString(const std::string& s)
{
	bool result = false;

	if (s.empty()) return result;

	if (isalpha(s.front()))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

void printMatrix(MatrixXld A, Output output, TraceLevel level)
{
	if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::MatrixXld nullptr!" << std::endl;
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

void printVector(VectorXld vec, Output output, TraceLevel level)
{	
    if(output.getLogger() == nullptr) 
	{
		std::cout << "PrintMatrix::VectorXd nullptr!" << std::endl;
		return;
	}

	for(int i = 0; i < vec.size(); i++)
	{
		if (level == TraceLevel::CRITICAL)
			output.getLogger()->critical("{:7.6e}", vec(i));
	    else if (level == TraceLevel::ERROR)
			output.getLogger()->error("{:7.6e}", vec(i));
		else if (level == TraceLevel::WARN)
			output.getLogger()->warn("{:7.6e}", vec(i));
		else if (level == TraceLevel::INFO)
			output.getLogger()->info("{:7.6e}", vec(i));
		else if(level == TraceLevel::DEBUG)
			output.getLogger()->debug("{:7.6e}", vec(i));
		else if(level == TraceLevel::TRACE)
			output.getLogger()->trace("{:7.6e}", vec(i));
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

// These lines are needed to convert a string to a string 
// in a specific format
std::string stringFormat(double number, std::string format)
{
	char buffer[32];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), format.c_str(), number);
    std::string numberString(buffer);
	return numberString;
}

// These lines are needed to convert a double to a string 
// in a specific format
std::string stringFormat(std::string numberStr, std::string format)
{
	double number = std::stod(numberStr);
	char buffer[32];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), format.c_str(), number);
    std::string numberString(buffer);
	return numberString;
}