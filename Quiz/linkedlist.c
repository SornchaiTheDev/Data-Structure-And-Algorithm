#include <stdio.h>

typedef struct Node_
{
  int value;
  struct Node_ *next;
} Node;

typedef Node *NodePtr;

typedef struct Header
{
  int n;
  NodePtr next;
  NodePtr last;
} Header;

int main()
{
  Node n2 = {2, NULL};
  Node n1 = {1, &n2};
  Header header = {2, &n1, &n2};

  printf("Header : \n");
  printf("n : %d\n", header.n);
  printf("Next Node : %p\n", header.next);
  printf("Last Node : %p\n", header.last);
  printf("-----------------\n");
  printf("Value : %d\n", header.next->value);
  printf("Next : %p\n", header.next->next);
  printf("-----------------\n");
  printf("Value : %d\n", header.next->next->value);
  printf("Next : %p\n", header.next->next->next);
}