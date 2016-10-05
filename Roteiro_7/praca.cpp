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
struct node{
  int h,m,s;
  char in;
  node(int a, int b, int c, char d){h=a,m=b,s=c, in=d;}
  node(){};
};
int n;
bool compare(const node &x, const node &y){
  if(x.h!=y.h) return x.h<y.h;
  if(x.m!=y.m) return x.m<y.m;
  if(x.s!=y.s) return x.s<y.s;
  return x.in<y.in;
}
int main()
{
  while(true){
    cin>>n;
    if(n==0) break;
    vector<node> v(n);
    int e=0;
    int s=0;
    for(int i=0;i<n;i++){
      int a,b,c;
      char p;
      cin>>a>>p>>b>>p>>c>>p;
      if(p=='E') e++;
      v[i]=node(a,b,c,p);
    }
    int quant=0;
    int resp=0;
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<n;i++){
      if(v[i].in=='X') quant--;
      else if(v[i].in=='E') quant++;
      else if(v[i].in=='?'and e<n/2) quant++,e++;
      else quant--;
      resp=max(resp,quant);
    }
    cout<<resp<<endl;
  }
  return 0;
}
