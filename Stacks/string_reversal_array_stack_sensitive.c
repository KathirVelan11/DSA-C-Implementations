#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct Stack 
{
    char characters[100];
    int top;
};

struct Stack* stack = NULL; 

void isEmpty() 
{
    if (stack == NULL || stack->top == -1)
        printf("Stack is empty\n");
    else 
        printf("Stack is not empty\n");
}

void isFull() 
{
    if (stack != NULL && stack->top == 99)
        printf("Stack is full\n");
    else 
        printf("Stack is not full\n");
}

void push(char item) 
{

    if (stack->top == 99) 
    {
        printf("Stack overflow\n");
        return;
    }
    (stack->top)++;     
    stack->characters[stack->top] = item;
}

char pop() 
{
    if (stack == NULL || stack->top == -1) 
    {
        printf("Stack underflow\n");
        return '\0'; 
    }
    char character = stack->characters[stack->top]; 
    (stack->top)--;                   
    return character;  
}

void reverseString(char *str) 
{
    int length = strlen(str);
    stack->top = -1; 

    for (int i = 0; i < length; i++) 
    {
        if (str[i] != ' ') 
        {
            push(str[i]);
        } 
        else 
        {
            while (stack->top != -1) 
            {
                printf("%c", pop());
            }
            printf(" ");
        }
    }

    while (stack->top != -1) 
    {
        printf("%c", pop());
    }
}

void main() 
{
    stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    char str[] = "data structure";
    printf("%s\n", str);
    reverseString(str);
    printf("\n");
    free(stack);
}
