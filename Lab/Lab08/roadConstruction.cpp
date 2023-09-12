#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
  int n;
  vector<vector<int> > adj;
  vector<bool> visited;

public:
  Graph(int n) : n(n), adj(n + 1), visited(n + 1, false) {}

  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

  void BFS(int v)
  {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
      int current = q.front();
      q.pop();

      for (int u : adj[current])
      {
        if (!visited[u])
        {
          q.push(u);
          visited[u] = true;
        }
      }
    }
  }

  int countComponents()
  {
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        BFS(i);
        count++;
      }
    }
    return count;
  }
};

int main()
{
  int city, roadComplete;
  cin >> city >> roadComplete;

  Graph g(city);

  for (int i = 0; i < roadComplete; i++)
  {
    int x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }

  int count = g.countComponents() - 1;
  cout << count << endl;

  return 0;
}
