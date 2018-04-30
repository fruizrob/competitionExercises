#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(){
    string num;
    getline(cin, num);
    cout << endl;
    cout << num;
    vector<int> N;
    vector<int> Cant;

    N[0] =  num[0];
    Cant[0] = 1;
    
    for(int i = 1; i < num.length(); i++){
        int index;
        int x = 0;
        for(int j = 0; j < N.size(); j++){
            if(num[i] == N[i]){
                x = 1;
                Cant[j] += 1;
                index = j;
            }
        }
        if ( x == 0) {
            N[index+1] = num[i];
            Cant[index+1] = 1;
        }
    }

    for(int i = 0; i < N.size(); i++){
        cout << N[i] << " " << Cant[i];
    }
    
    return 0;
}