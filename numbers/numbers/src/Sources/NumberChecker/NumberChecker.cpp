//
//  NumberChecker.cpp
//  numbers
//
//  Created by David Cervello Batlle on 9/4/21.
//

#include "NumberChecker.h"

namespace numberchecker
{

NumberChecker::NumberChecker()
{
    
}

NumberChecker::~NumberChecker()
{
    
}

bool NumberChecker::CheckWord(const std::string& _strWord, unsigned long int& _number, bool _bHasPreviousNumbers)
{
    if (_bHasPreviousNumbers && _strWord == msz_And)
    {
        _number = 0;
        return true;
    }
    
    for (auto num : mv_Numbers)
    {
        if (num.first == _strWord)
        {
            _number = num.second;
            return true;
        }
    }
    return false;
}

unsigned long int NumberChecker::ComposeNumber(const std::vector<unsigned long int>& _vNum)
{
    unsigned long int res {0}, partRes {0}, lastNum {0};
    
    auto itNum = _vNum.begin();
    while (itNum != _vNum.end())
    {
        if (lastNum > 0)
        {
            if (*itNum > lastNum)
                partRes *= *itNum;
            else
            {
                partRes += *itNum;
            }
        }
        else
        {
            partRes = *itNum;
        }
        lastNum = *itNum;
        if (*itNum >= 100)
        {
            if (res == 0)
                res += partRes;
            else if (res > 0 && partRes > res)
                res *= partRes;
            else
                res += partRes;
            partRes = 0;
            lastNum = 0;
        }
        
        ++itNum;
    }
    
    res += partRes;
    
    return res;
}

// number strings
const tdVectorNumber NumberChecker::mv_Numbers ({
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90},
    {"hundred", 100},
    {"thousand", 1000},
    {"million", 1000000},
    {"billion", 1000000000}
});

const std::string NumberChecker::msz_And    ("and");

}
