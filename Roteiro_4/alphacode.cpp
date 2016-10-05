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
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
bool converte(char a, char b)
{
  int x = a - '0';
  int y = b - '0';
  int z= 10*x + y;
  if (z <= 26 and z>=10) return true;
  return false;
}
int main()
{
  char p[5004];
  while (true) {
    scs(p);
    if (p[0] == '0') break;
    int n=strlen(p);
    vector<ll> r(n, 0);
    r[0] = 1;
    for (int i = 1; i< n; i++) {
      if(p[i]!='0')
        r[i] = r[i - 1];
      if (converte(p[i - 1], p[i])) {
        if(i>1)
          r[i] += r[i - 2];
        if(i==1)
          r[i]++;
      }
    }
    pri(r[n - 1]);
  }
  return 0;
}
