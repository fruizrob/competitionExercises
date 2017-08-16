//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       16/08/2017        //
//-------------------------//

#include <iostream>

using namespace std;

int main(){

  unsigned n, m, martina = 0, benjamin = 0, z = 0, x = 0, y = 0;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> m;
    for (int j = 0; j < m; j++){
      int aux;
      cin >> aux;
      if(aux == 0){
        martina++;
      }
      else if(aux == 1){
        benjamin++;
      }
    }
    if (martina > benjamin){
      x++;
    }
    else if (martina < benjamin){
      y++;
    }
    else {
      z++;
    }
    martina = 0;
    benjamin = 0;
  }
  cout << x << " " << y << " " << z;
  return 0;
}
