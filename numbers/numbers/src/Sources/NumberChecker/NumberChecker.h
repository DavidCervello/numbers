//
//  NumberChecker.hpp
//  numbers
//
//  Created by David Cervello Batlle on 9/4/21.
//

#ifndef NumberChecker_h
#define NumberChecker_h

#include "../../../src/Includes/INumberChecker.h"

#include <vector>
#include <string>

namespace numberchecker
{

typedef std::pair<std::string, unsigned int> tdNumber;
typedef std::vector<tdNumber> tdVectorNumber;

class NumberChecker : public INumberChecker
{
public:
    NumberChecker();
    ~NumberChecker();
    
    bool CheckWord(const std::string& _strWord, unsigned long int& _number, bool _bHasPreviousNumbers);
    unsigned long int ComposeNumber(const std::vector<unsigned long int>& _vNum);
    
private:
    static const tdVectorNumber mv_Numbers;
    static const std::string msz_And;
};

} /* namespace numberchecker */
#endif /* NumberChecker_h */
