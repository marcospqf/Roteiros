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
int m, n, t, v[10000], r[10000];
int main()
{
  while (sc3(m, n, t) > 0) {
    memset(v, 0, sizeof(v));
    memset(r, 0, sizeof(r));
    int a = min(m, n);
    n = max(m, n);
    m = a;
    for (int i = 0; i <= t;) {
      v[i] = 1;
      i += m;
    }
    for (int i = 0; i <= t; i++) {
      if (v[i] == 1) {
        int a = i / m;
        int b = (t - i) /n;
        int c = (t - i) % n;
        r[c] = max(a + b, r[c]);
      }
    }
    for (int i = 0; i <n ; i++){
      if(i==0 and r[i]>0){
        printf("%d\n", r[i]);
        break;
      }
      else if(r[i]>0){
        printf("%d %d\n", r[i],i);
        break;
      }
      if(i==n-1) printf("0 %d\n", t);
      
    }
  }
  return 0;
}
