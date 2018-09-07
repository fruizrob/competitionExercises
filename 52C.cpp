#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
struct SegmentTree{
  vector<int> ST, L;
  int N;

  SegmentTree(vector<int> &A){
    N = A.size();

    // Recordar 4*N
    ST.resize(4 * N);
    L.resize(4 * N, 0);

    build(1, 0, N - 1, A);
  }

  void build(int n, int l, int r, vector<int> &A){
    // Chequeo si es hoja
    if (l == r){
      ST[n] = A[r];
      return;
    }
    // Construyo los hijos
    build(2 * n, l, (l + r) / 2, A);
    build(2 * n + 1, (l + r) / 2 + 1, r, A);
    // Computo los valores
    ST[n] = min(ST[2 * n], ST[2 * n + 1]);
  }

  int query(int i, int j){
    return query(1, 0, N - 1, i, j);
  }
  // Computa la query(i,j) para el nodo n
  int query(int n, int l, int r, int i, int j){
    // Si hay que actualizar el nodo
    if (L[n] != 0){
      // Actualizo el valor
      ST[n] += L[n];
      // Si no es hoja, marco a los hijos
      if (l != r){
        L[2 * n] += L[n];
        L[2 * n + 1] += L[n];
      }
      // Desmarco al nodo
      L[n] = 0;
    }
    // Caso 1: No chocan
    if (r < i || j < l)
      return inf;
    // Caso 2: Contenido totalmente
    if (i <= l && r <= j)
      return ST[n];
    // Caso 3: Ninguno de los anteriores
    // Le paso la query a los hijos
    return min(query(2 * n, l, (l + r) / 2, i, j),
               query(2 * n + 1, (l + r) / 2 + 1, r, i, j));
  }

  // Setea A[i,j] = v
  void update(int i, int j, int v){
    return update(1, 0, N - 1, i, j, v);
  }

  void update(int n, int l, int r, int i, int j, int v){
    // Si hay que actualizar el nodo
    if (L[n] != 0){
      // Actualizo el valor
      ST[n] += L[n];
      // Si no es hoja, marco a los hijos
      if (l != r){
        L[2 * n] += L[n];
        L[2 * n + 1] += L[n];
      }
      // Desmarco al nodo
      L[n] = 0;
    }
    // Caso 1: No chocan
    if (j < l || r < i)
      return;
    // Caso 2: Contenido totalmente
    if (i <= l && r <= j){
      // Actualizo el valor
      ST[n] += v;
      // Si no es hoja, marco a los hijos
      if (l != r){
        L[2 * n] += v;
        L[2 * n + 1] += v;
      }
      // Desmarco al nodo
      L[n] = 0;
      return;
    }
    // Caso 3: Ninguno de los anteriores
    // Actualizar a los hijos
    update(2 * n, l, (l + r) / 2, i, j, v);
    update(2 * n + 1, (l + r) / 2 + 1, r, i, j, v);
    // Recomputo los valores
    ST[n] = min(ST[2 * n], ST[2 * n + 1]);
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec[i];
  }
  SegmentTree ST(vec);
  int M, num;
  cin >> M;
  cin.ignore();
  
  for (int i = 0; i < M; i++){
    string str;
    int resp;
    vector<int> aux;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> num ){
      aux.push_back(num);
    }
    if(aux.size() == 0) continue;

    if(aux.size() == 3){
      if (aux[0] > aux[1]){
        ST.update(aux[0], N - 1, aux[2]); 
        ST.update(0, aux[1], aux[2]);
      }
      else
        ST.update(aux[0], aux[1], aux[2]);
    }
    else if(aux.size() == 2){
      if(aux[0] > aux[1])
        resp = min(ST.query(aux[0], N-1),ST.query(0, aux[1]));
      else
        resp = ST.query(aux[0], aux[1]);
      cout << resp << endl;
    }
  }
  return 0;
}