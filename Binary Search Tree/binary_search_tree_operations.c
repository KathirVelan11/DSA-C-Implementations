#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode 
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* root = NULL;

struct BstNode* GetNewNode(int data) 
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* node, int data) 
{
    if (node == NULL) 
        node = GetNewNode(data);
    else if (data <= node->data)
        node->left = Insert(node->left, data);
    else 
        node->right = Insert(node->right, data);
    return node;
}

bool Search(struct BstNode* node, int data) 
{
    if (node == NULL) 
        return false;
    else if (node->data == data) 
        return true;
    else if (data <= node->data) 
        return Search(node->left, data);
    else 
        return Search(node->right, data);
}

int findMin(struct BstNode* node)
{
    if (node == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    else if (node->left == NULL)
    {
        return node->data;
    }
    return findMin(node->left);
}

int findMax(struct BstNode* node)
{
    if (node == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    else if (node->right == NULL)
    {
        return node->data;
    }
    return findMax(node->right);
}

int findHeight(struct BstNode* node)
{
    if (node == NULL)
        return -1; // Height of an empty tree is -1
    else {
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

void Preorder(struct Node *root) 
{
	if(root == NULL) return;
	printf("%c ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node *root) 
{
	if(root == NULL) return;
	Inorder(root->left);
	printf("%c ",root->data);
	Inorder(root->right);
}

void Postorder(Node *root) 
{
	if(root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ",root->data);
}


void main() 
{
    root = Insert(root, 15);
    Insert(root, 10);
    Insert(root, 20);
    Insert(root, 25);
    Insert(root, 8);
    Insert(root, 12);
    
    int number;
    printf("Enter number be searched\n");
    scanf("%d", &number);
    if (Search(root, number) == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    printf("Minimum element in the BST: %d\n", findMin(root));
    printf("Maximum element in the BST: %d\n", findMax(root));
    printf("Height of the BST: %d\n", findHeight(root));
    
}
