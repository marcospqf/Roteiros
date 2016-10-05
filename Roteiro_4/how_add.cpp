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
#define MOD 1000000
using namespace std;
int main()
{
  int n, k;
  vector<vector<int> > dp(101, vector<int>(101, 0));
  for (int i = 0; i <= 100; i++) dp[i][1] = 1;
  for (int l = 2; l <= 100; l++) {
    {
      for (int j = 0; j <= 100; j++) {
        for (int m = 0; m <= j; m++) {
          dp[j][l] = (dp[j][l] + dp[m][l - 1]) % MOD;
        }
      }
    }
  }
  while (true) {
    sc2(n, k);
    if (n == 0 and k == 0) break;
    cout << dp[n][k] << endl;
  }
  return 0;
}
