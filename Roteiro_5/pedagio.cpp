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
int c,e,l,p;
int g[50][50];
int u[50];
vector<int> bfs(int atual){
  vector<int> dist(c,0);
  queue<int> filona;
  filona.push(atual);
  u[atual]=1;
  dist[atual]=0;
  while(!filona.empty()){
    int at=filona.front();
    filona.pop();
    for(int i=0;i<c;i++){
      if(g[at][i] and !u[i]){
        filona.push(i);
        dist[i]=dist[at]+1;
        u[i]=1;
      }
    }
  }
  return dist;
}
int main()
{
  ios::sync_with_stdio(false);
  int t=0;
  while(true){
    memset(g,0,sizeof(g));
    memset(u,0,sizeof(u));
    cin>>c>>e>>l>>p;
    if(c+e+l+p==0) break;
    for(int i=0;i<e;i++){
      int x,y;
      cin>>x>>y;
      x--,y--;
      g[x][y]=g[y][x]=1;
    }
    vector<int> dist=bfs(l-1);
    t++;
    cout<<"Teste "<<t<<endl;
    for(int i=0;i<c;i++){
      if(dist[i]>0 and dist[i]<=p) cout<<i+1<<" ";
    }
    cout<<endl<<endl;
  }
  return 0;
}
