//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/10/2022
// C1A3E1_main.c
// Ubuntu 20.04
// GCC 6.3.0
//
// Description:
// Print the sum of the cubes of every integer starting from
// 0 up to and including whatever integer the user enters.
//
// Improvements:
// If we wanted to fix this so that we are no longer limited 
// by the max value of a short, we could store an array of ints
// with each element representing a digit of the last sum. 
// This way, we could add and print digit by digit like 
// a human would when they are adding together big numbers.
// Such a solution would still be limited by the max of the
// cubic that we calculate for each interation, but the size 
// of the number we need to store and print would grow much
// slower. 
//

#include <stdio.h>

int main(void) {
    // Get the user input
    int userInput;
    printf("Enter the number for your cubic sum: ");
    scanf("%i", &userInput);

    printf(
        "nbr    cubic sum\n"
        "----------------\n"
    );

    // Calculate the cube of each nbr and add it to
    // the previous sum until the number that the user inputs
    short lastCubeSum = 0;
    for (short nbr = 0; nbr <= userInput; nbr++) {
        lastCubeSum += nbr * nbr * nbr;
        printf("%3i %10i\n", nbr, lastCubeSum);
    }

    return 0;
}
