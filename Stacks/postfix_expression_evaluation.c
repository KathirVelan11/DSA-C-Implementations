#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stack 
{
    int elements[100];
    int top;
};

struct Stack* stack;

void push(int item) 
{
    if(stack->top == 99)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->elements[stack->top] = item;
}

int pop() 
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int temp = stack->elements[stack->top];
    stack->top--; 
    return temp;
}

bool is_number(char C) 
{
    return (C >= '0' && C <= '9');
}

bool is_operator(char C) 
{
    return (C == '+' || C == '-' || C == '*' || C == '/');
}

int perform_operation(char operation, int operand1, int operand2) 
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
            return -1;
        }
    }
    else 
    {
        printf("Error\n");
        return -1;
    }
}

int evaluate_postfix(char expression[]) 
{
    stack->top=-1;
    for (int i = 0; expression[i] != '\0'; i++) 
    {
        if (expression[i] == ' ' || expression[i] == ',') 
            continue;
        else if (is_operator(expression[i])) 
        {
            int operand2 = pop();
            int operand1 = pop();
            int result = perform_operation(expression[i], operand1, operand2);
            push(result);
        }
        else if (is_number(expression[i])) 
        {
            int operand = 0;
            while (expression[i] != ' ' && expression[i] != ',') 
            {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            push(operand);
        }
    }
    return pop();
}

void main() 
{
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    char expression[100];
    printf("Enter Postfix Expression: ");
    scanf("%[^\n]%*c", expression);
    int result = evaluate_postfix(expression);
    printf("Value = %d\n", result);
    free(stack);
}
