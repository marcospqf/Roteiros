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
int v[1000000];
string a,b;
void build(){
  int i=0, j=-1;
  v[0]=-1;
  while(i<b.size()){
    while(j>=0 and b[i]!=b[j]) j=v[j];
    i++,j++;
    v[i]=j;
  }
}
void kmp(){
  build();
  int i=0,j=0;
  while(i<a.size()){
    while(j>=0 and a[i]!=b[j]) j=v[j];
    i++,j++;
    if(j==b.size()){
      cout<<i-j<<endl;
      j=v[j];
    }
  }
}
int main()
{
  int n;
  while(true){
    cin>>n;
    if(cin.eof()) break;
    cin>>b>>a;
    kmp();
    cout<<endl;
  }
  return 0;
}
