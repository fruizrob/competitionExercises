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
  a = x/(z-y);
  while (a > 0){
    cont += 2;
    a = a/10;
  }
  float b = z-(y+cont);
  pag = ceil(x / b);
  cout << pag;
  return 0;
}
