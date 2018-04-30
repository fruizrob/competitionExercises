#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> num;
map<int, int> cantidad;

int main()
{
    int n;
    
    while (scanf("%d", &n) != EOF)
    {
        if (cantidad.count(n) == 0)
        {
            cantidad[n] = 1;
            num.push_back(n);
        }
        else
            cantidad[n] = cantidad[n] + 1;
    }

    for (int i = 0; i < (int)num.size(); i++){
        cout << num[i] << " " << cantidad[num[i]] << endl;
    }

    return 0;
}