// https://cses.fi/problemset/task/1068

#include<iostream>
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
 
 
 
void solve(){
       long long n;
	   cin>>n;
	   cout<<n<<" ";
	   while(n!=1){
		if(n&1)
		  n = 3*n+1;
		else
		  n = n/2;
		cout<<n<<" ";
	   }
       
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
