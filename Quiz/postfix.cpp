#include <iostream>
#include <stack>
using namespace std;

int len(string input)
{
  return input.length();
}

int order(char a)
{
  switch (a)
  {
  case '^':
    return 1;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 3;
  case '(':
  case ')':
    return 4;
  default:
    return 0;
  }
}

int main()
{
  stack<char> stack;
  string input;
  getline(cin, input);
  int inputLength = len(input);
  for (int i = 0; i < inputLength; i++)
  {
    if (input[i] == ' ')
      continue;
    if (input[i] >= 'A' && input[i] <= 'z')
    {
      cout << input[i];
      continue;
    }
    if (stack.empty())
    {
      stack.push(input[i]);
      continue;
    }

    if (input[i] == '(')
    {
      stack.push(input[i]);
      continue;
    }
    if (order(input[i]) < order(stack.top()))
    {
      stack.push(input[i]);
      continue;
    }
    else
    {
      cout << stack.top();
      stack.pop();
    }

    if (input[i] == ')')
    {
      while (stack.top() != '(')
      {
        cout << stack.top();
        stack.pop();
      }
      if (!stack.empty() && stack.top() == '(')
      {
        stack.pop();
      }
    }
  }
  while (!stack.empty())
  {
    cout << stack.top();
    stack.pop();
  }
}