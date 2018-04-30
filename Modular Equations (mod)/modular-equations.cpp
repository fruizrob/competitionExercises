#include <iostream>
#include <vector>
#include <algorithm>

// TIME LIMIT

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int cont = 0;
        int a_min, a_max, b_min, b_max, m_min, m_max;
        cin >> a_min >> a_max >> b_min >> b_max >> m_min >> m_max;

        for(int i = a_min; i <= a_max; i++){
            for(int j = b_min; j <= b_max; j++){
                for(int k = m_min; k <= m_max; k++){
                    int x = i+j;
                    int y = i-j;
                    while(x < k){
                        x += k;
                    }
                    while(y < k){
                        y += k;
                    }
                    if( x%k == y%k ){
                        cont++;
                        cout << "a=" << i << "  b=" << j << "  m=" << k << " ====>    (a+b)% m = " << x % k << "    //   (a-b)% m = " << y % k << endl << endl;
                    }
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}

// for (int i = a_min; i <= a_max; i++)
// {
//     for (int j = b_min; j <= b_max; j++)
//     {
//         for (int k = m_min; k <= m_max; k++)
//         {

//             int x = i + j;
//             int y = i - j;
//             while (x < k)
//             {
//                 x += k;
//             }
//             while (y < k)
//             {
//                 y += k;
//             }
//             cout << "a=" << i << "  b=" << j << "  m=" << k << " ====>    (a+b)% m = " << x % k << "    //   (a-b)% m = " << y % k << endl;
//             if (x % k == y % k)
//             {
//                 cont++;
//             }
//         }
//     }
// }