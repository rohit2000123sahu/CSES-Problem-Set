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

void build(ll index, ll low, ll high){
    if(low==high){
        seg[index]=a[low];
        return;
    }

    ll mid = (low+high)/2;


    build(2*index+1,low,mid);       // For Left child
    build(2*index+2,mid+1,high);    // For right child

    seg[index]=min(seg[2*index+1],seg[2*index+2]);
    return;
}

ll solve(ll index,ll low, ll high, ll l ,ll r){
    if(low>=l && high<=r){      // Completely Overlap 
        return seg[index];
    }

    if(high<l || low>r){
        return LONG_MAX;
    }

    ll mid = (low+high)/2;

    ll left = solve(2*index+1,low,mid,l,r);
    ll right = solve(2*index+2,mid+1,high,l,r);

    return min(left,right);


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
        ll l,r;
        cin>>l>>r;
        l--;
        r--;

        cout<<solve(0,0,n-1,l,r)<<endl;
    }

    return 0;
}
