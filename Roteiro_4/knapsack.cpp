#include<cstring>
#include<iostream>
#include<bitset>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int cap, n, dp[2001][2001], v[2000], p[2000];

int main()
{
  sc2(cap,n);
  for(int i=0;i<2001;i++) memset(dp[i],0,sizeof(dp[i]));
  for(int i=0;i<n;i++) sc2(v[i],p[i]);
  for(int i=1;i<=n;i++){
    for(int j=0;j<=cap;j++){
      dp[i][j]=dp[i-1][j];
      if(j-v[i-1]>=0)
        dp[i][j]=max(dp[i][j],dp[i-1][j-v[i-1]]+ p[i-1]);
    }
  }
  pri(dp[n][cap]);
  return 0;
}
