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
#define pri(x) printf("%d", x)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define ii pair<int, int>
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
using namespace std;
string fib[5001];
void zero_esq(string &resp)
{
  string retorno = resp;
  reverse(retorno.begin(), retorno.end());
  int i = resp.size() - 1;
  while (retorno[i] == '0' and i > 0) {
    retorno.erase(i);
    i--;
  }
  reverse(retorno.begin(), retorno.end());
  resp = retorno;
}

string sum_big(string a, string b)
{
  string resp;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a.size() <= b.size()) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
      int x = b[i] - '0' + a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = a.size(); i < b.size(); i++) {
      int x = b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  else {
    int carry = 0;
    for (int i = 0; i < b.size(); i++) {
      int x = a[i] - '0' + b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = b.size(); i < a.size(); i++) {
      int x = a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  reverse(resp.begin(), resp.end());
  zero_esq(resp);
  return resp;
}

int main()
{
  fib[0] = "0";
  fib[1] ="1";
  for (int i = 2; i < 5001; i++) {
    fib[i] = sum_big(fib[i - 1],fib[i - 2]);
  }
  while (1) {
    int n;
    cin >> n;
    if (cin.eof()) break;
    cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
  }
  return 0;
}
