#include <stdio.h>

int count = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
  if (n == 1)
  {
    count++;
    printf("move#%d(1,%c,%c,%c)\n", count, source, auxiliary, destination);

    return;
  }

  towerOfHanoi(n - 1, source, destination, auxiliary);

  count++;
  printf("move#%d(1,%c,%c,%c)\n", count, source, auxiliary, destination);

  towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
  int numDisks;
  printf("Input N = ");
  scanf("%d", &numDisks);
  printf("Output:\n");
  printf("Start\n");
  towerOfHanoi(numDisks, 'A', 'B', 'C');

  return 0;
}
