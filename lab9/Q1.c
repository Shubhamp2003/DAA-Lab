//To implement Dijkstra’s Algorithm for the given graph by user input

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int V;
    struct List* array;
};

struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct List*)malloc(V * sizeof(struct List));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printTable(int* distances, int* path, int start, int V) {
    printf("Vertex\tCost\tPath\n");
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
            while (path[current] != -1) {
                printf(" <- %d", path[current]);
                current = path[current];
            }
        } else {
            printf("-");
        }
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, int start) {
    int* distances = (int*)malloc(graph->V * sizeof(int));
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* path = (int*)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; ++i) {
        distances[i] = INT_MAX;
        visited[i] = 0;
        path[i] = -1;
    }

    distances[start] = 0;

    for (int count = 0; count < graph->V - 1; ++count) {
        int minDist = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < graph->V; ++v) {
            if (!visited[v] && distances[v] < minDist) {
                minDist = distances[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        struct Node* currentNode = graph->array[minIndex].head;
        while (currentNode != NULL) {
            int neighbor = currentNode->dest;
            int weight = currentNode->weight;

            if (!visited[neighbor] && distances[minIndex] != INT_MAX &&
                distances[minIndex] + weight < distances[neighbor]) {
                distances[neighbor] = distances[minIndex] + weight;
                path[neighbor] = minIndex;
            }

            currentNode = currentNode->next;
        }
    }

    printTable(distances, path, start, graph->V);

    free(distances);
    free(visited);
    free(path);
}

int main() {
    int V, E;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &V, &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    dijkstra(graph, startNode);

    return 0;
}