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

void ReversePrint(struct Node* p)
{
    if (p == NULL)
        return;

    ReversePrint(p->next);
    printf("%d ",p->data);
}



void main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    ReversePrint(head);
}
