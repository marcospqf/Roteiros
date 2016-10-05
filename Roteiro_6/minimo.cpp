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
#define mp(a, b) make_pair(a, b)
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n, m;
int dp[100][100][101];
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 0;
  while (true) {
    t++;
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<=n;k++) dp[i][j][k]=INF;
    if (cin.eof()) break;
    for (int i = 0; i < m; i++) {
      int x, y, k;
      cin >> x >> y >> k;
      x--, y--;
      dp[x][y][0]=min(dp[x][y][0],k);;
    }
    for (int g = 0; g < n; g++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j][g + 1] = min(dp[i][j][g], dp[i][g][g] + dp[g][j][g]);
        }
      }
    }
    int p;
    cout << "Instancia " << t << endl;
    cin >> p;
    for (int i = 0; i < p; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      int r = dp[a][b][c];
      if(a==b) r=0;
      if (r == INF)
        cout << -1 << endl;
      else
        cout << r << endl;
    }
    cout<<endl;
  }
return 0;
}
