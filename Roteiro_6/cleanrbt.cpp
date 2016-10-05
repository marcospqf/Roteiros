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
char graph[20][20];
int sujeira[10];
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n,m;
  cin>>n>>m;
  int k=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      cin>>graph[i][j];
      if(graph[i][j]=='*') sujeira[k]i*m+j);
    }
  
  return 0;
}
