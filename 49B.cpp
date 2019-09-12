#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y; cin >> x >> y;
    int a = x, b = y;
    int base = 0;

    while(a) {
        base = max(base, a%10);
        a = a/10;
    }
    while(b) {
        base = max(base, b%10);
        b = b/10;
    }

    base++;
    int len = 0, carry = 0;
    while(x || y) {
        int ans = x%10 + y%10 + carry;
        carry = ans / base;
        y /= 10;
        x /= 10;
        len++;
    }
    if(carry){
        len++;
    }

    cout << len;
    return 0;
}