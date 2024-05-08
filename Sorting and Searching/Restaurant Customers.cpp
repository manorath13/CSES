// https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
 
int bs(vector<int>& a,int t){
      int l=0,h=a.size();
      int ans = 0;
      while(l<h){
          int m = (l+h)/2;
          if(a[m]<=t){
             // ans = m;
              l = m+1;
          }
          else{
              h = m;
          }
          
      }
      return l;
  }
 
 
void solve() {
    
   int n;
   cin>>n;
   vi a(n),b(n);
 
    for(int i=0;i<n;++i){
        cin>>a[i];
        cin>>b[i];
        b[i]++;
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    
   
    for(int i=0;i<n;++i){
       // cout<<bs(a,i)<<bs(b,i)<<endl;
        ans = max(ans,(i+1-bs(b,a[i])));
    }
    cout << ans;
 
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
    int x = 1;
    //std::cin >> T;
    while(T--) {
        // cout<<"Case #"<<x<<": ";
        // x++;
        solve();
    }
    return 0;
}
