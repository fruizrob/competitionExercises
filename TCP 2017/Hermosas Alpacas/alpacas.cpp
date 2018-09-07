//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       15/08/2017        //
//-------------------------//

#include <iostream>
#include <string>

using namespace std;

int main () {
  long long n, m, d;
  string gen = "A";
  string aux = "";
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for (int j = 0; j < gen.size(); j++) {
      if(gen[j] == 'A'){
        aux.append("AL");
      }
      else if(gen[j] == 'L'){
        aux.append("PACA");
      }
      else if(gen[j] == 'P'){
        aux.append("CP");
      }
      else if(gen[j] == 'C'){
        aux.append("PC");
      }
    }
    gen = aux;
    aux = "";
  }
  for (int i = 0; i < gen.size(); i++){
    if(gen.substr(i,6) == "ALPACA"){
      d += 1;
    }
  }
  cout << d%m;
  return 0;
}
