#include <iostream>
#include <vector>

using namespace std;

bool isValidMove(int x, int y, int n, const vector<vector<int> > &grid, vector<vector<bool> > &visited)
{
  return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y];
}

bool dfs(int x, int y, int n, const vector<vector<int> > &grid, vector<vector<bool> > &visited)
{
  if (x == n - 1 && y == n - 1)
  {
    return true; // Reached the destination
  }

  visited[x][y] = true;

  // Try moving down, left, and right
  int dx[] = {1, 0, 0};
  int dy[] = {0, -1, 1};

  for (int i = 0; i < 3; ++i)
  {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if (isValidMove(newX, newY, n, grid, visited) && dfs(newX, newY, n, grid, visited))
    {
      return true;
    }
  }

  return false; // Couldn't reach the destination
}

int main()
{
  int n;
  cin >> n;

  vector<vector<int> > grid(n, vector<int>(n));
  vector<vector<bool> > visited(n, vector<bool>(n, false));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> grid[i][j];
    }
  }

  if (dfs(0, 0, n, grid, visited))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
