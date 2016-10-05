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
#define endl "\n"
using namespace std;
int n, m, c, k;
struct node {
  int cost;
  int at;
  node(int a, int b) { at = a, cost = b; }
};
bool operator<(const node &a, const node &b)
{
  if (a.cost != b.cost)
    return a.cost > b.cost;
  else
    return a.at > b.at;
}
vector<vector<pair<int, int> > > graph;
int minimum(node root)
{
  vector<int> dist(n, INF);
  vector<int> usados(n, 0);
  priority_queue<node> pq;
  pq.push(root);
  dist[root.at] = 0;
  while (!pq.empty()) {
    node atual = pq.top();
    pq.pop();
    int v = atual.at;
    if(usados[v]) continue;
    usados[v]=1;
    int custo = atual.cost;
    for (int i = 0; i < graph[v].size(); i++) {
      int prox = graph[v][i].first;
      int aresta = graph[v][i].second;
      if (v < c-1 and v != prox-1 ) continue;
      if (dist[prox] > aresta + custo) {
        dist[prox] = aresta + custo;
        pq.push(node(prox, dist[prox]));
      }
    }
  }
  return dist[c - 1];
}
int main()
{
  ios::sync_with_stdio(false);
  while (true) {
    cin >> n >> m >> c >> k;
    if(n==0 and m==0 and c==0 and k==0) break;
    graph.clear();
    graph.resize(n);
    for (int i = 0; i < m; i++) {
      int x, y, p;
      cin >> x >> y >> p;
      graph[x].push_back(make_pair(y, p));
      graph[y].push_back(make_pair(x, p));
    }
    cout << minimum(node(k, 0)) << endl;
   
  }
  return 0;
}
