// https://cses.fi/problemset/task/1158

#include<iostream>
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
   
   int n,x;
   cin>>n>>x;
 
  vector<int> b(n),p(n);
  for(int i=0;i<n;++i) cin>>b[i];
  for(int i=0;i<n;++i) cin>>p[i];
 
  //vector<vector<int> > dp(n+1,vector<int>(x+1,0));
  vector<int> prevdp(x+1,0);
  for(int i=b[0];i<=x;++i){
      prevdp[i] = p[0];
  }
  for(int i=1;i<n;++i){
    vector<int> currdp(x+1,0);
    for(int j=0;j<=x;++j){
      int nt=0;
      
      nt = prevdp[j];
      int take = 0;
      if(j>=b[i]){
          take = p[i]+prevdp[j-b[i]];
      }
      
      currdp[j] = max(take,nt);
    }
    prevdp = currdp;
  }
 
   
   cout<<prevdp[x];
 
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