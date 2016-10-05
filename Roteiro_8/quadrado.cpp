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
#define mp make_pair
#define pb push_back
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
const ll M = 1000004099;
const ll B = 1231;
int n, m;
vector<pair<int, int> > r;
ll int_mod(ll a, ll b) { return a; }
ll eleva(ll a, ll b, ll mod)
{
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  ll x = eleva(a, b / 2, mod);
  if (b % 2 == 0)
    return (x * x);
  else
    return (a * ((x * x)));
}

ll anda_coluna(char text[][1000], int lin, int col, ll ht)
{
  ll aux = 0;
  for (ll i = 0; i < m; i++) {
    ll E = eleva(B, m * m - 1 - i * m, M);
    int deb = m * m - 1 - i * m;
    ht = int_mod(ht - int_mod(text[lin - m + i + 1][col - m] * E, M), M);
    ll F = eleva(B, m * m - m - i * m, M);
    int bug = m * m - m - i * m;
    aux = int_mod(aux + int_mod(text[lin - m + i + 1][col] * F, M), M);
  }
  ht = int_mod(ht * B, M);
  ht = int_mod(ht + aux, M);
  return ht;
}

ll anda_linha(char text[][1000], int lin, int col, ll ht)
{
  ll aux = 0;
  for (ll i = 0; i < m; i++) {
    ll E = eleva(B, m * m - 1 - i, M);
    ht = int_mod(ht - int_mod(text[lin - m][col + i] * E, M), M);
    aux = int_mod(aux * B, M);
    aux = int_mod(aux + text[lin][col + i], M);
  }
  ht = int_mod(ht * B, M);
  ht = int_mod(ht * B, M);
  ht = int_mod(ht + aux, M);
  return ht;
}

void Rabin_karp(char text[][1000], char pattern[][60])
{
  ll hp = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) hp = int_mod(hp * B + pattern[i][j], M);
  ll ht = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) ht = int_mod(ht * B + text[i][j], M);
  if (ht == hp) r.pb(mp(0, 0));
  ll aux;
  for (int i = m - 1; i < n; i++) {
    aux = ht;
    for (int j = m - 1; j < n - 1; j++) {
      ht = anda_coluna(text, i, j + 1, ht);
      if (ht == hp) r.pb(mp(j - m + 2, i - m + 1));
    }
    if (i + 1 < n) {
      ht = anda_linha(text, i + 1, 0, aux);
      if (ht == hp) r.pb(mp(i - m + 1, 0));
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  int t = 1;
  char v[1000][1000];
  char v2[60][60];
  while (true) {
    cin >> n >> m;
    if (cin.eof()) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> v[i][j];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) cin >> v2[i][j];
    r.clear();
    Rabin_karp(v, v2);
    cout << "Instancia " << t << endl;
    t++;
    if (r.size() == 0)
      cout << "nenhuma ocorrencia"<<endl;
    else {
      sort(r.begin(), r.end());
      for (int i = 0; i < r.size(); i++)
        cout << r[i].second << " " << r[i].first << endl;
      cout << endl;
    }
  }
  return 0;
}
