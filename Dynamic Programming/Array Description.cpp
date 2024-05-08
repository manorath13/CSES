// https://cses.fi/problemset/task/1746

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
 
 
 //int dp[105][100005];
 
 
void solve() {
   
   int n,x;
   cin>>n>>x;
 
  vector<int> a(n);
  for(int i=0;i<n;++i) cin>>a[i];
  
  vector<vector<int> > dp(n+1,vector<int>(x+1,0));
 
 if(a[0]==0){
  for(int i=1;i<=x;++i){
    dp[0][i] = 1;
  }
 }
 else{
  dp[0][a[0]]=1;
 }
 
  for(int i=1;i<n;++i){
    if(a[i]==0){
    for(int j=1;j<=x;++j){
      int curr = dp[i-1][j];
      int prev=0,next=0;
      if(j>1) prev = dp[i-1][j-1];
      if(j<=x-1) next = dp[i-1][j+1];
        dp[i][j]= (curr+prev+next)%MOD;
      //cout<<dp[i][j]<<" ";
    }
    }
    else{
      int j = a[i];
      int curr = dp[i-1][j];
      int prev=0,next=0;
      if(j>1) prev = dp[i-1][j-1];
      if(j<=x-1) next = dp[i-1][j+1];
        dp[i][j]= (curr+prev+next)%MOD;
      //cout<<dp[i][j]<<" ";
    }
    //cout<<endl;
  }
  int ans = 0;
  for(int i=0;i<=x;++i){
    ans+= dp[n-1][i];
    ans%=MOD;
  }
 
  cout<<ans<<endl;
 
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
        solve();
    }
    return 0;
}
