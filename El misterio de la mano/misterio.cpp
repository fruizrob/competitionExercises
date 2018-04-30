//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       17/08/2017        //
//-------------------------//

#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int x, y, z, a, pag, cont = 1;
  cin >> x >> y >> z;

  // Aproximación al numero
  a = x/(z-y);

  // Encontrar la cantidad de caracteres a utilizar en la paginación
  while (a > 0){
    cont += 2;
    a = a/10;
  }

  // Encuentra el valor real por pagina
  float b = z-(y+cont);

  // Calcula la cantidad de paginas
  pag = ceil(x / b);
  cout << pag;
  return 0;
}
