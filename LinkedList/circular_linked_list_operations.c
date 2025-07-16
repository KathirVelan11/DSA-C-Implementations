#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last;

void addToEmpty(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newnode->next = newnode;
}

void addFront(struct Node* last, int data) 
{
    if (last == NULL)
        return addToEmpty(data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

struct Node* addEnd(struct Node* last, int data) {
    if (last == NULL)
        return addToEmpty(data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

struct Node* addAfter(struct Node* last, int data, int item) {
    if (last == NULL)
        return NULL;

    struct Node* newNode = NULL;
    struct Node* p = last->next;
    do {
        if (p->data == item) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;

            if (p == last)
                last = newNode;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    printf("\nThe given node is not present in the list");
    return last;
}

void deleteNode(struct Node* last, int key) {
    if (last == NULL)
        return;

    // If the list contains only a single node
    if (last->data == key && last->next == last) {
        free(last);
        return;
    }

    struct Node* temp = last;

    // If last is to be deleted
    if (last->data == key) {
        // Find the node before the last node
        while (temp->next != last)
            temp = temp->next;
        // Point temp node to the next of last i.e. first node
        temp->next = last->next;
        free(last);
        last = temp->next;
    }

    // Travel to the node to be deleted
    while (temp->next != last && temp->next->data != key) {
        temp = temp->next;
    }

    // If node to be deleted was found
    if (temp->next->data == key) {
        struct Node* d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

void traverse(struct Node* last) {
    struct Node* p;

    if (last == NULL) {
        printf("The list is empty");
        return;
    }

    p = last->next;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularLinkedList() {
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    head->next = second;
    second->next = third;
    third->next = head; // Make it circular

    return third; // Return a pointer to the last node
}

struct Node* deleteNodeFromBeginning(struct Node* last) {
    if (last == NULL || last->next == NULL) {
        free(last);
        return NULL;
    }
    struct Node* temp = last->next;
    last->next = temp->next;
    free(temp);
    return last;
}

struct Node* deleteNodeFromEnd(struct Node* last) {
    if (last == NULL || last->next == NULL) {
        free(last);
        return NULL;
    }

    struct Node* temp = last->next;
    struct Node* deleteNode = NULL;

    while (temp->next != last) {
        temp = temp->next;
    }
    deleteNode = last;
    temp->next = last->next;
    last = temp;
    free(deleteNode);
    deleteNode = NULL;
    return last;
}

int countNodes(struct Node* last) {
    int count = 0;
    struct Node* temp = last->next;
    while (temp->next != last) 
{
        count++;
        temp = temp->next;
    }
    return count;
}

struct Node* deleteNodeFromMiddle(struct Node* last) {
    int size = countNodes(last);

    if (size % 2 != 0 && size > 1) {
        int newsize = (size / 2) + 1;
        struct Node* temp = last->next;
        struct Node* deleteNode = NULL;
        for (int i = 0; i < (newsize - 1); i++) {
            temp = temp->next;
        }
        deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
        return last;
    }
    printf("The linked list cannot have a middle element\n");
    return last;
}

int main() {
    addEmpty(10);
    last = addEnd(last,1);
    last = addEnd(last, 2);
    last = addEnd(last, 3);
    last = addEnd(last, 4);
    last = addEnd(last, 5);
    traverse(last);
    printf("\n");

    last = deleteNodeFromBeginning(last);
    traverse(last);
    printf("\n");

    last = deleteNodeFromEnd(last);
    traverse(last);
    printf("\n");

    last = deleteNodeFromMiddle(last);
    traverse(last);
    printf("\n");

    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addFront(last, 2);
    last = addAfter(last, 10, 2);
    traverse(last);
    printf("\n");

    deleteNode(last, 8);
    traverse(last);
    printf("\n");

    return 0;
}
