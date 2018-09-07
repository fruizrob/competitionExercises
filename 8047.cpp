#include <bits/stdc++.h>

using namespace std;

int m, n, j;
map<char, vector<char> > map_test;
int visitado[26];

bool DFS(char a, char b, bool &find){
    j = int(a - 'a');
    visitado[j] = 1;
    if (a == b){
        find = true;
    }
    else{
        vector<char> vecinos = map_test[a];
        for (int i = 0; i < vecinos.size(); i++){
            if (b == vecinos[i]){
                find = true;
            }
            else{
                int k = int(vecinos[i] - 'a');
                if (!visitado[k])
                    DFS(vecinos[i], b, find);
            }
        }
    }
    if (find)
        return true;
    else{
        return false;
    }
}

int main()
{
    cin >> m >> n;
    while (m--){
        char a, b;
        cin >> a >> b;
        map_test[a].push_back(b);
    }
    while (n--){
        string word_1, word_2;
        cin >> word_1 >> word_2;
        if (word_1.length() != word_2.length())
            cout << "no" << endl;
        else{
            bool found = true;
            for (int i = 0; i < word_1.length(); i++){
                for (int i = 0; i < 26; i++)
                    visitado[i] = 0;
                char x = word_1[i];
                char y = word_2[i];
                j = int(word_1[i] - 'a');
                if (!visitado[j]){
                    visitado[j] = 1;
                    bool find = false;
                    if (!DFS(x, y, find)){
                        found = false;
                        break;
                    }
                }
            }
            printf(found ? "yes\n" : "no\n");
        }
    }
    return 0;
}