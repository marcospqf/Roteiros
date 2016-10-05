#include<cstring>
#include<iostream>
#include<bitset>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define ii pair<int,int> 
#define mp(a,b) make_pair(a,b);
const int INF= 0x3f3f3f3f;
#define ll long long int
#define ld long double
#define endl "\n"
using namespace std;
int n;
vector< pair<double, ii> > edge;
vector<int> pset;
void initset(int tam){
  pset.resize(tam);
  for(int i=0;i<tam;i++) pset[i]=i;
}
int findset(int i){
  if(pset[i]==i) return i;
  return pset[i]=findset(pset[i]);
}
void unionset(int i, int j){ pset[findset(i)]=findset(j);}
bool issameset(int i,int j){ return findset(i)==findset(j);}
double kruskal(){
  sort(edge.begin(), edge.end());
  initset(n);
  double mst=0;
  for(int i=0;i<edge.size();i++){
    int u=edge[i].second.first;
    int v=edge[i].second.second;
    if(!issameset(u,v)){
      unionset(u,v);
      mst=edge[i].first;
    }
  }
  return mst;
}
int main()
{
  while(true){
    cin>>n;
    if(n==0) break;
    edge.clear();
    vector<pair<double,double > > x(n);
    for(int i=0;i<n;i++) cin>>x[i].first>>x[i].second;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        double deltax=x[i].first-x[j].first;
        double deltay=x[i].second-x[j].second;
        double y= sqrt(deltax*deltax+deltay*deltay);
        ii p= mp(i,j);
        edge.push_back(make_pair(y,p));
      }
    }
    cout<<fixed<<setprecision(4)<<kruskal()<<endl;
  }
  return 0;
}
