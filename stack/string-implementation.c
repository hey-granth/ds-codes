#include <stdio.h>
#include <string.h>
#define MAXSIZE 20
char stack[MAXSIZE];
int top = -1;
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAXSIZE - 1;
}
void push(char ch)
{
    if (isFull())
    {
        printf("overflow\n");
        return;
    }
    stack[++top] = ch;
}
char pop()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return 1;
    }
    return stack[top--];
}
void reverse(char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < length; i++)
    {
        str[i] = pop();
    }
}
int main()
{
    char str[MAXSIZE];
    printf("Enter a string ");
    scanf("%s",str);
    reverse(str);
    printf("Reversed string: %s\n", str);
    return 0;
}