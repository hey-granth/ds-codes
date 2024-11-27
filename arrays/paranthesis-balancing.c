#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x)
{
    top++;
    stack[top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int Brackets(char exp[])
{
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' && pop() != '(')
        {
            return 0;
        }
        else if (exp[i] == '}' && pop() != '{') {
            return 0;
        } else if (exp[i] == ']' && pop() != '[')
        {
            return 0;
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}
int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (Brackets(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}