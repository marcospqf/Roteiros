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
#define pb(a) push_back(a)
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int main()
{
  while (true) {
    string s;
    vector<int> v;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B') v.pb(0);
      if (s[i] == 'S') v.pb(1);
      if (s[i] == 'C') v.pb(4);
      if (s[i] == 'F') v.pb(5);
    }
    if (cin.eof()) break;
    stack<int> p;
    int r = 0;
    for (int i = 0; i < v.size(); i++) {
      if (p.empty())
        p.push(v[i]);
      else {
        int topo = p.top();
        if (abs(topo - v[i]) == 1)
          p.pop(), r++;
        else
          p.push(v[i]);
      }
    }
    cout << r << endl;
  }

  return 0;
}
