//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E2_PrintLines-2.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// Overloads the PrintLines function to print the user's
// inputed character for the user's inputed count and repeats
// the line for the user's inputed line count
//

#include <iostream>

void PrintLines(char charValue, int charCount, int lineCount) {
    for (int line = 0; line < lineCount; line++) {
        for (int character = 0; character < charCount; character++) {
            std::cout << charValue;
        }
        std::cout << "\n";
    }
}