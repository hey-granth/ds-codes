#include <stdio.h>
int binarySearch(int data[], int n, int item) {
    int beg = 0;
    int end = n - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (data[mid] == item)
        {
            return mid;
        }
        if (item < data[mid])
        {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }
    return -1;
}
int main() {
    int i, n, item;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int data[n];
    printf("Enter %d sorted elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    printf("Enter the item to search: ");
    scanf("%d", &item);
    int loc = binarySearch(data, n, item);
    if (loc != -1) {
        printf("Item found at position %d\n", loc + 1);
    } else
    {
        printf("Item not found in the array\n");
    }
    return 0;
}