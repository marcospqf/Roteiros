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
bool bfs(vector<vector<int> >& graph, vector<int>& usados, int atual,
         int tamanho)
{
  bool temloop = false;
  vector<int> pai(tamanho, -1);
  queue<int> filona;
  int aux = 0;
  filona.push(atual);
  while (!filona.empty()) {
    int at = filona.front();
    usados[at] = 1;
    filona.pop();
    for (int i = 0; i < tamanho; i++) {
      if (graph[at][i] == 1 and usados[i] == 0) {
        filona.push(i);
        pai[i] = at;
      }
      else if (graph[at][i] == 1 and usados[i] == 1 and pai[at] != i) {
        temloop = true;
        aux++;
      }
    }
  }
  if (aux > 2) temloop = false;
  return temloop;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x - 1][y - 1] = 1;
    graph[y - 1][x - 1] = 1;
  }
  vector<int> usados(n, 0);
  bool temciclo = bfs(graph, usados, n - 1, n);
  for (int i = 0; i < n; i++)
    if (usados[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  if (temciclo)
    cout << "FHTAGN!" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
