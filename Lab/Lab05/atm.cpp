#include <iostream>
#include <queue>
using namespace std;

struct person
{
  int amount;
  int index;
};

int main()
{
  queue<person> queue;
  int n;
  int x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    int amount;
    cin >> amount;
    struct person person = {amount, i};
    queue.push(person);
  }

  while (!queue.empty())
  {
    int index = queue.front().index;
    int amount = queue.front().amount;
    if (amount - x <= 0)
    {
      cout << index + 1 << " ";
      queue.pop();
    }
    else
    {
      queue.pop();
      struct person person = {amount - x, index};
      queue.push(person);
    }
  }
}