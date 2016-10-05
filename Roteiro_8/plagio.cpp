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
#define imp(v)                                            \
  for (int i = 0; i < v.size(); i++) cout << v[i] << " "; \
  cout << endl;
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
const ll M = 1000004099;
const ll B = 33;
ll int_mod(ll a, ll b) { return (a % b + b) % b; }
ll eleva(ll a, ll b, ll mod)
{
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  ll x = eleva(a, b / 2, mod);
  if (b % 2 == 0)
    return (x * x) % mod;
  else
    return (a *( (x * x) % mod)) % mod;
}
bool Rabin_karp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  if (n < m) return false;
  ll hp = 0;
  for (int i = 0; i < m; i++) hp = int_mod(hp * B + pattern[i], M);
  ll ht = 0;
  for (int i = 0; i < m; i++) ht = int_mod(ht * B + text[i], M);
  if (ht == hp) return true;
  ll E = eleva(B, m - 1, M);
  for (int i = m; i < n; i++) {
    ht = int_mod(ht - int_mod(text[i - m] * E, M), M);
    ht = int_mod(ht * B, M);
    ht = int_mod(ht + text[i], M);
    if (ht == hp) return true;
  }
  return false;
}

int main()
{
  map<string, int> mp;
  mp["A"] = 0;
  mp["A#"] = 1;
  mp["Bb"] = 1;
  mp["B"] = 2;
  mp["Cb"] = 2;
  mp["C"] = 3;
  mp["B#"] = 3;
  mp["Db"] = 4;
  mp["C#"] = 4;
  mp["D"] = 5;
  mp["D#"] = 6;
  mp["Eb"] = 6;
  mp["E"] = 7;
  mp["Fb"] = 7;
  mp["F"] = 8;
  mp["E#"] = 8;
  mp["F#"] = 9;
  mp["Gb"] = 9;
  mp["G"] = 10;
  mp["Ab"] = 11;
  mp["G#"] = 11;
  int n, m;
  string a, b;
  while (true) {
    a.clear(), b.clear();
    cin >> n >> m;
    if (m == 0 and n == 0) break;
    vector<int> creuza, francylene;
    for (int i = 0; i < n; i++) {
      string c;
      cin >> c;
      creuza.pb(mp[c]);
    }
    for (int i = 0; i < m; i++) {
      string c;
      cin >> c;
      francylene.pb(mp[c]);
    }
    if (n == 1 or m == 1)
      cout << "N" << endl;
    else {
      string dif;
      string dif2;
      for (int i = 0; i < n - 1; i++) {
        char c = ((creuza[i + 1] - creuza[i] + 12) % 12 + 'l');
        dif += c;
      }
      for (int i = 0; i < m - 1; i++) {
        char c = ((francylene[i + 1] - francylene[i] + 12) % 12 + 'l');
        dif2 += c;
      }
      if (Rabin_karp(dif, dif2))
        cout << "S" << endl;
      else
        cout << "N" << endl;
    }
  }
  return 0;
}
