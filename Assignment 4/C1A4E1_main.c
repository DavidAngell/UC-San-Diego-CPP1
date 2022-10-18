//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E1_main.c
// Ubuntu 20.04
// GCC 6.3.0
//
// A program that will prompt the user for two double
// values and then display the maximum and minimum of
// the two values.
//

#include <stdio.h>
#include "C1A4E1_ComputeMinMax.h"

int main(void) {
    // Get two double inputs from the user
    double value1, value2;
    printf("Enter two values separated by a space: ");
    scanf("%lf %lf", &value1, &value2);

    // Compute the minimum and maximum of the two values
    double minimum = ComputeMinimum(value1, value2);
    double maximum = ComputeMaximum(value1, value2);

    // Display the results
    printf(
        "ComputeMinimum(%lf, %lf) returned %lf\n", 
        value1, value2, minimum
    );

    printf(
        "ComputeMaximum(%lf, %lf) returned %lf\n", 
        value1, value2, maximum
    );

    return 0;
}
