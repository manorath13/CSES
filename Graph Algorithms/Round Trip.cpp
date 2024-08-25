// https://cses.fi/problemset/task/1669

// Cycle detection and path
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
 
int p;
 
bool cycle(int par, int ch, vector<vector<int>> &g, vector<bool> &vis){
 
 vis[ch] = true;
   
 bool a = false;
 for(auto &i : g[ch]){
  if(i!=par){
    if(vis[i]){
    //finding where the cycle node is	
      p=i;
      return true;
    }
    a|= cycle(ch,i,g,vis);
  }
 }
 
 return a;
}
vector<int> ans;
bool dfs(int par, int c, vector<vector<int>> &g, vector<bool> &vis){
   vis[c] = true;
   bool a = false;

  for(auto &i : g[c]){
    if(i==par) continue;
    // if i is the cycle node backtrack from there
      if(i==p){
        ans.pb(c);
        return true;
      }
      bool x = false;
      if(!vis[i])
       x = dfs(c,i,g,vis);
      if(x){
        a = true;
        break;
      }
  }
  // vis[c] = false;
  if(a) ans.pb(c);
 
  return a;
 
}
 
void solve(){
  
  int n,m;
  cin>>n>>m;  
  vector<vector<int>> g(n);
  vector<bool> vis(n,false);
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }  
  
    bool c = false;
  for(int i=0;i<n;++i){
     if(!vis[i])
       c |= cycle(-1,i,g,vis);
  }
  if(!c){
    cout<<"IMPOSSIBLE";
    return;
  }
  
  for(int i=0;i<n;++i){
    vis[i] = false;
  }
  bool t = dfs(-1,p,g,vis);
  reverse(all(ans));
  ans.pb(p);
  cout<<ans.size()<<nl;
  for(auto &i : ans){
    cout<<i+1<<" ";
  }
 
 
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
      solve();
  }
  return 0;
}
