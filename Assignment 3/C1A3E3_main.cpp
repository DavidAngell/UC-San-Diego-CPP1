//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/11/2022
// C1A3E3_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//

#include <iostream>
#define BASE 10

int reverseInt(int num) {
    int reversed_number = 0;
    while(num != 0) {
        int remainder = num % BASE;
        reversed_number = reversed_number * BASE + remainder;
        num /= BASE;
    }
    return reversed_number;
}

std::string digitAsWord(int digit) {
    switch (digit) {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
}

std::string popLeastSignificantDigitInWords(int &num, std::string buffer) {
    int leastSignificantDigit = num % BASE;
    num /= BASE;
    return buffer + digitAsWord(leastSignificantDigit);
}

int main() {
    // Get user input
    int input;
    std::cout << "Enter an integer value: ";
    std::cin >> input;

    std::cout << "\"" << input << "\" in words is \"";

    // Reverse the input because the while loop goes in reverse order
    int reversedInput = reverseInt(input);

    /*
        Add minus to the front of the input in words if it is negative.
        Otherwise, pop the last digit of the reversed input and make 
        that the start of the ouput because otherwise the string would
        start with a space which is incorrect formatting.
    */
    std::string unreversedInputInWords = (input < 0) 
        ? "minus "
        : popLeastSignificantDigitInWords(reversedInput, "");

    // Pop the last digit and convert its corresponding word until
    // the reversed input has no more digits in it
    while (reversedInput != 0)
        unreversedInputInWords += popLeastSignificantDigitInWords(reversedInput, " ");

    // Print the input as words and add an ending quote 
    std::cout << unreversedInputInWords << "\"";

    return 0;
}