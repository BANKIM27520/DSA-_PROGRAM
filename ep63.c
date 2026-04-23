/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
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

void DFSUtil(int v, bool visited[], Node* adj[]) {
    visited[v] = true;
    printf("%d ", v);  // print current vertex

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSUtil(temp->vertex, visited, adj);
        }
        temp = temp->next;
    }
}

void DFS(int n, Node* adj[], int start) {
    bool visited[n+1];
    for (int i = 0; i <= n; i++) visited[i] = false;

    DFSUtil(start, visited, adj);
}

int main() {
    int n, e, u, v, start;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &e);   // number of edges

    Node* adj[n+1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); // if undirected graph
    }

    scanf("%d", &start); // starting vertex
    DFS(n, adj, start);

    return 0;
}


