#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int* items;
    int top;
};

struct Graph
{
    int vertices;
    int** adj_matrix;
};

struct Graph* graph;

struct Stack* create_stack(int max_vertices) 
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->items = (int*)malloc(max_vertices * sizeof(int));
    return s;
}

bool is_empty(struct Stack* s) 
{
    return s->top == -1;
}

void push(struct Stack* s, int value) 
{
    s->top++;
    s->items[s->top] = value;
}

int pop(struct Stack* s) 
{
    if (is_empty(s)) 
    {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

struct Graph* create_graph(int vertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adj_matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) 
    {
        graph->adj_matrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}

void add_edge(struct Graph* graph, int source, int destination) 
{
    graph->adj_matrix[source][destination] = 1;
}

void dfs(struct Graph* graph, int start) 
{
    struct Stack* s = create_stack(graph->vertices);
    bool visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = false;

    push(s, start);
    visited[start] = true;

    while (!is_empty(s)) 
    {
        int current = pop(s);
        printf("%d ", current);
        for (int i = 0; i < graph->vertices; i++) 
        {
            if (graph->adj_matrix[current][i] == 1 && !visited[i]) 
            {
                push(s, i);
                visited[i] = true;
            }
        }
    }
    free(s->items);
    free(s);
}

void main() 
{
    int max_vertices = 4;
    //printf("Enter the maximum number of vertices: ");
    //scanf("%d", &max_vertices);

    graph = create_graph(max_vertices);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);

    printf("DFS traversal starting from vertex 2: ");
    dfs(graph, 2);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < graph->vertices; i++) 
    {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}
