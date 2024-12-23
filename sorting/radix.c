#include <stdio.h>
#define MAX 100
#define RANGE 10

void countingSort(int arr[], int n, int exp) {
    int output[MAX];
    int count[RANGE] = {0};

    // Store count of occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count array to actual position
    for (int i = 1; i < RANGE; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    // Find maximum number to know number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}