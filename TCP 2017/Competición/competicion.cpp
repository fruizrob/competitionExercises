//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       14/08/2017        //
//-------------------------//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> N;
  vector<int> A;
  vector<int> B;
  int Acambios = 0, Bcambios = 0;
  int turno = 0;

  for (int i = 0; i < 3; i++){
    int x = 0;
    cin >> x;
    N.push_back(x);
  }
  for (int i = 0; i < N[1]; i++){
    int x = 0;
    cin >> x;
    A.push_back(x);
  }
  for (int i = 0; i < N[2]; i++){
    int x = 0;
    cin >> x;
    B.push_back(x);
  }

  for (int i = 0; i < A.size(); i++){ //Ordenamiento: menor a mayor de A
    int menor = A[i];
    int menorIndex = i;
    for (int m = i; m < A.size(); m++){
      if (A[m] < A[i]){
        menor = A[m];
        menorIndex = m;
      }
    }
    swap(A[i], A[menorIndex]);
  }
  for (int i = 0; i < B.size(); i++){ //Ordenamiento: menor a mayor de B
    int menor = B[i];
    int menorIndex = i;
    for (int m = i; m < B.size(); m++){
      if (B[m] < B[i]){
        menor = B[m];
        menorIndex = m;
      }
    }
    swap(B[i], B[menorIndex]);
  }
  int j = 0;
  int k = 0;
  for (int i = 0; i < N[0]; i++){
    // cout << "i : " << i << ", A : " << A[j] << ", B : " << B[k] << ", turno : " << turno;
    if (turno == 0){ // PRIMERO TURNO
      if ((i+1) == A[j]){
        if (A[j] == B[k])
        {
          k++;
        }
        j++;
        turno = 1;
      }
      else if ((i+1) == B[k]){
        if (B[k] == A[j])
        {
          j++;
        }
        k++;
        turno = 2;
      }
    }
    else if (turno == 1){    // ALICE EN EL PC
      if (A[j] == B[k])
      {
        k++;
      }
      if ((i+1) == A[j]){
        j++;
      }
      else if ((i+1) == B[k]){
        Acambios += 1;
        k++;
        turno = 2;
      }
    }
    else if (turno == 2){    // BOB EN EL PC
      if (B[k] == A[j])
      {
        j++;
      }
      if ((i+1) == B[k]){
        k++;
      }
      else if ((i+1) == A[j]){
        Acambios += 1;
        j++;
        turno = 1;
      }
    }
    // cout << "Acambios" << Acambios << endl;
  }
  j = 0;
  k = 0;
  for (int i = 0; i < N[0]; i++){
    // cout << "i : " << i << ", A : " << A[j] << ", B : " << B[k] << ", turno : " << turno;
    if (turno == 0){ // PRIMERO TURNO
      if ((i+1) == B[k]){
        if (B[k] == A[j])
        {
          j++;
        }
        k++;
        turno = 2;
      }
      else if ((i+1) == A[j]){
        if (A[j] == B[k])
        {
          k++;
        }
        j++;
        turno = 1;
      }

    }
    else if (turno == 1){    // ALICE EN EL PC
      if (A[j] == B[k])
      {
        k++;
      }
      if ((i+1) == A[j]){
        j++;
      }
      else if ((i+1) == B[k]){
        Bcambios += 1;
        k++;
        turno = 2;
      }
    }
    else if (turno == 2){    // BOB EN EL PC
      if (B[k] == A[j])
      {
        j++;
      }
      if ((i+1) == B[k]){
        k++;
      }
      else if ((i+1) == A[j]){
        Bcambios += 1;
        j++;
        turno = 1;
      }
    }
    // cout << "Bcambios" << Bcambios << endl;
  }
  if (Acambios == Bcambios){
    cout << Acambios;
  }
  else if (Acambios > Bcambios){
    cout << Bcambios;
  }
  else {
    cout << Acambios;
  }
}
