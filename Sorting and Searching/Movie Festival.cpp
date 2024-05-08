// https://cses.fi/problemset/task/1629


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
  int n;
  cin>>n;
  vector<pair<int,int> > p(n);
  for(int i=0;i<n;++i){
    cin>>p[i].first;
    cin>>p[i].second;
  }
  sort(p.begin(),p.end());
  int ans = 1;
  int end = p[0].second;
  for(int i=1;i<n;++i){
    if(p[i].first>=end){
      ans++;
      end = p[i].second;
    }
    else{
      end = min(end,p[i].second);
    }
  }
 
  cout<<ans<<endl;
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