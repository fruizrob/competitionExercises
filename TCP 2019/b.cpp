#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x(n), y(n), r(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    bool flag = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                float dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                float sum_radius = r[i] + r[j];

                if(dist <= sum_radius && dist+ min(r[i],r[j]) > max(r[i],r[j])) {
                    flag = false;
                }
            }
        }
    }

    if(flag) cout << "SI" << endl;
    else cout << "NO" << endl;

    return 0;
}