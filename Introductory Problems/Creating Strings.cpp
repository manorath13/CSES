// https://cses.fi/problemset/task/1622

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
 
string s;
int n;
set<string> ans;
int c = 0;
void helper(vector<bool>& vis, string temp){
  if((int)temp.size()==n){
    ans.insert(temp);
  }
  for(int i=0;i<n;++i){
    if(!vis[i]){
      string x = temp;
      x+=s[i];
      vis[i]=true;
      helper(vis,x);
      vis[i]=false;
    }
  }
}
 
void solve(){
  cin>>s;
  n = s.size();
  sort(all(s));
  vector<bool> vis(n,false);
  string temp = "";
  helper(vis,temp);
  c = ans.size();
  cout<<c<<nl;
  for(auto &i : ans){
    cout<<i<<nl;
  }
    
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
