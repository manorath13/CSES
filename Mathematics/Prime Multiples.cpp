// https://cses.fi/problemset/task/2185

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
#define setbits(x) __builtin_popcount(x)
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

const int N = (int)1e5, INF = (int)1e13;

void solve() {
    int n,k;
    cin>>n>>k;
    vi a(k);
    cin>>a;
    int ans =0;
    for(int i=1;i<(1<<k);++i){
            int m=1,ms=0;
            int f = 0;
            for(int j=0;j<k;++j){
                if(1&(i>>j)){
                    if(m> n/a[j]){
                        f = 1;
                        break;
                    }
                    m*=a[j];
                    ms++;
                }
            }
            if(m<=0 || f) continue;
            if(ms%2==0){
                ans-= (n/m);
            }
            else{
                ans+= (n/m);
            }
        }
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
  int T = 1, x = 1;;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
