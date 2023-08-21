#include <stdio.h>
#define MAX_SIZE 10

typedef struct
{
  int arr[MAX_SIZE];
  int front, rear;
} Queue;

void initialize(Queue *queue)
{
  queue->front = 0;
  queue->rear = -1;
}

void enqueue(Queue *queue, int n)
{
  if (queue->rear == MAX_SIZE - 1)
  {
    printf("The queue is now full\n");
  }
  else
  {
    queue->rear++;
    queue->arr[queue->rear] = n;
  }
}

void dequeue(Queue *queue)
{
  if (queue->front > queue->rear)
  {
    printf("The queue is already empty\n");
  }
  else
  {
    queue->front++;
  }
}

void print(Queue queue)
{
  for (int i = queue.front; i <= queue.rear; i++)
  {
    printf("%d ", queue.arr[i]);
  }
}

int main()
{
  Queue queue;
  initialize(&queue);
  enqueue(&queue, 10);
  enqueue(&queue, 20);
  dequeue(&queue);
  print(queue);
}