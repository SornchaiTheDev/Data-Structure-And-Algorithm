#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> stack;
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
      stack.push(value);
    }

    if (type == 2)
    {
      if (!stack.empty())
      {
        stack.pop();
      }
    }

    if (type == 3)
    {
      if (stack.empty())
      {
        cout << "EMPTY" << endl;
      }
      else
      {
        cout << stack.top() << endl;
      }
    }

    if (type == 4)
    {
      cout << stack.size() << endl;
    }
  }
}