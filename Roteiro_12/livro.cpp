#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define imprime(v)                                        \
  for (int X = 0; X < v.size(); X++) cout << v[X] << " "; \
  cout << endl;
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) cout << v[X][Y] << " "; \
    cout << endl;                                                 \
  }
#define endl "\n"
#define double long double
using namespace std;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
typedef long long int ll;
int main()
{
  int dp[41][10001];
  int v[41];
  while(true){
    int n,m;
    cin>>n>>m;
    if(n==0 and m==0) break;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
      for(int j=0;j<10001;j++){
        if(j-v[i-1]>=0){
          dp[i][j]+=dp[i-1][j-v[i-1]];
        }
        if(j+v[i-1]<10001){
          dp[i][j]+=dp[i-1][j+v[i-1]];
        }
      }
    }
    vector<char> r;
    if(dp[n][m]==0) puts("*");
    else{
      int atual=n;
      while(true){
        if(dp[n][m-v[n-1]]
      }
    }
  }
  return 0;
}
