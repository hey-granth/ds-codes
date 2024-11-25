#include<stdio.h>
int main()
{
    int i, n, item, loc = 0;
    printf("ENTER THE NUMBER OF ARRAY:");
    scanf("%d", &n);
    int data[n];
    printf("Enter the elements of the array:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("Enter the item to search:");
    scanf("%d", &item);

    int k = 0;
    while(k < n && loc == 0)
    {
        if(data[k] == item)
        {
            loc = k + 1;
        }
        k++;
    }

    if(loc != 0) {
        printf("Successful: Item found at position %d\n", loc);
    }
    else {
        printf("Unsuccessful: Item not found in the array\n");
    }

    return 0;
}