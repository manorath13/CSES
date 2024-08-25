// https://cses.fi/problemset/task/1671

//Dijkstra
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define pb push_back
#define ss second
#define ff first
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define frr(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define setbits(x)      __builtin_popcll(x)
#define minel(a) *min_element(all(a))
#define maxiel(a) *max_element(all(a))
 
////////////////////////////////////
 
template <class T>
istream &operator>>(istream &is, vector<T> &a)
{
  for (auto &x : a)
    is >> x;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a)
{
  for (const auto &x : a)
    os << x << ' ';
  return os;
}
//////////////////////////////////////////
 
const int INF = 1e18;
 
void solve(){
  
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> g(n);
  for(int i=0;i<m;++i){
    int a,b,w;
    cin>>a>>b>>w;
    a--;b--;
    g[a].pb({b,w});
    // g[b].pb({a,w});
  }
  vector<int> ans(n,INF);
  ans[0]=0;
  // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
  set<pii> p;
  vector<bool> vis(n,false);
  p.insert({0,0});
  while(!p.empty()){
    auto t = *p.begin();
    p.erase(p.begin());
    int x = t.ff;
    int c = t.ss;
    if(vis[c]) continue;
    vis[c] = true;
    for(auto &i : g[c]){
      if(x+i.ss<ans[i.ff]){
        // cout<<c<<" "<<i.ff<<" "<<x+i.ss<<" "<<ans[i.ff]<<nl;
        ans[i.ff] = x+i.ss;
        p.insert({ans[i.ff],i.ff});
      }
 
    }
  }
  cout<<ans;
}
 
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cout.tie(0);
    #ifndef ONLINE_JUDGE
   freopen("./input.txt","r",stdin);
   freopen("./output1.txt","w",stdout);
  #endif
 
  int T = 1,x=1;
  // cin >> T;
  while(T--){
    //  cout<<"Test Case #"<<x<<":"<<endl;x++;
      solve();
  }
  return 0;
}
