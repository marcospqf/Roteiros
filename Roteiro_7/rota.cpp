#include <unordered_map>
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
int n, m;
int g[100][100];
int u[100];
unordered_map<string, int> mp;
unordered_map<int, string> mp2;
unordered_map<int, int> mp3;
unordered_map<int, int> mp4;
char v[10][40];
stack<int> pilhona;
int us = 0;
void dfs(int atual)
{
  u[atual] = 1;
  us++;
  for (int i = 0; i < n; i++)
    if (g[atual][i] > 0 and !u[i]) dfs(i);
}
void dfs2(int atual){
  u[atual]=1;
  for(int i=0;i<n;i++)
    if(g[atual][i]>0 and !u[i]) pilhona.push(atual*n+i), dfs2(i);
}
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  while (true) {
    mp.clear();
    mp2.clear();
    memset(g, 0, sizeof(g));
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      mp[s] = i;
      mp2[i] = s;
    }
    for (int i = 0; i < m; i++) {
      string a, b;
      cin >> a >> b;
      int x = mp[a];
      int y = mp[b];
      mp3[y * n + x] = i;
      mp4[i] = y * n + x;
      g[y][x]++;
    }
    memset(u, 0, sizeof(u));
    dfs2(0);
    bool imprimiu = false;
    vector<int> r;
    while (!pilhona.empty()) {
      int at = pilhona.top();
      pilhona.pop();
      int y = at / n;
      int x = at % n;
      g[y][x]--;
      memset(u, 0, sizeof(u));
      us = 0;
      dfs(0);
      if (us < n) r.pb(mp3[at]);
      g[y][x]++;
    }
    if (r.size() == 0)
      cout << "Nenhuma" << endl;
    else {
      sort(r.begin(), r.end());
      for (int i = 0; i < r.size(); i++) {
        int g = mp4[r[i]];
        cout << mp2[g % n] << " " << mp2[g / n] << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
