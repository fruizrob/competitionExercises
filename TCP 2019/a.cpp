#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
    	if(i==str.length()-1){
    		cout << "ic";
    		cout << str[str.length()-1] << endl;
    	}else{
    		cout << str[i];
    	}
    }

    return 0;
}