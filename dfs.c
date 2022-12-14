#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int visit[100];

typedef struct Graph {
    int V;
    int E;
    int** adj;
} Graph;

Graph* adjMatrix(int vertex, int** graph) {
    Graph* G = malloc(sizeof(Graph));

    if (!G) {
        printf("Memory Error\n");
        return NULL;
    }
    G-> V = vertex;
    G-> E = vertex;

    G-> adj = (int**)malloc((G-> V) * sizeof(int*));
    for (int k = 0; k < G-> V; k++) G-> adj[k] = (int*)malloc((G-> V) * sizeof(int));

    for (int u = 0; u < G-> V; u++) {
        for (int v = 0; v < G-> V; v++) G-> adj[u][v] = graph[u][v];
    }

    return G;
}

void dfs(Graph* G, int u) {
    visit[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < G-> V; v++) {
        if (!visit[v] && G-> adj[u][v]) dfs(G, v);
    }
}

void dfsTraversal(Graph* G) {
    for (int i = 0; i < 100; i++) visit[i] = 0;
    for (int i = 0; i < G-> V; i++) {
        if(!visit[i]) dfs(G, i);
    }
}

int main() {
    int vertex;
    scanf("%d", &vertex);

    int** graph;
    graph = (int**)malloc(vertex * sizeof(int*));
    for (int i = 0; i < vertex; i++) graph[i] = (int*)malloc(vertex * sizeof(int));

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) scanf("%d", &graph[i][j]);
    }

    Graph* G = adjMatrix(vertex, graph);
    dfsTraversal(G);
    printf("\n");

    return 0;
}
