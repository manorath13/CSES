// https://cses.fi/problemset/task/1164/

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


void solve() {
  int n;
  cin>>n;
  vector<array<int,3>> a(n);
  for(int i=0;i<n;++i){
    cin>>a[i][0]>>a[i][1];
    a[i][2] = i;
  }
  sort(all(a));
  vector<int> ans(n);
  set<pii> s;
  int k = 0;
  for(int i=0;i<n;++i){
    int l,r,ind;
    l = a[i][0], r = a[i][1], ind = a[i][2];
    if(s.empty()){
      k++;
      s.insert({r,k});
      ans[ind] = k;
      continue;
    }
    auto it = s.lower_bound({l,0});
    if(it==s.begin()){
      k++;
      s.insert({r,k});
      ans[ind] = k;
      continue;
    }
    it--;
    int c = (*it).ss;
    ans[ind] = c;
    s.erase(it);
    s.insert({r,c});
  }

  cout<<k<<nl;
  cout<<ans;

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
