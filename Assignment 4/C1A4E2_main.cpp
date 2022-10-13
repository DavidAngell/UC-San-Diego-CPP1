//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E2_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// Prompts the user for a character, a count, and a line count, 
// then prints a character count times for count lines,
// then prints a character count times for 1 line,
// then prints the character once, and finally, prints 'Z' once.
//

#include "C1A4E2_PrintLines.h"
#include <iostream>

int main() {
    // Prompt the user for a character, a count, and a line count
    char charValue;
    int charCount, lineCount;
    std::cout << 
        "Enter a character, a count, " 
        "and a line count separated by spaces: ";
    std::cin >> charValue >> charCount >> lineCount;

    // Print the lines
    PrintLines(charValue, charCount, lineCount);
    PrintLines(charValue, charCount);
    PrintLines(charValue);
    PrintLines();

    return 0;
}