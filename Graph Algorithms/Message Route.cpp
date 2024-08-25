// https://cses.fi/problemset/task/1667

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
 
 
 
void solve() {
   
   int n,m;
   cin>>n>>m;
   vector<vector<int>> g(n+1);
   vector<bool> vis(n+1,false);
   vector<int> mindis(n+1,INT_MAX);
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
   
  queue<int> q;
  q.push(1);vis[1]=true;
  mindis[1] = 0;
 
  while(!q.empty()){
    int p = q.front();
    if(p==n) break;
    q.pop();
    for(auto &ch : g[p]){
      if(!vis[ch]){
        mindis[ch] = p;
        vis[ch] = true;
        q.push(ch);
      }
      
    }
  }
 
  if(mindis[n]==INT_MAX){
    cout<<"IMPOSSIBLE";
    return;
  }
  vector<int> ans;
  
  int p = n;
  ans.push_back(n);
  while(p!=1){
     ans.push_back(mindis[p]);
     p = mindis[p];
  }
  
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  for(auto &i : ans) cout<<i<<" ";
 
 
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
