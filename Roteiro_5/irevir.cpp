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
int n, m, call;
int g[2000][2000];
int usados[2000];
void dfs(int atual)
{
  usados[atual] = 1;
  call++;
  for (int i = 0; i < n; i++) {
    if (g[atual][i] and usados[i]==0) {
      dfs(i);
    }
  }
}
int main()
{
  while (true) {
    sc2(n, m);
    bool ok = true;
    memset(g, 0, sizeof(g));
    if (n == 0) break;
    for (int i = 0; i < m; i++) {
      int x, y, z;
      sc3(x, y, z);
      x--, y--;
      if (z == 1)
        g[x][y] = 1;
      else
        g[x][y] = g[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
      call = 0;
      memset(usados, 0, sizeof(usados));
      dfs(i);
      if (call != n) ok = false;
    }
    if (ok)
      pri(1);
    else
      pri(0);
  }
  return 0;
}
