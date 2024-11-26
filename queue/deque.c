#include <stdio.h>
#define SIZE 5

int front, rear;
int dq[SIZE];

int isEmpty() {
    if (front == -1) {
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

int isFull() {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

void enqueue_rear() {
    int num;
    if (!isFull()) {
        printf("Enter number to insert: ");
        scanf("%d", &num);
        rear = (rear + 1) % SIZE;
        if (front == -1)
            front++;
        dq[rear] = num;
        printf("%d inserted in the queue at rear\n", num);
    }
}

void enqueue_front() {
    int num;
    if (!isFull()) {
        printf("Enter number to insert: ");
        scanf("%d", &num);
        if (front == -1) {
            rear++;
            front++;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        dq[front] = num;
        printf("%d inserted in the queue at front\n", num);
    }
}

void dequeue_front() {
    int num;
    if (!isEmpty()) {
        num = dq[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("%d deleted from front\n", num);
    }
}

void dequeue_rear() {
    int num;
    if (!isEmpty()) {
        num = dq[rear];
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + SIZE) % SIZE;
        printf("%d deleted from rear\n", num);
    }
}

void show() {
    int i;
    if (!isEmpty()) {
        printf("Elements of Queue:\n");
        i = front;
        while (i != rear) {
            printf("%d ", dq[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d \n", dq[i]);
    }
}

int get_rear() {
    if (!isEmpty()) {
        printf("%d is at rear", dq[rear]);
        return dq[rear];
    }
    return 0;
}

int get_front() {
    if (!isEmpty()) {
        printf("%d is at front", dq[front]);
        return dq[front];
    }
    return 0;
}

int main() {
    front = rear = -1;
    int ch, num;
    do {
        printf("1..........Enqueue Front\n");
        printf("2..........Enqueue Rear\n");
        printf("3..........Dequeue Front\n");
        printf("4..........Dequeue Rear\n");
        printf("5..........Show\n");
        printf("6..........Get Front\n");
        printf("7..........Get Rear\n");
        printf("0..........Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue_front();
                break;
            case 2:
                enqueue_rear();
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                show();
                break;
            case 6:
                get_front();
                break;
            case 7:
                get_rear();
                break;
            case 0:
                printf("See you later\n");
                break;
            default:
                printf("Invalid option! try again\n");
        }
    } while (ch != 0);

    return 0;
}