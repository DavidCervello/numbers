/*
 * ITextParser.h
 *
 *  Created on: 9 abr. 2021
 *      Author: david
 */

#ifndef NUMBERS_INCLUDES_TEXTPARSER_ITEXTPARSER_H_
#define NUMBERS_INCLUDES_TEXTPARSER_ITEXTPARSER_H_

#include <string>

namespace textparser
{

class ITextParser
{
public:
	virtual ~ITextParser () {};

	/**
	 * Function to open the text file to read.
	 * @_strFileName route to file
	 */
	virtual void OpenOriginTextFile (const std::string &_strFileName) = 0;

	/**
	 * Function to open the text file to write the output.
	 * @_strFileName route to file
	 * @_bOverwirte true to overwrite existing file, false otherwise
	 * @return true if file opened, false if file already exists
	 */
	virtual bool OpenDestinationTextFile (const std::string &_strFileName, bool _bOverwrite = false) = 0;

	/**
	 * Function to close the origin previously opened text file.
	 */
	virtual void CloseOriginTextFile () = 0;

	/**
	 * Function to close the destination previously opened text file.
	 */
	virtual void CloseDestinationTextFile () = 0;

	/**
	 * Function to parse the origin text file already opened and
	 * writes the output into the destination file.
	 * Checks for written numbers and converts them to digits.
	 * Leaves the rest of the text as it is.
	 */
	virtual void ParseTextFile () = 0;
};

}	/* namespace textparser */

#endif /* NUMBERS_INCLUDES_ITEXTPARSER_H_ */
