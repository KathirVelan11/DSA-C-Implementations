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

int palindrome(struct Node *p)
{
    int size = countNodes(p);
    int arr[size];
    int i = 0;
    while (p != NULL)
    {
        arr[i] = p->data;
        i++;
        p = p->next;
    }

    for(int j=0;j<i/2;j++)
    {
        if(arr[j]!=arr[i-j-1])
        {
            printf("LL is not a palindrome ");
            return 0;
        }
    }
    printf("LL is a palindrome");
    return 1;
}

void main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(2);
    Insert(1);
    palindrome(head);
}
