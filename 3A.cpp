// A. Shortest path of the king CodeForces
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main () {

	string p1;
	string p2;
	cin >> p1;
	cin >> p2;
	int resp = 0;
	vector<string> r;
	cout << max( abs(p1[0] - p2[0]), abs(p1[1]- p2[1])) << "\n";
	while (p1 != p2) {
		bool validadorL = false;
		bool validadorR = false;
		string k = "";
		if( p1[0] > p2[0]) {
			k+="L";
			p1[0]--;
			validadorL = true;
			resp++;
		} else if( p1[0] < p2[0]) {
			k +="R";
			p1[0]++;
			validadorR = true;
			resp++;
		}
		if( p1[1] > p2[1]) {	
			k += "D";
			p1[1]--;
			if(!validadorL) resp++;
			if(!validadorR) resp++;
		} else if(p1[1] < p2[1]) {
			k += "U";
			p1[1]++;
			if(!validadorL) resp++;
			if(!validadorR) resp++;
		}
		r.push_back(k);
	}
	for(int i=0; i<r.size(); i++) {
		cout << r[i] << "\n";
	}
	return 0;
}