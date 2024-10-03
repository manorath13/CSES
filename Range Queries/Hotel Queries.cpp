// https://cses.fi/problemset/task/1143/

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

const int N = (int)1e4 + 1, INF = (int)1e18+1;

class SegmentTree{
  public:
  int n;
  vi a,tree;
  SegmentTree(vi &a){
    n = a.size();
    this->a = a;
    tree.resize(4*n);
  }
  void build(int ind, int l, int h){
    if(l==h){
      tree[ind]=a[l];
      return;
    }
    int m = (l+h)/2;
    build(2*ind+1,l,m);
    build(2*ind+2,m+1,h);
    tree[ind] = max(tree[2*ind+1],tree[2*ind+2]);
  }
  int query(int ind, int l, int h, int x){
    if(tree[ind]<x){
      return 0;
    }
    if(l==h){
      tree[ind]-=x;
      return l+1;
    }
    int m = (l+h)/2;
    int ans;
    if(tree[2*ind+1]>=x){
      ans = query(2*ind+1,l,m,x);
    }
    else{
      ans = query(2*ind+2,m+1,h,x);
    }
    tree[ind] = max(tree[2*ind+1],tree[2*ind+2]);
    return ans;
  }
};

void solve() {
  int n,m;
  cin>>n>>m;
  vi a(n);
  cin>>a;
  SegmentTree s(a);
  s.build(0,0,n-1);
  fr(i,0,m){
    int x;
    cin>>x;
    cout<<s.query(0,0,n-1,x)<<" ";
  }

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
   
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
