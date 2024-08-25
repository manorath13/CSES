// https://cses.fi/problemset/task/2216

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
#define mp make_pair
 
void solve() {
   
   int n;
   cin>>n;
   vi a(n);
  map<int,int> mp;
   for(int i=0;i<n;++i){
       cin>>a[i];
       mp[a[i]]=i;
   }
  mp[0]=-1;
  int ans = 1;
 
  for(int i=1;i<=n;++i){
    ans+= (mp[i]<mp[i-1]);
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
	#endif
    int T = 1;
    int x = 1;
    //std::cin >> T;
    while(T--) {
        // cout<<"Case #"<<x<<": ";
        // x++;
        solve();
    }
    return 0;
}
