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
int grid[9][9], n, tam, foi = false;
int xab;
int zero[100];
int v[10];
int l=false;
int t;
bool compativel(int x, int y)
{
  memset(v, 0, sizeof(v));
  for (int i = 0; i < n; i++) {
    v[grid[x][i]]++;
    if (v[grid[x][i]] > 1 and grid[x][i] != 0) return false;
  }
  memset(v, 0, sizeof(v));
  for (int i = 0; i < n; i++) {
    v[grid[i][y]]++;
    if (v[grid[i][y]] > 1 and grid[i][y] != 0) return false;
  }
  memset(v, 0, sizeof(v));
  int areah = x / xab, areav = y / xab;
  for (int i = areah * xab; i < xab*areah + xab; i++) {
    for (int j = areav * xab; j <xab*areav+xab; j++) {
      v[grid[i][j]]++;
      if (v[grid[i][j]] > 1 and grid[i][j] != 0) return false;
    }
  }
  if(x==0) l=true;
  return true;
}
void imprime()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(j>0) cout<<" ";
      cout << grid[i][j];
    }
    cout << endl;
  }
}
void solve()
{
  if(foi) return;
  if (t == tam)
    if (!foi) {
      foi = true;
      imprime();
      return;
    }
  bool retorno = false;
  int atual = zero[t];
  int x = atual /n;
  int y = atual % n;
  for (int i = 1; i <= n; i++) {
    grid[x][y] = i;
    if (compativel(x, y)) {
      t++;
      solve();
      t--;
    }
    grid[x][y] = 0;
  }
}
int main()
{
  int tinto=1;
  while (true) {
    memset(grid,0,sizeof(grid));
    foi = false;
    cin >> n;
    xab=n;
    n=n*n;
    tam = 0;
    if (cin.eof() or n==0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 0) {
          zero[tam] = i*n + j;
          tam++;
        }
      }
    t=0;
    if(tinto>1) cout<<endl;
    tinto++;
    solve();
    if (!foi) cout << "NO SOLUTION" << endl;
    t++;
  }
  return 0;
}
