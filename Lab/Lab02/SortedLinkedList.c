#include <stdio.h>
#include <stdlib.h>

struct _Node
{
  int value;
  struct _Node *next;
};

typedef struct _Node Node;
typedef Node *NodePtr;

void swap(NodePtr n1, NodePtr n2)
{
  int tmp = n1->value;
  n1->value = n2->value;
  n2->value = tmp;
}

void bubbleSort(NodePtr head)
{

  int swapped;
  NodePtr i = head;
  while (i != NULL)
  {

    swapped = 0;
    NodePtr j = head;
    while (j->next != NULL)
    {
      if (j->value > j->next->value)
      {
        swap(j, j->next);
        swapped = 1;
      }
      j = j->next;
    }
    if (swapped == 0)
      break;
    i = i->next;
  }
}

void insertNode(NodePtr *head, int value)
{
  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->value = value;
  tmp->next = NULL;

  if (*head == NULL)
  {
    *head = tmp;
  }
  else
  {
    NodePtr current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = tmp;
  }
}

int main()
{

  NodePtr head = NULL;

  while (1)
  {
    int value;
    scanf("%d", &value);
    if (value == -1)
    {
      break;
    }
    insertNode(&head, value);
  }

  bubbleSort(head);
  // Print
  while (head != NULL)
  {
    printf("%d\n", head->value);
    head = head->next;
  }

  return 0;
}