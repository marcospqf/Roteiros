#include<cstring>
#include<iostream>
#include<bitset>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define ii pair<int,int> 
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int d[61],e[61],n;
int main()
{
  while(true){
    cin>>n;
    if(cin.eof()) break;
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    for(int i=0;i<n;i++){
      int x;
      char p;
      cin>>x>>p;
      if(p=='D') d[x]++;
      else e[x]++;
    }
    int resp=0;
    for(int i=0;i<61;i++) resp+=min(e[i],d[i]);
    pri(resp);
  }
  return 0;
}
