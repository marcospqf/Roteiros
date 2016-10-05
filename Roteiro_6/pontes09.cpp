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
#define mp(a,b) make_pair(a,b)
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
struct node{
  int cost;
  int at;
  node(int a,int b){ at=a, cost=b;}
};
bool operator<(const node &a, const node &b){
  if(a.cost!=b.cost) return a.cost>b.cost;
  return a.at>b.at;
}
int n,m;
vector< vector< ii > > graph;
int minimo(node root){
  vector<int> dist(n+2,INF);
  vector<int> usados(n+2,0);
  priority_queue<node> pq;
  dist[root.at]=0;
  pq.push(root);
  while(!pq.empty()){
    node topo=pq.top();
    pq.pop();
    int atual=topo.at;
    int custo= topo.cost;
    if(usados[atual]) continue;
    usados[atual]=1;
    for(int i=0;i<graph[atual].size();i++){
      int prox= graph[atual][i].first;
      int aresta= graph[atual][i].second;
      if(dist[prox]> dist[atual] + aresta){
        dist[prox]=dist[atual]+aresta;
        node x(prox,dist[prox]);
        pq.push(x);
      }
    }
  }
  return dist[n+1];
}
int main()
{
  cin>>n>>m;
  graph.resize(n+2);
  for(int i=0;i<m;i++){
    int x,y,t;
    cin>>x>>y>>t;
    graph[x].push_back(mp(y,t));
    graph[y].push_back(mp(x,t));
  }
  node root(0,0);
  cout<<minimo(root)<<endl;
  return 0;
}
