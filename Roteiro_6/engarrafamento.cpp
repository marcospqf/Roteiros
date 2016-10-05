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
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n,m,t,s,d;
vector< vector<pair<int,int> > > g;
struct node{
  int cost;
  int at;
  node(int a,int b) {cost=a, at=b;}
};
bool operator<(const node &a, const node &b){
  if(a.cost!=b.cost) return a.cost>b.cost;
  return a.at>b.at;
}
int cam(node root){
  vector<int> dist(n,INF);
  vector<int> usado(n,0);
  priority_queue<node> pq;
  pq.push(root);
  dist[root.at]=0;
  while(!pq.empty()){
    node top= pq.top();
    pq.pop();
    int x=top.cost, u=top.at;
    if(u==d-1) return x;
    if(usado[u]) continue;
    usado[u]=1;
    for(int i=0;i<g[u].size();i++){
      int v= g[u][i].first;
      int next=g[u][i].second+x;
      if(dist[v] > next){
        dist[v]=next;
        pq.push(node(next,v));
      }
    }
  }
  return -1;
}
int main()
{
  ios::sync_with_stdio(false);
  while(true){
    g.clear();
    cin>>n>>m;
    if(n==0 and m==0) break;
    g.resize(n);
    for(int i=0;i<m;i++){
      int x,y,t;
      cin>>x>>y>>t;
      x--,y--;
      g[x].push_back(make_pair(y,t));
    }
    cin>>s>>d;
    node root(0,s-1);
   cout<<cam(root)<<endl;
  }
  return 0;
}
