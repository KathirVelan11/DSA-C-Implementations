#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct Deque 
{
    int A[100];
    int front, rear;
};

struct Deque *Q;

bool checkempty() 
{
    if(Q->front == -1 && Q->rear == -1)
        return true;
    else
        return false;
}

bool checkfull() 
{
    if ((Q->rear + 1) % 100 == Q->front)
        return true;
    else
        return false;
}

void enqueue_front(int x) 
{
    if (checkfull()) 
    {
        printf("Deque is Full\n");
        return;
    }
    if (checkempty()) 
    {
        Q->front = 0;
        Q->rear = 0;
    } 
    else 
    {
        Q->front = (Q->front - 1 + 100) % 100;
    }
    Q->A[Q->front] = x;
    printf("Element %d inserted at the front\n", x);
}

void enqueue_rear(int x) 
{
    if (checkfull()) 
    {
        printf("Deque is Full\n");
        return;
    }
    if (checkempty()) 
    {
        Q->front = 0;
        Q->rear = 0;
    } 
    else 
    {
        Q->rear = (Q->rear + 1) % 100;
    }
    Q->A[Q->rear] = x;
    printf("Element %d inserted at the rear\n", x);
}

void dequeue_front() 
{
    if (checkempty()) 
    {
        printf("Deque is Empty\n");
        return;
    } 
    else if (Q->front == Q->rear) 
    {
        printf("Element %d removed from the front\n", Q->A[Q->front]);
        Q->rear = -1;
        Q->front = -1;
    } 
    else 
    {
        printf("Element %d removed from the front\n", Q->A[Q->front]);
        Q->front = (Q->front + 1) % 100;
    }
}

void dequeue_rear() 
{
    if (checkempty()) 
    {
        printf("Deque is Empty\n");
        return;
    } 
    else if (Q->front == Q->rear) 
    {
        printf("Element %d removed from the rear\n", Q->A[Q->rear]);
        Q->rear = -1;
        Q->front = -1;
    } 
    else 
    {
        printf("Element %d removed from the rear\n", Q->A[Q->rear]);
        Q->rear = (Q->rear - 1 + 100) % 100;
    }
}

int front() 
{
    if (Q->front == -1) 
    {
        printf("Empty deque\n");
        return -1;
    }
    return Q->A[Q->front];
}

int rear() 
{
    if (Q->rear == -1) 
    {
        printf("Empty deque\n");
        return -1;
    }
    return Q->A[Q->rear];
}

void print() 
{
    if (checkempty()) 
    {
        printf("Empty deque\n");
        return;
    }

    printf("Deque:");
    int count = (Q->rear + 100 - Q->front) % 100 + 1;
    for (int i = 0; i < count; i++) 
    {
        int index = (Q->front + i) % 100;
        printf("%d ", Q->A[index]);
    }
    printf("\n\n");
}

void main() 
{
    Q = (struct Deque*)malloc(sizeof(struct Deque));
    Q->front = -1;
    Q->rear = -1;
    enqueue_front(2);  
    print();
    enqueue_rear(4);  
    print();
    enqueue_front(6);  
    print();
    dequeue_front();   
    print();
    enqueue_rear(8);  
    print();
    dequeue_rear();   
    print();
    free(Q);
}
