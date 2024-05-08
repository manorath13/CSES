// https://cses.fi/problemset/task/1069

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
   string s;
   cin>>s;
   int ans=0,c=1;
 
   for(int i=1;i<s.size();++i){
    if(s[i]==s[i-1]){
        c++;
    }
    else{
        ans = max(ans,c);
        c=1;
    }
   }
   ans = max(ans,c);
   cout<<ans;
    
    
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
