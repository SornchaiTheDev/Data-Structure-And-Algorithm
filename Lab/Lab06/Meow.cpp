#include <iostream>
#include <regex>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int amount;
  cin >> amount;

  regex match("[mM]+[eE]+[oO]+[wW]+", regex_constants::icase);

  for (int i = 0; i < amount; i++)
  {
    int length;
    cin >> length;

    string input;
    cin >> input;

    if (regex_match(input, match))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
