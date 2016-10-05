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
int b[100005];
int n;
void kmpPreprocess(char *pattern)
{
  int i = 0, j = -1;
  b[0] = -1;
  while (pattern[i] != '\0') {
    while (j >= 0 and pattern[i] != pattern[j]) j = b[j];
    i++, j++;
    b[i] = j;
  }
  n = i;
}

int main()
{
  char text[100001];
  while (true) {
    scanf("%s", text);
    if (text[0] == '*') break;
    kmpPreprocess(text);
    int ult = -1;
    for (int i = 0; i <= n; i++) {
//      cout<<b[i]<<" ";
      if (b[i] == 0) ult = i;
    }
    cout<<endl;
    if(n%ult==0) cout<<n/ult<<endl;
    else cout<<1<<endl;
  }
  return 0;
}
