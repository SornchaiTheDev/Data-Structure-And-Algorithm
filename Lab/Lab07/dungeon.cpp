#include <iostream>
#include <algorithm>
using namespace std;

int findDefeatedMonsters(int weapon, int *monsters, int n)
{
    int count = 0;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (monsters[mid] <= weapon)
        {
            count = mid + 1;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    int monster[n];
    for (int i = 0; i < n; i++)
    {
        cin >> monster[i];
    }

    sort(monster, monster + n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int weapon;
        cin >> weapon;

        int count = findDefeatedMonsters(weapon, monster, n);
        cout << count << endl;
    }

    return 0;
}
