#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;
    int adjMatrix[MAX][MAX];
    Edge edges[MAX];
} Graph;

void initGraph(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v, int directed) {
    g->adjMatrix[u][v] = 1;
    if (!directed) {
        g->adjMatrix[v][u] = 1;
    }
}

int dfsDirected(Graph *g, int v, int visited[], int recStack[]) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;
        for (int i = 0; i < g->n; i++) {
            if (g->adjMatrix[v][i]) {
                if (!visited[i] && dfsDirected(g, i, visited, recStack)) {
                    return 1;
                } else if (recStack[i]) {
                    return 1;
                }
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int hasCycleDirected(Graph *g) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};
    for (int i = 0; i < g->n; i++) {
        if (dfsDirected(g, i, visited, recStack)) {
            return 1;
        }
    }
    return 0;
}

int dfsUndirected(Graph *g, int v, int visited[], int parent) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->adjMatrix[v][i]) {
            if (!visited[i]) {
                if (dfsUndirected(g, i, visited, v)) {
                    return 1;
                }
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycleUndirected(Graph *g) {
    int visited[MAX] = {0};
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            if (dfsUndirected(g, i, visited, -1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, u, v, directed, choice;
    Graph g;

    printf("Do thi co huong (1) hay vo huong (0): ");
    scanf("%d", &directed);

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    initGraph(&g, n);

    for (int i = 0; i < m; i++) {
        printf("Nhap canh %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v, directed);
    }

    if (directed) {
        if (hasCycleDirected(&g)) {
            printf("Do thi co chu ky\n");
        } else {
            printf("Do thi khong co chu ky\n");
        }
    } else {
        if (hasCycleUndirected(&g)) {
            printf("Do thi co chu ky\n");
        } else {
            printf("Do thi khong co chu ky\n");
        }
    }

    return 0;
}

