// https://cses.fi/problemset/task/1666

// Components

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
#define mp make_pair
 
 //int dp[105][100005];
 
 
 void dfs(int i,vector<bool>& vis,vector<vector<int>>& g){
  vis[i]=true;
  for(auto &it : g[i]){
    if(!vis[it])
    dfs(it,vis,g);
  }
 
 }
 
void solve() {
   
   int n,m;
   cin>>n>>m;
   vector<vector<int>> g(n+1);
   vector<bool> vis(n+1,false);
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
    
  vector<int> comp;
 
  for(int i=1;i<=n;++i){
    if(!vis[i]){
      dfs(i,vis,g);
      comp.push_back(i);
    }
  }
  int r = comp.size();
  if(r==1){
    cout<<0;
    return;
  }
  cout<<r-1<<endl;
 
  for(int i=1;i<r;++i){
      cout<<comp[i]<<" "<<comp[i-1]<<endl;
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
    int T = 1;
    int x = 1;
    //std::cin >> T;
    while(T--) {
        // cout<<"Case #"<<x<<": ";
        // x++;
        solve();
    }
    return 0;
}
