#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int V; 
    struct List* array;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct List*)malloc(V * sizeof(struct List));
    
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = newNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

bool isCyclicUtil(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;
    struct Node* i;
    for (i = graph->array[v].head; i != NULL; i = i->next) {
        if (!visited[i->data]) {
            if (isCyclicUtil(graph, i->data, visited, v)) {
                return true;
            }
        } else if (i->data != parent) {
            return true;
        }
    }
    return false;
}

// Check if the graph is a tree
bool isTree(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    if (isCyclicUtil(graph, 0, visited, -1)) {
        return false;
    }

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    struct Graph* graph = createGraph(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isTree(graph)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
