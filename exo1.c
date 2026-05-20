#include <stdio.h>

double power(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) return 1.0 / power(base, -exponent);
    return base * power(base, exponent - 1);
}

int main(void) {
    double base;
    int exponent;

INPUT_BASE:
    printf("Enter the base: ");
    if (scanf("%lf", &base) != 1) {
        while (getchar() != '\n');
        goto INPUT_BASE;
    }

INPUT_EXP:
    printf("Enter the exponent: ");
    if (scanf("%d", &exponent) != 1) {
        while (getchar() != '\n');
        goto INPUT_EXP;
    }

    printf("Result: %.2f\n", power(base, exponent));

    return 0;
}