#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void initialize()
{
    front = rear = -1;
}
int isEmpty()
{
    return (front == -1);
}
int isFull()
{
    return (rear == MAX - 1);
}
void enqueue(int ITEM) {
    if (isFull())
    {
        printf("OVERFLOW\n", ITEM);
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }
    queue[++rear] = ITEM;
    printf("%d enqueued to the queue\n", ITEM);
}
void dequeue() {
    if (isEmpty()) {
        printf("UNDERFLOW.\n");
        return;
    }
    printf("%d dequeued from the queue\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}
void Traversal()
{
    int i;
    if (isEmpty())
    {
        printf("empty queue.\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, ITEM;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Initialization\n");
        printf("2. Emptiness check\n");
        printf("3. Insertion (Enqueue)\n");
        printf("4. Deletion (Dequeue)\n");
        printf("5. Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initialize();
            printf("Queue initialized.\n");
            break;
            case 2:
                if (isEmpty())
                {
                    printf("no element so far.\n");
                }
                else
                {
                    printf("Queue is not empty.\n");
                }
            break;
            case 3:
                printf("Enter value to enqueue: ");
                scanf("%d", &ITEM);
                enqueue(ITEM);
            break;
            case 4:
                dequeue();
            break;
            case 5:
                Traversal();
            break;
            case 6:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}