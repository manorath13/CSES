// https://cses.fi/problemset/task/1070

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
 
 
 
void solve() {
   int n;
   cin>>n;
   if(n==1){cout<<"1";return;}
   if(n<=3){ cout<<"NO SOLUTION"; return;}
   for(int i=2;i<=n;i+=2){
    cout<<i<<' ';
   }
   for(int i=1;i<=n;i+=2){
    cout<<i<<" ";
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
    int T = 1;
   // std::cin >> T;
    while(T--) {
        
        solve();
    }
    return 0;
}