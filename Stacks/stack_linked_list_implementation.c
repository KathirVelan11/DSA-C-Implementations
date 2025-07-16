#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void Push(int x) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void Pop() 
{
    if(top == NULL) 
    {
        printf("Error: No element to pop\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

int Top() 
{
    if(top == NULL) 
    {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return top->data;
}

int IsEmpty() 
{
    return top == NULL;
}

void Print() 
{
    Node* temp = top;
    printf("Stack: ");
    while(temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{    
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
}
