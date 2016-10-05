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
int t, din, n, p;
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  for (int g = 0; g < t; g++) {
    cin >> din >> n;
    vector<vector<int> > loja(n);
    for (int i = 0; i < n; i++) {
      cin >> p;
      for (int j = 0; j < p; j++) {
        int x;
        cin >> x;
        loja[i].push_back(x);
      }
    }
    vector<vector<int> > dp(n + 1, vector<int>(din + 1, 0));
    for (int j = 1; j <= din; j++) {
      dp[1][j] = dp[1][j - 1];
      for (int i = 0; i < loja[0].size(); i++) {
        if (j - loja[0][i] >= 0)
          dp[1][j] = max(dp[1][j], dp[0][j - loja[0][i]] + loja[0][i]);
      }
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= din; j++) {
        for (int k = 0; k < loja[i - 1].size(); k++) {
          if (j - loja[i - 1][k] >= 0 and dp[i - 1][j - loja[i - 1][k]] != 0) {
            int x = loja[i - 1][k];
            dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + x);
          }
        }
      }
    }
    int resposta = 0;
    for (int i = din; i >= 0; i--) resposta = max(dp[n][i], resposta);
    if (resposta == 0)
      cout << "no solution" << endl;
    else
      cout << dp[n][din] << endl;
  }
  return 0;
}
