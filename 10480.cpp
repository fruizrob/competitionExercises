// Sabotage
#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int> > rGraph, int s, int t, int parent[])
{
  bool visited[rGraph.size()];
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty()){
    int u = q.front();
    q.pop();

    for (int v = 0; v < rGraph.size(); v++){
      if (visited[v] == false && rGraph[u][v] > 0){
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return (visited[t] == true);
}

void dfs(vector<vector<int> > rGraph, int s, bool visited[])
{
  visited[s] = true;
  for (int i = 0; i < rGraph.size(); i++)
    if (rGraph[s][i] && !visited[i])
      dfs(rGraph, i, visited);
}

void minCut(vector<vector<int> > graph, int s, int t, int V)
{
  int u, v;

  vector<vector<int> > rGraph(V, vector<int>(V, 0));
  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      rGraph[u][v] = graph[u][v];

  int parent[V];

  while (bfs(rGraph, s, t, parent))
  {
    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }
  }
  bool visited[V];
  memset(visited, false, sizeof(visited));
  dfs(rGraph, s, visited);

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      if (visited[i] && !visited[j] && graph[i][j])
        cout << i+1 << " " << j+1 << endl;

  return;
}

int main(){
  int n, m;
  while (scanf("%d %d", &n, &m) && n != 0 && m != 0){

    vector<vector<int> > g(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
      int x, y, w;
      cin >> x >> y >> w;
      g[x-1][y-1] = w;
      g[y-1][x-1] = w;
    }
    minCut(g, 0, 1, n);
    cout << endl;
  }
  return 0;
}