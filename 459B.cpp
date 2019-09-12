#include <bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    int min = 1e9 + 100, max = 0; 
    long long count_max = 0, count_min = 0;
    while(n--){
        int x;
        cin >> x;

        if(max < x) { max = x; count_max = 1; }
        else if(max == x) { count_max++; }
        if(min > x)  { min = x; count_min = 1; }
        else if(min == x) { count_min++; }
    }
    if(max == min){
        cout << max - min << " " << (count_max * (count_min - 1))/2;
    } else {
        cout << max - min << " " << (count_max * count_min);
    }

    return 0;
}