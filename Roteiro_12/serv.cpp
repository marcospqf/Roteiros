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
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define imprime(v)                                        \
  for (int X = 0; X < v.size(); X++) cout << v[X] << " "; \
  cout << endl;
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) cout << v[X][Y] << " "; \
    cout << endl;                                                 \
  }
#define endl "\n"
#define ld long double
using namespace std;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
typedef long long int ll;
int custo[101];
double v[101];
double dp[101][1001];
int main()
{
  BUFF;
  int n, c;
  while (true) {
    cin >> n >> c;
    if (n == 0 and c == 0) break;
    if(cin.eof()) break;
    for (int i = 0; i < n; i++) cin >> custo[i] >> v[i];
    for(int j=0;j<=n;j++) 
      for(int i=0;i<=c;i++) 
        dp[j][i]=0;
    for(int i=0;i<=c;i++) dp[0][i]=1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= c; j++) {
        double cu2=1;
        for (int k = 1;; k++) {
          cu2*=v[i-1];
          if (j - k*custo[i-1] < 0) break;
          dp[i][j] = max(dp[i][j], dp[i - 1][j - k*custo[i-1]] * (1 - cu2));
        }
      }
    }
    cout <<setprecision(3)<<fixed<< dp[n][c] << endl;
  }
  return 0;
}
