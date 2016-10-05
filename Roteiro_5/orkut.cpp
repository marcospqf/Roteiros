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
vector<int> top_sort(vector<vector<int> >& g)
{
  vector<int> resp;
  vector<int> indegree(g.size());
  queue<int> filona;
  for (int i = 0; i < g.size(); i++) {
    if (g[i].size() == 0) filona.push(i);
    indegree[i] = g[i].size();
  }
  while (!filona.empty()) {
    int at = filona.front();
    resp.push_back(at);
    filona.pop();
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[i].size(); j++)
        if (g[i][j] == at) {
          indegree[i]--;
          if (indegree[i] == 0) 
            filona.push(i);
        }
  }
  return resp;
}

int main()
{
  int t = 1;
  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    vector<vector<int> > v(n);
    map<string, int> m;
    map<int, string> m2;
    int ocor = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      m[s] = ocor;
      m2[ocor] = s;
      ocor++;
    }
    for (int i = 0; i < n; i++) {
      int a;
      string s;
      cin >> s >> a;
      int dep = m.find(s)->second;
      for (int j = 0; j < a; j++) {
        string x;
        cin >> x;
        int sec = m.find(x)->second;
        v[dep].push_back(sec);
      }
    }
    vector<int> resp = top_sort(v);
    cout << "Teste " << t << endl;
    t++;
    if (resp.size() <n)
      cout << "impossivel" << endl;
    else {
      for (int i = 0; i < resp.size(); i++)
        cout << m2.find(resp[i])->second << " ";
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
