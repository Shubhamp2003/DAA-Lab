//To implement Floyd Warshall Algorithm for the given graph by user input

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floydWarshall(int graph[MAX_NODES][MAX_NODES], int V) {
    int dist[MAX_NODES][MAX_NODES];

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    printf("Shortest distances between vertices:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the number of nodes: ");
    scanf("%d", &V);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix (INF for infinity):\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, V);

    return 0;
}