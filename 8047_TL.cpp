#include <bits/stdc++.h>

using namespace std;
int graph[26][26] = {0};

void DFS_Visitar(int a, vector<int> visitado, vector<int> &aux);

void DFS(int a, vector<int> &aux){
    vector<int> visitado;
    int j = 0;
    for(int i = 0; i < 26; i++){
        visitado.push_back(0);
    } // SIMPLIFICAR
    DFS_Visitar(a, visitado, aux);
}   

void DFS_Visitar(int a, vector<int> visitado, vector<int> &aux){
    visitado[a] = 1;
    for(int i=0; i < 26; i++){
        if(graph[a][i] == 1 && visitado[i] == 0){
            aux.push_back(i);
            DFS_Visitar(i, visitado, aux);
        }
    }
}

bool compare(int x, int y){
    if (x == y)
        return true;
    else{
        vector<int> aux;
        DFS(x, aux);
        for (int i = 0; i < aux.size(); i++){
            if (y == aux[i])
                return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    while (n--){
        char a[2], b[2];
        cin >> a >> b;
        int x = int(a[0] - 'a');
        int y = int(b[0] - 'a');
        graph[x][y] = 1;   
    }
    while(m--){
        string word_1, word_2;
        cin >> word_1 >> word_2;
        if(word_1.length() != word_2.length())
            cout << "no" << endl;
        else{
            bool found = true;
            for(int i = 0; i < word_1.length(); i++){

                int x = int(word_1[i] - 'a');
                int y = int(word_2[i] - 'a');

                if(!compare(x, y)){
                    found = false;
                    break;
                }
                
            }
            printf(found ? "yes\n" : "no\n");
        }
    }
    return 0;
}