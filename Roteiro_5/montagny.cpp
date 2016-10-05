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
int graph[100][100];
int u[100];
int n,m;
bool cicle=false;
void dfs(int atual, int last){
  if(last==-1 or u[last]==2)
     u[atual]=1;
  else u[atual]=2;
  for(int i=0;i<n;i++){
    if(graph[atual][i] and u[i]==0)
      dfs(i,atual);
    else if(graph[atual][i] and u[i]==u[atual] and i!=last)
      cicle=true;
  }
}
int main()
{
  int t=1;
  while(sc2(n,m)!=EOF){
    memset(graph,0,sizeof(graph));
    memset(u,0,sizeof(u));
    cicle=false;
    for(int i=0;i<m;i++){
      int x,y;
      sc2(x,y);
      x--,y--;
      graph[x][y]=graph[y][x]=1;
    }
    for(int i=0;i<n;i++){
      if(u[i]==0) dfs(i,-1);
    }
    printf("Instancia %d\n", t);
    if(cicle) printf("nao\n\n");
    else printf("sim\n\n");
    t++;
  }
  return 0;
}
