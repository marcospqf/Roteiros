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
int n, m;
vector<int> usados;
vector<vector<int> > g;
vector<int> v;
vector<int> parid;
vector<int> resp;
void dfs(int atual, int pai)
{
  usados[atual] = 1;
  resp.push_back(atual);
  parid[atual]++;
  for (int i = 0; i < g[atual].size(); i++) {
    int x = g[atual][i];
    if (!usados[x]) {
      dfs(x, atual);
      resp.push_back(atual);
      parid[atual]++;
    }
  }
  if (parid[atual] % 2 != v[atual]) {
    if (pai != -1) {
      resp.push_back(pai);
      parid[pai]++;
      resp.push_back(atual);
      parid[atual]++;
    }
    else resp.pop_back();
  }
}
int main()
{
  cin >> n >> m;
  g.resize(n), usados.resize(n, 0), v.resize(n), parid.resize(n, 0);
  ;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int inicio = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 1 and inicio == -1) inicio = i;
  }
  if (inicio != -1) {
    dfs(inicio, -1);
    for (int i = 0; i < n; i++)
      if (usados[i] == 0 and v[i] == 1) {
        cout << "-1" << endl;
        return 0;
      }
    cout << resp.size() << endl;
    for (int i = 0; i < resp.size(); i++) cout << resp[i] + 1 << " ";
    cout << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}
