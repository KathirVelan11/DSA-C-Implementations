#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Infinity = 100000;
int numEdges = 0;
int numNodes;

struct Edge 
{
    int source;
    int destination;
    int weight;
};

struct Edge *edges = NULL;

void addEdge(int source, int destination, int weight) 
{
    if (edges == NULL) 
    {
        edges = malloc(sizeof(struct Edge));
    } 
    else 
    {
        edges = realloc(edges, (numEdges + 1) * sizeof(struct Edge));
    }

    edges[numEdges].source = source;
    edges[numEdges].destination = destination;
    edges[numEdges].weight = weight;
    numEdges++;
}

void bellmanFord(int source) 
{
    int *distance = (int*)malloc(numNodes * sizeof(int));

    for (int i = 0; i < numNodes; i++) 
    {
        distance[i] = Infinity;
    }
    distance[source] = 0;

    for (int i = 0; i < numNodes - 1; i++) 
    {
        for (int j = 0; j < numEdges; j++) 
        {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != Infinity && distance[u] + weight < distance[v]) 
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int i = 0; i < numEdges; i++) 
    {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (distance[u] != Infinity && distance[u] + weight < distance[v]) 
        {
            printf("Graph contains negative weight cycle.\n");
            free(distance);
            return;
        }
    }

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < numNodes; i++) 
    {
        printf("Node %d: Distance %d\n", i, distance[i]);
    }
    free(distance);
}

void main() 
{
    numNodes = 5;
    addEdge(0, 1, 10);
    addEdge(0, 2, 3);
    addEdge(1, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 3, 2);
    addEdge(3, 1, -1);
    addEdge(3, 4, 7);
    addEdge(4, 3, -3);
    int sourceNode = 0;
    bellmanFord(sourceNode);
    free(edges);
}
