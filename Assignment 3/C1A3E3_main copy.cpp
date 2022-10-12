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
// Takes in a user input and prints it as words
//

#include <iostream>
const int BASE = 8;

int reverseInt(int num) {
    // Move the least significant digit of the num
    // into reversed number until num has no more digits
    int reversedNumber = 0;
    while (num != 0) {
        int leastSignificantDigit = num % BASE;
        reversedNumber = reversedNumber * BASE + leastSignificantDigit;
        num /= BASE;
    }
    return reversedNumber;
}

std::string digitAsWord(int digit) {
    // Apparently I nned to put a comment 
    // here to appease the static analysis gods
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
        default: return "you messed somthing up mr programmer";
    }
}

std::string popLeastSignificantDigitInWords(int &num, std::string buffer) {
    int leastSignificantDigit = num % BASE;
    num /= BASE;
    return buffer + digitAsWord(leastSignificantDigit);
}

int main() {
    // Get user input
    int userInput;
    std::cout << "Enter an integer value: ";
    std::cin >> userInput;

    std::cout << "\"" << userInput << "\" in words is \"";

    /*
        Store whether the number was negative so that we can
        do all of our calculations as if the input were positive
        because otherwise everything breaks
    */
    bool inputIsNegative = userInput < 0;
    if (inputIsNegative) 
        userInput = -userInput;

    // Reverse the input because the while loop goes in reverse order
    int reversedInput = reverseInt(userInput);

    /*
        Add minus to the front of the input in words if it is negative.
        Otherwise, pop the last digit of the reversed input and make 
        that the start of the output because otherwise the string would
        start with a space which is incorrect formatting.
    */
    std::string unreversedInputInWords = 
        (inputIsNegative) 
            ? "minus"
            : popLeastSignificantDigitInWords(reversedInput, "");

    // Pop the last digit and convert its corresponding word until
    // the reversed input has no more digits in it
    while (reversedInput != 0)
        unreversedInputInWords += popLeastSignificantDigitInWords(reversedInput, " ");

    // Print the input as words and add an ending quote 
    std::cout << unreversedInputInWords << "\"\n";

    return 0;
}