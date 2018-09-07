#include <bits/stdc++.h>

using namespace std;
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    vector<string> tel;
    for (int j = 0; j < n; j++)
    {
      string tp;
      cin >> tp;
      tel.push_back(tp);
    }
    string s;
    string patron = tel[0];
    bool esta = true;
    sort(tel.begin(), tel.end());
    for (int i = 0; i < n - 1; i++)
    {
      if (tel[i + 1].size() >= tel[i].size())
      {
        s = tel[i + 1].substr(0, tel[i].size());
        if (s == tel[i])
        {
          esta = false;
          break;
        }
      }
    }
    if (esta)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }

  return 0;
}