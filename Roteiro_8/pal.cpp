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
  int t = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    string s;
    cin >> s;
    vector<vector<bool> > dp(n + 1, vector<bool>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = true;
    for (int i = n; i >= 1; i--) {
      for (int j = i + 1; j <= n; j++) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i + 1][j - 1];
          if (j - i <= 2) dp[i][j] = 1;
        }
      }
    }
    vector<int> cu(n+1,INF);
    cu[0]=0;
    for(int i=1;i<=n;i++){
      cu[i]=cu[i-1]+1;
      for(int j=0;j<=i;j++){
        if(dp[j][i]){
          cu[i]=min(cu[i],cu[j-1]+1);
        }
      }
    }
    cout << "Teste " << t << endl;
    t++;
    cout<<cu[n]<<endl;
    cout << endl;
  }

return 0;
}
