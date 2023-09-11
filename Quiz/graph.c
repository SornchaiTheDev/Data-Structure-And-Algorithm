#include <stdio.h>
#include <stdlib.h>

int **initialGraph(int n)
{
  int **arr = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
  {
    arr[i] = malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = 0;
    }
  }
  return arr;
}

void addEdge(int **arr, int from, int to)
{
  arr[from][to] = 1;
}

void printGraph(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{

  int **arr = initialGraph(5);
  addEdge(arr, 0, 1);
  addEdge(arr, 0, 3);
  addEdge(arr, 1, 2);
  addEdge(arr, 1, 4);
  addEdge(arr, 2, 1);
  addEdge(arr, 2, 4);
  addEdge(arr, 4, 3);
  printGraph(arr, 5);
}