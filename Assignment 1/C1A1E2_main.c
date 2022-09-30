#include <stdio.h>

int main() {
    printf("Enter any number: ");
    
    double x;
    scanf("%lf", &x);
    double xAfterEquation = 3*x*x*x - 5*x*x - 6;

    printf("If x = %g the value of \"3x^3 - 5x^2 + 6\" is %g\n", x, xAfterEquation);

    return 0;
}