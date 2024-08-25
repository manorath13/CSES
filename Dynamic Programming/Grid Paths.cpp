// https://cses.fi/problemset/task/1638

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
  vector<vector<int> > dp(n,vector<int>(n,0));
   vector<vector<char> > a(n,vector<char>(n));
   for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin>>a[i][j];
    }
   }
  
  for(int i=0;i<n;++i){
    if(a[i][0]=='.'){
      dp[i][0]=1;
    }
    else break;
  }
  for(int i=0;i<n;++i){
    if(a[0][i]=='.'){
      dp[0][i]=1;
    }
    else break;
  }
   
   for(int i=1;i<n;++i){
    for(int j=1;j<n;++j){
      
      
        if(a[i][j]=='.')
        dp[i][j] = dp[i-1][j]+dp[i][j-1];
        dp[i][j]%=MOD;
      
    }
   }
   cout<<dp[n-1][n-1];
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
