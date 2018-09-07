#include <bits/stdc++.h>

using namespace std;

map<int, int>::iterator it;

int main(){
  int n, m, s;
  cin >> n >> m >> s;
  map<int> AdjList(M);
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    AdjList[u].push_back(v);
  }

  

  return 0;
}