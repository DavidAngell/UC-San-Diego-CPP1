//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E2_PrintLines-1.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// Overloads the PrintLines function to print the inputted
// character once
//

#include <iostream>

/// @brief Prints the inputted character once
/// @param charValue 
void PrintLines(int charValue) {
    std::cout << static_cast<char>(charValue) << "\n";
}