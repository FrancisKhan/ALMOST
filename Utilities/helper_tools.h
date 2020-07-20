#ifndef HELPER_TOOLS_H
#define HELPER_TOOLS_H

#include <algorithm>
#include <vector>

namespace HelperTools
{
    template <typename T>
    inline bool isElementHere(const std::vector<T>& vec, const T& elem)
    {
        typename std::vector<T>::const_iterator it = find(vec.begin(), vec.end(), elem);

        if(it != vec.end())
            return true;
        else
            return false;
    }

    template <typename T>
    inline bool isElementNotHere(const std::vector<T>& vec, const T& elem)
    {
        return !isElementHere(vec, elem);
    }
}

#endif