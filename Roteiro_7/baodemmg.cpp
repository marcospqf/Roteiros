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
int main()
{
  int e;
  cin>>e;
  for(int i=0;i<e;i++){
    int t;
    cin>>t;
    int p=3*t;
    int c=0;
    for(int j=0;j<t;j++){
      int x;
      cin>>x;
      c+=x;
    }
    c*=3;
    if(p>=c) cout<<"nao precisa"<<endl;
    else cout<<"precisa"<<endl;
  }
  return 0;
}
