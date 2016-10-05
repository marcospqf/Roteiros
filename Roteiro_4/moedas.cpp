#include<cstring>
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
int v[101];
int ocor[50001];
int m, n;
int resp = -1;
void solve()
{
  memset(ocor,INF,sizeof(ocor));
  ocor[m]=0;
  for(int j=m;j>=0;j--){
    for(int i=0;i<n;i++){
      if(ocor[j]<INF){
        if(j-v[i]<0) continue;
        ocor[j-v[i]]= min(ocor[j-v[i]], ocor[j]+1); 
      }
    }
  }
}
int main()
{
  while (true) {
    resp = 0;
    if(sc2(m, n)==0) break;
    if (m == 0) break;
    for (int i = 0; i < n; i++) sc(v[i]);
    solve();
    bool x = false;
    resp = -1;
    if (ocor[0]==INF)
      printf("Impossivel\n");
    else
      pri(ocor[0]);
  }
  return 0;
}
