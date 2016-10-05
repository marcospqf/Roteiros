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
struct node{
  int cost,at;
  node(int a, int b){at=a,cost=b;}
};
bool operator<(const node &a, const node &b){
  if(a.cost!=b.cost) return a.cost>b.cost;
  else return a.at<b.at;
}
vector< vector< pair<int,int> > > graph;
int n,m;
int minimo(node root){
  vector<int> usados(2*n,0);
  vector<int> dist(2*n,INF);
  priority_queue<node> pq;
  dist[root.at]=0;
  pq.push(root);
  while(!pq.empty()){
    node topo=pq.top();
    pq.pop();
    int v=topo.at;
    int x=topo.cost;
    if(usados[v]) continue;
    usados[v]=1;
    for(int i=0;i<graph[v].size();i++){
     int prox= graph[v][i].first;
     int aresta= graph[v][i].second;
     if(dist[prox] > x+aresta){
       dist[prox]=x+aresta;
       node p(prox,dist[prox]);
       pq.push(p);
     }
    }
  }
  return dist[n-1];
}
int main()
{
  cin>>n>>m;
  graph.resize(2*n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    graph[a].push_back(make_pair(b+n,c));
    graph[a+n].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a+n,c));
    graph[b+n].push_back(make_pair(a,c));
  }
  node root(0,0);
  int resp=minimo(root);
  if(resp==INF) cout<<-1<<endl;
  else
  cout<<resp<<endl;
  return 0;
}
