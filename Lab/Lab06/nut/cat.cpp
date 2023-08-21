#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool matchesCondition(string &input, int length)
{
  int state = 0;
  for (int i = 0; i < length; i++)
  {
    if (state == 0)
    {
      if (input[i] == 'm' || input[i] == 'M')
        state = 1;
      else
        return false;
    }
    else if (state == 1)
    {
      if (input[i] == 'e' || input[i] == 'E')
        state = 2;
      else if (input[i] == 'm' || input[i] == 'M')
        continue;
      else
        return false;
    }
    else if (state == 2)
    {
      if (input[i] == 'o' || input[i] == 'O')
        state = 3;
      else if (input[i] == 'e' || input[i] == 'E')
        continue;
      else
        return false;
    }
    else if (state == 3)
    {
      if (input[i] == 'w' || input[i] == 'W')
        state = 4;
      else if (input[i] == 'o' || input[i] == 'O')
        continue;
      else
        return false;
    }
    else if (state == 4)
    {
      if (input[i] == 'w' || input[i] == 'W')
      {
        continue;
      }

      return false;
    }
  }

  return state == 4;
}

int main()
{
  int numStrings;
  cin >> numStrings;

  for (int i = 0; i < numStrings; ++i)
  {
    int length;
    string input;
    cin >> length;
    cin >> input;

    if (matchesCondition(input, length))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}
