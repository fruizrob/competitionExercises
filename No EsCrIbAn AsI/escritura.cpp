//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       16/08/2017        //
//-------------------------//

#include <iostream>
#include <string>

using namespace std;

int main(){
  int n, turno=0;
  char c;
  string texto;
  cin >> n;
  getline(cin,texto);
  getline(cin,texto);
  for(int i = 0; i < n; i++){
    int x = texto[i];
    if ((x > 64 && x < 91) or (x > 96 && x<123)){ // 65 - 90 MAYUSCULAS // 97 - 122 minusculas
      if(turno == 0){
        c = texto[i];
        putchar (toupper(c));
        turno = 1;
      }
      else if(turno == 1){
        c = texto[i];
        putchar (tolower(c));
        turno = 0;
      }
    }
    else{
      cout << texto[i];
    }
  }
  return 0;
}
