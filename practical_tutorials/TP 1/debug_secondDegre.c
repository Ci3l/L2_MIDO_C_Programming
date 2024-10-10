#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c;
    double x = 1, x1 = 0, x2 = 0;

    printf("a ? ");
    scanf("%lf", &a);
    printf("b ? ");
    scanf("%lf", &b);
    printf("c ? ");
    scanf("%lf", &c);

    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("Il n'y a pas de solutions reelles.\n");
    } else if ((delta > 0)) {
        x1 = (-b + sqrt(delta))/(2 * a);
        x2 = (-b - sqrt(delta)) /(2 * a);
        printf("Deux solutions : %f et %f\n", x1, x2);
    } else {
        x = -b/(2*a);
        printf("Solution double : %f\n", x);
    }
    
    return 0;
}