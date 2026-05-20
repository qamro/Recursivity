#include <stdio.h>

int MaxRec(int arr[], int size) {
    if (size == 1) return arr[0];
    int rest = MaxRec(arr, size - 1);
    if (arr[size - 1] > rest) return arr[size - 1];
    return rest;
}

int main(void) {
    int n, i;

INPUT_N:
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        while (getchar() != '\n');
        goto INPUT_N;
    }

    int arr[n];
    i = 0;

INPUT_VAL:
    if (i == n) goto DONE;
    printf("Enter element %d: ", i + 1);
    if (scanf("%d", &arr[i]) != 1) {
        while (getchar() != '\n');
        goto INPUT_VAL;
    }
    i++;
    goto INPUT_VAL;

DONE:
    printf("Maximum: %d\n", MaxRec(arr, n));

    return 0;
}