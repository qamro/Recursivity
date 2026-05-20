#include <stdio.h>
#include <string.h>

int isPalindrome(char word[], int left, int right) {
    if (left >= right) return 1;
    if (word[left] != word[right]) return 0;
    return isPalindrome(word, left + 1, right - 1);
}

int main(void) {
    char word[100];

INPUT:
    printf("Enter a word: ");
    if (scanf("%s", word) != 1) {
        while (getchar() != '\n');
        goto INPUT;
    }

    int result = isPalindrome(word, 0, strlen(word) - 1);

    if (result == 1)
        printf("\"%s\" is a palindrome\n", word);
    else
        printf("\"%s\" is not a palindrome\n", word);

    return 0;
}