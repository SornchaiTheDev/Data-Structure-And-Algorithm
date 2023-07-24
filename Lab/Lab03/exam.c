#include <stdio.h>

struct Score
{
  float first;
  float second;
  float third;
  float total;
};

typedef struct Score Score;

int main()
{
  int n;
  scanf("%d", &n);
  Score people[n];
  Score avg;
  int pass[n];

  for (int i = 0; i < n; i++)
  {
    int first, second, third;
    scanf("%d %d %d", &first, &second, &third);
    people[i].first = first;
    people[i].second = second;
    people[i].third = third;
    people[i].total = first + second + third;
    pass[i] = 0;
  }

  int sumFirst = 0;
  int sumSecond = 0;
  int sumThrid = 0;
  for (int i = 0; i < n; i++)
  {
    sumFirst += people[i].first;
    sumSecond += people[i].second;
    sumThrid += people[i].third;
  }
  int sumTotal = sumFirst + sumSecond + sumThrid;
  avg.first = (float)sumFirst / n;
  avg.second = (float)sumSecond / n;
  avg.third = (float)sumThrid / n;
  avg.total = (float)sumTotal / n;

  for (int i = 0; i < n; i++)
  {
    int count = 0;
    if (people[i].first >= avg.first)
    {
      count++;
    }

    if (people[i].second >= avg.second)
    {
      count++;
    }

    if (people[i].third >= avg.third)
    {
      count++;
    }

    if (count < 2)
      continue;

    if (people[i].total < avg.total)
      continue;
    if (people[i].first == 0 || people[i].second == 0 || people[i].third == 0)
      continue;
    pass[i] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    if (pass[i] == 0)
      continue;
    printf("%d ", i + 1);
  }
  return 0;
}