// https://cses.fi/problemset/task/1668

// Bipartite graph

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
 
 
 
void solve(){
  
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  
  vector<int> ans(n,0);
  unordered_set<int> s;
  queue<int> q;
  for(int i=0;i<n;++i) s.insert(i);
  while(!s.empty()){
  int f = *s.begin();
  s.erase(s.begin());
  ans[f]=1;
  q.push(f);
    while(!q.empty()){
      int x = q.front();
      q.pop();
      s.erase(x);
      for(auto c : g[x]){
        if(ans[c]==0) q.push(c);
        if(ans[c]==ans[x]){
          // cout<<c<<" "<<x<<" "<<ans[x];
          cout<<"IMPOSSIBLE";
          return;
        }
        if(ans[c]==0){
          if(ans[x]==1){
            ans[c]=2;
          }
          else{
            ans[c]=1;
          }
        }
        
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
