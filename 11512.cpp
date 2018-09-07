#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    map<string, int> contador;
    string p;
    cin >> p;
    int s = p.size();
    bool exito = false;
    for (int d = s - 1; d > 0; d--)
    {
      contador.clear();
      for (int i = 0, j; (j = d + i) <= s; i++)
      {
        string sub = p.substr(i, d);
        contador[sub]++;
      }
      for (map<string, int>::iterator i = contador.begin(); i != contador.end(); i++)
      {
        if (i->second >= 2)
        {
          cout << i->first << " " << i->second << "\n";
          exito = true;
          d = -1;
          break;
        }
      }
    }
    if (!exito)
      cout << "No repetitions found!"
           << "\n";
  }
  return 0;
}
