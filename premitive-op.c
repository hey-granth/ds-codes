#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

struct node *create_node()
{
    return (struct node *)malloc(sizeof(struct node));
}

void show()
{
    if (start == NULL)
        printf("List is empty\n");
    else
    {
        struct node *temp = start;
        printf("Nodes are\n");
        while (temp != NULL)
        {
            printf("[%d|%u]-> ", temp->data, temp->next);
            temp = temp->next;
        }
        printf("\n");
    }
}
void add_beg(int info)
{
    struct node *temp = create_node();
    temp->data = info;
    temp->next = NULL;
    if (start != NULL)
        temp->next = start;

    start = temp;
    printf("Node added at beginning\n");
}
void add_last(int info)
{
    struct node *newnode = create_node();
    newnode->data = info;
    newnode->next = NULL;
    if (start == NULL)
        start = newnode;
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("node added at last\n");
}
int main()
{
    int i;
    start = NULL;
    show();

    for (i = 1; i <= 10; i++)
    {
        add_beg(i * 10);
        show();
        add_last(i * 200);
        show();
    }
}