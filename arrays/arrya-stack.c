#include <stdio.h>
#include <stdlib.h>
#define maxsize 8

struct stack {
    int top;
    int STACK[maxsize];
} S;
void initialize() {
    S.top = -1;
}
int IsEmpty() {
    return S.top == -1;
}
int IsFull() {
    return S.top == maxsize - 1;
}
int push(int ITEM) {
    if (IsFull()) {
        printf("Stack overflow!\n");
        return -1;
    }
    S.top++;
    S.STACK[S.top] = ITEM;
    return 1;
}
int pop() {
    if (IsEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    int ITEM = S.STACK[S.top];
    S.top--;
    return ITEM;
}
int peek() {
    if (IsEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S.STACK[S.top];
}
void show() {
    if (IsEmpty()) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = S.top; i >= 0; i--) {
        printf("%d ", S.STACK[i]);
    }
    printf("\n");
}
int main() {
    initialize();
    int choice, ITEM, y;
    while (1) {
        printf("\nOperations performed by Stack");
        printf("\n1. Push the element\n2. Pop the element\n3. Show top element of stack\n4. Show all stack elements\n5. End");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ITEM);
            if (push(ITEM) == 1) {
            printf("%d pushed onto stack.\n", ITEM);
            }
            show();
            break;
        case 2:
            y = pop();
            if (y != -1) {
            printf("Popped element is %d\n", y);
            }
            show();
            break;
        case 3:
            y = peek();
            if (y != -1) {
            printf("Top of the stack is %d\n", y);
            }
            break;
        case 4:
            show();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!!\n");
        }
    }
    return 0;
}