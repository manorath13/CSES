// https://cses.fi/problemset/task/1079

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
 
const int N = (int)1e6+1;
 
int powermod(int x,  int y) //(x^y)%MOD
{
    int res = 1; 
 
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
int fact[N];
void fun(){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=N;++i){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
}
 
 
void solve(){
   
   int n,r;
   cin>>n>>r;
    
    int ncr = ((fact[n]*powermod(fact[n-r],MOD-2))%MOD*powermod(fact[r],MOD-2))%MOD;
 
    if(n<r) ncr = 0;
    
    cout<<ncr<<nl;
   
    
}
 
 
signed main() {
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cout.tie(0);
    #ifndef ONLINE_JUDGE
   freopen("./input.txt","r",stdin);
   freopen("./output1.txt","w",stdout);
  #endif
  fun();
  int T = 1,x=1;
  cin >> T;
  while(T--){
    //  cout<<"Test Case #"<<x<<":"<<endl;x++;
      solve();
  }
  return 0;
}
