//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/3/2022
// C1A2E3_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//

#include <iostream>

const char DIAGONAL_CHAR = '$';

int main(int argc, char const *argv[]) {
    int userInput;
    std::cout << "Enter any positive decimal integer: ";
    std::cin >> userInput;

    int count = userInput;
    for (size_t row = 0; row < userInput; row++) {
        for (size_t col = 0; col < row; col++) {
            std::cout << count % 10;
            count++;
        }

        std::cout << DIAGONAL_CHAR << "\n";
    }
    
    return 0;
}
