#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char name[100];           // for file or folder name
  int size;                 // for file or folder size in kb
  int type;                 // e.g. type=0 for file, or type=1 for folder
  int total_size;           // for the total size of the directory
  struct node *parent;      // for link to the node's parent
  struct node *firstChild;  // for link to the node's first child
  struct node *nextSibling; // for link to the node's next sibling
};

typedef struct node Node;
typedef Node *NodePtr;

NodePtr createRoot(char name[100], int type, int size)
{
  NodePtr node = (NodePtr)malloc(sizeof(Node));
  strcpy(node->name, name);
  node->size = size;
  node->type = type;
  node->total_size = 0;
  node->parent = NULL;
  node->firstChild = NULL;
  node->nextSibling = NULL;
  return node;
}

NodePtr createNode(char name[100], int type, int size, NodePtr parent)
{
  NodePtr node = (NodePtr)malloc(sizeof(Node));
  strcpy(node->name, name);
  node->size = size;
  node->type = type;
  node->total_size = 0;
  node->parent = parent;
  node->firstChild = NULL;
  node->nextSibling = NULL;

  if (parent->firstChild == NULL)
  {
    parent->firstChild = node;
  }
  else
  {
    NodePtr leftNode = parent->firstChild;
    if (leftNode->nextSibling == NULL)
    {
      leftNode->nextSibling = node;
    }
    else
    {
      NodePtr currentSibling = leftNode->nextSibling;
      while (currentSibling->nextSibling != NULL)
      {
        currentSibling = currentSibling->nextSibling;
      }
      currentSibling->nextSibling = node;
    }
  }
  return node;
}

void printChild(NodePtr node, int space, int isLast)
{
  if (node == NULL)
    return;

  for (int i = 1; i < space; i++)
  {
    if (i % 4 == 0)
    {
      printf("│");
    }
    else
    {
      printf(" ");
    }
  }

  if (isLast)
  {
    printf("└── ");
  }
  else
  {
    printf("├── ");
  }

  printf("%s\n", node->name);

  if (node->firstChild != NULL || node->nextSibling != NULL)
  {
    printChild(node->firstChild, space + 4, node->nextSibling == NULL);
    printChild(node->nextSibling, space, 1);
  }
}

void printTree(NodePtr node)
{
  printf(".\n");
  printChild(node, 0, 1);
}

int main()
{
  NodePtr root = createRoot("/user/rt/courses/", 1, 1000);
  NodePtr cs016 = createNode("cs016/", 1, 2000, root);
  NodePtr grades1 = createNode("grades", 0, 8000, cs016);

  NodePtr homeworks = createNode("homeworks/", 1, 1000, cs016);
  NodePtr hw1 = createNode("hw1", 0, 3000, homeworks);
  NodePtr hw2 = createNode("hw2", 0, 2000, homeworks);
  NodePtr hw3 = createNode("hw3", 0, 4000, homeworks);

  NodePtr programs = createNode("programs/", 1, 1000, cs016);
  NodePtr pr1 = createNode("pr1", 0, 57000, programs);
  NodePtr pr2 = createNode("pr2", 0, 97000, programs);
  NodePtr pr3 = createNode("pr3", 0, 74000, programs);

  NodePtr cs252 = createNode("cs252/", 1, 1000, root);
  NodePtr projects = createNode("projects/", 1, 1000, cs252);
  NodePtr grades2 = createNode("grades", 0, 3000, cs252);
  NodePtr papers = createNode("papers/", 1, 1000, projects);
  NodePtr demos = createNode("demos/", 1, 1000, projects);
  NodePtr buylow = createNode("buylow", 0, 26000, papers);
  NodePtr sellhigh = createNode("sellhigh", 0, 55000, papers);
  NodePtr market = createNode("market", 0, 4786000, demos);
  printTree(root);
  return 0;
}