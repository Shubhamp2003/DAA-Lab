//To implement Bellman-Ford Algorithm for the given graph by user input

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight, int edgeCount) {
    graph->edges[edgeCount].src = src;
    graph->edges[edgeCount].dest = dest;
    graph->edges[edgeCount].weight = weight;
}

void printTable(int* distances, int* parent, int start, int V) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; ++i) {
        printf("%d\t", i);
        if (distances[i] == INT_MAX) {
            printf("INF\t");
        } else {
            printf("%d\t", distances[i]);
        }

        if (i != start) {
            int current = i;
            printf("%d", current);
            while (parent[current] != -1) {
                printf(" <- %d", parent[current]);
                current = parent[current];
            }
        } else {
            printf("-");
        }
        printf("\n");
    }
}

void bellmanFord(struct Graph* graph, int start) {
    int V = graph->V;
    int E = graph->E;
    int* distances = (int*)malloc(V * sizeof(int));
    int* parent = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; ++i) {
        distances[i] = INT_MAX;
        parent[i] = -1;
    }

    distances[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < E; ++i) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            printf("Graph contains negative-weight cycle.\n");
            return;
        }
    }

    printTable(distances, parent, start, V);

    free(distances);
    free(parent);
}

int main() {
    int V, E;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight, i);
    }

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);

    bellmanFord(graph, startNode);

    return 0;
}