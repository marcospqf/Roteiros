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
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define ii pair<int, int>
#define mp(a, b) make_pair(min(a, b), max(a, b))
#define endl "\n"
using namespace std;
int n, m;
vector<pair<int, ii> > edge;
vector<int> pset;
vector<ii> resp;
void initset(int tam)
{
  pset.resize(tam);
  for (int i = 0; i < tam; i++) pset[i] = i;
}
int findset(int i)
{
  if (pset[i] == i) return i;
  return pset[i] = findset(pset[i]);
}
void unionset(int i, int j) { pset[findset(i)] = findset(j); }
bool issameset(int i,int j) { return findset(i)==findset(j);}
void kruskal() { 
  resp.clear();
  sort(edge.begin(), edge.end()); 
  initset(n);
  int mst_cost=0;
  for(int i=0;i<m;i++){
    pair<int,ii > front= edge[i];
    if(!issameset(front.second.first, front.second.second)){
       mst_cost+=front.first;
      unionset(front.second.first, front.second.second);
      resp.push_back(mp(front.second.first, front.second.second));
    }
  }
}
int main()
{
  int t=1;
  while (true) {
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    edge.clear();
    for (int i = 0; i < m; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      x--, y--;
      edge.push_back(make_pair(t, mp(x, y)));
    }
    kruskal();
    cout<<"Teste "<<t<<endl;
    t++;
    for(int i=0;i<resp.size();i++)
      cout<<resp[i].first+1<<" "<<resp[i].second+1<<endl;
    cout<<endl;
  }
  return 0;
}
