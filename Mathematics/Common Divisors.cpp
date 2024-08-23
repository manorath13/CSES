// https://cses.fi/problemset/result/9255984/

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
#define maxel(a) *max_element(all(a))

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

void solve(){

  int n;
  cin>>n;
  vector<int> a(n);
  cin>>a;
  int maxi = maxel(a)+1;
  vector<int> freq(maxi,0);
  for(auto &i : a) freq[i]++;
  for(int i=maxi;i>=1;--i){
    int c = 0;
    //check if i has multiples in array a
    //log(i)
    for(int j=i;j<maxi;j+=i){
      if(freq[j]>0) c+=freq[j];
    }
    if(c>1){
      cout<<i;
      return;
    }
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

