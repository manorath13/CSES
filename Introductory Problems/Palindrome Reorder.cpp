// https://cses.fi/problemset/task/1755

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
  
  
  string s;
  cin>>s;
  int n = s.size();
  int f[26] = {0};
  for(auto &i : s){
    f[i-'A']++;
  }
  int c=0;
  for(int i=0;i<26;++i){
    if(f[i]&1) c++;
  }
  if(c>1){
    cout<<"NO SOLUTION";
    return;
  }
  vector<char> v(n);
  int i=0,j=n-1;
  for(int k=0;k<26;++k){
    int x = f[k];
    if(x&1) v[n/2] = char(65+k);
    for(int c=0;c<x/2;++c){
      v[i]=char(65+k);
      v[j]=char(k+65);
      i++;j--;
    }
  }
  for(auto &i:v){
    cout<<i;
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
