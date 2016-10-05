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
int n, m;
int b[1000001];
vector< pair<int,int> > r;
bool diferentao(char pattern[][60], int lin1, int lin2)
{
  for (int i = 0; i < m; i++)
    if (pattern[i][lin1] != pattern[i][lin2]) return true;
  return false;
}
void kmpPreprocess(char pattern[][60])
{
  int i = 0, j = -1;
  b[0] = -1;
  while (i < m) {
    while (j >= 0 and diferentao(pattern, i, j)) j= b[j];
    i++, j++;
    b[i] = j;
  }
}

bool dif(char text[][1000], int lin, int col1,char pattern[][60], int col2)
{
  for(int i=0;i<m;i++)
   if(text[lin+i][col1]!=pattern[i][col2]){
     return true;
    }
   return false;
}
void kmpSearch(char pattern[][60], char text[][1000])
{
  kmpPreprocess(pattern);
  int i = 0, j = 0, lin = 0;
  while (lin <= n-m) {
    while (i < n) {
      while (j >= 0 and dif(text,lin,i,pattern,j)) {
        j = b[j];
      }
      i++, j++;
      if (j == m) {
        r.push_back(make_pair(i-j,lin));
        j = b[j];
      }
    }
    lin++, i=0, j=0;
  }
}
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t=1;
  char v[1000][1000];
  char v2[60][60];
  while (true) {
    cin >> n >> m;
    if(cin.eof()) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> v[i][j];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) cin >> v2[i][j];
    r.clear();
    kmpSearch(v2,v);
    cout<<"Instancia "<<t<<endl;
    t++;
    if(r.size()==0)
      cout<<"nenhuma ocorrencia"<<endl;
    else{
      sort(r.begin(), r.end());
      for(int i=0;i<r.size();i++)
        cout<<r[i].second<<" "<<r[i].first<<endl;
    }
    cout<<endl;
  }  
  return 0;
}
