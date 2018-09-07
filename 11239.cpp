#include <bits/stdc++.h>
#include <algorithm>
#include <ctype.h> // isupper()  //  islower()  //  toupper()  //  tolower()

using namespace std;

map<string, vector<string> > project;
map<string, vector<string> >::iterator it;
vector<string> p;
vector<int> n;

string Busqueda(string s, int &pos, string i){
    for (it = project.begin(); it != project.end(); ++it){
        string key = it->first;
        vector <string> u = it->second;
        for(int i = 0; i < u.size(); i++){
            if(u[i] == s){
                pos = i;
                return key;
            }
        }
    }
    return i;
}

void porCasoPrueba(){
    
    for (it = project.begin(); it != project.end(); it++){
        string s = it->first;
        vector<string> u = it->second;

        p.push_back(s);
        n.push_back(u.size());
    }

    for (int i = 0; i < p.size(); i++){
        for (int j = i; j < p.size(); j++){
            if (n[i] < n[j]){
                swap(n[i], n[j]);
                swap(p[i], p[j]);
            }
            if(n[i] == n[j]){
                if(p[i] > p[j]){
                    swap(n[i], n[j]);
                    swap(p[i], p[j]);
                }
            }
        }
        cout << p[i] << " " << n[i] << endl;
    }
    cout << endl;
    cout << endl;
}

int main(){
    string s;
    string i;
    vector <string> u_global; // TODOS LOS USUARIOS

    while (getline(cin, s)){
        if(s == "1"){
            porCasoPrueba();
            p.clear();
            n.clear();
            project.clear();
            u_global.clear();
        }

        if(s == "0"){
            return 0;
        } 
        
        if(isupper(s[0])){
            i = s;
            project[i];
        } 

        if(islower(s[0])){
            if (find(u_global.begin(), u_global.end(), s) != u_global.end()){
                int pos;
                string key = Busqueda(s, pos, i);

                if (i != key){
                    project[key].erase(project[key].begin() + pos);
                } 
            } else {
                u_global.push_back(s);
                project[i].push_back(s);
            }
        }
    }
    return 0;
}
