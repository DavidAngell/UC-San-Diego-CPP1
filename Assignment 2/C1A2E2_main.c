#include <stdio.h>

#define DIAGONAL_CHAR "$"

int main(int argc, char const *argv[]) {
    int userInput;
    printf("Enter any positive decimal integer: ");
    scanf("%d", &userInput);

    int count = userInput;
    for (size_t row = 0; row < userInput; row++) {
        for (size_t col = 0; col < row; col++) {
            printf("%d", count % 10);
            count++;
        }

        printf(DIAGONAL_CHAR);
        printf("\n");
    }
    
    return 0;
}
