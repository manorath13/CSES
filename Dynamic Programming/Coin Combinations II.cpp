// https://cses.fi/problemset/task/1636

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
   
   int n,k;
   cin>>n>>k;
  vector<int> prevdp(k+1,0);
 
   vi a(n);
   for(int i=0;i<n;++i) cin>>a[i];
   sort(a.begin(),a.end());
 
   for(int i=0;i<n;++i){
    vector<int> dp(k+1,0);
    for(int j=0;j<=k;++j){
      dp[0]=1;
      int ntake = prevdp[j];
      int take = 0;
      if(j-a[i]>=0){
          take = dp[j-a[i]];
      }
      dp[j] = (ntake+take)%MOD;
    }
    prevdp = dp;
   }
 
 
   cout<<prevdp[k];
 
 
 
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

 //int dp[105][100005];
// int helper(int ind,vi &a,int k,int n){
//           if(ind==n){
//            if(k==0){
//             return 1;
//            }
//            return 0;
//           }
//           if(k==0) return 1;
 
//          // if(dp[ind][k]!=-1) return dp[ind][k];
 
//          int ans = 0;
//          if(k-a[ind]>=0){
//           ans+= helper(ind,a,k-a[ind],n);
//           ans%=MOD;
//           ans+= helper(ind+1,a,k,n);
//           ans%=MOD;
//          }  
 
//          ans%=MOD;
 
//         // return dp[ind][k]=ans;
// }
