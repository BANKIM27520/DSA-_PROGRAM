/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
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
bool DFSUtil(int v, bool visited[], Node* adj[], int parent) {
    visited[v] = true;

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            if (DFSUtil(temp->vertex, visited, adj, v)) return true;
        } else if (temp->vertex != parent) {
            return true; // cycle detected
        }
        temp = temp->next;
    }
    return false;
}
bool hasCycle(int n, Node* adj[]) {
    bool visited[n+1];
    for (int i = 0; i <= n; i++) visited[i] = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (DFSUtil(i, visited, adj, -1)) return true;
        }
    }
    return false;
}
int main() {
    int n, e, u, v;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &e);   // number of edges

    Node* adj[n+1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); // for undirected graph
    }

    if (hasCycle(n, adj)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
