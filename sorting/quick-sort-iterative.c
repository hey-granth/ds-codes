#include <stdio.h>
#define MAX 15

void quick(int A[], int N, int BEG, int END, int *LOC) {
    int LEFT = BEG, RIGHT = END;
    *LOC = BEG;
    // Step 2: Scan from right to left
    while (1) {
        while (A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
            RIGHT--;
        if (*LOC == RIGHT)
		    return;
        if (A[*LOC] > A[RIGHT]) {
            // Interchange A[LOC] and A[RIGHT]
            int temp = A[*LOC];
            A[*LOC] = A[RIGHT];
            A[RIGHT] = temp;

            *LOC = RIGHT;
        }

        // Step 3: Scan from left to right
        while (A[LEFT] <= A[*LOC] && LEFT != *LOC)
            LEFT++;
        if (*LOC == LEFT)
		    return;
        if (A[LEFT] > A[*LOC]) {
            // Interchange A[LEFT] and A[LOC]
            int temp = A[LEFT];
            A[LEFT] = A[*LOC];
            A[*LOC] = temp;

            *LOC = LEFT;
        }
    }
}

void quicksort(int A[], int N) {
    int LOWER[MAX], UPPER[MAX], TOP = -1; // Stack initialization
    int BEG, END, LOC;

    // Step 2: Push the boundary values onto stacks
    if (N > 1) {
        TOP++;
        LOWER[TOP] = 0;
        UPPER[TOP] = N - 1;
    }

    // Step 3: Repeat while stack is not empty
    while (TOP != -1) {
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP--;

        quick(A, N, BEG, END, &LOC);

        // Step 6: Push left sublist onto stacks
        if (BEG < LOC - 1) {
            TOP++;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC - 1;
        }

        // Step 7: Push right sublist onto stacks
        if (LOC + 1 < END) {
            TOP++;
            LOWER[TOP] = LOC + 1;
            UPPER[TOP] = END;
        }
    }
}

int main() {
    int A[MAX], N, i;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Input the array elements
    printf("Enter the elements: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

     quicksort(A, N);

    printf("Sorted elements: ");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
