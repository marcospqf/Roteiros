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
int lis(const vector<int>& v)
{
  vector<int> pd(v.size(), INF);
  int maxi = 0, x = 0, j = 0, ind = 0;
  for (int i = 0; i < v.size(); i++) {
    x = v[i];
    j = upper_bound(pd.begin(), pd.begin() + maxi, x) - pd.begin();
    pd[j] = x;
    if (j == maxi) maxi++;
  }
  return maxi;
}
int main()
{
  int i = 0;
  vector<int> v;
  int t = 1;
  while (true) {
    int x;
    sc(x);
    if (x == -1 and i == 0) break;
    if (x == -1) {
      i = 0;
      reverse(v.begin(), v.end());
      if (t > 1) printf("\n");
      printf("Test #%d:\n", t);
      t++;
      printf("  maximum possible interceptions: %d\n", lis(v));
      v.clear();
      continue;
    }
    i++;
    v.push_back(x);
  }
  return 0;
}
