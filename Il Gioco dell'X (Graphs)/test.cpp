#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> board;
int visited[201][201];
int aux_i[] = {-1, -1, 0, 0, 1, 1};
int aux_j[] = {-1, 0, -1, 1, 0, 1};

bool dfsBlack(int x, int y, bool &win){
    int I, J;

    for (int i = 0; i < 6; i++){
        I = x + aux_i[i];
        J = y + aux_j[i];
        if (I >= 0 && I < n && J >= 0 && J < n && !visited[I][J]){

            if (board[I][J] == 'b'){
                visited[I][J] = 1;
                if (I == n - 1)
                    win = true;
                dfsBlack(I, J, win);
            }
        }
    }
    if (win){
        return true;
    }else {
        return false;
    }
}

int main(){
    string s;
    int cont = 1;
    while (scanf("%d", &n)){
        if (!n)
            break;

        bool win = false;
        board.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            board.push_back(s);
        }
        for(int j=0; j<n; j++){
            int i = 0;
            if(!visited[i][j]){
                visited[i][j] = 1;
                if (board[i][j] == 'b' && i == 0)
                {
                    if (dfsBlack(i, j, win)){
                        cout << cont << " " << "B" << endl;
                        cont++;
                        break;
                    }
                } 
            }
        }
        if(!win){
            cout << cont << " " << "W" << endl;
            cont++;
        }
    }
    return 0;
}