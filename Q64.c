#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Node {
    int data;
    struct Node* next;
};


int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}


void bfs(int s, struct Node* adj[], int visited[], int n) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

   
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

  
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        
    }

    int s;
    scanf("%d", &s);  

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    bfs(s, adj, visited, n);

    return 0;
}
