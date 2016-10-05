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
int n;
char a[5002];
int main()
{
  sc(n);
  scs(a);
  int dp[2][5001];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 5001; j++) dp[i][j] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (a[i] == a[j]) {
        if (j == 0)
          dp[i & 1][j] = 1;
        else
          dp[i & 1][j] = dp[(i + 1) & 1][j - 1] + 1;
      }
      else {
        if (j != 0)
          dp[i & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j - 1]);
        else
          dp[i & 1][j] = dp[(i + 1) & 1][j];
      }
    }
  }
  pri(n - dp[0][n - 1]);
  return 0;
}
