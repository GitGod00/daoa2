#include <stdio.h>
#include <limits.h>
#define V 5
#define INF 999999

int parent[V];

int find(int i) 
{
	while (parent[i] != i) 
    {
		i = parent[i];
	}
	return i;
}

void union_set(int i, int j) 
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void main() 
{
	int graph[V][V] = {{INF, 2, INF, 6, INF},
	                  {2, INF, 3, 8, 5},
	                  {INF, 3, INF, INF, 7},
	                  {6, 8, INF, INF, 9},
	                  {INF, 5, 7, 9, INF}};
    int mincost = 0;

	for (int i = 0; i < V; i++) 
    {
		parent[i] = i;
	}
	int edge_count = 0;

	while (edge_count < V - 1) 
    {
		int min = INF;
		int a = -1;
		int b = -1;
		for (int i = 0; i < V; i++) 
        {
			for (int j = 0; j < V; j++) 
            {
				if (find(i) != find(j) && graph[i][j] < min) 
                {
					min = graph[i][j];
					a = i;
					b = j;
				}
			}
		}
		union_set(a, b);
		printf("Edge %d: (%d, %d) cost: %d\n", edge_count, a, b, min);
		edge_count += 1;
		mincost += min;
	}

	printf("Minimum cost= %d\n", mincost);
}