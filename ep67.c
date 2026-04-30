/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
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
void DFSUtil(int v, bool visited[], Node* adj[], int stack[], int* top) {
    visited[v] = true;

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSUtil(temp->vertex, visited, adj, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = v; // push vertex to stack after visiting all neighbors
}
void topologicalSort(int n, Node* adj[]) {
    bool visited[n+1];
    for (int i = 0; i <= n; i++) visited[i] = false;

    int stack[n+1], top = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited, adj, stack, &top);
        }
    }

    // print stack in reverse order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
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
