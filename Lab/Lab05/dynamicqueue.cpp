#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<int> queue;
  int round;
  cin >> round;

  for (int i = 0; i < round; i++)
  {
    int type;
    int value;
    cin >> type;

    if (type == 1)
    {
      cin >> value;
      queue.push(value);
    }

    if (type == 2)
    {
      if (!queue.empty())
      {
        queue.pop();
      }
    }

    if (type == 3)
    {
      if (queue.empty())
      {
        cout << "EMPTY" << endl;
      }
      else
      {
        cout << queue.front() << endl;
      }
    }

    if (type == 4)
    {
      cout << queue.size() << endl;
    }
  }
}