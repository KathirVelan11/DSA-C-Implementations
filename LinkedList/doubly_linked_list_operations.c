#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

struct Node* getnode(int x)
{
    struct Node* insertnode = (struct Node*)malloc(sizeof(struct Node));
    insertnode->data = x;
    insertnode->prev = NULL;
    insertnode->next = NULL;
    return insertnode;
}

void printnode()
{
    struct Node* temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d->", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

void reverseprintnode()
{
    struct Node* temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    while (temp2 != NULL)
    {
        printf("%d->", temp2->data);
        temp2 = temp2->prev;
    }
    printf("\n");
}

void insertathead(int x)
{
    struct Node* temp = getnode(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertatnthnode(int x, int n)
{
    if (n == 1)
    {
        insertathead(x);
        return;
    }
    struct Node* temp3 = getnode(x);
    struct Node* temp4 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp4 = temp4->next;
    }
    temp3->prev = temp4;
    temp3->next = temp4->next;
    if (temp4->next != NULL)
    {
        temp4->next->prev = temp3;
    }
    temp4->next = temp3;
}

void insertatend(int x)
{
    struct Node* temp5=getnode(x);
    struct Node* temp6=head;
    while(temp6->next != NULL)
    {
        temp6=temp6->next;
    }
    temp5->prev=temp6;
    temp6->next=temp5;
}

void deleteatnthnode(int n)
{
    struct Node* temp7 = head;
    if (n == 1)     
    {
        head = temp7->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp7);
        return;
    }
    for (int j = 0; j < n - 2; j++)
    {
        temp7 = temp7->next;
    }
    struct Node* temp8 = temp7->next;
    temp7->next = temp8->next;
    if (temp8->next != NULL)
    {
        temp8->next->prev = temp7;
    }
    free(temp8);
}

struct Node* reverse()
{
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) 
    {
        head = temp->prev;
    }
    
    return head;
}

Node* sortedInsert(Node * head, int x)
{
    struct Node* addnode = getNode(x); 
    
    if (head == NULL) 
    { 
        head = addnode;
        return head;
    }
    
    if (x < head->data) 
    {
        addnode->next = head;
        head->prev = addnode;
        head = addnode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < x) 
    { 
        temp = temp->next;
    }
    
    addnode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = addnode;
    temp->next = addnode;
    addnode->prev = temp;
    
    return head;
};

int main()
{
    insertathead(5);
    insertathead(4);
    insertathead(3);
    insertathead(2);
    insertathead(1);
    insertatend(6);
    insertatnthnode(7, 7);
    deleteatnthnode(7);
    printnode();
    //reverseprintnode();
    head=reverse();
    printnode();
    //reverseprintnode();
    return 0;
}
