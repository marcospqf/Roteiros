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
int main()
{
  int n, m;
  while (1) {
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    int tam = n + m - 1;
    tam = tam / m;
    if (tam <= 6)
      cout << "Poodle" << endl;
    else {
      if (tam > 20) tam = 20;
      tam -= 6;
      cout << "Poo";
      for (int i = 0; i < tam; i++) cout << "o";
      cout << "dle" << endl;
    }
  }
  return 0;
}
