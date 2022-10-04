//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/3/2022
// C1A1E2_main.c
// Ubuntu 20.04
// GCC 6.3.0
//

#include <stdio.h>

int main(void) {
    printf("Enter any number: ");
    
    double x;
    scanf("%lf", &x);
    double xAfterEquation = 3 * x * x * x - 5 * x * x + 6;

    printf("If x = %g the value of \"3x^3 - 5x^2 + 6\" is %g\n", x, xAfterEquation);

    return 0;
}
