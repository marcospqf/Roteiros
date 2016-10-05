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
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ii pair<int,int> 
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int g[1001];
int in[10];
int out[10];
int n;
int bfs(){
  memset(g,INF,sizeof(g));
  queue<int> f;
  g[100]=0;
  f.push(100);
  while(!f.empty()){
    int topo=f.front();
    f.pop();
    for(int i=0;i<n;i++){
      int prox= topo-in[i];
      if(prox==0){
        g[prox]=g[topo]+1;
        return g[prox];
      }
      if(prox<0) continue;
      prox=prox+out[i];
      if(prox>1000) continue;
      if(g[prox]==INF){
        g[prox]=g[topo]+1;
        f.push(prox);
      }
    }
  }
  return g[0];
}
int main()
{
  while(1){
    sc(n);
    if(n==0) break;
    for(int i=0;i<n;i++) sc(in[i]);
    for(int i=0;i<n;i++) sc(out[i]);
    int r=bfs();
    if(r==INF) cout<<"cavaleiro morreu"<<endl;
    else cout<<r<<endl;
  }
  return 0;
}
