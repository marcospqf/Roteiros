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
int v[100], x, y, n;
int dp[2][10001];
int solve(int c)
{
  for(int i=0;i<2;i++)
    for(int j=0;j<10001;j++)
      dp[i][j]=0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
        dp[(i%2)][j] = dp[(i - 1)%2][j];
        if(j - v[i-1] >=0 and dp[(i-1)%2][j-v[i-1]]==1)
          dp[i%2][j]=1;
    }
  }
  return dp[n%2][c];;
}
int main()
{
  int t = 1;
  while (true) {
    sc3(x, y, n);
    if (x == 0 and y == 0 and n == 0) break;
    int tot = x + y;
    for (int i = 0; i < n; i++) {
      sc(v[i]);
      tot += v[i];
    }
    int resp = 0;
    if (tot % 2 == 0) resp = solve(tot / 2 - x);

    if (t > 1) printf("\n");
    printf("Teste %d\n", t);
    t++;
    if (resp)
      printf("S\n");
    else
      printf("N\n");
  }
  return 0;
}
