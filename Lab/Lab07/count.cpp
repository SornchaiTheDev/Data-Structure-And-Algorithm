#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int numbers[n];
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  int find;
  cin >> find;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (find == numbers[i])
    {
      count++;
    }
  }
  cout << count;
}