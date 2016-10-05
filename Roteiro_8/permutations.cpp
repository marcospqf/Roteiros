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
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
ll n;
ll fat[21];
string a;
string r;
int main()
{
  fat[0]=1;
  for(ll i=1;i<21;i++) fat[i]=i*fat[i-1];
  int t;
  cin>>t;
  while(t--){
    cin >> a;
    cin>>n;
    n=n%(fat[a.size()]);
    r.clear();
    sort(a.begin(), a.end());
    ll tam=a.size();
    while(tam>0){
      ll prox=fat[tam-1];
      r.push_back(a[n/prox]);
      a.erase(a.begin()+n/prox);
      n-=(n/prox)*prox;
      tam--;
    }
    cout<<r<<endl;
  }
  return 0;
}
