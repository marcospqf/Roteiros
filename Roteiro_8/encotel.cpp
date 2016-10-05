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
  while(true){
    string a;
    cin>>a;
    if(cin.eof()) break;
    for(int i=0;i<a.size();i++){
      if(a[i]>='A' and a[i]<='Z'){
        int x= (int)(a[i]-'A');
        int y=x/3;
        if(x>=18 and x%3==0) y--;
        y+=2;
        if(x==25 and x%3==1) y--;
        a[i]=(char)(y+'0');
      }
    }
    cout<<a<<endl;
  }
  return 0;
}
