#include "C1A4E1_ComputeMaximum.h"
#include "C1A4E1_ComputeMinimum.h"
#include <stdio.h>

int main(void) {
    // Get two double inputs from the user
    double value1, value2;
    printf("Enter two values separted by a space: ");
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