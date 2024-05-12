#include <stdio.h>
#include <stdbool.h>
#define V 5
#define inf 9999

void main()
{
  int graph[V][V] = {
      {0, 9, 75, 0, 0},
      {9, 0, 95, 19, 42},
      {75, 95, 0, 51, 66},
      {0, 19, 51, 0, 31},
      {0, 42, 66, 31, 0}};
  int src = 0;
  int n = 0;
  int x, y, i, j, min;
  bool visited[V];

  for (i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  visited[src] = true;
  while (n < V - 1)
  {
    x = 0;
    y = 0;
    min = inf;
    for (i = 0; i < V; i++)
    {
      if (visited[i])
      {
        for (j = 0; j < V; j++)
        {
          if (!visited[j] && graph[i][j] && graph[i][j] < min)
          {
            min = graph[i][j];
            x = i;
            y = j;
          }
        }
      }
    }
    printf("%d -> %d: %d\n", x, y, graph[x][y]);
    visited[y] = true;
    n++;
  }
}