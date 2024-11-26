#include <stdio.h>
void insert_element(int arr[], int n, int loc, int ITEM)
{
    for (int i=n-1; i>=loc-1;i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[loc - 1] = ITEM;
}
void traverse_array(int arr[], int n) {
    printf("TRAVERSAL: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int size, loc, ITEM;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to insert: ");
    scanf("%d", &loc);
    printf("Enter the value to insert: ");
    scanf("%d", &ITEM);
    insert_element(arr, size, loc, ITEM);
    traverse_array(arr, size);
    return 0;
}