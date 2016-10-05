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
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
using namespace std;
int main()
{
  int n, c;
  sc2(n, c);
  int v[n];
  for (int i = 0; i < n; i++) sc(v[i]);
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] > c) {
      printf("N\n");
      return 0;
    }
  }
  if (42192-v[n - 1] > c) {
    printf("N\n");
    return 0;
  }

  printf("S\n");
  return 0;
}
