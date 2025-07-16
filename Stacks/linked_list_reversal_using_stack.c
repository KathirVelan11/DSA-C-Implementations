#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* head = NULL;
struct Stack* stack = NULL;

void createStack() {
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
}

int isEmpty() {
    return stack->top == NULL;
}

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void reverseLinkedList() {
    struct Node* current = head;

    while (current != NULL) {
        push(current->data);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        current->data = pop();
        current = current->next;
    }
}

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printLinkedList() {
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeMemory() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main() {
    createStack();

    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    printf("Original ");
    printLinkedList();

    reverseLinkedList();

    printf("Reversed ");
    printLinkedList();

    freeMemory();

    return 0;
}
