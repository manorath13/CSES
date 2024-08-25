// https://cses.fi/problemset/task/1637

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
  vi dp(n+1,INT_MAX);
 
  dp[0]=0;
 
  for(int i=1;i<=n;++i){
    int t = i;
    while(t>0){
      dp[i] = min(dp[i],dp[i-(t%10)]+1);
      t/=10;
    }
  }
  
  cout<<dp[n];
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
