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

void initGraphMatrix(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(Graph *g, int u, int v, int directed) {
    g->adjMatrix[u][v] = 1;
    if (!directed) {
        g->adjMatrix[v][u] = 1;
    }
}

void printMatrix(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void initGraphList(Graph *g, int n) {
    g->n = n;
    g->m = 0;
}

void addEdgeList(Graph *g, int u, int v, int directed) {
    g->edges[g->m].u = u;
    g->edges[g->m].v = v;
    g->m++;
    if (!directed) {
        g->edges[g->m].u = v;
        g->edges[g->m].v = u;
        g->m++;
    }
}

void printList(Graph *g) {
    for (int i = 0; i < g->m; i++) {
        printf("%d -> %d\n", g->edges[i].u, g->edges[i].v);
    }
}

int main() {
    int type, n, m, u, v, directed;
    Graph g;

    printf("Nhap loai do thi (0: Vo huong, 1: Co huong): ");
    scanf("%d", &directed);

    printf("Nhap so dinh: ");
    scanf("%d", &n);

    printf("Nhap so canh: ");
    scanf("%d", &m);

    printf("Chon kieu luu tru (0: Ma tran ke, 1: Danh sach ke): ");
    scanf("%d", &type);

    if (type == 0) {
        initGraphMatrix(&g, n);
        for (int i = 0; i < m; i++) {
            printf("Nhap canh %d (u v): ", i + 1);
            scanf("%d %d", &u, &v);
            addEdgeMatrix(&g, u, v, directed);
        }
        printf("Ma tran ke:\n");
        printMatrix(&g);
    } else {
        initGraphList(&g, n);
        for (int i = 0; i < m; i++) {
            printf("Nhap canh %d (u v): ", i + 1);
            scanf("%d %d", &u, &v);
            addEdgeList(&g, u, v, directed);
        }
        printf("Danh sach ke:\n");
        printList(&g);
    }

    return 0;
}

