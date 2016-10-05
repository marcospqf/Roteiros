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
const int INF = 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int add(vector< vector<int> > &sum, int i,int j, int m, int n){
  int retorno=sum[m][n];
  if(j>0) retorno-=sum[m][j-1];
  if(i>0) retorno-=sum[i-1][n];
  if(i>0 and j>0) retorno+=sum[i-1][j-1];
  return retorno;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int> > ret(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ret[i][j];
    }
  }
  vector<vector<int> > sum(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum[i][j] = ret[i][j];
      if (i > 0) sum[i][j] += sum[i - 1][j];
      if (j > 0) sum[i][j] += sum[i][j - 1];
      if (i > 0 and j > 0) sum[i][j] -= sum[i - 1][j - 1];
    }
  }
  int resposta=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=i;k<n;k++){
        for(int l=j;l<n;l++){
          if(k==i and l==j) continue;
          resposta=max(resposta,add(sum,i,j,k,l));
        }
      }
    }
  }
  cout<<resposta<<endl;
  return 0;
}
