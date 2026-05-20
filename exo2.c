#include <stdio.h>

void DecToBin(int n) {
    if (n == 0) return;
    DecToBin(n / 2);
    printf("%d", n % 2);
}

int main(void) {
    int n;

INPUT:
    printf("Enter a decimal number: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        while (getchar() != '\n');
        goto INPUT;
    }

    printf("Binary: ");
    DecToBin(n);
    printf("\n");

    return 0;
}