#include "additionalPrintFuncs.h"

#include <iostream>

using namespace Numerics;

namespace PrintFuncs
{
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
			else if (level == TraceLevel::ERR)
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
				else if (level == TraceLevel::ERR)
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
		else if (level == TraceLevel::ERR)
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

	void printMatrix(Eigen::MatrixXd A, Output output, TraceLevel level, bool asVector)
	{
		if(output.getLogger() == nullptr) 
		{
			std::cout << "PrintMatrix::MatrixXd nullptr!" << std::endl;
			return;
		}

		if(asVector)
		{
			for(int i = 0; i < A.rows(); i++)
	    	{
		    	for(int j = 0; j < A.cols(); j++)
		    	{
					std::string msg = stringFormat(A(i, j), "%7.6e");
		
		    		if (level == TraceLevel::CRITICAL)
			    		output.getLogger()->critical(msg);
		    		else if (level == TraceLevel::ERR)
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
		}
		else
		{
			for(int i = 0; i < A.rows(); i++)
	    	{
				std::string msg;
		
		    	for(int j = 0; j < A.cols(); j++)
		    	{
					msg += stringFormat(A(i, j), "%7.6e") + " ";
		    	}
		
		    	if (level == TraceLevel::CRITICAL)
			    	output.getLogger()->critical(msg);
		    	else if (level == TraceLevel::ERR)
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
		else if (level == TraceLevel::ERR)
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

	void printVector(Eigen::VectorXd vec, Output output, TraceLevel level, bool isVertical, bool endline)
	{	
	    if(output.getLogger() == nullptr) 
		{
			std::cout << "PrintMatrix::VectorXd nullptr!" << std::endl;
			return;
		}

		if(isVertical)
		{
			for(int i = 0; i < vec.size(); i++)
			{
				if (level == TraceLevel::CRITICAL)
					output.getLogger()->critical("{:7.6e}", vec(i));
		    	else if (level == TraceLevel::ERR)
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
		}
		else
		{
			std::string msg;

			for(unsigned i = 0; i < vec.size(); i++)
				msg += stringFormat(vec[i], "%7.6e") + " ";

			if (level == TraceLevel::CRITICAL)
				output.getLogger()->critical("{}", msg);
		    else if (level == TraceLevel::ERR)
				output.getLogger()->error("{}", msg);
			else if (level == TraceLevel::WARN)
				output.getLogger()->warn("{}", msg);
			else if (level == TraceLevel::INFO)
				output.getLogger()->info("{}", msg);
			else if(level == TraceLevel::DEBUG)
				output.getLogger()->debug("{}", msg);
			else if(level == TraceLevel::TRACE)
				output.getLogger()->trace("{}", msg);
			else {}
		}
		
		if(isVertical && endline)
		{
			if (level == TraceLevel::CRITICAL)
				output.getLogger()->critical(" ");	
			else if (level == TraceLevel::ERR)
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
	}

	void printVector(std::vector<std::string> vec, Output output, TraceLevel level, bool isVertical)
	{	
	    if(output.getLogger() == nullptr) 
		{
			std::cout << "PrintVector::Vector nullptr!" << std::endl;
			return;
		}

		if(isVertical)
		{
			for(unsigned i = 0; i < vec.size(); i++)
			{
				if (level == TraceLevel::CRITICAL)
					output.getLogger()->critical("{}", stringFormat(vec[i],"%7.6e"));
		    	else if (level == TraceLevel::ERR)
					output.getLogger()->error("{}", stringFormat(vec[i],"%7.6e"));
				else if (level == TraceLevel::WARN)
					output.getLogger()->warn("{}", stringFormat(vec[i],"%7.6e"));
				else if (level == TraceLevel::INFO)
					output.getLogger()->info("{}", stringFormat(vec[i],"%7.6e"));
				else if(level == TraceLevel::DEBUG)
					output.getLogger()->debug("{}", stringFormat(vec[i],"%7.6e"));
				else if(level == TraceLevel::TRACE)
					output.getLogger()->trace("{}", stringFormat(vec[i],"%7.6e"));
				else {}
			}
		}
		else
		{
			std::string msg;

			for(unsigned i = 0; i < vec.size(); i++)
				msg += stringFormat(vec[i], "%7.6e") + " ";

			if (level == TraceLevel::CRITICAL)
				output.getLogger()->critical("{}", msg);
		    else if (level == TraceLevel::ERR)
				output.getLogger()->error("{}", msg);
			else if (level == TraceLevel::WARN)
				output.getLogger()->warn("{}", msg);
			else if (level == TraceLevel::INFO)
				output.getLogger()->info("{}", msg);
			else if(level == TraceLevel::DEBUG)
				output.getLogger()->debug("{}", msg);
			else if(level == TraceLevel::TRACE)
				output.getLogger()->trace("{}", msg);
			else {}
		}

		if(isVertical)
		{
			if (level == TraceLevel::CRITICAL)
				output.getLogger()->critical(" ");	
			else if (level == TraceLevel::ERR)
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
		    else if (level == TraceLevel::ERR)
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
		else if (level == TraceLevel::ERR)
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

	// These lines are needed to a string (number) to a string 
	// in a specific format
	std::string stringFormat(std::string numberStr, std::string format)
	{
		if(isString(numberStr)) return numberStr;

		double number = std::stod(numberStr);
		char buffer[32];
		memset(buffer, 0, sizeof(buffer));
	    snprintf(buffer, sizeof(buffer), format.c_str(), number);
	    std::string numberString(buffer);
		return numberString;
	}

	// These lines are needed to convert an unsigend to a string 
	// in a specific format
	std::string stringFormat(unsigned number, std::string format)
	{
		char buffer[32];
 	    memset(buffer, 0, sizeof(buffer));
 	    snprintf(buffer, sizeof(buffer), format.c_str(), number);
 	    std::string numberString(buffer);
		return numberString;
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
}
