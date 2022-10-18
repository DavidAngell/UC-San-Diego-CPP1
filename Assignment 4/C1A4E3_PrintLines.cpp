//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E3_PrintLines.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// Overloads the PrintLines function to print the inputted 
// character for the inputted count and repeats
// the line for the inputted line count
//

#include <iostream>

/// @brief Prints the inputted character for the inputted count
///        and repeats the line for the inputted line count
///
/// @param charValue The character to print
/// @param charCount The number of times to print the character
/// @param lineCount The number of times to repeat the line
void PrintLines(int charValue, int charCount, int lineCount) {
    // Print the line lineCount times
    for (int line = 0; line < lineCount; line++) {
        // Print the character cout times
        for (int character = 0; character < charCount; character++) {
            std::cout << static_cast<char>(charValue);
        }

        std::cout << "\n";
    }
}