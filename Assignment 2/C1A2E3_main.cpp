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

int main() {
    // Get user input
    int userInput;
    std::cout << "Enter any positive decimal integer: ";
    std::cin >> userInput;
    
    // set user input equal to the starting count to that the 
    // first digit printed is equal to the ones place of the user input
    int count = userInput;

    // print the triangle row by row and column by column, adding
    // the DIAGONAL_CHAR to the last column of each row (starting from 0)
    for (int row = 0; row < userInput; row++) {
        for (int col = 0; col < row; col++) {
            int countOnesPlace = count % 10;
            std::cout << countOnesPlace;
            count++;
        }

        std::cout << DIAGONAL_CHAR << "\n";
    }
    
    return 0;
}