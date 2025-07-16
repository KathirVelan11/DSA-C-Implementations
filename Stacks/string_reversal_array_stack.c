#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack 
{
    char items[MAX_SIZE];
    int top;
};

struct Stack* stack;

void isEmpty() 
{
    if (stack->top == -1)
        printf("Stack is empty\n");
    else 
        printf("Stack is not empty\n");
}

void isFull() 
{
    if (stack->top == MAX_SIZE - 1)
        printf("Stack is full\n");
    else 
        printf("Stack is not full\n");
}

void push(char item) 
{
    if (stack->top == MAX_SIZE - 1) 
    {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = item;
}

char pop() 
{
    if (stack->top == -1) 
    {
        printf("Error: Stack underflow\n");
        return '\0'; 
    }
    return stack->items[(stack->top)--];
}

void reverseString(char *str) 
{
    int length = strlen(str);
    stack->top = -1;

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
    struct Stack s;
    stack = &s;

    char str[] = "hello";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
