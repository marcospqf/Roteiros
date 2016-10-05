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
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
struct node {
  int cost, at, dir;
  node(int a, int b, int c) { at = a, cost = b, dir = c; }
};
bool operator<(const node &a, const node &b)
{
  if (a.cost != b.cost) return a.cost > b.cost;
  if (a.at != b.at) return a.at > b.at;
  return a.dir > b.dir;
}
char graph[101][101][4];
int usados[101][101][4];
int dist[101][101][4];
int n, m;
int mv[] = {0, 0, -1, 1};
int mh[] = {1, -1, 0, 0};
int minimo(int a, int b, int li, int lj)
{
  memset(usados, 0, sizeof(usados));
  memset(dist, INF, sizeof(dist));
  dist[a][b][0] = dist[a][b][1] = dist[a][b][2] = dist[a][b][3] = 0;
  priority_queue<node> pq;
  node x(a * m + b, 0, 0);
  node x1(a * m + b, 0, 1);
  node x2(a * m + b, 0, 2);
  node x3(a * m + b, 0, 3);
  pq.push(x), pq.push(x1), pq.push(x2), pq.push(x3);
  while (!pq.empty()) {
    node topo = pq.top();
    pq.pop();
    int atual = topo.at;
    int x = atual / m, y = atual % m;
    int c = topo.cost;
    int d = topo.dir;
    if (usados[x][y][d]) continue;
    usados[atual / m][atual % m][d] = 1;
    for (int i = 0; i < 4; i++) {
      int proxX = x + mv[i];
      int proxY = y + mh[i];
      int aresta = 0;
      if (i != d) aresta = 1;
      if (proxX >= n or proxY >= m or proxX < 0 or proxY < 0) continue;
      if (graph[proxX][proxY][i] == '*') continue;
      if (dist[proxX][proxY][i] > dist[x][y][d] + aresta) {
        dist[proxX][proxY][i] = dist[x][y][d] + aresta;
        node xab(proxX * m + proxY, dist[proxX][proxY][i], i);
        pq.push(xab);
      }
    }
  }
  int resp = INF;
  for (int i = 0; i < 4; i++) resp = min(resp, dist[li][lj][i]);
  return resp;
}
int main()
{
  cin >> m >> n;
  pair<int, int> start;
  pair<int, int> last;
  start.first = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char p;
      cin >> p;
      if (p == 'C' and start.first == -1)
        start.first = i, start.second = j;
      else if (p == 'C')
        last.first = i, last.second = j;
      for (int k = 0; k < 4; k++) graph[i][j][k] = p;
    }
  cout << minimo(start.first, start.second, last.first, last.second) << endl;
  return 0;
}
