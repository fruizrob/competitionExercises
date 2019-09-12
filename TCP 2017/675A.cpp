#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(c == 0){
        if(a == b){
            cout << "YES";
        } else {
            cout << "NO";
        }
    }else {
        if(c > 0){
            if(b < a) {
                cout << "NO";
            } else if (b == a) {
                cout << "YES";
            } else {
                while (b > a) {
                    a += c;
                    if(a == b){
                        cout << "YES";
                        break;
                    }
                }
                if(b < a) {
                    cout << "NO";
                }
            }
        } else {
            if(b > a) {
                cout << "NO";
            } else if (b == a) {
                cout << "YES";
            } else {
                while (b < a) {
                    a += c;
                    if(a == b){
                        cout << "YES";
                        break;
                    }
                }
                if(b > a) {
                    cout << "NO";
                }
            }
        }
    }

    return 0;
}