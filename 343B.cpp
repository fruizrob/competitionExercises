#include <bits/stdc++.h>
using namespace std;

int main(){


	string x;
	cin >> x;

	stack<char> pila;
	if (x.size() % 2 == 0)
		for(int i = 0; i<x.size();++i){
			//char top = pila.top();
			if (!pila.empty() && pila.top() == x[i]){
				//cout << "entro1";
				pila.pop();
			} else {
				//cout << "entro2";
				pila.push(x[i]);
			}
		}

	if (pila.size() != 0 || x.size() % 2 != 0){
		cout << "No";
	} else {
		cout << "Yes";
	}

}