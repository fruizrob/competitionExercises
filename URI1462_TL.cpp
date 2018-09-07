#include <bits/stdc++.h>

using namespace std;

bool desc(int i, int j) { return (i > j); }

int main(){
  int N;
  while (scanf("%d", &N) != EOF){
    vector<int> vec;
    for (int i = 0; i < N; i++){
      int x;
      cin >> x;
      vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), desc);

    vec.push_back(-1);
    bool possivel = true;
    for (int i = 0; i < N; i++){
      if (possivel){
        int x = vec[i];
        int j = i;
        while (x > 0){
          if (vec[j + 1] > 0){
            vec[j + 1] = vec[j + 1] - 1;
            x--;
            j++;
          }
          else if (vec[j + 1] == 0){
            j++;
          }
          else if (vec[j + 1] < 0){
            possivel = false;
            break;
          }
        }
      }
      else{
        break;
      }
    }
    if (possivel){
      cout << "possivel\n";
    }
    else{
      cout << "impossivel\n";
    }
  }
  return 0;
}