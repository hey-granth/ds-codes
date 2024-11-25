#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node* reverseList(struct node* start) {
    struct node* prev = NULL;
    struct node* current = start;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    return prev; // New Start 
}

int main() {
    int a, i = 1, n;
    struct node *p, *q, *start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of nodes must be positive.\n");
        return 1;
    }

    printf("Enter node %d: ", i);
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &a);
    p->data = a;
    p->next = NULL;
    start = p;

    for (i = 2; i <= n; i++) {
        printf("Enter node %d: ", i);
        q = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &a);
        q->data = a;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }

    printf("Original list: ");
    p = start;
    while (p != NULL) {
        printf("[%d]-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // Reverse the linked list
    start = reverseList(start);

    printf("Reversed list: ");
    p = start;
    while (p != NULL) {
        printf("[%d]-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // Free allocated memory
    p = start;
    while (p != NULL) {
        struct node* temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}