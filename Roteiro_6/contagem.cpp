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
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
ll eleva(int x){
  if(x==1) return 2;
  if(x==0) return 1;
  ll resp=eleva(x/2);
  if(x%2==0) return resp*resp;
  return 2*resp*resp;
}
int main()
{
  ios::sync_with_stdio(false);
  string a;
  int t=1;
  ll resp=0;
  while(true){
    cin>>a;
    if(cin.eof()) break;
    resp=0;
    bool temb=false;
    for(int i=0;i<a.size();i++){
      if(a[i]=='b'){
        temb=true;
        resp+=eleva(a.size()-i-1);
      }
    }
    cout<<"Palavra "<<t<<endl;
    if(temb)
    cout<<resp<<endl<<endl;
    else
    cout<<0<<endl<<endl;
    t++;
  }
  return 0;
}
