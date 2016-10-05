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
int n,m;
int t[10][10];
int u[10][10];
int d[10][10];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int bfs(pair<int,int> inicio){
  queue< pair<int, int> > filona;
  filona.push(inicio);
  u[inicio.first][inicio.second]=1;
  memset(d,0,sizeof(d));
  d[inicio.first][inicio.second]=0;
  while(!filona.empty()){
    pair<int,int> at= filona.front();
    filona.pop();
    for(int i=0;i<4;i++){
      pair<int,int> aux;
      aux.first=at.first+mx[i];
      aux.second=at.second+my[i];
      if(aux.first>=0 and aux.first<n and aux.second>=0 and aux.second<m){
        if(t[aux.first][aux.second]==1 and !u[aux.first][aux.second]){
          filona.push(aux);
          u[aux.first][aux.second]=1;
          d[aux.first][aux.second]=d[at.first][at.second]+1;
        }
        else if(t[aux.first][aux.second]==0 and !u[aux.first][aux.second])
          return d[at.first][at.second]+1;
      } 
    }
  }
  return -1;
}
int main()
{
  pair<int,int> inicio;
  memset(t,0,sizeof(t));
  memset(u,0,sizeof(u));
  sc2(n,m);
  for(int i=0;i<n;i++)
   for(int j=0;j<m;j++){
     sc(t[i][j]);
       if(t[i][j]==3) inicio.first=i, inicio.second=j;
   } 
  int resp=bfs(inicio);
  pri(resp);
  return 0;
}
