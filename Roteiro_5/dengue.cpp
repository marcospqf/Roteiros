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
int n;
int g[100][100];
int u[100];
int prof=0;
int prof_max=0;
void dfs(int a){
  u[a]=1;
  for(int i=0;i<n;i++){
    if(g[a][i] and !u[i]){
      prof++;
      prof_max=max(prof_max,prof);
      dfs(i);
      prof--;
    }
  }
}
int main()
{
  int t=1;
  while(true){
    sc(n);
    if(n==0) break;
    memset(g,0,sizeof(g));
    for(int i=1;i<n;i++){
      int x,y;
      sc2(x,y);
      x--,y--;
      g[x][y]=g[y][x]=1;
    }
    int r=0;
    int antes=INF;
    for(int i=0;i<n;i++){
      prof_max=0; 
      memset(u,0,sizeof(u));
      dfs(i);
      if(prof_max<antes) r=i+1, antes=prof_max;
    }
    printf("Teste %d\n%d\n\n",t,r);
    t++;
  }
  return 0;
}
