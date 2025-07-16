#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Infinity = 10000;
int **graph;
int *distance;
bool *visited;
int numNodes;

void dijkstra(int source) 
{
    for (int i = 0; i < numNodes; i++) 
    {
        distance[i] = Infinity;
        visited[i] = false;
    }

    distance[source] = 0;

    while (true) 
    {
        int minDist = Infinity;
        int minIndex = -1;

        for (int i = 0; i < numNodes; i++) 
        {
            if (!visited[i] && distance[i] < minDist) 
            {
                minDist = distance[i];
                minIndex = i;
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = true;

        for (int i = 0; i < numNodes; i++) 
        {
            if (graph[minIndex][i] != Infinity && !visited[i]) 
            {
                int altDist = distance[minIndex] + graph[minIndex][i];
                if (altDist < distance[i]) 
                {
                    distance[i] = altDist;
                }
            }
        }
    }
}

void main() 
{
    /*printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);*/
    numNodes=5;
    
    graph = (int **)malloc(numNodes * sizeof(int *));
    for (int i = 0; i < numNodes; i++) 
    {
        graph[i] = (int *)malloc(numNodes * sizeof(int));
    }
    distance = (int *)malloc(numNodes * sizeof(int));
    visited = (bool *)malloc(numNodes * sizeof(bool));

    /*printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = Infinity;
        }
    }*/
    
    graph[0][0] = 0;
    graph[0][1] = 10;
    graph[0][2] = 3;
    graph[0][3] = Infinity;
    graph[0][4] = Infinity;
    graph[1][0] = 10;
    graph[1][1] = 0;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = Infinity;
    graph[2][0] = 3;
    graph[2][1] = 1;
    graph[2][2] = 0;
    graph[2][3] = 2;
    graph[2][4] = Infinity;
    graph[3][0] = Infinity;
    graph[3][1] = 1;
    graph[3][2] = 2;
    graph[3][3] = 0;
    graph[3][4] = 7;
    graph[4][0] = Infinity;
    graph[4][1] = Infinity;
    graph[4][2] = Infinity;
    graph[4][3] = 7;
    graph[4][4] = 0;


    dijkstra(0);

    printf("Shortest distances from Node 0:\n");
    for (int i = 0; i < numNodes; i++) 
    {
        printf("Node %d: Distance %d\n", i, distance[i]);
    }
    free(graph);
    free(distance);
    free(visited);
}
