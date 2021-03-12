#include "inputParser.h"
#include "Output.h"

#include <algorithm>
#include <iostream>


namespace InputParser
{
    std::string removeTrailingSpaces(std::string &input)
    {
	    input.erase(std::find_if_not(input.rbegin(),input.rend(),
	             [](int c){return isspace(c);}).base(), input.end());  
	    return input;
    }

    std::vector<unsigned> findLine(std::vector<std::string> &dataVec, const std::string &key)
    {
        std::vector<unsigned> result {};
        unsigned lineNumber = 0;

	    for(auto itemLine : dataVec)
	    {
		    if(itemLine == key) 
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
}
