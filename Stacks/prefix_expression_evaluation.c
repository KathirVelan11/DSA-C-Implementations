#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define size 100

struct Stack 
{
    int elements[size];
    int top;
};

struct Stack* stack;

bool isfull() 
{
    if(stack->top == size - 1)
        return true;
    else
        return false;
}

bool isempty() 
{
    if(stack->top == -1)
        return true;
    else
        return false;
}

void push(int item) 
{
    if (isfull()) 
    {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->top++;
    stack->elements[stack->top] = item;
}

int pop() 
{
    if (isempty()) 
    {
        printf("Error: Stack underflow\n");
        return 0;
    }
    int temp = stack->elements[stack->top];
    stack->top--; 
    return temp;
}

bool isnumber(char C) 
{
    return (C >= '0' && C <= '9');
}

bool isoperator(char C) 
{
    return (C == '+' || C == '-' || C == '*' || C == '/');
}

int performoperation(char operation, int operand1, int operand2) 
{
    if (operation == '+') 
        return operand1 + operand2;
    else if (operation == '-') 
        return operand1 - operand2;
    else if (operation == '*') 
        return operand1 * operand2;
    else if (operation == '/')
    {
        if (operand2 != 0) 
            return operand1 / operand2;
        else 
        {
            printf("Division by zero error\n");
            return 0;
        }
    }
    else 
    {
        printf("Error: Invalid operator\n");
        return 0;
    }
}

int evaluatePrefix(char expression[]) 
{
    stack->top=-1;
    int result; 
    for (int i = strlen(expression) - 1; i >= 0; i--)
    {
        if (isnumber(expression[i])) 
            push(expression[i] - '0');
        else if (isoperator(expression[i])) 
        {
            int operand1 = pop();
            int operand2 = pop();
            result = performoperation(expression[i], operand1, operand2);
            push(result);
        }
    }
    return pop();
}

void main() 
{
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    char expression[size];
    printf("Enter Prefix Expression: ");
    scanf("%[^\n]s", expression);
    getchar();
    int len = strlen(expression);
    int result = evaluatePrefix(expression);
    printf("Output = %d\n", result);
    free(stack);
}
