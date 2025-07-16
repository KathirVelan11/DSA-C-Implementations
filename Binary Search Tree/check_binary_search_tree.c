//Check whether given Binary Tree is Binary Search Tree

//https://youtu.be/yEwSGhSsT0U?si=sqk16NMfLoTuRn2Y

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node* root = NULL;

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

bool subtreeLesser(struct Node* root, int value) 
{
    if (root == NULL)
        return true;
    if (root->data < value && subtreeLesser(root->left, value) && subtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool subtreeGreater(struct Node* root, int value) 
{
    if (root == NULL)
        return true;
    if (root->data > value && subtreeGreater(root->left, value) && subtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool isBinarySearchTree(struct Node* root) 
{
    if (root == NULL)
        return true;

    bool leftIsBST = subtreeLesser(root->left, root->data);
    bool rightIsBST = subtreeGreater(root->right, root->data);
    bool leftSubtreeIsBST = isBinarySearchTree(root->left);
    bool rightSubtreeIsBST = isBinarySearchTree(root->right);

    return leftIsBST && rightIsBST && leftSubtreeIsBST && rightSubtreeIsBST;
}

void main() 
{
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (isBinarySearchTree(root))
        printf("The binary tree is a binary search tree.\n");
    else
        printf("The binary tree is not a binary search tree.\n");
}
