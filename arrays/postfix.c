#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    stack[++top] = x;
}
int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int evaluatePostfix(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == ' ')
        {
            continue;
        } else if (exp[i] >= '0' && exp[i] <= '9')
        {
            int num = 0;
            while (i < strlen(exp) && exp[i] >= '0' && exp[i] <= '9') {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            i--;
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            switch (exp[i]) {
                case '+':
                    result = operand1 + operand2;
                break;
                case '-':
                    result = operand1 - operand2;
                break;
                case '*':
                    result = operand1 * operand2;
                break;
                case '/':
                    result = operand1 / operand2;
                break;
            }
            push(result);
        }
    }
    return pop();
}
int main() {
    char exp[100];
    printf("Enter a postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);
    return 0;
}