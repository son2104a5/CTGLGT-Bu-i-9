#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

typedef struct {
    int n;
    AdjList list[MAX];
} Graph;

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < vertices; i++) {
        g->list[i].head = NULL;
    }
}

void addEdge(Graph* g, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = g->list[u].head;
    g->list[u].head = newNode;

    newNode = createNode(u);
    newNode->next = g->list[v].head;
    g->list[v].head = newNode;
}

void BFS(Graph* g, int startVertex) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    printf("Thu tu duyet BFS: ");
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        Node* temp = g->list[currentVertex].head;
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, m, u, v, startVertex;
    Graph g;

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    initGraph(&g, n);

    for (int i = 0; i < m; i++) {
        printf("Nhap canh %d (dinh1 dinh2): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &startVertex);

    BFS(&g, startVertex);

    return 0;
}
 
