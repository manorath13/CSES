// https://cses.fi/problemset/task/1133/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define MOD 1000000007
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define pb push_back
#define ss second
#define ff first
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define frr(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define setbits(x) __builtin_popcountll(x)
#define minel(a) *min_element(all(a))
#define maxel(a) *max_element(all(a))
#define sumall(a) accumulate(all(a), 0ll)

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
template <class T> void _print(T t){cerr << t <<" ";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<nl;}
//////////////////////////////////////////

const int N = (int)2e5 + 1, INF = LLONG_MAX;

vector<vector<int>> g;
int dpc[N],dpp[N],dpn[N];//child,parent,count of child in subtree
int n;
void dfs1(int r, int p){
  for(auto &c : g[r]){
    if(c==p) continue;
    dfs1(c,r);
    dpn[r]+= 1+dpn[c];
    dpc[r]+= 1+dpn[c]+dpc[c];
  }
    
  
}
void dfs2(int r, int p){
  for(auto &c : g[r]){
    if(c==p) continue;
    dpp[c] = dpp[r]+dpc[r]-(dpc[c]+dpn[c]+1)+(n-dpn[c]-1);
    dfs2(c,r);
  }
}
void solve() {
  cin>>n;
  g = vector<vi>(n+1);
  for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs1(1,0);
  dfs2(1,0);
  for(int i=1;i<=n;++i)cout<<(dpc[i]+dpp[i])<<' ';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt", "w", stderr);
  #endif
  int T = 1, x = 1;;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
