//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/3/2022
// C1A2E1_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// If the user enters the value of 30, then the program will print characters
// beyond the 26 letters in the alphabet. For the uppercase characters, characters
// with the values 91, 92, 93, and 94 (which correspond to '[', '\', ']', and '^' respectively).
// For the lowercase characters, the program will print the characters with the value 123, 124,
// 125, and 126 (which correspond to '{', '|', '}', and '~').
//

#include <iostream>

int main() {
    const char UPPERCASE_START = 'A';
    const char LOWERCASE_START = 'a';

    // Get a number from the user
    int userInput;
    std::cout << "Enter a positive decimal integer value: ";
    std::cin >> userInput;

    // Iterate over letters of the alphabet (0-25) for all letters less than the
    // value inputted by the user (where 0 = A/a and 25 = Z/z) and print them
    for (int letterNum = 0; letterNum < userInput; letterNum++) {
        char uppercaseLetter = char(UPPERCASE_START + letterNum);
        char lowercaseLetter = char(LOWERCASE_START + letterNum);
        std::cout << "'" << uppercaseLetter << "' --> '" << lowercaseLetter << "'\n";
    }
    
    return 0;
}
