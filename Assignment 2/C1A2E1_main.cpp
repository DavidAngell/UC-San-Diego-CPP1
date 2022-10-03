/*
    Author: David Angell
    If the user enters the value of 30, then the prgram will print characters
    beyond the 26 letters in the alphabet. For the uppercase characters, characters
    with the values 91, 92, 93, and 94 (which correspond to '[', '\', ']', and '^' respectively).
    For the lowercase characters, the program will print the characters with the value 123, 124,
    125, and 126 (which correspond to '{', '|', '}', and '~').
*/
#include <iostream>

int main(int argc, char const *argv[]) {
    int userInput;
    std::cout << "Enter a positive decimal integer value: ";
    std::cin >> userInput;

    int uppercaseCharacterOffset = 65;
    int lowercaseCharacterOffset = 97;
    for (int i = 0; i < userInput; i++) {
        std::cout 
            << "'"
            << (char) (i + uppercaseCharacterOffset) 
            << "' --> '" 
            << (char) (i + lowercaseCharacterOffset) 
            << "'\n";
    }
    
    return 0;
}
