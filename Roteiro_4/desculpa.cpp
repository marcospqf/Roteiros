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
int c, f;
int pag[51], desc[50];
int dp[51][1001];
int solve()
{
  int maxi = 0;
  for (int i = 0; i < f; i++) memset(dp[i], 0, sizeof(dp[i]));
  for(int j=1;j<=c;j++){
    for(int i=1;i<=f;i++){
      if(pag[i-1]>j)
        dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],dp[i-1][j-pag[i-1]]+desc[i-1]);
    }
  }
  return dp[f][c];
}
int main()
{
  int t=0;
  while (true) {
    sc2(c, f);
    if (c == 0 and f == 0) break;
    for (int i = 0; i < f; i++) sc2(pag[i],desc[i]);
    printf("Teste %d\n",t+1);
    t++;
    pri(solve());
  }
  return 0;
}
