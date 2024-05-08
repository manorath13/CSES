// https://cses.fi/problemset/task/1648

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
typedef vector<int> vi;
const int  N= 100005;
int a[2*N],seg[8*N];
void build(int ind,int low,int high){
    if(low==high){
        seg[ind]=a[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
 
}
int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(r<low || l>high)return 0;
    int mid = (low+high)/2;
    return query(2*ind+1,low,mid,l,r)+query(2*ind+2,mid+1,high,l,r);
 
}
void update(int ind,int d,int k,int low,int high){
         if(k>=low && k<=high){
            seg[ind]+=d;
         }
         if(low==high) return;
         if(k<low || k>high) return;
         int mid = (low+high)/2;
         if(k>=low && k<=mid)
           update(2*ind+1,d,k,low,mid);
         if(k>mid && k<=high)
           update(2*ind+2,d,k,mid+1,high);
}
void solve() {
    int n,q;
    cin>>n>>q;
    
    for(int i=0;i<n;++i) cin>>a[i];
    build(0,0,n-1);
    while(q--){
        int o;
        cin>>o;
        if(o==1){
            int k,u;
            cin>>k>>u;
            k--;
            update(0,u-a[k],k,0,n-1);
            a[k]=u;
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<query(0,0,n-1,l,r)<<endl;
        }
    }
    
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
    int T = 1;
   // std::cin >> T;
    while(T--) {
        
        solve();
    }
    return 0;
}
