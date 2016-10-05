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
#define xablau ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define imprime(v)                     \
  for (int i = 0; i < v.size(); i++) { \
    cout << v[i] << " ";               \
  }
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n, m;
int g[101][101];
int d[101];
set<int> caminho;
void way()
{
  queue<int> f;
  f.push(n - 1);
  while (!f.empty()) {
    int atual = f.front();
    f.pop();
    for (int i = 0; i < n; i++)
      if (g[atual][i] and d[i]+1==d[atual] and caminho.count(i)==0)
        caminho.insert(i), f.push(i);
  }
}
void bfs(vector<ll>& dp, int inicio)
{
  memset(d, -1, sizeof(d));
  queue<int> f;
  f.push(inicio);
  dp[inicio] = 1;
  d[inicio]=0;
  while (!f.empty()) {
    int at = f.front();
    f.pop();
    for (int i = 0; i < n; i++) {
      if (g[at][i] and d[i] == -1) {
        f.push(i);
        d[i] = d[at] + 1;
        dp[i] += dp[at];
      }
      else if (d[at]  == d[i]-1 and g[at][i]) {
        dp[i] += dp[at];
      }
    }
  }
  if (inicio == 0) way();
}
int main()
{
  queue<int> f;
  xablau;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x][y] = g[y][x] = 1;
  }
  vector<ll> dp(n, 0);
  vector<ll> dp2(n, 0);
  bfs(dp, 0);
  bfs(dp2, n - 1);
  ld resp = dp[n-1];
  for (int i = 1; i < n - 1; i++) {
    if (caminho.count(i)) {
      ld r =2.0 *(ld)dp[i] * (ld)dp2[i];
      resp = max(resp, r);
    }
  }
  if(dp[n-1]==0) cout<<"oi";
  cout << fixed << setprecision(8) << resp/ (ld)dp2[0] << endl;
  return 0;
}
