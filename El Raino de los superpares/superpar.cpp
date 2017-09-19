//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       17/08/2017        //
//-------------------------//

#include <iostream>

using namespace std;

int main() {
  long long n, y, x = 0;
  cin >> n;
  if (n%2 == 0) {
    while (n > 0){
      y = n % 10;
      x += y;
      n = n/10;
    }
    if (x%2 == 0) {
      cout << "superpar";
    }
    else{
      cout << "no";
    }
  }
  else {
    cout << "no";
  }
  return 0;
}
