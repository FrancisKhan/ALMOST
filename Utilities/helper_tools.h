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

    inline bool isElementHere(const std::vector<SolverData>& vec, const SolverKind& elem)
    {
        bool result = false;

        for(SolverData i : vec)
        {
            if(i.getKind() == elem)
                result = true;
        }

        return result;
    }

    template <typename T>
    inline bool isElementNotHere(const std::vector<T>& vec, const T& elem)
    {
        return !isElementHere(vec, elem);
    }

    inline bool isElementNotHere(const std::vector<SolverData>& vec, const SolverKind& elem)
    {
        return !isElementHere(vec, elem);
    }
}

#endif