#include <iostream>
using namespace std;

int main()
{
  int vertex;
  int edge;
  cin >> vertex >> edge;

  int k;
  cin >> k;
  int count = 0;
  for (int i = 0; i < edge; i++)
  {
    int u, v;
    cin >> u >> v;
    if (u == k || v == k)
    {
      count++;
    }
  }

  cout << count;
}