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
int solve(int n,int k){
  if(n<=k) return 1;
  return solve((n+1)/2,k)+ solve(n/2,k);
}
int main()
{
  int n,k;
  while(true){
    cin>>n>>k;
    if(n==0 and k==0) break;
    cout<<solve(n,k)<<endl;
  }
  return 0;
}
