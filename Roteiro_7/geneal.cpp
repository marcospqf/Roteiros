#include<unordered_map>
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
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ii pair<int,int> 
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
unordered_map<string,int> mp;
unordered_map<int,string> mp2;
int n;
int pai[1000];
int dp[1000][1000];
int solve(int A, int B){
   if(A==B) return dp[A][B]=0;
   if(dp[A][B]==INF){
     int x= pai[A];
     int y=pai[B];
     if(x==-1){
      return dp[A][B]=1+solve(A,y);
     }
     else if(y==-1){
       return dp[A][B]=1+solve(x,B);
     }
     else return dp[B][A]=1+min(solve(x,B), solve(A,y));
   }
   else return dp[A][B];
}
int main()
{
  ios::sync_with_stdio(false);
  memset(pai,-1,sizeof(pai));
  memset(dp,INF,sizeof(dp));
  mp.clear(), mp2.clear();
  cin>>n;
  int cont=1;
  for(int i=0;i<n;i++){
    string c,d;
    cin>>c>>d;
    if(mp.count(c)<=0){
      mp[c]=cont;
      mp2[cont]=c;
      cont++;
    }
    if(mp.count(d)<=0){
      mp[d]=cont;
      mp2[cont]=d;
      cont++;
    }
    pai[mp[d]]=mp[c];
  }
  int resp=0;
  int x,y;
  for(int i=1;i<cont;i++)
    for(int j=1;j<cont;j++){
      int a=solve(i,j);
      if(a>100)
        cout<<i<<" "<<j<<endl;
      if(resp<a){
        resp=a,x=i,y=j;
      }
    }
  string a,b;
  a=mp2[x], b=mp2[y];
  cout<<min(a,b)<<" "<<max(a,b)<<" "<<resp<<endl;
  return 0;
}
