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
// This program takes in an octal integer from
// the user and outputs the reverse of whatever 
// input was given
//

#include <iostream>
const int BASE = 8;

int main() {
    // Get user input
    int userInput;
    std::cout << "Enter an octal integer value: ";
    std::cin >> std::oct >> userInput;

    /*
        Store whether the number was negative so that we can
        do all of our calculations as if the input were positive
        because "std::cout << std::oct << userInput" seems to 
        treat userInput as unsigned, leading to the outputted number
        being absurdly large
    */
    bool isNegative = userInput < 0; 
    if (isNegative) 
        userInput = -userInput;

    // Move the least significant digit of the user input
    // into reversed number until the input has no more digits
    int reversedNumber = 0;
    int inputCopy = userInput;
    while (inputCopy != 0) {
        int leastSignificantDigit = inputCopy % BASE;
        reversedNumber = reversedNumber * BASE + leastSignificantDigit;
        inputCopy /= BASE;
    }

    // Print the initial user input and the reversed number 
    // and append "-" if the original input was negative
    std::cout << std::oct
        << "\""
        << (isNegative ? "-" : "")
        << userInput 
        << "\" in reverse is \""
        << reversedNumber 
        << (isNegative ? "-" : "")
        << "\"\n";
    
    return 0;
}
