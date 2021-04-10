/*
 * TextParser.cpp
 *
 *  Created on: 9 abr. 2021
 *      Author: david
 */

#include "TextParser.h"

#include <vector>
#include <sstream>
#include <exception>

#if defined _WIN32 || defined _WIN64
#include <direct.h>
#elif defined __linux__ || defined TARGET_OS_X
#include <sys/stat.h>
#endif

namespace textparser
{

TextParser::TextParser (numberchecker::INumberChecker* _pNumberChecker)
    : mp_NumberChecker(_pNumberChecker)
{
}

TextParser::~TextParser ()
{
}

void TextParser::OpenOriginTextFile (const std::string &_strFileName)
{
	m_OriginFile.open(_strFileName);
	if (!m_OriginFile.is_open())
		throw std::logic_error("Unable to open origin file: " + _strFileName);
}

bool TextParser::OpenDestinationTextFile (const std::string &_strFileName, bool _bOverwrite)
{
	if (!_bOverwrite && !FileExists(_strFileName))
		return false;

	m_DestinationFile.open(_strFileName);
	if (!m_DestinationFile.is_open())
		throw std::logic_error("Unable to destination origin file: " + _strFileName);
    
    return true;
}

void TextParser::CloseOriginTextFile ()
{
	if (m_OriginFile.is_open())
		m_OriginFile.close();
}

void TextParser::CloseDestinationTextFile ()
{
	if (m_DestinationFile.is_open())
		m_DestinationFile.close();
}

void TextParser::ParseTextFile ()
{
    bool pendingNum {false};
    std::vector<unsigned long int> vNum;
    unsigned long int num {0};
    std::string word, line;
	while (std::getline(m_OriginFile, line))
    {
        std::stringstream ssl (line);
        while (ssl >> word)
        {
            if (mp_NumberChecker->CheckWord(word, num, vNum.size() > 0))
            {
                if (num > 0)
                {
                    // checking if two numbers are the same, to separate them
                    if ((vNum.size() > 0 && vNum.back() != num) || vNum.size() == 0)
                    {
                        vNum.push_back(num);
                    }
                    else
                    {
                        m_DestinationFile << mp_NumberChecker->ComposeNumber(vNum) << ' ';
                        vNum.clear();
                        vNum.push_back(num);
                    }
                }
            }
            else
            {
                if (vNum.size())
                {
                    m_DestinationFile << mp_NumberChecker->ComposeNumber(vNum) << ' ';
                    vNum.clear();
                    if (pendingNum)
                    {
                        m_DestinationFile << std::endl;
                        pendingNum = false;
                    }
                }
                
                m_DestinationFile << word << ' ';
            }
        }
        if (vNum.size() == 0)
            m_DestinationFile << std::endl;
        else
            pendingNum = true;
    }
    
    if (vNum.size())
    {
        m_DestinationFile << mp_NumberChecker->ComposeNumber(vNum) << ' ';
    }
}

bool TextParser::FileExists(const std::string& _strFileName)
{
#if defined _WIN32 || defined _WIN64
    return false;
#elif defined __linux__ || defined TARGET_OS_X
	struct stat buf;
	if (stat(_strFileName.c_str(), &buf) != -1)
	{
		return true;
	}
#endif
	return false;
}

} // namespace textparser
