// https://cses.fi/problemset/task/1753

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

class RollingHash {
private:
     long long BASE = 41;          
     // long long MOD = 1e9 + 9;      
    vector<long long> h;   
    vector<long long> pow;  
    string str;

public:
    // Constructor to initialize the class with the input string and precompute hash and power values.
    RollingHash(string& s){
        str = s;
        int n = str.size();
        h.resize(n + 1, 0);
        pow.resize(n + 1, 1);  

        // Precompute hash values and powers of the base
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE + str[i] - 'a' + 1) % MOD;
            pow[i + 1] = (pow[i] * BASE) % MOD;
        }
    }

    // Get the hash of a substring str[l...r] (0-indexed, inclusive)
    long long getHash(int l, int r) {
        long long hashValue = (h[r + 1] - (h[l] * pow[r - l + 1]) % MOD + MOD) % MOD;
        return hashValue;
    }

    // Helper function to check if two substrings [l1...r1] and [l2...r2] are equal
    bool compareSubstrings(int l1, int r1, int l2, int r2) {
        return getHash(l1, r1) == getHash(l2, r2);
    }
};

void solve() {
  string a,b;
    cin>>a>>b;
    RollingHash ra(a), rb(b);
    int n=a.size(), m=b.size();
    int ans = 0;
    if(m>n){
        cout<<ans<<nl;return;
    }
    int hb = rb.getHash(0,m-1);
    for(int i=m-1;i<n;++i){
        int ha = ra.getHash(i-m+1,i);
        if(ha==hb) ans++;
    }
    
    cout<<ans<<nl;

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
