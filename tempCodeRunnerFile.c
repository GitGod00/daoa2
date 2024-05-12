#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
void KruskalMST(int graph[][MAX_VERTICES], int V);

int main()
{
    int V = 5;

    int graph[][MAX_VERTICES] = {
        {0, 1, 7, 0, 0},
        {1, 0, 5, 0, 3},
        {7, 5, 0, 0, 6},
        {0, 0, 0, 0, 2},
        {0, 3, 6, 2, 0}};

    KruskalMST(graph, V);

    return 0;
}

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (xroot != yroot)
    {
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else
        {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
}

void KruskalMST(int graph[][MAX_VERTICES], int V)
{
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int edges_count = 0;
    struct Edge *edges = (struct Edge *)malloc(V * V * sizeof(struct Edge));

    for (int i = 0; i < V; ++i)
    {
        for (int j = i + 1; j < V; ++j)
        {
            if (graph[i][j] != 0)
            {
                edges[edges_count].src = i;
                edges[edges_count].dest = j;
                edges[edges_count].weight = graph[i][j];
                edges_count++;
            }
        }
    }

    struct Edge result[V];
    int e = 0;

    for (int i = 0; i < edges_count && e < V - 1; ++i)
    {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y)
        {
            result[e++] = edges[i];
            Union(subsets, x, y);
        }
    }

    printf("Edges of MST:\n");
    for (int i = 0; i < e; ++i)
