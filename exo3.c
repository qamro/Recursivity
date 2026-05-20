#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* reverseLinkedList(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* rest = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    int n, val;

INPUT_N:
    printf("How many elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        while (getchar() != '\n');
        goto INPUT_N;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    int i = 0;
INPUT_VAL:
    if (i == n) goto DONE;
    printf("Enter element %d: ", i + 1);
    if (scanf("%d", &val) != 1) {
        while (getchar() != '\n');
        goto INPUT_VAL;
    }
    struct Node* node = newNode(val);
    if (head == NULL) { head = node; tail = node; }
    else { tail->next = node; tail = node; }
    i++;
    goto INPUT_VAL;

DONE:
    printf("\nOriginal: ");
    printList(head);

    head = reverseLinkedList(head);

    printf("Reversed: ");
    printList(head);

    return 0;
}