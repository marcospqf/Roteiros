#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t, n;
  cin >> t;
  map<string, int> mapa;
  map<int, string> mapa2;

  for (int g = 0; g < t; g++) {
    cin >> n;
    string lixo;
    getline(cin,lixo);
    vector<string> v(n);
    for (int i = 0; i < n; i++) getline(cin, v[i]);
    mapa.clear(), mapa2.clear();
    int cont = 1;
    for (int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      if (mapa.count(s) == 0) {
        mapa.insert(make_pair(s, cont));
        mapa2.insert(make_pair(cont, s));
        cont++;
      }
    }
    vector<int> entrada(n);
    for (int i = 0; i < n; i++) entrada[i] = mapa.find(v[i])->second;
    int resp = 0;
    for (int i = 0; i < n; i++) {
      int ocor = 0;
      for (int j = i + 1; j < n; j++) {
        if (entrada[j] > entrada[i]) ocor++;
      }
      if (ocor < n - entrada[i]) resp = max(resp, entrada[i]);
    }
    for (int i = resp; i >= 1; i--) 
    {
      cout << mapa2.find(i)->second << endl;
    }
    cout<<endl;
  }
  return 0;
}
