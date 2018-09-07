//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       12/08/2017        //
//-------------------------//

#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> A;
  vector<int> B;
  int aux, golpe = 0;

  for (int i = 0; i < 3; i++) {
    cin >> aux;
    A.push_back (aux);
  }
  for (int i = 0; i < A[2]; i++) {
    cin >> aux;
    B.push_back (aux);
  }

  for (int i = 0; i < A[2]; i++) {
    if ( B[i] >= A[0] && B[i] <= A[1] ) {
      golpe++;
    }
  }

  cout << golpe;

  return 0;
}
