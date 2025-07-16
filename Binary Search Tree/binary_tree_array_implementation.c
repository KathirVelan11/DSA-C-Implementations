#include <stdio.h>

char binary_tree[10];

void root(char key) 
{
    if (binary_tree[0] != '\0')
        printf("Root value exits");
    else
        binary_tree[0] = key;
}

void left_child(char key, int parent) 
{
    if (binary_tree[parent] == '\0')
        printf("\nNo parent found");
    else
        binary_tree[(parent * 2) + 1] = key;
}

void right_child(char key, int parent) 
{
    if (binary_tree[parent] == '\0')
        printf("\nNo parent found");
    else
        binary_tree[(parent * 2) + 2] = key;
;
}

void print_binary_tree() 
{
    for (int i = 0; i < 10; i++) 
    {
        if (binary_tree[i] != '\0')
            printf("%c", binary_tree[i]);
        else
            printf(" ");
    }
}


void main() 
{
    root('A');
    left_child('B', 0);
    right_child('C', 0);
    left_child('D', 1);
    right_child('E', 1);
    right_child('F', 2);
    left_child('G', 3);
    right_child('H', 3);
    print_binary_tree();

}
