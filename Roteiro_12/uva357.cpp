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
#define double long double
using namespace std;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
typedef long long int ll;
ll dp[30001][5];
int main()
{
  memset(dp, 0, sizeof(dp));
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
  ll v[] = {1, 5, 10, 25, 50};
  for (int i = 0; i < 30001; i++) dp[i][0] = 1;
  for (int j = 1; j < 5; j++) {
    for (int i = 0; i < 30001; i++) {
      dp[i][j] = dp[i][j - 1];
      if (i - v[j] >= 0) dp[i][j] += dp[i - v[j]][j];
//      cout<<dp[i][j]<<" ";
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (cin.eof()) break;
    if(dp[n][4]==1)
    cout << "There is only "<<dp[n][4]<<" way to produce "<<n<<" cents change."<< endl;
    else
    cout << "There are "<<dp[n][4]<<" ways to produce "<<n<<" cents change."<< endl;
  }
  return 0;
}
