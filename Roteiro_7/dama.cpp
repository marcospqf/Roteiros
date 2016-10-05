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
#define X first
#define Y second
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int x, y, x2, y2;
bool confere(){
  if(x+y==x2+y2) return true;
  if(y-x==y2-x2) return true;
  if(x==x2 or y==y2) return true;
  return false;
}
int main()
{
  while (true) {
    cin >> x >> y >> x2 >> y2;
    if(x+y+x2+y2==0) break;
    if(confere()){
      if(x==x2 and y==y2) cout<<"0"<<endl;
      else cout<<"1"<<endl;
    }
    else cout<<2<<endl;
  }
  return 0;
}
