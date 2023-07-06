#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int height[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &height[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i++)
  {

    // printf("%d\n", height[i]);

    for (int j = i + 1; j < n; j++)
    {
      // printf("from %d -> to %d\n", height[i], height[j]);
      // printf("pass : ");
      int isSame = 0;
      for (int k = i + 1; k < j; k++)
      {
        // printf("%d ", height[k]);
        if (height[k] >= height[i] || height[k] >= height[j])
        {
          // printf("\nskip>> \n");
          isSame = 1;
          break;
        }
      }
      if (!isSame)
      {
        // printf("\ncount\n");
        count++;
      }
      // printf("\n");
    }

    // printf("-------\n");
  }
  printf("%d", count);
  // printf("count : %d", count);

  return 0;
}