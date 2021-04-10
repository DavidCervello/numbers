README:

Application ‘numbers’:
To be called with 2 parameters:
- origin file to parse
- destination file to write the results
If the destination file already exists, it will ask to overwrite it. If permission is denied, the application will exit.

Application architecture:
The code has been divided into 2 main classes: TextParser and NumberChecker.
TextParser opens the origin and destination file and parses the text in origin. It separates every word to pass it to NumberChecker to find numbers.
TextParser stores every converted digit into an array and after the last word corresponding to a number is found, then calls NumberChecker to convert the digit array to a number.
NumberChecker compares every word to check if it contains a number. Then it converts every array of numbers to a composed number.

Improvements:
TextParser checking on destination file existence only works on Linux and MacOS. As I don’t have a Windows environment to test the application, I decided that in Windows would always overwrite the destination file.
There is a particular corner case that has not been solved. For instance, if we have the text:

I have found one hundred
fifty one and fifty coins.

Should be converted into:

I have found 151
and 50 coins.

But it is converted into:

I have found 7550 
coins.

Other particular cases are, for example, the use of quotations marks. As TextParser parses the text as words separated by an space, it can’t detect this particular case.

Another improvement I haven’t had time to do, especially as I can’t test it in Windows environment, is to put TextParser and NumberChecker classes into a shared library and then load the library
from the any application.
Related to use a shared library, I could have hide the implementation of both classes using design patterns and export only the interfaces and the builder class.

This is not an improvement to make, but the application accepts ‘rare’ cases as for example “fifty hundred” and parses it as “5000”.


