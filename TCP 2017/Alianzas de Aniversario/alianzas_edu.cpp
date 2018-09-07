#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct dato{
	int costo;
	int valor;
	
	double propor;
	
	bool operator < (const dato &tmp) const { return propor < tmp.propor; }
	
} dato;

int maxi = 0;
int total = 0;



void recursion(vector<dato> lista, int pre, int N, int cont, int peso){
	if (cont > pre){
		return;
	}
	
	if (maxi <= cont && total < peso){
		maxi = cont;
		total = peso;
	}
		//cout << " c:" << cont << " p:" << peso << endl;
	
	
	for (int i = 0;i<N;i++){
		if (cont + lista[i].costo <= pre){
			recursion(lista, pre, N, cont+lista[i].costo, peso+lista[i].valor);
			
		}
	}
	
	
}

int main(){
	
	int pre = 0;
	cin >> pre;
	
	int N = 0;
	cin >> N;
	
	vector<dato> x (N);
	
	for (int i=0;i<N;i++){
		cin >> x[i].costo;
	}
	
	for (int i=0;i<N;i++){
		cin >> x[i].valor;
		x[i].propor = (double)x[i].valor / (double)x[i].costo;
	}

	sort(x.rbegin(), x.rend());
	
	for(int i = 0; i< N;i++){
		cout << x[i].propor << " ";
	}
	
	recursion(x, pre, N, 0, 0);
	
	cout << total << " " << maxi;

}