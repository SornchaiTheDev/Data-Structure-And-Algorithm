#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[20];
  float score;
} Person;

int main()
{

  Person people[5];

  // Store Input information

  for (int i = 0; i < 5; i++)
  {
    char name[20];
    float score;
    printf("Enter name : ");
    scanf("%s", name);
    strcpy(people[i].name, name);
    printf("Enter score : ");
    scanf("%f", &score);
    people[i].score = score;
  }

  // calculate mean
  float mean;
  for (int i = 0; i < 5; i++)
  {
    mean += people[i].score;
  }

  mean /= 5;

  printf("\nMean : %.2f\n", mean);
  printf("This people have score greater than menan\n");
  printf("-----------------------------------------\n");

  for (int i = 0; i < 5; i++)
  {
    if (people[i].score > mean)
    {
      printf("Name : %s , Score : %.2f\n", people[i].name, people[i].score);
    }
  }

  printf("-----------------------------------------");

  return 0;
}