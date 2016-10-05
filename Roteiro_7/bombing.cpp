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
using namespace std;
int n, m;
set<int>::iterator it;
map<int, multiset<int> > X, Y;
int main()
{
  int t=1;
  while (true) {
    sc2(n, m);
    if (n == 0 and m == 0) break;
    X.clear(), Y.clear();
    t++;
    if(t>2) cout<<endl;
    for (int i = 0; i < n; i++) {
      int x, y;
      sc2(x, y);
      X[x].insert(y);
      Y[y].insert(x);
    }
    for (int i = 0; i < m; i++) {
      int c, d;
      sc2(c, d);
      if (c == 0) {
        if (X.count(d)) {
          printf("%d\n", X[d].size());
          for (it = X[d].begin(); it != X[d].end(); ++it) {
            if(Y.count(*it)){
              Y[*it].erase(d);
              if(Y[*it].size()==0) Y.erase(*it);
            }
          }
          X.erase(d);
        }
        else
          pri(0);
      }
      else {
        if (Y.count(d)) {
         printf("%d\n", Y[d].size());
          for (it = Y[d].begin(); it != Y[d].end(); ++it) 
            if(X.count(*it)){
              X[*it].erase(d);
              if(X[*it].size()==0) X.erase(*it);
            }
          Y.erase(d);
        }
        else
          pri(0);
      }
    }
  }
  return 0;
}
