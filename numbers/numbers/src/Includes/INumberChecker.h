//
//  INumberChecker.h
//  numbers
//
//  Created by David Cervello Batlle on 9/4/21.
//

#ifndef INumberChecker_h
#define INumberChecker_h

#include <string>

namespace numberchecker
{

class INumberChecker
{
public:
    virtual ~INumberChecker() {};
    
    /**
     * Function to check whether a word is a number or not
     */
    virtual bool CheckWord(const std::string& _strWord, unsigned long int& _number, bool _bHasPreviousNumbers) = 0;
    
    /**
     * Function to compose a number from a parsed vector of numbers
     * @_vNum vector of parsed numbers
     * @return composed number
     */
    virtual unsigned long int ComposeNumber(const std::vector<unsigned long int>& _vNum) = 0;
};

} /* namespace numberchecker */

#endif /* INumberChecker_h */
