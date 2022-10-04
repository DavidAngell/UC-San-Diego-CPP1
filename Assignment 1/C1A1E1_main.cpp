//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/3/2022
// C1A1E1_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//

#include <iostream>

int main() {
    std::cout 
        << "Enter two space-separated positive integer numeric values."
        << "The first must be in hexadecimal while the second must be in octal."
        << "Do not precede the values with 0x or 0\n";
    
    int hexAsDecimal, octalAsDecimal;
    std::cin 
        >> std::hex >> hexAsDecimal
        >> std::oct >> octalAsDecimal;
    
    std::cout 
        << std::hex << hexAsDecimal << " hexadecimal = "
        << std::oct << hexAsDecimal << " octal = "
        << std::dec << hexAsDecimal << " decimal\n"

        << std::oct << octalAsDecimal << " octal = "
        << std::hex << octalAsDecimal << " hexadecimal = "
        << std::dec << octalAsDecimal << " decimal\n";

    return 0;
}