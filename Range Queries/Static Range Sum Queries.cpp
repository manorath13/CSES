// https://cses.fi/problemset/task/1646

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
 
void solve() {
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vi pre(n,0);
    pre[0]=a[0];
    for(int i=1;i<n;++i) pre[i] = pre[i-1]+a[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans = pre[r-1]-pre[l-2];
        if(l==1) ans = pre[r-1];
        cout<<ans<<endl;
    }
    
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
    int T = 1;
   // std::cin >> T;
    while(T--) {
        
        solve();
    }
    return 0;
}