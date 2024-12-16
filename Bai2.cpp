#include <stdio.h>

#define MAX 100

void initMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX][MAX], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void printMatrix(int matrix[MAX][MAX], int n) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkSymmetry(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, m, u, v;
    int matrix[MAX][MAX];

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    initMatrix(matrix, n);

    for (int i = 0; i < m; i++) {
        printf("Nhap canh %d (dinh1 dinh2): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(matrix, u, v);
    }

    printMatrix(matrix, n);

    if (checkSymmetry(matrix, n)) {
        printf("Ma tran ke doi xung\n");
    } else {
        printf("Ma tran ke khong doi xung\n");
    }

    return 0;
}

