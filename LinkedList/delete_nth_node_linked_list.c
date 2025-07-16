#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int data)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if (head == NULL)
    {
        head = temp1;
        return;
    }

    struct Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}


void Delete(int n)
{
    struct Node *temp1 = head;
    if(n==1)
    {
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }
    temp1->next=temp1->next->next;
}

void Print()
{
    struct Node *temp = head;
    printf("\nList is ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Print();
    int n;
    printf("Enter a position:");
    scanf("%d",&n);
    Delete(n);
    Print();
}
