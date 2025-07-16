#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Infinity=10000;
int **graph;
int **distance;
int numNodes;

void floydWarshall() 
{
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            distance[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < numNodes; k++) 
    {
        for (int i = 0; i < numNodes; i++) 
        {
            for (int j = 0; j < numNodes; j++) 
            {
                if (distance[i][k] + distance[k][j] < distance[i][j]) 
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

void main() 
{
    numNodes = 5;
    
    graph = (int **)malloc(numNodes * sizeof(int *));
    distance = (int **)malloc(numNodes * sizeof(int *));
    for (int i = 0; i < numNodes; i++) 
    {
        graph[i] = (int *)malloc(numNodes * sizeof(int));
        distance[i] = (int *)malloc(numNodes * sizeof(int));
    }

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

    floydWarshall();

    printf("Shortest distances between nodes:\n");
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numNodes; i++) 
    {
        free(graph[i]);
        free(distance[i]);
    }
    free(graph);
    free(distance);

}
