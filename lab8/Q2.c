//To implement BFS for a given graph as adjacency matrix.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
#define QUEUE_CAPACITY 100

void BFS(int startVertex, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES])
{
    int queue[QUEUE_CAPACITY];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    queue[++rear] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[++front];

        for (int i = 0; i < MAX_VERTICES; i++)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
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
    printf("BFS starting from vertex %d:\n", roll);
    BFS(roll, adjacencyMatrix, visited);
    return 0;
}