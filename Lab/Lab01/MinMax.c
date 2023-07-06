#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int min = -1;
  int max = -1;
  for (int i = 0; i < n; i++)
  {
    int number;
    scanf("%d", &number);
    if (i == 0)
    {
      min = number;
      max = number;
    }
    if (number < min)
      min = number;
    if (number > max)
      max = number;
  }
  printf("%d\n", min);
  printf("%d", max);
}