#include <stdio.h>
#include <stdbool.h>
#define V 9
#define inf 9999

int minDist(int dist[], bool visited[])
{
    int min_idx;
    int min = inf;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] < min)
        {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void dijkstra(int graph[V][V], int src)
{
    bool visited[V];
    int dist[V];
    int i;
    for (i = 0; i < V; i++)
    {
        dist[i] = inf;
        visited[i] = false;
    }
    dist[src] = 0;
    visited[src] = true;

    for (i = 0; i < V; i++)
    {
        int u = minDist(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != inf &&
                graph[u][v] + dist[u] < dist[v])
            {
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    for (i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
}
void main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
}
