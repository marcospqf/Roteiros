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
int n,m,l;
int minimo=INF;
void dfs(vector< vector< int> >&g, vector<int>&u, vector<int> &idade, int inicio){
  u[inicio]=1;
  for(int i=0;i<n;i++){
    if(g[i][inicio] and !u[i]){
      minimo=min(minimo, idade[i]);
      dfs(g,u,idade,i);
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  while(true){
    cin>>n>>m>>l;
    if(cin.eof()) break;
    vector< vector<int> > g(n, vector<int>(n,0));
    vector<int> idade(n,0);
    vector<int> pont(n,0);
    for(int i=0;i<n;i++) pont[i]=i;
    vector<int> u(n,0);
    for(int i=0;i<n;i++) cin>>idade[i];
    for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      x--,y--;
      g[x][y]=1;
    }
   for(int i=0;i<l;i++){
     char p;
     cin>>p;
     if(p=='T'){
       int x,y;
       cin>>x>>y;
       x--,y--;
       swap(pont[x],pont[y]);
       swap(idade[pont[x]],idade[pont[y]]);
     }
     else {
       for(int i=0;i<n;i++) u[i]=0;
       minimo=INF;
       int x;
       cin>>x;
       x--;
       dfs(g,u,idade,pont[x]);
       if(minimo==INF) cout<<"*"<<endl;
       else cout<<minimo<<endl;
     }
   }  
    
  }
  return 0;
}
