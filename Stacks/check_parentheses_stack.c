#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ArePair(char opening, char closing) 
{
    if (opening == '(' && closing == ')') 
    return true;
    else if (opening == '{' && closing == '}') 
    return true;
    else if (opening == '[' && closing == ']') 
    return true;
    return false;
}

bool AreParenthesesBalanced(char* exp) 
{
    int len = strlen(exp);
    char S[len];
    int top = -1;

    for (int i = 0; i < len; i++) 
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            top++;
            S[top] = exp[i];
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
        {
            if (top == -1 || !ArePair(S[top], exp[i]))
                return false;
            else
                top--;
        }
    }
    return top == -1;
}

void main() 
{
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (AreParenthesesBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}
