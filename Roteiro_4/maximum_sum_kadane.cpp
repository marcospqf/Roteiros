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
int kadane(vector<int>&v){
  int resp=0, retorno=0;;
  for(int i=0;i<v.size();i++){
    if(resp+v[i]<0) resp=0;
    else {
      resp+=v[i];
      retorno=max(retorno,resp);
    }
  }
  return retorno;
}
int main()
{ while(true){
  int n;
  cin >> n;
  if(cin.eof()) break;
  vector<vector<int> > ret(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ret[i][j];
    }
  }
  vector<int> temp(n,0);
  int resposta=-INF;
  for(int i=0;i<n;i++){
    for(int k=0;k<n;k++) temp[k]=0;
    for(int j=i;j<n;j++){
      for(int k=0;k<n;k++){
         temp[k]+=ret[j][k];
      }
      resposta=max(kadane(temp),resposta);
    }
  }
  cout<<resposta<<endl;
             }
  return 0;
}
