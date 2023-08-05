#include <stdio.h>

int main()
{
  int size;
  scanf("%d", &size);
  int grid[size][size];
  int max;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      int number;
      scanf(" %d", &number);
      if ((i == 0 && j == 0) || number > max)
      {
        max = number;
      }
      grid[i][j] = number;
    }
  }

  for (int row = 0; row < size; row++)
  {
    if (row == size)
      break;
    for (int col = 0; col < size; col++)
    {
      printf("-o-o-o-o-o-o-o-o-o-o-\n");
      printf("row : %d , col : %d = %d \n", row, col, grid[row][col]);
      if (row == 0 && col == 0)
      {
        if (grid[row][col] + grid[row][col + 1] > max)
        {
          max = grid[row][col] + grid[row][col + 1];
        }
        if (grid[row][col] + grid[row + 1][col] > max)
        {
          max = grid[row][col] + grid[row + 1][col];
        }
        printf("%d + %d = %d\n", grid[row][col], grid[row][col + 1], grid[row][col] + grid[row][col + 1]);
        printf("%d + %d = %d\n", grid[row][col], grid[row + 1][col], grid[row][col] + grid[row + 1][col]);
      }
      if (row == 0 && col == 1)
      {
        if (grid[row][col] + grid[row + 1][col] > max)
        {
          max = grid[row][col] + grid[row + 1][col];
        }
        printf("%d + %d = %d\n", grid[row][col], grid[row + 1][col], grid[row][col] + grid[row + 1][col]);
      }
      if (row == 0 && col == 2)
      {
        // if (grid[row][col] + grid[row + 1][col] > max)
        // {
        //   max = grid[row][col] + grid[row + 1][col];
        // }
        printf("")
        printf("%d + %d = %d\n", grid[row][col], grid[row][col], grid[row][col] + grid[row][col]);
      }

      if (row == 1 && col == 0)
      {
        if (grid[row][col] + grid[row][col + 1] > max)
        {
          max = grid[row][col] + grid[row][col + 1];
        }
        printf("%d + %d = %d\n", grid[row][col], grid[row][col + 1], grid[row][col] + grid[row][col + 1]);
      }
    }

    printf("--------\n");
  }

  printf("%d", max);
  return 0;
}