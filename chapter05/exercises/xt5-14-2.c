#include <stdio.h>
#include <math.h>

int main(){
    double x, x0 = 0, fx, fdx;
    x = 1.5;
    while (fabs(x - x0) >= 1e-5) {
        x0 = x;
        fx = x0 * (x0 * (2 * x0 - 4) + 3) - 6;
        fdx = x0 * (6 * x0 - 8) + 3;
        x = x0 - fx / fdx;
    }
    printf("The root of the equation near 1.5 is %f\n", x);

    return 0;
}