// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define MOD 1000000007
#define ff              first
#define ss              second
#define pb              push_back
#define eb              emplace_back
 
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define all(v)          v.rbegin(),v.rend()
typedef long long ll;
void solve() {
    int n,m;
	cin>>n>>m;
	vi a(n);
	map<int,int> mp;
	for(int i=0;i<n;++i){ 
	cin>>a[i];
	mp[a[i]]++;
	}
	 
	vi ans(m);
	for(int i=0;i<m;++i){
		int b;
		cin>>b;
		if(mp.empty()){
			ans[i] = -1;
			continue;
		}
        auto it = mp.lower_bound(b);
		//cout<<it->first<<" ";
		if(it!=mp.end()&&(it->first!=b&&it==mp.begin())){
			ans[i] = -1;
			continue;
		}
		if(it!=mp.end()&&it->first==b){
			ans[i]=it->first;
			it->second--;
			if(it->second==0){
				mp.erase(it);
			}
		}
		else{
			it--;
            ans[i]=it->first;
            
			it->second--;
			if(it->second==0){
				mp.erase(it);
			}
		}
		
	}
	for(int i=0;i<m;++i){
		cout<<ans[i]<<endl;
	}
 
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
 
