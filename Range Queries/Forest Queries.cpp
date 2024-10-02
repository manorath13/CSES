// https://cses.fi/problemset/task/1652/

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define int long long
#define MOD 1000000007
#define cy cout << "Yes\n"
#define cn cout << "No\n"
#define pb push_back
#define ss second
#define ff first
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fr(i, a, b) for (ll i = (a); i < (ll)(b); ++i)
#define frr(i, a, b) for (ll i = (a); i >= (ll)(b); --i)
#define setbits(x) __builtin_popcountll(x)
#define minel(a) *min_element(all(a))
#define maxel(a) *max_element(all(a))
#define sumall(a) accumulate(all(a), 0ll)

////////////////////////////////////

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
    for (auto &x : a)
        is >> x;
    return is;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    for (const auto &x : a)
        os << x << ' ';
    return os;
}

template <class T> 
void _print(T t) { 
    cerr << t << " "; 
}

template <class T> 
void _print(vector<T> v) { 
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]" << nl;
}

//////////////////////////////////////////

const int N = (int)1e5 + 1, INF = (int)1e18+1;


void solve() {
  int n,q;
  cin>>n>>q;
  vector<string> s(n);
  vector<vector<int>> pre(n+1,vi(n+1));
  fr(i,0,n) cin>>s[i];
  fr(i,0,n){
    fr(j,0,n){
        if(s[i][j]=='*') pre[i+1][j+1]=1;
        pre[i+1][j+1]+= pre[i][j+1]+pre[i+1][j]-pre[i][j];
    }
  }
  while(q--){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    int ans = pre[l2][r2]-pre[l1-1][r2]-pre[l2][r1-1]+pre[l1-1][r1-1];
    cout<<ans<<nl;
  }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
