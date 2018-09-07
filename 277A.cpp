#include <bits/stdc++.h>

using namespace std;

void dfs(map<int, vector<int> >&g , int n, vector<bool> &visited){
  visited[n] = true;
  for(int i =0; i < g[n].size(); i++){
    int hijo = g[n][i];
    if(!visited[hijo]){
      visited[hijo] = true;
      dfs(g,hijo,visited);
    }
  }
}


int main(){
  int n, m, k, x;
  cin >> n >> m;
  vector<vector<int> > g(m);
  map<int, vector<int> > grafo;
  bool dist = false;

  for(int i=0; i<n; i++){
    cin >> k; 
    if(k!=0){
      dist = true;
    }
    while(k--){
      cin >> x;
      g[x-1].push_back(i);
    }
  }

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g[i].size(); j++){
      
      
      if (j + 1 == g[i].size()){
        break;
      }

      int n1 = g[i][j];
      int n2 = g[i][j + 1];
      grafo[n1].push_back(n2);
      grafo[n2].push_back(n1);
    }
  }

  int cont = 0;
  vector<bool> visited(n, false);
  for(int i=0; i<n; i++){
      if(!visited[i]){
        visited[i] = true;
        dfs(grafo, i, visited);
        cont++;
      }
  }
  if(dist){
    cout << cont - 1 << endl;
  } else{
    cout << cont << endl;
  }
  return 0;
}