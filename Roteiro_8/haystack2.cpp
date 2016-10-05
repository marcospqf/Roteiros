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
#define ll long long int
#define ld long double
using namespace std;
const ll M = 1000004099;
const ll B = 11797;
ll int_mod(ll a, ll mod) { return (a % mod + mod) % mod; }
ll eleva(ll a, ll b, ll mod)
{
  if (b == 0)
    return 1;
  else if (b == 1)
    return a%mod;
  ll x = eleva(a, b / 2, mod);
  x=x%mod;
  if (b % 2 == 0)
    return (x * x) % mod;
  else
    return (a * ((x * x) % mod)) % mod;
}
void Rabin_karp(string &text, string &pattern)
{
  int n = text.size();
  int m = pattern.size();
  if (n < m) return;
  ll hp = 0;
  for (int i = 0; i < m; i++) hp = int_mod(hp * B + pattern[i], M);
  ll ht = 0;
  for (int i = 0; i < m; i++) ht = int_mod(ht * B + text[i], M);
  if (ht == hp) cout<<0<<endl;;
  ll E = eleva(B, m - 1, M);
  for (int i = m; i < n; i++) {
    ht = int_mod(ht - int_mod(text[i - m] * E, M), M);
    ht = int_mod(ht * B, M);
    ht = int_mod(ht + text[i], M);
    if (ht == hp) cout<<i-m+1<<endl;
  }
}

int main()
{
  string text, pattern;
  int n;
  while (true) {
    cin >> n;
    if (cin.eof()) break;
    cin >> pattern >> text;
    Rabin_karp(text, pattern);
    cout << endl;
  }
  return 0;
}
