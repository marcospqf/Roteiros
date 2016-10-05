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
struct node{
  int cost,at;
  node(int a, int b){at=a,cost=b;}
};
bool operator<(const node &a, const node &b){
  if(a.cost!=b.cost) return a.cost>b.cost;
  return a.at>b.at;
}
int dist[100];
int usados[100];
int g[100][100];
int n,m;
int minimo(int i){
  memset(dist,INF,sizeof(dist));
  memset(usados,0,sizeof(usados));
  priority_queue<node> pq;
  node root(i,0);
  pq.push(root);
  dist[i]=0;
  while(!pq.empty()){
    node topo=pq.top();
    pq.pop();
    int u= topo.at;
    int c=topo.cost;
    if(usados[u]) continue;
    usados[u]=1;
    for(int i=0;i<n;i++){
      if(g[u][i]==INF) continue;
      int next=c+ g[u][i];
      if(dist[i]>next){
        dist[i]=next;
        node x(i,dist[i]);
        pq.push(x);
      }
    }
  }
  int retorno=0;
  for(int j=0;j<n;j++) {
    retorno=max(retorno,dist[j]);
  }
  return retorno;
}
int main()
{
  sc2(n,m);
  memset(g,INF,sizeof(g));
  for(int i=0;i<m;i++){
    int x,y,z;
    sc3(x,y,z);
    g[x][y]=g[y][x]=min(z,g[x][y]);
  }
  int r=INF;
  for(int i=0;i<n;i++){
    r=min(r,minimo(i));
  }
  cout<<r<<endl;
  return 0;
}
