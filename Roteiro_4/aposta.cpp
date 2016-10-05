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
int v[10000], n;
int solve()
{
  int result = 0, resp=0;
  for (int i = 0; i < n; i++) 
    if(result+v[i]<0) result=0;
    else {
      result+=v[i];
      resp=max(resp,result);
    }
  return resp;
}
int main()
{
  while (true) {
    sc(n);
    if (n == 0) break;
    for (int i = 0; i < n; i++) sc(v[i]);
    int x = solve();
    if (x > 0)
      printf("The maximum winning streak is %d.\n", x);
    else
      printf("Losing streak.\n");
  }
  return 0;
}
