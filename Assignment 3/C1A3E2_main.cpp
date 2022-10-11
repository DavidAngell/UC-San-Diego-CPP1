//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/10/2022
// C1A3E2_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//

#include <iostream>
#define BASE 8

int main() {
    int octalInput;
    std::cout << "Enter an octal integer value: ";
    std::cin >> std::oct >> octalInput;

    std::cout << "\"" << std::oct << octalInput << "\" in reverse is \"";

    bool isNegative = octalInput <= 0; 
    int reversed = 0;
    while (octalInput != 0) {
        int leastSignificantDigit = octalInput % BASE;
        reversed = reversed * BASE + leastSignificantDigit;
        octalInput /= BASE;
    }

    std::cout << std::oct << reversed << ((isNegative) ? "-\"" : "\"");
    
    return 0;
}
