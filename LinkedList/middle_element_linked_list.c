#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
int temp=0;

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

int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int middledata(struct Node *head)
{
    int size=countNodes(head);
    int index=0;
    while(size%2!=0)
    {
        int newsize=(size/2)+1;
        struct Node *temp = head;
        while (temp != NULL)
            {
                index+=1;
                if(index==newsize)
                    return temp->data;
                temp = temp->next;
            }
    }
    printf("The LL cannot have middle element");
}

void main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(2);
    Insert(1);
    int mid=middledata(head);
    printf("The middle element is : %d",mid);
}
