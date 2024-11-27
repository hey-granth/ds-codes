#include <stdio.h>
#define SIZE 5
int cqueue[SIZE];
int front, rear;
int isFull()
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Circular Queue is full\n");
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (front == -1)
    {
        printf("Circular Queue is empty\n");
        return 1;
    }
    return 0;
}
void dequeue()
{
    int num;
    if (!isEmpty())
    {
        num = cqueue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("%d deleted from circular queue\n", num);
    }
}
void enqueue()
{
    int num;
    if (!isFull())
    {
        rear = (rear + 1) % SIZE;
        if (front == -1)
            front++;
        printf("Enter number to insert:");
        scanf("%d", &num);
        cqueue[rear] = num;
        printf("%d inserted successfully\n", num);
    }
}
void show()
{
    int i;
    if (!isEmpty())
    {
        printf("Elements of Queue\n");
        i = front;
        while (i != rear)
        {
            printf("%d ", cqueue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d ", cqueue[i]);
    }
    printf("\nFront=%d rear=%d\n", front, rear);
}
int main()
{
    front = rear = -1;
    int ch, num;
    do
    {
        printf("1..........Enqueue\n");
        printf("2..........Dequeue\n");
        printf("3..........Show\n");
        printf("0..........Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
            break;
            case 2:
                dequeue();
            break;
            case 3:
                show();
            break;
            case 0:
                printf("See you later\n");
            break;
            default:
                printf("Invalid option! try again\n");
        }
    } while (ch != 0);
}