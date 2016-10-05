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
ll fib[50];
int main()
{
  fib[0] = 1;
  fib[1] = 2;
  for (int i = 2; i < 50; i++) fib[i] = fib[i - 1] + fib[i - 2];
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    string a;
    getline(cin, a);
    getline(cin, a);
    char out[105];
    memset(out, ' ', sizeof(out));
    int maximo=0;
    for (int i = 0, j = 0; i < m; i++) {
      while (j < a.size() and (a[j] < 'A' or a[j] > 'Z')) j++;
      int x = lower_bound(fib, fib + 50, (ll)v[i]) - fib;
      out[x] = a[j];
      j++;
      maximo=max(maximo,x);
    }
    for(int i=0;i<=maximo;i++) putchar(out[i]);
    puts("");
  }
  return 0;
}
