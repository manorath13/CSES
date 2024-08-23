// https://cses.fi/problemset/task/1642

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
    int n,k;
    cin>>n>>k;
    vector<pii> a(n);
    fr(i,0,n){
        int x;
        cin>>x;
        a[i] = {x,i+1};
    }
    sort(all(a));
    if(n<4){
        cout<<"IMPOSSIBLE";
        return;
    }
    fr(i,0,n-3)fr(j,i+1,n-2){
        int rem = k-a[i].ff-a[j].ff;
        if(rem<0) break;
        int l=j+1,r=n-1;
        while(l<r){
            int s = a[l].ff+a[r].ff;
            if(s==rem){
                cout<<a[i].ss<<" "<<a[j].ss<<" "<<a[l].ss<<" "<<a[r].ss;return;
            }
            if(s>rem){
                r--;
            }
            else{
                l++;
            }
        }
    }
 
    cout<<"IMPOSSIBLE";
 
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
