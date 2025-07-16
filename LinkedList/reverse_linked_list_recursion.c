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
        temp2 = temp2->next;

    temp2->next = temp1;
}

void Reverse(struct Node* p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    Reverse(p->next);
    struct Node* q=p->next;
    q->next=p;
    p->next=NULL;
}

void Print(struct Node* p)
{
    if (p == NULL)
        return;

    printf("%d ",p->data);
    Print(p->next);
}

int main()
{
    head = NULL;
    Insert(5);
    Insert(6);
    Insert(7);
    Insert(8);
    Reverse(head);
    Print(head);
    return 0;
}
