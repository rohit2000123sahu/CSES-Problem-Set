// Please have a look on segment trees before proceeding to this question.
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

void build(ll index,ll low, ll high){
    if(low==high){
        seg[index]=a[low];
        return;
    }
    ll mid=(low+high)/2;
    build(2*index+1,low,mid);       // For left child
    build(2*index+2,mid+1,high);    // For right child

    seg[index]=seg[2*index+1]+seg[2*index+2];   // Value of parent is equal to sum of its right child and its left child
}

ll solve(ll index, ll low, ll high, ll l ,ll r){
    if(low>=l && high<=r){  // Overlap Condition
        return seg[index];
    }

    if(low>r || high<l){        // If no element present in the specific sub tree then sub of that particular subtree would be 0 
        return 0;
    }

    ll mid=(low+high)/2;

    ll left=solve(2*index+1,low,mid,l,r);   // Left Child
    ll right=solve(2*index+2,mid+1,high,l,r); // For right child

    return left+right;
}

void update(ll index, ll low, ll high, ll k , ll u){    // Here k is the new postion where we want to update
    if(low==k && high==k){              // On finding the postion K we will update
        seg[index]=u;
        return;
    }

    if(low>k || high<k){
        return;
    }

    ll mid=(low+high)/2;
    update(2*index+1,low,mid,k,u);
    update(2*index+2,mid+1,high,k,u);
    seg[index]=seg[2*index+1]+seg[2*index+2];     // On backtracking we will update our results of all nodes that belong to our path.
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
            ll k,u;
            cin>>k>>u;
            k--;

            update(0,0,n-1,k,u);

        }else{
            ll a,b;
            cin>>a>>b;
            a--;
            b--;

            cout<<solve(0,0,n-1,a,b)<<endl;

        }
    }

    return 0;
}
