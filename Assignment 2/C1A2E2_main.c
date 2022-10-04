//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/3/2022
// C1A2E2_main.c
// Ubuntu 20.04
// GCC 6.3.0
//

#include <stdio.h>

#define DIAGONAL_CHAR "$"

int main(void) {
    int userInput;
    printf("Enter any positive decimal integer: ");
    scanf("%d", &userInput);

    int count = userInput;
    for (int row = 0; row < userInput; row++) {
        for (int col = 0; col < row; col++) {
            int countOnesPlace = count % 10;
            printf("%d", countOnesPlace);
            count++;
        }

        printf("%s\n", DIAGONAL_CHAR);
    }
    
    return 0;
}
