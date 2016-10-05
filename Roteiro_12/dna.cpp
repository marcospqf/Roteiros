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
int lcs[101][101];
string r;
void recupera(string &a, string &b){
  int lin=a.size();
  int col=b.size();
  while(true){
    if(lin==0 or col==0) break; 
    if(a[lin-1]==b[col-1]){
      r.pb(a[lin-1]);
      lin--,col--;
    }
    else{
      if(lcs[lin-1][col]>=lcs[lin][col-1]){
        r.pb(a[lin-1]);
        lin--;
      }
      else{
        r.pb(b[col-1]);
        col--;
      }
    }
  }
  while(lin>0){
    r.pb(a[lin-1]);
    lin--;
  }
  while(col>0){
    r.pb(b[col-1]);
    col--;
  }
}
int main()
{
  int t=1;
  while(true){
    string a,b;
    cin>>a>>b;
    if(a[0]=='#' and a.size()==1) break;
    memset(lcs,0,sizeof(lcs));
    for(int i=1;i<=a.size();i++){
      for(int j=1;j<=b.size();j++){
        if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
        else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
      }
    }
    r.clear();
    recupera(a,b);
    reverse(r.begin(),r.end());
    cout<<"Teste "<<t<<endl;
    t++;
    cout<<r<<endl<<endl; 
  }
  return 0;
}
