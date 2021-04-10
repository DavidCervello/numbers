/*
 * TextParser.h
 *
 *  Created on: 9 abr. 2021
 *      Author: david
 */

#ifndef SRC_SOURCES_TEXTPARSER_TEXTPARSER_H_
#define SRC_SOURCES_TEXTPARSER_TEXTPARSER_H_

#include "../../Includes/ITextParser.h"
#include "../../Includes/INumberChecker.h"

#include <string>
#include <iostream>
#include <fstream>
#include <memory>

namespace textparser
{

class TextParser : public ITextParser
{
public:
	TextParser (numberchecker::INumberChecker* _pNumberChecker);
	~TextParser ();

	void OpenOriginTextFile (const std::string &_strFileName);
	bool OpenDestinationTextFile (const std::string &_strFileName, bool _bOverwrite = false);
	void CloseOriginTextFile ();
	void CloseDestinationTextFile ();
	void ParseTextFile ();

private:
	/**
	 * Checks whether a file exists or not
	 * @_strFileName file path to check
	 * @return true if the file exists, false otherwise
	 */
	bool FileExists(const std::string& _strFileName);

	std::ifstream m_OriginFile;
	std::ofstream m_DestinationFile;
    numberchecker::INumberChecker* mp_NumberChecker;
};

} /* namespace textparser */

#endif /* SRC_SOURCES_TEXTPARSER_TEXTPARSER_H_ */
