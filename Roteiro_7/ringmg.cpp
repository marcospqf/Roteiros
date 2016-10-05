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
  int n;
  while(true){
    cin>>n;
    if(n==0) break;
    vector<int> v(2*n,INF);
    vector<int> c(2*n,INF);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) v[n+i]=v[i];
    for(int i=0;i<n;i++) c[n+i]=c[i];
    int inicio=-1;
    for(int i=0;i<n;i++){
      int saldo=0;
      for(int j=0;j<n;j++){
        saldo+=v[i+j]-c[i+j];
        if(saldo<0) saldo=-INF;
      }
      if(saldo>=0 and inicio==-1) inicio=i+1; 
    }
    int end=-1;
    for(int i=n;i<2*n;i++){
      int saldo=0;
      for(int j=0;j<n;j++){
        saldo+=v[i-j]-c[i-j-1];
        if(saldo<0) saldo=-INF;
      }
      if(saldo>=0 and end==-1) end=i-n+1; 
    }
    cout<<inicio<<" "<<end<<endl;
  }
  return 0;
}
