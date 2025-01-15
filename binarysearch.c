#include <stdio.h>
int main() {
    int n, x, i, j, mid;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    i = 0;
    j = n - 1;
    mid = (i + j) / 2;
    while (i <= j) {
        if (arr[mid] == x) {
            printf("Element found at index %d\n", mid);
            break;
        } else if (arr[mid] < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
        mid = (i + j) / 2;
    }
    if (i > j) {
        printf("Element not found in the array\n");
    }
    return 0;
}

int main() {
    printf("hello world\n");
}