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
set<int> z;
set<int>::iterator it;
set<int> botoes;
bool pau = false;
void atualiza(vector<vector<int> > &g, vector<int> &v)
{
  it = z.begin();
  int x = *it;
  if (botoes.count(x)) {
    pau = true;
    return;
  }
  botoes.insert(x);
  v[x]--;
  for (int i = 0; i < g[x].size(); i++) {
    if (v[g[x][i]] == 0) z.erase(g[x][i]);
    else if (v[g[x][i]] == 1) z.insert(g[x][i]);
    v[g[x][i]]--;
  }
  z.erase(x);
}
int main()
{
  cin >> n >> m;
  vector<vector<int> > g(n);
  vector<int> v(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[y].push_back(x);
    g[x].push_back(y);
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 0) z.insert(i);
  }
  if (z.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (z.size() > 0 and !pau) atualiza(g, v);
  if (pau)
    cout << -1 << endl;
  else {
    cout << botoes.size() << endl;
    for (it = botoes.begin(); it != botoes.end(); ++it) cout << *it + 1 << " ";
  }
  return 0;
}
