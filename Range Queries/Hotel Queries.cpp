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

ll seg[800005];
ll a[200005];

void build(ll index, ll low, ll high){
    if(low==high){
        seg[index]=a[low];
        return;
    }

    ll mid=(low+high)/2;

    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);

    seg[index]=max(seg[2*index+1],seg[2*index+2]);
    return;
}

ll solve(ll index, ll low, ll high, ll rooms){
    if(seg[index]<rooms){           // Check if rooms can be allocated or not
        return 0;
    }

    if(low==high){                  // If it is a leaf node
        seg[index]-=rooms;          // Substract the rooms
        return low+1;               // And return it 
    }

    ll ans=0;
    ll mid=(low+high)/2;

    if(seg[2*index+1]>=rooms){                    // If we could get an hotel in left then get it otherwise go for right because according to the problem we should 
                                                  // select the first hotel that has enough rooms to accomate the group
        ans=solve(2*index+1,low,mid,rooms);       // Remember do not return it directly we need to update our segment tree also
    }else{
        ans=solve(2*index+2,mid+1,high,rooms);
    }

    seg[index]=max(seg[2*index+1],seg[2*index+2]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    build(0,0,n-1);   // build the segment tree

    while(m--){
        ll rooms;
        cin>>rooms;
        cout<<solve(0,0,n-1,rooms)<<" ";
    }

    return 0;
}
