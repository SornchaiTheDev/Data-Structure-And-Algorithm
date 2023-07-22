#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
  int value;
  struct Node_ *next;
} Node;

typedef Node *NodePtr;

void insertLast(NodePtr *head, int value)
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

void insertFirst(NodePtr *head, int value)
{
  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->value = value;

  if (*head == NULL)
  {
    *head = tmp;
  }
  else
  {
    tmp->next = *head;
    *head = tmp;
  }
}

int main()
{
  NodePtr head = NULL;

  insertLast(&head, 10);
  insertLast(&head, 20);
  insertFirst(&head,1);

  NodePtr current = head;

  while (current != NULL)
  {
    printf("%d ", current->value);
    current = current->next;
  }

  return 0;
}