#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

typedef struct node Node;
typedef Node *NodePtr;

void print(NodePtr head)
{
  NodePtr current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
}

void addLast(NodePtr *head, int n)
{

  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->data = n;
  tmp->next = NULL;

  if (*head == NULL)
  {
    *head = tmp;
  }
  else
  {
    NodePtr current = *head;
    while (current != NULL)
    {
      current = current->next;
    }
    current->next = tmp;
  }
}

void addFirst(NodePtr *head, int n)
{
  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->data = n;
  tmp->next = NULL;

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

void insert(NodePtr *head, int index, int n)
{
  NodePtr tmp = (NodePtr)malloc(sizeof(Node));
  tmp->data = n;
  tmp->next = NULL;

  if (index == 0)
  {
    tmp->next = *head;
    *head = tmp;
  }
  else
  {
    int count = 0;
    NodePtr current = *head;
    while (current != NULL)
    {
      count++;
      if (count == index)
      {
        tmp->next = current->next;
        current->next = tmp;
      }
      current = current->next;
    }
  }
}

// void removeData(NodePtr *head, int n)
// {
//   NodePtr current = *head;
//   if (current->data == n)
//   {
//     *head = current->next;
//   }
//   else
//   {
//     while (current->next != NULL)
//     {
//       if (current->next->data == n)
//       {
//         current->next = current->next->next;
//       }
//       current = current->next;
//     }
//   }
// }
int main()
{
  NodePtr head = NULL;
  addLast(&head, 10);
  addFirst(&head, 1);
  insert(&head, 1, 5);
  print(head);
}