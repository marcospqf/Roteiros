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
#define TAM 1000009
int v[50], dp[TAM];
int main()
{
  int k, l, m;
  sc3(k, l, m);
  for (int i = 0; i < m; i++) sc(v[i]);
  dp[0]=0;
  for(int i=1;i<TAM;i++){
    if(dp[i-1]==0) dp[i]=1;
    else dp[i]=0;
    if(i>=k and dp[i-k]==0) dp[i]=1;
    if(i>=l and dp[i-l]==0) dp[i]=1;
  }
  for(int i=0;i<m;i++) 
    if(dp[v[i]]) printf("A");
    else printf("B");
  printf("\n");
  return 0;
}
