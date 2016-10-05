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
#define ii pair<int, int>
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
const long double pi = acos(-1);
typedef long long int ll;
typedef long double ld;
using namespace std;
struct node {
  bool isleaf;
  map<char, node*> son;
  node() { isleaf = false; }
};
class trie {
 private:
  node *root;

 public:
  trie() { root = new node(); }
  void insert(string s)
  {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
      if (cur->son.count(s[i]) == 0)
        cur->son[s[i]] = new node();
      cur = cur->son[s[i]];
    }
    cur->isleaf = true;
  }
  int confere(string s)
  {
    node *cur = root;
    int retorno = 0;
    for (int i = 0; i < s.size(); i++) {
      if(i==0) retorno++;
      else if (cur->isleaf or cur->son.size() > 1)
        retorno++;
      cur = cur->son[s[i]];
    }
    return retorno;
  }
  void clear(node *atual)
  {
    map<char, node *>::iterator it;
    if (atual->son.size() > 0) {
      for (it = atual->son.begin(); it != atual->son.end(); ++it) {
        clear(it->second);
      }
    }
    atual->son.clear();
    delete atual;
  }
  ~trie(){
    clear(root);
  }
};
int main()
{
  int n;
  while (true) {
  trie t;
    cin >> n;
    if (cin.eof()) break;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      t.insert(s[i]);
    }
    int nop = 0;
    for (int i = 0; i < n; i++) {
      nop += t.confere(s[i]);
    }
    cout << fixed << setprecision(2) << (double)nop / (double)n << endl;
  }
  return 0;
}
