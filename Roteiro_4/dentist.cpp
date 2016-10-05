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
typedef struct node{
  int ini,fim;
}consulta;
bool compare(consulta a, consulta b){
  if(a.fim==b.fim) return a.ini>b.fim;
  return a.fim<b.fim;
}
int main()
{
  int n;
  sc(n);
  vector<int> check(1e6,0);
  vector<consulta> v(n); 
  for(int i=0;i<n;i++) sc2(v[i].ini, v[i].fim);
  sort(v.begin(),v.end(),compare);
  int last=0;
  int r=0;
  for(int i=0;i<n;i++)
    if(v[i].ini>=last) last= v[i].fim,r++;
  pri(r);
  return 0;
}
