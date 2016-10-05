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
int main()
{
  while (true) {
    sc2(n, m);
    if (n == 0 and m == 0) break;
    vector<vector<int> > v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) sc(v[i][j]);
    vector<vector<int> > dp(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
      dp[i][0]=v[i][0];
      dp[i][1]=max(v[i][1],dp[i][0]);
      for(int j=2;j<m;j++){
        dp[i][j]= max(dp[i][j-2]+v[i][j], dp[i][j-1]);
      }
    }
    vector<int> xablau(n);
    vector<int> dpzinha(n,0);
    for(int i=0;i<n;i++) xablau[i]=dp[i][m-1];
    dpzinha[0]=xablau[0];
    dpzinha[1]=max(dpzinha[0],xablau[1]);
    for(int i=2;i<n;i++){
      dpzinha[i]=max(dpzinha[i-2]+xablau[i], dpzinha[i-1]);
    }
    pri(dpzinha[n-1]);
  }
  return 0;
}
