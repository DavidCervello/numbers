#include "src/Sources/TextParser/TextParser.h"
#include "src/Sources/NumberChecker/NumberChecker.h"

#include <iostream>
#include <memory>

int main (int argc, char **argv)
{
    std::unique_ptr<textparser::ITextParser> textParser;
    std::unique_ptr<numberchecker::INumberChecker> numberChecker;
    
    numberChecker.reset(new numberchecker::NumberChecker());
    textParser.reset(new textparser::TextParser(numberChecker.get()));

    if (argc != 3)
    {
        std::cout << "Invalid number of arguments, 2 expected" << std::endl;
        return -1;
    }

    std::string origFile(argv[1]);
    std::string destFile(argv[2]);

    std::cout << "File to parse: " << origFile << std::endl
              << "Destination file: " << destFile << std::endl;

    try
    {
        textParser->OpenOriginTextFile(origFile);
        if (!textParser->OpenDestinationTextFile(destFile))
        {
            char c ('\0');
            std::cout << "Want to overwrite destination file [y/n]? ";
            std::cin >> c;
            std::cout << std::endl;
            if (c == 'y')
                textParser->OpenDestinationTextFile(destFile, true);
        }
    } catch (const std::exception& e)
    {
            std::cout << e.what() << std::endl;
            return -1;
    }
    
    textParser->ParseTextFile();

    textParser->CloseOriginTextFile();
    textParser->CloseDestinationTextFile();

    return 0;
}
