#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>

namespace InputParser
{
    std::string removeTrailingSpaces(std::string &input);
	std::vector<unsigned> findLine(std::vector<std::string> &dataVec, const std::string &key);
	std::string findKeyword(std::string toSearch, unsigned lowLimit = 0, 
	unsigned topLimit = std::numeric_limits<unsigned>::max());
    std::string getLine(std::vector<std::string> &dataVec, unsigned i);
}

#endif