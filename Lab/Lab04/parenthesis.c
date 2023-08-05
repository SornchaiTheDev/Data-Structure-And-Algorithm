#include <stdio.h>

int main()
{
  char input[1000];
  scanf("%s", input);

  int sum = 0;
  for (int i = 0; input[i] != 0; i++)
  {
    if (input[i] == '(')
      sum++;
    if (input[i] == ')')
      sum--;
  }
  if (sum == 0)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }
  return 0;
}