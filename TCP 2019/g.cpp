#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    long long x; cin >> x;
    n -= 1;
    int m = n;

    vector<long long> vec;
    while(n--) {
        long long aux; cin >> aux;
        vec.push_back(aux);  
    }

    sort(vec.begin(), vec.begin()+m);

    long long total = 0;
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        sum += vec[i]-1 + total;
        total += vec[i];
    }

    if(x > sum) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}