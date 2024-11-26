#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly linked list
struct node {
    int info;
    struct node* prev;
    struct node* next;
};

struct node* start = NULL;

// Function to create a new node
struct node* createNode() {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    return p;
}

// Function to insert a node at the beginning
void insertBeginning(int item) {
    struct node* p = createNode();
    p->info = item;
    p->prev = NULL;
    p->next = start;

    if (start != NULL) {
        start->prev = p;
    }

    start = p;
}

// Function to insert a node at the end
void insertEnd(int item) {
    struct node* p = createNode();
    p->info = item;
    p->next = NULL;

    if (start == NULL) {
        p->prev = NULL;
        start = p;
    } else {
        struct node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

// Function to insert a node after a specific node
void insertAfter(struct node* Q, int item) {
    if (Q == NULL) {
        printf("Location not available.\n");
        return;
    }

    struct node* p = createNode();
    p->info = item;
    p->next = Q->next;
    p->prev = Q;

    if (Q->next != NULL) {
        Q->next->prev = p;
    }
    Q->next = p;
}

// Function to traverse and display the doubly linked list
void Traversal() {
    struct node* temp = start;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the beginning
int deleteBeginning() {
    if (start == NULL) {
        printf("Underflow\n");
        return -1;
    }

    struct node* p = start;
    int item = p->info;
    start = start->next;

    if (start != NULL) {
        start->prev = NULL;
    }

    free(p);
    return item;
}

// Function to delete a node from the end
int deleteEnd() {
    if (start == NULL) {
        printf("Underflow\n");
        return -1;
    }

    struct node* temp = start;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    int item = temp->info;

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        start = NULL; // List becomes empty
    }

    free(temp);
    return item;
}

// Main function to demonstrate the operations
int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    Traversal();

    int x, y;
    printf("Enter the data and node value after which you want to insert data: ");
    scanf("%d%d", &x, &y);

    struct node* temp = start;
    while (temp != NULL) {
        if (temp->info == y) {
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL) {
        insertAfter(temp, x);
    } else {
        printf("Node with value %d not found.\n", y);
    }

    Traversal();

    int item1 = deleteBeginning();
    if (item1 != -1) {
        printf("%d deleted successfully.\n", item1);
    }
    Traversal();

    int item2 = deleteEnd();
    if (item2 != -1) {
        printf("%d deleted successfully.\n", item2);
    }
    Traversal();

    return 0;
}