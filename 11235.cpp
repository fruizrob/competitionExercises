#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct SegmentTree
{
  vector<int> ST;
  int N;

  SegmentTree(vector<int> &A){
    N = A.size();

    ST.resize(4 * N);

    build(1, 0, N - 1, A);
  }

  void build(int n, int l, int r, vector<int> &A){
    if (l == r){
      ST[n] = A[r];
      return;
    }

    build(2 * n, l, (l + r) / 2, A);
    build(2 * n + 1, (l + r) / 2 + 1, r, A);

    ST[n] = min(ST[2 * n], ST[2 * n + 1]);
  }

  int query(int i, int j)
  {
    return query(1, 0, N - 1, i, j);
  }

  int query(int n, int l, int r, int i, int j){
    if (r < i || j < l)
      return inf;

    if (i <= l && r <= j)
      return ST[n];

    return min(query(2 * n, l, (l + r) / 2, i, j),
               query(2 * n + 1, (l + r) / 2 + 1, r, i, j));
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while(cin >> n && n != 0){
    vector<int> vec(n), freq(n);
    cin >> m;
    for(int i=0; i<n; i++){
      cin >> vec[i];
    }

    SegmentTree ST(vec);
    while(m--){
      int i, j;
      cin >> i >> j;
    }
  }
  return 0;
}