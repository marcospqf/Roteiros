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
int tam=0;
void dfs( vector< vector<int> > &g,vector<bool> &u, int inicio, int last){
  tam++;
  u[inicio]=true;
  for(int i=0;i<g[inicio].size();i++){
    if(!u[g[inicio][i]] and g[inicio][i]!=last){
      dfs(g,u,g[inicio][i],inicio);
    }
  }
}
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int c,r;
  while(true){
    tam=0;
    cin>>c>>r;
    if(c+r==0) break;
    map<string,int> m;
    int ocor=0;
    for(int i=0;i<c;i++){
      string s;
      cin>>s;
      m[s]=ocor;
      ocor++;
    }
    vector< vector<int> > g(c);
    vector<bool> u(c,false);
    for(int i=0;i<r;i++){
      string a,b;
      cin>>a>>b;
      int x= m.find(a)->second;
      int y= m.find(b)->second;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int r=0;
    for(int i=0;i<c;i++){
      if(!u[i]) {
        tam=0;
        dfs(g,u,i,-1);
        r=max(r,tam);
      }
    }
   cout<<r<<endl; 
  }
  return 0;
}
