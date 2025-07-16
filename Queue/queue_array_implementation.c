#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define size 100

struct Queue 
{
    int A[size];
    int front, rear;
};

struct Queue *Q;

bool IsEmpty() 
{
    if(Q->front == -1 && Q->rear == -1)
    return true;
    else
    return false;
}

bool IsFull() 
{
    if((Q->rear + 1) % size == Q->front)
    return true;
    else
    return false;
}

void Enqueue(int x) 
{
    if (IsFull()) 
    {
        printf("Queue is Full\n");
        return;
    }
    if (IsEmpty()) 
    {
        Q->front = 0;
        Q->rear = 0;
    } 
    else 
    {
        Q->rear = (Q->rear + 1) % size;
    }
    Q->A[Q->rear] = x;
}

void Dequeue() 
{
    if (IsEmpty()) 
    {
        printf("Queue is Empty\n");
        return;
    } 
    else if (Q->front == Q->rear) 
    {
        Q->rear =-1;
        Q->front = -1;
    } 
    else 
    {
        Q->front = (Q->front + 1) % size;
    }
}

int Front() 
{
    if (Q->front == -1) 
    {
        printf("Empty queue\n");
        return -1;
    }
    return Q->A[Q->front];
}

void Print() 
{
    int count = (Q->rear + size - Q->front) % size + 1;
    printf("Queue:");
    for (int i = 0; i < count; i++) 
    {
        int index = (Q->front + i) % size;
        printf("%d ", Q->A[index]);
    }
    printf("\n\n");
}

void main() 
{
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->front = -1;
    Q->rear = -1;
    Enqueue(2);  
    Print();
    Enqueue(4);  
    Print();
    Enqueue(6);  
    Print();
    Dequeue();   
    Print();
    Enqueue(8);  
    Print();
    free(Q);
}
