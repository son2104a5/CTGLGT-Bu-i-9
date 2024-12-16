#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Khoang cach ngan nhat tu dinh %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Dinh %d: ", i);
        if (dist[i] == INF) {
            printf("Khong the den\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX] = {0};
    int n, m, u, v, w, src;

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Nhap canh %d (dinh1 dinh2 trong so): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Nhap dinh nguon: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}

