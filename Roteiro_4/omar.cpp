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
#define pri(x) printf("%lld\n", x)
const int INF = 0x3f3f3f3f;
#define ll int
#define ld long double
#define endl "\n"
using namespace std;
int t, m, n;
int tab[1100][1100];
int sum[1100][1100];
int main()
{
  sc(t);
  for (int g = 0; g < t; g++) {
    memset(tab, 0, sizeof(tab));
    memset(sum, 0, sizeof(sum));
    sc2(n, m);
    for (int i = n - 1; i >= 0; i--)
      for (int j = m - 1; j >= 0; j--) sc(tab[i][j]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i][j] = tab[i][j];
        if (j > 0) sum[i][j] += sum[i][j - 1];
        if (i > 0) sum[i][j] += sum[i - 1][j];
        if (i > 0 and j > 0) sum[i][j] -= sum[i - 1][j - 1];
      }
    }
    int resp = sum[0][0];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) resp = max(resp, sum[i][j]);
    cout << resp << endl;
  }
  return 0;
}
