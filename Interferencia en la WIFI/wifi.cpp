//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       17/08/2017        //
//-------------------------//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
  int N, Q;
  vector<int> p, r, q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    int aux1, aux2;
    cin >> aux1 >> aux2;
    p.push_back(aux1);
    r.push_back(aux2);
  }

  for (int i = 0; i < Q; i++) {
    int aux;
    cin >> aux;
    q.push_back(aux);
  }

  for (int i = 0; i < Q; i++){
    int index = q[i] - 1; // index = indice para encontrar en el arreglo p el enrutador a consultar.
    int cont = -1; // incia en -1 porque el enrutador se contiene a si mismo lo que no deberia sumar.
    for (int j = 0; j < N; j++){
      int aux = abs(p[index]-p[j])+r[j]; 
      if(aux <= r[index]){
        cont++;
      }
    }
    cout << cont << endl;
  }
  return 0;
}
