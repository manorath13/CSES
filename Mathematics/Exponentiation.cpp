// https://cses.fi/problemset/task/1095

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
 
int powermod(long long x,  int y) //(x^y)%MOD
{
    if(x==0 && y==0) return 1;
    long long res = 1; 
 
    x = x % MOD; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
 
        y = y>>1; 
        x = (x*x) % MOD;
    }
    return res;
}
 
 
void solve() {
  int a,b;
  cin>>a>>b;
  int ans = powermod(a,b);
  cout << ans << "\n";
 
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
    std::cin >> T;
    while(T--) {
        // cout<<"Case #"<<x<<": ";
        // x++;
        solve();
    }
    return 0;
}
