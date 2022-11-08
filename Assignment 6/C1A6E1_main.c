//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 11/1/2022
// C1A6E1_main.c
// Ubuntu 20.04
// GCC 6.3.0
//
// A program that prompts the user for a string and then prints 
// the length of the string using the MyStrlen function and the
// strlen function from the standard library.
//

#include <stdio.h>
#include <string.h>
#include "C1A6E1_MyStrlen.h"
#define MAX_STR_LEN 100

int main(void) {
    // Get user input using fgets
    char input[MAX_STR_LEN];
    printf("Enter a string: ");
    fgets(input, MAX_STR_LEN, stdin);

    // Remove the newline character from the end of the input
    input[strcspn(input, "\n")] = '\0';

    // Print the lengths of the string
    printf("strlen(\"%s\") returned %zu\n", input, strlen(input));
    printf("MyStrlen(\"%s\") returned %zu\n", input, MyStrlen(input));

    return 0;
}
