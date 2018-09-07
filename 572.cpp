#include <bits/stdc++.h>

using namespace std;

vector<string> oil;
bool visited[100][100];
int  m, n;
int aux_i[] = {1, 1, 1, 0, -1, -1, -1, 0};
int aux_j[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void busqueda(int x, int y, int &d, int &a){
    visited[x][y] = 1;
    int I, J;

    for(int i=0; i<8; i++){
        I = x+aux_i[i];
        J = y+aux_j[i];
        if (I >= 0 && I < m && J >= 0 && J < n && !visited[I][J]){
            visited[I][J] = 1;
            if (oil[I][J] == '@'){
                busqueda(I, J);
            }
        }

    }
}

int main(){
    string s;
    while(scanf("%d", &m)){
        if (!m)
            break;
        int cont = 0;
        oil.clear();
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for (int i = 0; i < m; i++){
            cin >> s;
            oil.push_back(s);
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j]){
                    visited[i][j] = 1;
                    if (oil[i][j] == '@'){
                        cont++;
                        busqueda(i, j);
                    }
                }
            }
        }

        cout << cont << endl;
    }
    return 0;
}