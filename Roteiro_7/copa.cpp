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
int n,m;
int main()
{
  while(true){
    cin>>n>>m;
    if(n==0 or cin.eof()) break;
    vector<int> v(n);
    int aux=0;
    for(int i=0;i<n;i++){
      string s;
      cin>>s>>v[i];
      aux+=v[i];
    }
    int r=m*3;
    cout<<r-aux<<endl;
  }
  return 0;
}
