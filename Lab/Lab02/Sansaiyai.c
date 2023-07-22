#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
  int value;
  struct Node_ *leftHand;
  struct Node_ *rightHand;
} Node;

typedef Node *NodePtr;

void createHead(NodePtr *head, int index)
{
  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->value = index;
  *head = tmp;
}

void addRightHand(NodePtr head, NodePtr rightHand)
{
  head->rightHand = rightHand;
}

void addLeftHand(NodePtr head, NodePtr leftHand)
{
  head->leftHand = leftHand;
}

int main()
{
  int amount;
  scanf("%d", &amount);

  NodePtr people[amount];

  for (int i = 0; i < amount; i++)
  {
    createHead(&people[i], i);
  }

  int *counts = (int *)malloc(sizeof(int) * amount);

  for (int i = 0; i < amount; i++)
  {
    int leftHand, rightHand;
    scanf("%d %d", &leftHand, &rightHand);
    if (rightHand == 0)
    {
      counts[i] = 1;
    }
    if (leftHand != 0)
    {
      addLeftHand(people[i], people[leftHand - 1]);
    }
    // if (rightHand != 0)
    // {
    //   addRightHand(people[i], people[rightHand - 1]);
    // }
  }

  int maxCount = 0;
  // print check
  // for (int i = 0; i < amount; i++)
  // {
  //   printf("%d ->", counts[i]);
  // }
  // printf("\n");
  for (int i = 0; i < amount; i++)
  {
    int count = 1;
    if (counts[i] != 1)
    {
      continue;
    }

    // printf("Person : %d\n", people[i]->value + 1);
    // printf("%d -> ", people[i]->value + 1);

    for (NodePtr person = people[i]->leftHand; person != NULL; person = person->leftHand)
    {
      // printf("%d -> ", person->value + 1);
      count++;
    }
    // printf("\n");

    if (count > maxCount)
    {
      maxCount = count;
    }
  }
  printf("%d", maxCount);
  return 0;
}