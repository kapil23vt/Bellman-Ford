// Bellman ford code implementation for Directed Graph
// This project works for negative edge weight scenarios too!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =(struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge =(struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

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
    for (int i = 1; i <= V; i++)
        dist[i]   = INT_MAX;

    dist[src] = 0; // Distance to source node itself is zero

    //Applying Bellman Ford Algorithm

    // Iterating through all the vertices
    // We just do not use information from neighbors, we consider all nodes in network
    for (int i = 2; i <= V; i++)
    {
        // Iterating through each edge for every vertices
        for (int j = 1; j <= E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            // Apply distance vector formula
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    //check for negative-weight cycles. The above step guarantees shortest
    //distances if graph doesn't contain negative weight cycle.
    //If we get a shorter path, then there is a cycle.

    for (int i = 1; i <= E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
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
    for (int x = 1 ; x<= E ; x++){

    scanf("%d", &graph->edge[x].src);
    scanf("%d", &graph->edge[x].dest);
    scanf("%d", &graph->edge[x].weight);
    }
    printf("Enter the source node ");
    scanf("%d", &source);
    BellmanFord(graph, source);

    return 0;
}
