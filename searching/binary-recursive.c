#include <stdio.h>
int recursiveSearch(int data[], int n, int item, int index)
{
    if (index >= n)
    {
        return -1;
    }
    if (data[index] == item)
    {
        return index + 1;
    }
    return recursiveSearch(data, n, item, index + 1);
}
int main() {
    int i,n, item;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int data[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    printf("Enter the item to search: ");
    scanf("%d", &item);
    int loc = recursiveSearch(data, n, item, 0);
    if (loc != -1)
    {
        printf("Successful: Item found at position %d\n", loc);
    }
    else
    {
        printf("Unsuccessful: Item not found in the array\n");
    }
    return 0;
}