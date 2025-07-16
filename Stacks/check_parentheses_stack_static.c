#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool ArePair(char opening, char closing) {
    if (opening == '(' && closing == ')') 
        return true;
    else if (opening == '{' && closing == '}') 
        return true;
    else if (opening == '[' && closing == ']') 
        return true;
    return false;
}

bool AreParenthesesBalanced(const char* exp) {
    char S[MAX_LENGTH]; // Static allocation
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top++;
            S[top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !ArePair(S[top], exp[i]))
                return false;
            else
                top--;
        }
    }
    return top == -1;
}

int main() {
    char expression[MAX_LENGTH];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin); // Safer input reading
    if (AreParenthesesBalanced(expression))
        printf("The expression is balanced\n");
    else
        printf("The expression is not balanced\n");
    return 0;
}
