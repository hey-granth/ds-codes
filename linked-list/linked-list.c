#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int a, i = 1, n;
    struct node *p, *q, *start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

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

    p = start;
    while (p != NULL) {
        printf("[%d]-> ", p->data);
        p = p->next;
    }

    return 0;
}
