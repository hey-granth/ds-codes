#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int Cycle(struct node* head) {
    struct node* slow = head; 
    struct node* fast = head; 

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 

        if (slow == fast) {
            return 1; 
        }
    }
    return 0; 
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printCycle(struct node* head) {
    struct node* slow = head; 
    struct node* fast = head; 

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 

        if (slow == fast) {
            printf("Cycle detected: ");
            struct node* temp = slow;
            do {
                printf("%d -> ", temp->data);
                temp = temp->next;
            } while (temp != slow);
            printf("\n");
            return;
        }
    }
}

int main() {
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
   head->next->next->next->next = head->next; 

    if (Cycle(head))
	 {
        printCycle(head);
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}