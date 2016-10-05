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
int n, k;
void dfs(vector<vector<int> > &g, vector<int> &u, int atual, vector<int> &pai,
         int last, vector<vector<ll> > &dp)
{
  u[atual] = 1;
  pai[atual] = last;
  for (int i = 0; i < g[atual].size(); i++) {
    if (!u[g[atual][i]]) {
      dfs(g, u, g[atual][i], pai, atual, dp);
    }
  }
  dp[atual][0] = 1;
  for (int i = 1; i <= k; i++) {
    if (last != -1) {
      dp[last][i] += dp[atual][i - 1];
    }
  }
}
int main()
{
  cin >> n >> k;
  vector<vector<int> > g(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> u(n, 0);
  vector<int> pai(n, 0);
  vector<vector<ll> > dp(n, vector<ll>(k + 1, 0));
  ll resp = 0;
  dfs(g, u, 0, pai, -1, dp);
  ll x = 0;
  for (int i = 0; i < n; i++) x += dp[i][k];
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < k; j++) {
      if (pai[i] != -1) {
        resp += dp[i][j-1] * dp[pai[i]][k - j];
        resp -= dp[i][j-1] * dp[i][k -j-1];
      }
    }
  }
  cout << resp/2+x << endl;
  return 0;
}
