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
int dp[100][100];
int main()
{
  memset(dp,INF,sizeof(dp));
  int n,e,t,m;
  cin>>n>>e>>t>>m;
  for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    x--,y--;
    dp[x][y]=z;
//    cout<<x<<" "<<y<<" "<<dp[x][y]<<endl;
  }
  for(int i=0;i<n;i++) dp[i][i]=0;
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int r=0;
  for(int i=0;i<n;i++){
    if(dp[i][e-1]<=t) r++;
  }
  cout<<r<<endl;
  return 0;
}
