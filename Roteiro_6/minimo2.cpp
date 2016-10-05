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
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n, m;
struct node {
  int at, cost;
  node(int a, int b) { at = a, cost = b; }
};
bool operator<(const node &a, const node &b)
{
  if (a.cost != b.cost) return a.cost > b.cost;
  return a.at > b.at;
}
int graph[100][100];
int dp[100][100][101];
void minimo(node root, int t)
{
  vector<int> dist(n, INF);
  vector<int> usados(n, 0);
  priority_queue<node> pq;
  dist[root.at] = 0;
  pq.push(root);
  while (!pq.empty()) {
    node topo = pq.top();
    pq.pop();
    int atual = topo.at;
    int c = topo.cost;
    if (usados[atual]) continue;
    usados[atual] = 1;
    for (int i = 0; i < n; i++) {
      int prox =i;
      int aresta = graph[atual][i];
      if(aresta==INF) continue;
      if (dist[prox] > c + aresta and (atual < t or atual == root.at)) {
        dist[prox] = c + aresta;
        node x(prox, dist[prox]);
        pq.push(x);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == root.at) continue;
    dp[root.at][i][t] = dist[i];
  }
}
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 0;
  while (true) {
    t++;
    memset(dp, INF, sizeof(dp));
    cin >> n >> m;
    if (cin.eof()) break;
    memset(graph, INF, sizeof(graph));
    for (int i = 0; i < m; i++) {
      int x, y, k;
      cin >> x >> y >> k;
      x--, y--;
      graph[x][y]=min(graph[x][y],k);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        node root(i, 0);
        minimo(root, j);
      }
    }
    int p;
    cout << "Instancia " << t << endl;
    cin >> p;
    for (int i = 0; i < p; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      if (c >= 0) {
        int r = dp[a][b][c];
        if (r == INF)
          cout << -1 << endl;
        else
          cout << r << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
