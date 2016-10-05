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
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define imprime(v)                                        \
  for (int X = 0; X < v.size(); X++) cout << v[X] << " "; \
  cout << endl;
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) cout << v[X][Y] << " "; \
    cout << endl;                                                 \
  }
#define endl "\n"
#define double long double
using namespace std;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
typedef long long int ll;
int main()
{
  int n, m, k;
  int dp[22][22][2002];
  int mv[] = {0,0,0,1,1,1,-1,-1,-1};
  int mh[] = {0,1,-1,0,1,-1,0,1,-1};
  while (true) {
    cin >> n >> m >> k;
    if (n == 0 and m == 0 and k == 0) break;
    memset(dp,0 , sizeof(dp));
    for (int i = 0; i < k; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      dp[x][y][t]=1;
    }
    int x1,y1;
    cin>>x1>>y1;
    for (int K = 2*k; K >= 0; K--) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          int u = 0;
          for (int l = 0; l < 9; l++) {
              u = max(u, dp[i + mv[l]][j + mh[l]][K + 1]);
          }
          dp[i][j][K] += u;
        }
      }
    }
    cout << dp[x1][y1][0] << endl;
  }
  return 0;
}
