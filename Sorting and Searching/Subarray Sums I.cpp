// https://cses.fi/problemset/task/1660/
// sliding window

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define nl '\n'
#define MOD 1000000007
#define cy cout << "YES\n"
#define cn cout << "NO\n"
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
#define setbits(x) __builtin_popcountll(x)
#define minel(a) *min_element(all(a))
#define maxel(a) *max_element(all(a))
#define sumall(a) accumulate(all(a),0ll)

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


const int N = (int)2e5 + 1;

void solve() {
    int n,x;
    cin>>n>>x;
    vi a(n);
    cin>>a;
    int ans = 0;
    int i=0;
    int s = 0;
    fr(j,0,n){
        s+= a[j];
        while(s>x && i<=j){
            s-= a[i];
            i++;
        }
        if(s==x) ans++;
    }

    cout<<ans<<nl;


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}




