#include <stdio.h>

int a(int n, int sum)
{
  if (n <= 1)
  {
    return sum;
  }
  return a(n - 1, 3 + sum);
}

int main()
{
  printf("%d", a(5, 2));
  return 0;
}