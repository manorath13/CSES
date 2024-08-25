// https://cses.fi/problemset/task/1624

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define pb push_back
#define ss second
#define ff first
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define frr(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define setbits(x)      __builtin_popcll(x)
#define minel(a) *min_element(all(a))
#define maxiel(a) *max_element(all(a))
 
////////////////////////////////////
 
template <class T>
istream &operator>>(istream &is, vector<T> &a)
{
  for (auto &x : a)
    is >> x;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a)
{
  for (const auto &x : a)
    os << x << ' ';
  return os;
}
//////////////////////////////////////////
int s = 8;
vector<string> v(s);
set<vector<vector<bool>>> st;
int c = 0;
bool check(int i,int j, vector<vector<bool>> &vis){
  
  for(int k=0;k<s;++k){
    if(vis[k][j]) return false;
    if(vis[i][k]) return false;
  }
  int ti=i,tj=j;
  while(ti>=0 && tj>=0){
    if(vis[ti][tj]) return false;
    ti--;tj--;
  }
  ti=i,tj=j;
  while(ti>=0 && tj<s){
    if(vis[ti][tj]) return false;
    ti--;tj++;
  }
  ti=i,tj=j;
  while(ti<s && tj>=0){
    if(vis[ti][tj]) return false;
    ti++;tj--;
  }
  while(i<s && j<s){
    if(vis[i][j]) return false;
    i++;j++;
  }
 
  return true;
}
 
void helper(int r, int n,vector<vector<bool>> &vis){
  if(n==0){
      c++;
     st.insert(vis);
     
     return;
  }
  
  for(int i=r;i<s;++i){
      
    for(int j=0;j<s;++j){
      if(!vis[i][j] && v[i][j]!='*'){
        if(check(i,j,vis)){
          vis[i][j]=true;
          
          helper(r+1,n-1,vis);
          
          vis[i][j]=false;
        }
      }
    }
  }
  
}
 
void solve(){
  
  for(int i=0;i<s;++i) cin>>v[i];
 
  vector<vector<bool>> vis(s,vector<bool>(s,false));
 
   helper(0,s,vis);
   int ans = st.size();
  cout<<ans<<nl;
    
}
 
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cout.tie(0);
    #ifndef ONLINE_JUDGE
   freopen("./input.txt","r",stdin);
   freopen("./output1.txt","w",stdout);
  #endif
 
  int T = 1,x=1;
  // cin >> T;
  while(T--){
    //  cout<<"Test Case #"<<x<<":"<<endl;x++;
      solve();
  }
  return 0;
}
