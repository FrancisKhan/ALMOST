#include "inputParser.h"
#include "Output.h"

#include <algorithm>
#include <iostream>
#include <sstream>  

namespace InputParser
{
    std::string removeTrailingSpaces(std::string &input)
    {
	    input.erase(std::find_if_not(input.rbegin(),input.rend(),
	             [](int c){return isspace(c);}).base(), input.end());  
	    return input;
    }

	std::string removeLeadingSpaces(std::string &input)
	{
		input.erase(input.begin(), std::find_if_not(input.begin(),input.end(),
		[](int c){return isspace(c);}));
		return input;
	}

	std::string removeSpaces(std::string &input)
    {
		std::string result = removeLeadingSpaces(input);
	    return removeTrailingSpaces(result);
    }

    std::vector<unsigned> findLine(std::vector<std::string> &dataVec, const std::string &key, 
								   unsigned inputLowerBound, unsigned inputUpperBound)
    {
        std::vector<unsigned> result {};
		unsigned lowerBound, upperBound, lineNumber; 

		if (inputUpperBound == std::numeric_limits<unsigned>::max())
		{
			lowerBound = 0;
			upperBound = dataVec.size();
			lineNumber = 0;
		}
    	else
		{
			lowerBound = inputLowerBound;
			upperBound = inputUpperBound;
			lineNumber = inputLowerBound;
		}

		for(unsigned i = lowerBound; i < upperBound; i++)
		{
			if(dataVec[i] == key) 
		    {
			    result.push_back(lineNumber);
		    }
		    lineNumber++;
		}

	    return result;
    }

    std::string findKeyword(std::vector<std::string> &dataVec, std::string toSearch, unsigned lowLimit, unsigned topLimit)
    {
	    bool keywordFound = false;
	    size_t pos = 0;
	    unsigned counter = 0;
	    std::string line = "";
	    for(auto itemLine : dataVec)
	    {
		    if(pos != std::string::npos && counter >= lowLimit && counter <= topLimit) 
		    {
			    line = itemLine;
			    keywordFound = true;
			    break;
		    }

		    counter++;
	    }

        if(keywordFound == false) 
	    {
		    out.print(TraceLevel::CRITICAL, "{} is missing from the input!", toSearch);
	        exit(-1);
	    }

	    return line;
    }

    std::string getLine(std::vector<std::string> &dataVec, unsigned i)
    {
	    return dataVec[i];
    }

	std::vector<std::string> splitLine(std::string line)
	{ 
		// ignore in line comments (that start with %)
		std::size_t found = line.find("%");
  		if (found != std::string::npos)
    	{
			line = line.substr(0, found);
		}

    	std::istringstream iss(line);
    	std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());
	
		return words;
	} 

	std::vector<double> fromStringVecToDoubleVec(std::vector<std::string> &strVec)
	{ 
		std::vector<double> dVec(strVec.size(), 0.0);
    	std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    	[](std::string &i){return std::stod(i);});
		return dVec;
	}

	bool isKeywordPresent(std::vector<std::string> &dataVec, const std::string &key, 
						  unsigned inputLowerBound, unsigned inputUpperBound)
    {
        std::vector<unsigned> lines = findLine(dataVec, key, inputLowerBound, inputUpperBound);

		if(lines.empty())
			return false;
		else
			return true;
    }
}
