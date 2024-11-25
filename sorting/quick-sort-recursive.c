#include <stdio.h>
#define MAX 15 

void quick(int A[], int BEG, int END, int *LOC) {
    int LEFT = BEG, RIGHT = END;
    *LOC = BEG; 
 
    while (1) {
        while (A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
            RIGHT--;
        if (*LOC == RIGHT)
            return;
        if (A[*LOC] > A[RIGHT]) 
		{
            int temp = A[*LOC];
            A[*LOC] = A[RIGHT];
            A[RIGHT] = temp;
            *LOC = RIGHT;
        }

        while (A[LEFT] <= A[*LOC] && LEFT != *LOC)
            LEFT++;
        if (*LOC == LEFT)
            return;
        if (A[LEFT] > A[*LOC]) {
            
            int temp = A[LEFT];
            A[LEFT] = A[*LOC];
            A[*LOC] = temp;

            *LOC = LEFT;
        }
    }
}

void quicksort_recursive(int A[], int BEG, int END) {
    int LOC;
    if (BEG < END) {
        quick(A, BEG, END, &LOC); 
        quicksort_recursive(A, BEG, LOC - 1); 
        quicksort_recursive(A, LOC + 1, END); 
    }
}

int main() {
    int A[MAX], N, i;

    printf("Enter the number of elements: ");
    scanf("%d", &N);
    printf("Enter the elements: ");
    for (i = 0; i < N; i++) 
	{
        scanf("%d", &A[i]);
    }

    quicksort_recursive(A, 0, N - 1);

    printf("Sorted elements: ");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
