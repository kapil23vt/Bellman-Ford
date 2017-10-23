// Bellman ford code implementation for Directed Graph
// This project works for negative edge weight scenarios too!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Each edge has source, destination and weight
struct Edge
{
    int src, dest, weight;
};

// Each graph has number of vertices, edges and "edges"
struct Graph
{
    int V, E;
    struct Edge* edge;
};

// Create graph for say 3 vertices and 4 edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =(struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge =(struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// dist[V] will store shortest distance values
void printArr(int dist[], int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", i, dist[i]);
}


void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Initialize distances from source to other all nodes as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;

    dist[src] = 0; // Distance to source node itself is zero

    //Applying Bellman Ford Algorithm

    // Iterating through all the vertices
    // We just do not use information from neighbors, we consider all nodes in network
    for (int i = 1; i < V; i++)
    {
        // Iterating through each edge for every vertices
        for (int j = 0; j < E; j++)
        {
            // For each edge, we are storing src, dest and weight values
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            // Apply distance vector formula
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    printArr(dist, V);
    return;
}
int main()
{
    int V;int E;int source;
    printf("Enter the number of Vertices in the graph ");
    scanf("%d", &V);
    printf("Enter the number of Edges in the graph ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);
    printf("Enter start-end-weight for the edges\n");
    for (int x = 0 ; x< E ; x++){

    scanf("%d", &graph->edge[x].src);
    scanf("%d", &graph->edge[x].dest);
    scanf("%d", &graph->edge[x].weight);
    }
    printf("Enter the source node ");
    scanf("%d", &source);
    BellmanFord(graph, source);

    return 0;
}
