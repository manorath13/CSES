// https://cses.fi/problemset/task/1640

#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
typedef long long ll;
 
 
 
 
void solve() {
    
   int  n,x ;
   cin>>n>>x;
   
   vector<pair<int,int>> p(n);
   
   for(int i=0;i<n;++i){
       cin>>p[i].first;
       p[i].second=i+1;
   }
   sort(p.begin(),p.end());
   
   int i=0,j=n-1;
   while(i<j){
       if(p[i].first+p[j].first==x){
           cout<<p[i].second<<" "<<p[j].second;
           return;
       }
       else if(p[i].first+p[j].first<x){
           i++;
       }
       else{
           j--;
       }
   }
   cout<<"IMPOSSIBLE";
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
