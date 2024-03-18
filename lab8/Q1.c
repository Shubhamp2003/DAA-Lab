//To implement DFS for a given graph as adjacency matrix.

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 7

void DFS(int vertex, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
        {
            DFS(i, adjacencyMatrix, visited);
        }
    }
}

int main()
{
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[1][0] = 1;
    adjacencyMatrix[0][2] = 1;
    adjacencyMatrix[2][0] = 1;
    adjacencyMatrix[0][3] = 1;
    adjacencyMatrix[3][0] = 1;
    adjacencyMatrix[4][2] = 1;
    adjacencyMatrix[2][4] = 1;
    adjacencyMatrix[3][4] = 1;
    adjacencyMatrix[4][3] = 1;
    adjacencyMatrix[4][5] = 1;
    adjacencyMatrix[5][4] = 1;
    adjacencyMatrix[4][6] = 1;
    adjacencyMatrix[6][4] = 1;

    int visited[MAX_VERTICES] = {0};
    int roll;
    printf("Enter your roll no: ");
    scanf("%d", &roll);
    roll = roll % 5;
    printf("DFS starting from vertex %d:\n", roll);
    DFS(roll, adjacencyMatrix, visited);
    return 0;
}