// https://cses.fi/problemset/task/1651

// Lazy Segment Tree

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
    vi tree,lazy;
    vi a;
    SegTree(int n, vi& a){
      tree.resize(4*n,0);
      lazy.resize(4*n,0);
      this->a = a;
    }
    void build(int i, int l, int h){
           if(l>h){
            return;
           }
           if(l==h){
 
            tree[i] = a[l];
            // cout<<i<<" "<<l<<" "<<tree[i]<<nl;
            return;
           }
 
           int mid = (l+h)/2;
 
           build(2*i+1,l,mid);
           build(2*i+2,mid+1,h);
 
           tree[i] = tree[2*i+1]+tree[2*i+2];
    }
 
    void rangeUpdate(int i, int low, int high, int l, int r, int val){
      if(lazy[i]!=0){
        // cout<<i<<" "<<l<<" "<<r<<" "<<lazy[i]<<nl;
        tree[i] += lazy[i]*(r-l+1);
        if(l!=r){
          lazy[2*i+1]+= lazy[i];
          lazy[2*i+2]+= lazy[i];
        }
        lazy[i]=0;
      }
      if(low>r || high<l) return;
      if(low<=l && high>=r){
        // cout<<i<<" "<<l<<" "<<r<<" "<<tree[i]<<nl;
        tree[i]+= val*(r-l+1);
        // cout<<i<<" "<<l<<" "<<r<<" "<<tree[i]<<nl;
        if(l!=r){
          lazy[2*i+1]+= val;
          lazy[2*i+2]+= val;
        }
        return;
      }
 
      int mid = (l+r)>>1;
      rangeUpdate(2*i+1,low,high,l,mid,val);
      rangeUpdate(2*i+2,low,high,mid+1,r,val);
      tree[i] = tree[2*i+1]+tree[2*i+2];
    }
 
    int LazyQuery(int i, int low, int high, int l, int r){
      if(lazy[i]!=0){
        // cout<<i<<" "<<l<<" "<<r<<" "<<tree[i]<<nl;
        tree[i] += lazy[i]*(r-l+1);
        if(l!=r){
          lazy[2*i+1]+= lazy[i];
          lazy[2*i+2]+= lazy[i];
        }
        lazy[i]=0;
      }
 
      if(low>r || high<l) return 0;
 
      if(low<=l && high>=r){
       // cout<<i<<" "<<l<<" "<<r<<" "<<tree[i]<<nl;
       return tree[i];
     }
 
      int mid = (l+r)>>1;
 
      return LazyQuery(2*i+1,low,high,l,mid)+LazyQuery(2*i+2,low,high,mid+1,r);
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
    int x;
    cin>>x;
    if(x==1){
      int a,b,val;
      cin>>a>>b>>val;
      a--;
      b--;
      seg.rangeUpdate(0,a,b,0,n-1,val);
    }
    else{
      int k;
      cin>>k;
      k--;
      int ans = seg.LazyQuery(0,k,k,0,n-1);
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