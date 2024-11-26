#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Queue node
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;  // Points to the front of the queue
    struct Node* rear;   // Points to the rear of the queue
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue (insert) an element at the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;  // If the queue is empty, both front and rear will point to the new node
    } else {
        q->rear->next = newNode;  // Add the new node after the rear node
        q->rear = newNode;  // Move the rear to the new node
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the front of the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Queue is empty\n");
        return -1;  // Return -1 to indicate queue is empty
    } else {
        struct Node* temp = q->front;
        int dequeuedData = temp->data;
        q->front = q->front->next;  // Move the front pointer to the next node
        if (q->front == NULL) {
            q->rear = NULL;  // If the queue becomes empty, set rear to NULL
        }
        free(temp);
        return dequeuedData;
    }
}

// Function to display the elements of the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = q->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate the Queue operations
int main() {
    struct Queue q;
    initializeQueue(&q);  // Initialize an empty queue

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    displayQueue(&q);

    int dequeuedItem = dequeue(&q);
    if (dequeuedItem != -1) {
        printf("%d dequeued from queue\n", dequeuedItem);
    }

    displayQueue(&q);

    return 0;
}
