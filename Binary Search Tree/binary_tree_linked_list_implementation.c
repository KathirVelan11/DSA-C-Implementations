#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode 
{
    char data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

struct BinaryTreeNode* root = NULL;

struct BinaryTreeNode* createNode(char key) 
{
    struct BinaryTreeNode* newNode = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void setRoot(char key)
{
    if (root != NULL) 
    {
        printf("Root value exists.\n");
    } 
    else 
    {
        root = createNode(key);
    }
}

void leftChild(struct BinaryTreeNode* parent, char key) 
{
    if (parent == NULL) 
    {
        printf("No parent found.\n");
    } 
    else 
    {
        if (parent->left != NULL) 
        {
            printf("Left child already exists for this parent.\n");
        } 
        else 
        {
            parent->left = createNode(key);
        }
    }
}

void rightChild(struct BinaryTreeNode* parent, char key) 
{
    if (parent == NULL) 
    {
        printf("No parent found.\n");
    } 
    else 
    {
        if (parent->right != NULL) 
        {
            printf("Right child already exists for this parent.\n");
        } 
        else 
        {
            parent->right = createNode(key);
        }
    }
}

void printBinaryTree(struct BinaryTreeNode* node) 
{
    if (node != NULL) 
    {
        printBinaryTree(node->left);
        printf("%c ", node->data);
        printBinaryTree(node->right);
    }
}

void main() 
{
    setRoot('A');
    leftChild(root, 'B');
    rightChild(root, 'C');
    leftChild(root->left, 'D');
    rightChild(root->left, 'E');
    rightChild(root->right, 'F');
    leftChild(root->left->left, 'G');
    rightChild(root->left->left, 'H');
    printf("Binary tree: ");
    printBinaryTree(root);
    printf("\n");
}
