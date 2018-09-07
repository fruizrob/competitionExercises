#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

//Maximo Comun Divisor
int mcd(int x, int y){
  int mcd = 0;
  int a = max(x,y);
  int b = min(x,y);
  do {
    mcd = b;
    b = a%b;
    a = mcd;
  } while (b!=0);
  return mcd;
}

//Minimo Comun Multiplo
int mcm(int x, int y){
  int mcm = 0;
  int a = max(x,y);
  int b = min(x,y);
  mcm = (a/mcd(a,b))*b;
  return mcm;
}

int main(){
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll ab = b-a;
  ll cont = 0;
  int aux = mcm(x,y);
  cout << (b/aux) - ((a-1)/aux) << endl;
}