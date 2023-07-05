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

    printf("%d\n", height[i]);

    for (int j = i + 2; j < n; j++)
    {

      int isSame = 0;
      for (int k = i + 1; k < j; k++)
      {

        if (height[k] == height[i] || height[k] == height[j])
        {
          isSame = 1;
          break;
        }
      }
      if (!isSame)
      {
        count++;
      }
    }
  }
  printf("%d", count);

  return 0;
}