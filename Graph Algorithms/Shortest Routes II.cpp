// https://cses.fi/problemset/task/1672

//Floyd Warshall
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
  
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int>> g(n,vector<int>(n,INF));
  for(int i=0;i<n;++i) g[i][i] = 0;
  for(int i=0;i<m;++i){
      int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      g[a][b]=min(c,g[a][b]);
      g[b][a]=min(c,g[b][a]);
  }
  for(int k=0;k<n;++k){
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
  while(q--){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int ans = g[a][b]>=INF ? -1 : g[a][b];
    cout<<ans<<nl;
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
    //  cout<<"Test Case #"<<x<<":"<<endl;x++;
      solve();
  }
  return 0;
