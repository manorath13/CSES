// https://cses.fi/problemset/task/1094

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
 
 
 
void solve() {
  
  int n;
  cin>>n;
  vi a(n);
  for(int i=0;i<n;++i) cin>>a[i];
  int ans = 0;
  for(int i=0;i<n-1;++i){
      if(a[i+1]<a[i]){
        ans+= a[i]-a[i+1];
        a[i+1] = a[i];
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