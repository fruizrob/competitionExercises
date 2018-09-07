#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#define f(i,x,y) for(int i= x; i<y; ++i)

using namespace std;
vector<int> pos;
vector<int> prefix(string &S) {
  vector<int> p(S.size()); p[0] = 0;
  for(int i = 1;i < S.size();++i)
  {
    p[i] = p[i-1];
    while(p[i]>0 && S[p[i]]!=S[i]) p[i] = p[p[i]-1];
    if(S[p[i]]==S[i]) p[i]++;
  }
  return p;
}

int KMP(string &P, vector<int> &pi, string &S)
{
  int n = S.length(), m = P.length();
  int j = 0, ans = 0;
  for(int i = 0; i < n; ++i)
  {
    while(j > 0 && S[i] != P[j]) j = pi[j-1];
    if(S[i] == P[j]) ++j;

    if(j == P.length())
    {
      cout << (i-P.length()+1) << '\n';
      ++ans;
      j = pi[j-1];
    }
  }

  return ans;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string texto;
	string patron;
	int casos = 0;
	while(cin >> n) {
		pos.clear();
		cin >> patron;
		cin >> texto;	
		if(patron.size() > texto.size()) {
			cout << '\n';
			continue;
		}
		vector<int> pf = prefix(patron);
		int c = KMP(patron, pf, texto);
		//cout << c << endl;
		//sort(pos.begin(), pos.end());
		/*for(int i=0; i<pos.size(); i++) {
			cout << pos[i] << '\n';
		}*/
	}
	
	return 0;
}