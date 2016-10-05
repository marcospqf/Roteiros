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
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int t, n;
int v[1050000];
int prefix[1050000];
pair<int, int> inter[1050000];
bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second) return a.first > b.first;
  return a.second > b.second;
}
int main()
{
  sc(t);
  for (int g = 0; g < t; g++) {
    sc(n);
    for (int i = 0; i < n; i++) inter[i].X = inter[i].Y = prefix[i] = v[i] = -1;
    for (int i = 0; i < n; i++) sc(v[i]);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + v[i];
    bool ok = binary_search(prefix , prefix + n, 42);
    int idx = 0;
    if (ok) {
      inter[idx].X = 0;
      inter[idx].Y = lower_bound(prefix + 1, prefix + n, 42) - prefix;
      idx++;
    }
    for (int i = 1; i < n - 1; i++) {
      ok = binary_search(prefix, prefix + n, prefix[i-1] + 42);
      if (ok) {
        inter[idx].X = i;
        inter[idx].Y =
            lower_bound(prefix, prefix + n, prefix[i-1] + 42) - prefix;
        idx++;
      }
    }
    sort(inter, inter + idx, compare);
    int r = 0;
    if (inter[0].X != -1) {
      r++;
      int b = inter[0].Y;
      int e = inter[0].X;
      for (int i = 1; i < idx; i++) {
        if (inter[i].Y < e) {
          e = inter[i].X;
          r++;
        }
      }
    }
    cout << r << endl;
  }
  return 0;
}
