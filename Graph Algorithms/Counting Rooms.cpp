// https://cses.fi/problemset/task/1192

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
typedef long long ll;
 
 
void dfs(int r,int c,vector<string>& a,vector<vector<bool> >& vis,int n,int m){
    vis[r][c] = false;
 
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
 
    for(int i=0;i<4;++i){
        
            int nr = r+dr[i];
            int nc = c+dc[i]; 
 
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&(vis[nr][nc])){
                dfs(nr,nc,a,vis,n,m);
            }
        
    }
 
}
 
void solve() {
    int n,m;
    cin>>n>>m;
    
    vector<string> a(n);
    vector<vector<bool> > vis(n,vector<bool>(m,true));
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
 
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]=='#') vis[i][j] = false;
        }
    }
    
    int ans = 0;
 
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]=='.' && vis[i][j]){
                 dfs(i,j,a,vis,n,m);
                 ans++;
            }
            
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
 