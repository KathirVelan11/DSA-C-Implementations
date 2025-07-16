#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue
{
    int* items;
    int front;
    int rear;
};

struct Graph
{
    int vertices;
    int** adj_matrix;
};

struct Graph* graph;

struct Queue* create_queue(int max_vertices) 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->items = (int*)malloc(max_vertices * sizeof(int));
    return q;
}

bool is_empty(struct Queue* q) 
{
    if(q->front == -1)
        return true;
    else
        return false;
}

void enqueue(struct Queue* q, int value, int max_vertices) 
{
    if (q->rear == max_vertices - 1) 
    {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1) 
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) 
{
    if (is_empty(q)) 
    {
        printf("Queue underflow!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) 
    {
        q->front = q->rear = -1;
    }
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

void bfs(struct Graph* graph, int start) 
{
    struct Queue* q = create_queue(graph->vertices);
    bool visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = false;

    visited[start] = true;
    enqueue(q, start, graph->vertices);

    while (!is_empty(q)) 
    {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++) 
        {
            if (graph->adj_matrix[current][i] == 1 && !visited[i]) 
            {
                visited[i] = true;
                enqueue(q, i, graph->vertices);
            }
        }
    }

    free(q->items);
    free(q);
}

int main() 
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

    printf("BFS traversal starting from vertex 2: ");
    bfs(graph, 2);
    printf("\n");
    
    // Free allocated memory
    for (int i = 0; i < max_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
    
    return 0;
}
