//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E4_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// Asks the for 3 space-separated values and prints the 
// maximum of the three values using a macro and an inline function
//

#include "C1A4E4_MaxOf.h"
#include <iostream>

int main() {
    // Prompt the user for 3 space-separated long double values
    std::cout << "Enter 3 space-separated long double values: ";
    long double value1, value2, value3;
    std::cin >> value1 >> value2 >> value3;

    // Output the maximum of the 3 values using the macro
    std::cout 
        << "mMaxOf3(" << value1 << ", " << value2 << ", " << value3 << ")"
           " returned " 
        << mMaxOf3(value1, value2, value3) 
        << "\n";

    // Output the maximum of the 3 values using the inline function
    std::cout 
        << "fMaxOf3(" << value1 << ", " << value2 << ", " << value3 << ")"
           " returned " 
        << fMaxOf3(value1, value2, value3)
        << "\n";

    return 0;
}