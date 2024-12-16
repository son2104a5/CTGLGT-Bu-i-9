#include <stdio.h>

#define MAX 100

void calculateDegreesUndirected(int graph[MAX][MAX], int n) {
    int degree[MAX] = {0};
    int maxDegree = 0, vertex = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                degree[i]++;
            }
        }
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            vertex = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", vertex);
}

void calculateDegreesDirected(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0}, outDegree[MAX] = {0};
    int totalDegree[MAX] = {0};
    int maxDegree = 0, vertex = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
        totalDegree[i] = inDegree[i] + outDegree[i];
        if (totalDegree[i] > maxDegree) {
            maxDegree = totalDegree[i];
            vertex = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", vertex);
}

int main() {
    int graph[MAX][MAX] = {0};
    int n, m, u, v, type;

    printf("Nhap loai do thi (0: Vo huong, 1: Co huong): ");
    scanf("%d", &type);

    printf("Nhap so dinh: ");
    scanf("%d", &n);

    printf("Nhap so canh: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Nhap canh %d (dinh1 dinh2): ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (type == 0) {
            graph[v][u] = 1;
        }
    }

    if (type == 0) {
        calculateDegreesUndirected(graph, n);
    } else {
        calculateDegreesDirected(graph, n);
    }

    return 0;
}

