//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       14/08/2017        //
//-------------------------//

#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  getline(cin, S);
  float prom = 0, suma = 0, num = 0;
  for (int i = 0; i < S.length(); i++){
    if (S[i] != '1'){
      suma += (int)S[i] - 48;
      num++;
    }
    else {
      if (S[i+1] != '0'){
        suma += (int)S[i] - 48;
        num++;
      }
      else {
        suma += 10;
        num++;
        i++;
      }
    }
  }
  cout.precision(2);
  prom = suma/num;
  cout << fixed << prom << endl;
}
