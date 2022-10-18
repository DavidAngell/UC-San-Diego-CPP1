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
// Overloads the PrintLines function to print the
// inputted character for the inputted count
//

#include <iostream>

/// @brief Prints the inputted character for the inputted count
/// @param charValue The character to print
/// @param charCount The number of times to print the character
void PrintLines(int charValue, int charCount) {
    // Print the character cout times
    for (int character = 0; character < charCount; character++) {
        std::cout << static_cast<char>(charValue);
    }
    
    std::cout << "\n";
}