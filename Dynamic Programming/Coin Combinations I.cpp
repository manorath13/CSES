// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define all(v)          v.rbegin(),v.rend()
typedef long long ll;
int dp[1000005];
int helper(vi& a,int x){
       if(x==0){
		return 1;
	   }
	   if(dp[x]!=-1) return dp[x];
	   int ans = 0;
	   for(int i=0;i<a.size();++i){
		if(x-a[i]>=0){
			ans+=helper(a,x-a[i]);
			ans%=MOD;
		}
		else break;
	   }
 
	   return dp[x]=ans;
}
void solve() {
    int n,x;
	cin>>n>>x;
	vi a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a.begin(),a.end());
    memset(dp,-1,sizeof(dp));
	int ans = helper(a,x);
 
	cout<<ans<<endl;
 
 
}
	
    
int32_t main() {
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
