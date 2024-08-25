// https://cses.fi/problemset/result/6224324/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define ff              first
#define ss              second
#define pb              push_back
#define eb              emplace_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef long long ll;
 
 
 
void solve() {
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int dp[k+1];
   // memset(dp,2*k,sizeof(dp));
   for(int i=0;i<=k;++i) dp[i]=2*k;
    dp[0]=0;
    
    for(int i=1;i<=k;++i){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0)
            dp[i] = min(dp[i],1+dp[i-v[j]]);
           // cout<<dp[i]<<" ";
        }
    }
    if(dp[k]==2*k) dp[k]=-1;
    cout<<dp[k];
}
	
    
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
	
	int T =  1;
    
	//std::cin>> T;
	while(T--){
	   solve();
	}
	
	return 0;
}
