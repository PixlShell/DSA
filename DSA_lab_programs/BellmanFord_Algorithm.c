#include <stdio.h>
#include <limits.h>

#define MAX 100                                                   // Maximum number of nodes

typedef struct {
    int u, v, w;                                                // Edge from u->v with weight w
} Edge;

int main() {
    int nodes, edges;                                           // Number of nodes and edges
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    Edge edge[edges];                                           // Array of edges
    printf("Enter edges (u v w) with 0-based indexing:\n");
    for (int i = 0; i < edges; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w); // Input edges

    int source, destination;                                     // Source and destination
    printf("Enter source and destination nodes: ");
    scanf("%d %d", &source, &destination);

    int dist[MAX];                                               // Distance array
    int parent[MAX];                                             // Parent array for path
    for (int i = 0; i < nodes; i++) {
        dist[i] = INT_MAX;                                       // Initialize distances
        parent[i] = -1;                                          // Initialize parent pointers
    }
    dist[source] = 0;                                            // Distance to source = 0

    // Relax edges (nodes-1) times
    for (int i = 1; i <= nodes - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {   // Relaxation condition
                dist[v] = dist[u] + w;                           // Update distance
                parent[v] = u;                                   // Update path
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edges; j++) {
        int u = edge[j].u, v = edge[j].v, w = edge[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {       // Negative cycle detected
            printf("Negative cycle detected. No shortest path exists.\n");
            return 0;
        }
    }

    // Print shortest path and cost
    if (dist[destination] == INT_MAX) {
        printf("No path exists from %d to %d\n", source, destination); // No path
        return 0;
    }

    printf("Shortest path cost: %d\n", dist[destination]);      // Total cost

    // Reconstruct path
    int path[MAX], count = 0;
    for (int v = destination; v != -1; v = parent[v]) path[count++] = v; // Trace path

    printf("Shortest path: ");
    for (int i = count - 1; i >= 0; i--) {                       // Print path in order
        printf("%d", path[i]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");

    return 0;
}
