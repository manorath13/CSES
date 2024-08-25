// https://cses.fi/problemset/task/1090

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
#define all(v)          v.begin(),v.end()
typedef long long ll;
 
void solve() {
    int n,x;
	cin>>n>>x;
	vi a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	
	sort(all(a)); 
	int ans = 0;
	int i=0,j=n-1;
	while(i<=j){
		if(a[i]+a[j]<=x){
			ans++;i++;j--;
		}
		else{
			ans++;
			j--;
		}
	}
 
	cout<<ans<<endl;
 
}
	
    
int main() {
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
