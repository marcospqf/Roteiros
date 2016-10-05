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
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int bb(int i, int f, int value, vector<int> &v)
{
  if (i == f) return i;
  int m = (i + f) / 2;
  if (v[m] <= value) return bb(m + 1, f, value, v);
  return bb(i, m, value, v);
}
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> v2(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> v2[i];
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  int j = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    j = bb(0 + j, n - 1, v[i], v2);
    if (v2[j] <= v[i]) break;
    j++;
    r++;
    if (j == n) break;
  }
  cout << r << endl;
  return 0;
}
