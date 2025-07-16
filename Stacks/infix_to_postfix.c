#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_operator_weight(char op) 
{
    int weight = -1;
    if (op == '+' || op == '-')
        weight = 1;
    else if (op == '*' || op == '/') 
        weight = 2;
    else if (op == '^') 
        weight = 3;  
    return weight;
}

bool is_right_associative(char op) 
{
    return (op == '^');
}

bool has_higher_precedence(char op1, char op2) 
{
    int op1_weight = get_operator_weight(op1);
    int op2_weight = get_operator_weight(op2);

    if (op1_weight == op2_weight) 
    {
        if (is_right_associative(op1)) 
            return false; 
        else 
            return true;
    }
    return op1_weight > op2_weight;
}

bool is_operator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool is_operand(char c) 
{
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void infix_to_postfix(char* expression, char* postfix) 
{
    char stack[100];
    int top = -1;
    int i = 0;
    int k = 0; 

    while (expression[i] != '\0') 
    {
        if (expression[i] == ' ' || expression[i] == ',') 
        {
            i++;
            continue;
        } 
        else if (is_operator(expression[i])) 
        {
            while (top != -1 && stack[top] != '(' && has_higher_precedence(stack[top], expression[i])) 
            {
                postfix[k++] = stack[top--];
            }
            top++;       
            stack[top] = expression[i];  
        } 
        else if (is_operand(expression[i])) 
        {
            postfix[k] = expression[i];
            k++;
        } 
        else if (expression[i] == '(') 
        {
            top++;       
            stack[top] = expression[i]; 
        } 
        else if (expression[i] == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                postfix[k] = stack[top];
                k++;
                top--;
            }
            top--;
        }
        i++;
    }
    while (top != -1) 
    {
        postfix[k] = stack[top];
        k++;
        top--;
    }
    postfix[k] = '\0'; 
}

void main() 
{
    char infix_expression[100];
    char postfix_expression[100];
    printf("Enter infix expression: ");
    scanf("%[^\n]", infix_expression);
    getchar(); 
    infix_to_postfix(infix_expression, postfix_expression);
    printf("Postfix expression: %s\n", postfix_expression);

}
