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
#define pri(x) printf("%d ", x)
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n, t = 0;
void solve()
{
  printf("Teste %d\n", t);
  pri(n / 50);
  n %= 50;
  pri(n / 10);
  n %= 10;
  pri(n / 5);
  n %= 5;
  pri(n);
  printf("\n\n");
}
int main()
{
  while (true) {
    t++;
    sc(n);
    if (n == 0) break;
    solve();
  }
  return 0;
}
