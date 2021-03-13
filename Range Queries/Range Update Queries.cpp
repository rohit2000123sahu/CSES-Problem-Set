#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define all(x) x.begin(),x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;
 
ll a[200005];
ll seg[800005];
ll lazy[800005];
 
void build(ll index,ll low, ll high){     // For building the segment tree
    if(low==high){
        seg[index]=a[low];
        return;
    }
 
    ll mid=(low+high)/2;
    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);
 
    seg[index]=seg[2*index+1]+seg[2*index+2];
    return;
}
 
void update(ll index,ll low,ll high, ll l ,ll r, ll u){   // For updating the segment tree
    if(lazy[index]!=0){                                   // Checking if any lazy propogation is left or not
        seg[index]+=(high-low+1)*lazy[index];             // If yes then update it
        if(low!=high){                                    // Checking whether it is leaf node or not. If leaf node then only propogate the lazy update to its child otherwise not
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    
    if(low>=l && high<=r){
        seg[index]+=(high-low+1)*u;
        if(low!=high){
            lazy[2*index+1]+=u;
            lazy[2*index+2]+=u;
        }
        return;
    }
    
    if(low>r || high<l){
        return;
    }
 
    ll mid=(low+high)/2;
 
    update(2*index+1,low,mid,l,r,u);
    update(2*index+2,mid+1,high,l,r,u);
    
    seg[index]=seg[2*index+1]+seg[2*index+2];
}
 
ll query(ll index,ll low, ll high,ll k){        // For getting the answer of any subquery
    if(lazy[index]!=0){                         // Before answering the query we should check whether the node has any lazy index or not. If yes then please solve it first.
        seg[index]+=(high-low+1)*lazy[index];
        if(low!=high){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
 
    if(low>k || high<k || low>high){
        return 0;
    }
 
 
    if(low==k && high==k){
        return seg[index];
    }
 
    ll mid=(low+high)/2;
 
    ll left = query(2*index+1, low, mid, k);
    ll right = query(2*index+2,mid+1,high,k);
 
    return left+right;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,q;
    cin>>n>>q;
 
    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
 
    build(0,0,n-1);
    while(q--){
        ll type;
        cin>>type;
 
        if(type==1){
            ll l,r,u;
            cin>>l>>r>>u;
            l--;
            r--;
            update(0,0,n-1,l,r,u);
        }else{
            ll k;
            cin>>k;
            k--;
            cout<<query(0,0,n-1,k)<<endl;
        }
    }

    return 0;
}
