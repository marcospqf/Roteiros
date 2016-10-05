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

void zero_esq(string &resp){
  string retorno=resp;
  reverse(retorno.begin(), retorno.end());
  int i= resp.size()-1;
  while(retorno[i]=='0' and i>0) 
  {
    retorno.erase(i);
    i--;
  }
  reverse(retorno.begin(), retorno.end());
  resp=retorno;
}

string sum_big(string a, string b)
{
  string resp;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a.size() <= b.size()) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
      int x = b[i] - '0' + a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = a.size(); i < b.size(); i++) {
      int x = b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  else {
    int carry = 0;
    for (int i = 0; i < b.size(); i++) {
      int x = a[i] - '0' + b[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    for (int i = b.size(); i < a.size(); i++) {
      int x = a[i] - '0' + carry;
      resp.push_back((char)(x % 10 + '0'));
      carry = x / 10;
    }
    if (carry > 0) resp.push_back((char)(carry + '0'));
  }
  reverse(resp.begin(), resp.end());
  zero_esq(resp);
  return resp;
}

string mul_big(string a, string b)
{
  string resp;
  resp.push_back('0');
  string temp;
  int carry = 0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    temp.clear();
    for (int k = 0; k < i; k++) temp.push_back('0');
    int x = a[i] - '0';
    for (int j = 0; j < b.size(); j++) {
      int y = b[j] - '0';
      int novo = (x * y + carry);
      temp.push_back((novo % 10) + '0');
      carry = novo / 10;
    }
    if (carry > 0) temp.push_back(carry + '0');
    reverse(temp.begin(), temp.end());
    carry = 0;
    resp = sum_big(temp, resp);
  }
  zero_esq(resp);
  return resp;
}

int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  vector<string> dp(151);
  dp[0].push_back('1');
  dp[1].push_back('1');
  for (int i = 2; i <= 150; i++) {
    dp[i].push_back('0');
    string s;
    for (int j = 0; j < i; j++) {
      string s=mul_big(dp[j], dp[i-j-1]);
      dp[i]=sum_big(s,dp[i]);
    }
  }
  while(true){
    int n;
    cin>>n;
    if(n==-1) break;
    cout<<dp[n]<<endl;
  }
  return 0;
}
