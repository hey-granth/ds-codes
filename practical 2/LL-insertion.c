// WAP in c for ll insertion with given loc

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int data, int loc)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    int i = 1;
    while (i < loc - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    insert(&head, 10, 1);
    insert(&head, 20, 2);
    insert(&head, 30, 3);
    insert(&head, 40, 4);
    insert(&head, 50, 5);
    insert(&head, 60, 6);
    insert(&head, 70, 7);
    insert(&head, 80, 8);
    insert(&head, 90, 9);
    insert(&head, 100, 10);
    print(head);
    return 0;
}

