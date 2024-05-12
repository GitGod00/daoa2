#include <stdio.h>
#include <limits.h>

#define V 4

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int tsp(int graph[][V], int mask, int pos, int dp[][V], int n)
{

    if (mask == (1 << n) - 1)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        if (!(mask & (1 << i)))
        {
            int newAns = graph[pos][i] + tsp(graph, mask | (1 << i), i, dp, n);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix of size %d x %d:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("Minimum cost for TSP is %d\n", tsp(graph, 1, 0, dp, n));

    return 0;
}
