#include <stdio.h>

#define MAX_SIZE 10

typedef struct
{
  int arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack)
{
  stack->top = -1;
}

void push(Stack *stack, int x)
{

  if (stack->top == MAX_SIZE)
  {
    printf("The stack is already full.");
  }
  else
  {
    stack->top++;
    stack->arr[stack->top] = x;
  }
}

int pop(Stack *stack)
{
  if (stack->top == -1)
  {
    printf("The stack is empty.\n");
    return -1;
  }
  else
  {
    int x = stack->arr[stack->top];
    stack->top--;
    return x;
  }
}

int top(Stack *stack)
{
  if (stack->top == -1)
  {
    printf("The stack is empty\n");
    return -1;
  }
  return stack->arr[stack->top];
}

int main()
{
  Stack stack;
  initialize(&stack);
  push(&stack, 1);
  printf("%d\n", top(&stack));
  push(&stack, 3);
  push(&stack, 5);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  printf("%d", top(&stack));
}