#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> vec;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }
  int aux = n, i = 0;
  while (n > 0)
  {
    pq.push(vec[i]);
    if (vec[i] == aux)
    {
      int cont = 1, top = pq.top();
      pq.pop();
      cout << top << " ";

      while (top - 1 == pq.top())
      {
        top = pq.top();
        cout << top << " ";
        cont++;
        pq.pop();
      } // imprime cola de propidad hasta que no encuentre antecesor
      aux = aux - cont;
    }
    if (vec[i] != aux)
    {
      cout << "\n";
    }
    i++;
    n--;

    //cout << "--------------" << endl;
  }
  return 0;
}