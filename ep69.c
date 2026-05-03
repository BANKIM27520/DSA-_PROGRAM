/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// adjacency list representation
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}
void dijkstra(int n, Node* adj[], int source) {
    int dist[n+1];
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    // simple priority queue using array
    int visited[n+1];
    for (int i = 0; i <= n; i++) visited[i] = 0;

    for (int count = 0; count < n; count++) {
        int minDist = INT_MAX, minIndex = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) break; // all reachable vertices processed
        visited[minIndex] = 1;

        Node* temp = adj[minIndex];
        while (temp != NULL) {
            if (!visited[temp->vertex] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + temp->weight < dist[temp->vertex]) {
                dist[temp->vertex] = dist[minIndex] + temp->weight;
            }
            temp = temp->next;
        }
    }

    // print shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
}
int main() {
    int n, e, u, v, w;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &e);   // number of edges

    Node* adj[n+1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w); // directed edge from u to v with weight w
    }

    int source;
    scanf("%d", &source); // source vertex
    dijkstra(n, adj, source);

    return 0;
}
