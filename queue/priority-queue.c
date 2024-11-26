#include <stdio.h>
#define MAX 100

struct PriorityQueue {
    int arr[MAX];
    int size;
};

void initQueue(struct PriorityQueue *pq) {
    pq->size = 0;
}

void enqueue(struct PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Queue full\n");
        return;
    }
    
    int i = pq->size - 1;
    
    // Find position to insert
    while (i >= 0 && pq->arr[i] > value) {
        pq->arr[i+1] = pq->arr[i];
        i--;
    }
    
    pq->arr[i+1] = value;
    pq->size++;
}

int dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue empty\n");
        return -1;
    }
    
    return pq->arr[--pq->size];
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);
    
    enqueue(&pq, 10);
    enqueue(&pq, 5);
    enqueue(&pq, 15);
    
    printf("Dequeued: %d\n", dequeue(&pq));
    
    return 0;
}