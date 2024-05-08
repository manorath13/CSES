// https://cses.fi/problemset/task/1092

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
 
 
 
void solve(){
  
  int n;
  cin>>n;
  if(n%4==0){
    vi a,b;
    for(int i=1;i<=n;++i){
      if(i%4==0 || i%4==1){
        a.pb(i);
      }
      else{
        b.pb(i);
      }
    }
    cy;
    cout<<a.size()<<nl;
    cout<<a<<nl;
    cout<<b.size()<<nl;
    cout<<b<<nl;
    return;
  }
  if((n+1)%4==0){
    vi a,b;
    a.pb(1);a.pb(2);b.pb(3);
    for(int i=4;i<=n;++i){
      if(i%4==0 || i%4==3){
        a.pb(i);
      }
      else{
        b.pb(i);
      }
    }
    cy;
    cout<<a.size()<<nl;
    cout<<a<<nl;
    cout<<b.size()<<nl;
    cout<<b<<nl;
    return;
  }
  
  cn;
    
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
