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
int g[100][100];
int u[100];
int n,m,cont;
void dfs(int atual){
  cont++;
  u[atual]=1;
  for(int i=0;i<n;i++){
   if(g[atual][i] and u[i]==0)
     dfs(i);
  }
}
int main()
{
  int t=1;
  while(true){
    sc2(n,m);
    memset(g,0,sizeof(g));
    memset(u,0,sizeof(u));
    if(n==0 and m==0) break;
    for(int i=0;i<m;i++){
      int x,y;
      sc2(x,y);
      x--,y--;
      g[x][y]=g[y][x]=1;
    }
    cont=0;
    dfs(0);
    if(cont==n)
      printf("Teste %d\nnormal\n\n",t); 
    else
      printf("Teste %d\nfalha\n\n",t); 
    t++;
  }
  return 0;
}
