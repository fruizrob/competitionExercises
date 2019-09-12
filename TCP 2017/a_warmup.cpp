//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       15/08/2017        //
//-------------------------//

#include <iostream>
#include <vector>

using namespace std;


int main(){
  int n, p;
  vector<int> costo;
  vector<int> puntaje;

  cin >> p; // Entrada
  cin >> n;
  for (int i = 0; i < n; i++){
    int aux;
    cin >> aux;
    costo.push_back(aux);
  }
  for (int i = 0; i < n; i++){
    int aux;
    cin >> aux;
    puntaje.push_back(aux);
  }

  vector<int> relacion; // Puntaje c/u 1 producto de cada alimento
  for (int i = 0; i < n; i++){
    int aux;
    aux = puntaje[i]/costo[i];
    relacion.push_back(aux);
  }

  for (int i = 0; i < relacion.size(); i++){ //Ordenamiento: mayor a menor
    int mayor = relacion[i];
    int mayorIndex = i;
    for (int m = i; m < relacion.size(); m++){
      if (relacion[m] > relacion[i]){
        mayor = relacion[m];
        mayorIndex = m;
      }
    }
    swap(relacion[i], relacion[mayorIndex]);
    swap(costo[i], costo[mayorIndex]);
    swap(puntaje[i], puntaje[mayorIndex]);
  }

  int puntajeT = 0;
  int costoT = 0;
  for (int i = 0; i < n; i++) { // Contador de puntaje y costo total de la mejor mezcla
    while (p >= costo[i]){
      p -= costo [i];
      puntajeT += puntaje[i];
      costoT += costo[i];
    }
  }

  cout << puntajeT << " " << costoT;

  return 0;
}
