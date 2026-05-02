/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}
void topologicalSort(int n, Node* adj[]) {
    int inDegree[n+1];
    for (int i = 0; i <= n; i++) inDegree[i] = 0;

    // calculate in-degrees
    for (int i = 1; i <= n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    int queue[n+1], front = 0, rear = 0;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current); // print current vertex

        Node* temp = adj[current];
        while (temp != NULL) {
            inDegree[temp->vertex]--;
            if (inDegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}
int main() {
    int n, e, u, v;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &e);   // number of edges

    Node* adj[n+1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v); // directed edge from u to v
    }

    topologicalSort(n, adj);
    return 0;
}
