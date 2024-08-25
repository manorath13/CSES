// https://cses.fi/problemset/task/1649

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
 
 
class SegTree{
  public:
    vi tree;
    vi a;
    SegTree(int n, vi& a){
      tree.resize(4*n);
      this->a = a;
    }
    void build(int i, int l, int h){
           if(l>h){
            return;
           }
           if(l==h){
            tree[i] = a[l];
            return;
           }
 
           int mid = (l+h)/2;
 
           build(2*i+1,l,mid);
           build(2*i+2,mid+1,h);
 
           tree[i] = min(tree[2*i+1],tree[2*i+2]);
    }
 
    void query(int i,int l,int h,int ind,int x){
      if(h<ind || l>ind){
        return;
      }
      if(l==h && l==ind){
        tree[i] = x;
        return;
      }
      int mid = (l+h)/2;
      query(2*i+1,l,mid,ind,x);
      query(2*i+2,mid+1,h,ind,x);
      tree[i] = min(tree[2*i+1],tree[2*i+2]);
    }
    int query1(int i,int l,int h, int a, int b)
    {
      if(l>b || h<a){
        return INT_MAX;
      }
      if(l>=a && h<=b){
        return tree[i];
      }
      int mid = (l+h)/2;
       return min(query1(2*i+1,l,mid,a,b),query1(2*i+2,mid+1,h,a,b));
    }
 
};
 
void solve(){
  
   int n,q;
   cin>>n>>q;
   vi a(n);
   cin>>a;
   SegTree seg(n,a);
   seg.build(0,0,n-1);
   while(q--){
    int o,a,b;
    cin>>o>>a>>b;
    // cout<<o<<nl;
    if(o==1){
      a--;
      seg.query(0,0,n-1,a,b);
    }
    else{
      a--;b--;
      int ans = seg.query1(0,0,n-1,a,b);
      cout<<ans<<nl;
    }
   }
 
    
}
 
 
signed main() {
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cout.tie(0);
    #ifndef ONLINE_JUDGE
   freopen("./input.txt","r",stdin);
   freopen("./output2.txt","w",stdout);
  #endif
  int T = 1,x=1;
  //cin >> T;
  while(T--){
    //  cout<<"Test Case #"<<x<<":"<<endl;x++;
      solve();
  }
  return 0;
}
