// https://cses.fi/problemset/task/1734/

// Mo's Algorithm

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

const int N = (int)2e5+2, INF = (int)1e18+1;

int n,q;
int b;
struct Q{
    int l,r,id;

    bool operator<(const Q &y) const{
        if(y.l/b==l/b){
            return r<y.r;
        }
        return l/b<y.l/b;
    }
};


void solve() {
    cin>>n>>q;
    vi a(n);
    int c=1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(mp.find(x)!=mp.end()){
            a[i]=mp[x];
        }
        else{
            a[i]=c;
            mp[x]=c;
            c++;
        }
    }
    mp.clear();
    b = sqrtl(n);
    vector<Q> qs(q);
    for(int i=0;i<q;++i){
        cin>>qs[i].l>>qs[i].r;
        qs[i].l--;qs[i].r--;
        qs[i].id=i;
    }
    sort(all(qs));
    int cl=0,cr=-1,s=0;
    vi ans(q);
    vi m(N+1);
    for(int i=0;i<q;++i){
        while(cr<qs[i].r){
            cr++;
            if(m[a[cr]]!=0) s--;
            m[a[cr]]++;
            if(m[a[cr]]!=0) s++;
        }
        while(cl>qs[i].l){
            cl--;
            if(m[a[cl]]!=0) s--;
            m[a[cl]]++;
            if(m[a[cl]]!=0) s++;
        }
        while(cl<qs[i].l){
            if(m[a[cl]]!=0) s--;
            m[a[cl]]--;
            if(m[a[cl]]!=0) s++;
            cl++;
        }
        while(cr>qs[i].r){
            if(m[a[cr]]!=0) s--;
            m[a[cr]]--;
            if(m[a[cr]]!=0) s++;
            cr--;
        }
        ans[qs[i].id]=s;
    }
   cout<<ans;
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
