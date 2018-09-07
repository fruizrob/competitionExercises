#include <bits/stdc++.h>

using namespace std;

int main()
{
    string p;
    map<string, int> arbol;
    float total = 0;
    while (getline(cin, p)){
        if (p == "") 
            break;
        total++;
        arbol[p]++;
    }
    for (map<string, int>::iterator i = arbol.begin(); i != arbol.end(); i++){
        cout.precision(4);
        cout << i->first << " " << fixed << i->second * 100.0 / total << endl;
    }
    return 0;
}

