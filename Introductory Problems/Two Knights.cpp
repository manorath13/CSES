// https://cses.fi/problemset/task/1072

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
 
 
 
void solve() {
   int n;
   cin>>n;
   int x = 0,t=0;
   cout<<0<<endl;
   for(int i=2;i<=n;++i){
       int s = i*i;
       int ans = (s*(s-1))/2 -(8*t);
       cout<<ans<<endl;
       x++;
       t+=x;
   }
    
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
    int T = 1;
   // std::cin >> T;
    while(T--) {
        
        solve();
    }
    return 0;
}