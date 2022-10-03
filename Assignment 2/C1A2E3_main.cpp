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
