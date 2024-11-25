#include <stdio.h>
#include<math.h>
void indexedSequentialSearch(int arr[], int n, int key)
{
    int k = 3; // block size
    int blocks = (int)ceil((double)n / k); // number of blocks
    int ele[blocks], indices[blocks];
    int i, indx = 0, si, ei;
    for (i = 0; i < n; i= i+k)
    {
        ele[indx] = arr[i];
        indices[indx] = i;
        indx++;
    }
    if (key < arr[0]) {
        printf("Not found\n");
        return;
    }
    si = 0;
    ei = n;
    for (i=0;i<indx;i++)
    {
        if (key<ele[i])
        {
            si = indices[i - 1]; // Start index of the found block
            ei = indices[i]; // End index is the start of the next block
            break;
        }
    }
    if (key>=ele[indx - 1])
    {
        si = indices[indx - 1];
        ei = n;
    }
    for (i = si; i < ei; i++) //with block search
    {
        if (key == arr[i])
        {
            printf("Found at location %d\n", i + 1);
            return;
        }
    }
    printf("Not found\n");
}
int main() {
    int arr[20];
    int n, i, key;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the elements (sorted order)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key that you want to search:\n");
    scanf("%d", &key);
    indexedSequentialSearch(arr, n, key);
    return 0;
}