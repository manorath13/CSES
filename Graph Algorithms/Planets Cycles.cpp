// https://cses.fi/problemset/task/1751

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
#define setbits(x)      __builtin_popcll(x)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef long long ll;
 
 const int N = (int)2e5 +5;
 
 
int dp[N];
int a[N];
int vis[N];
queue<int> q;
int c = 0;
 
void dfs(int i){
    q.push(i);
    if(vis[i]){
        c+=dp[i];
        return;
    }
    vis[i] = 1;
    c++;
    dfs(a[i]);
}
 
void solve() {
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;++i) {
    cin>>a[i];
    a[i]--;
    }
    
    for(int i=0;i<n;++i){
        if(!vis[i]){
            c = 0;
            dfs(i);
            int d = 1;
            while(!q.empty()){
                if(q.front()==q.back()){
                    d = 0;
                }
                int h = q.front();
                q.pop();
                
                dp[h]=c;
                c-=d;
            }
        }
    }
    

   for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
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
