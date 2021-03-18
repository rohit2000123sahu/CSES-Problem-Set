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
ll seg[800005];     // For segment tree
// Here the segment tree is storing the number of elements it has under it (including itself).

void build(ll index, ll low, ll high){
    if(low==high){
        seg[index]=1;           // If it is a leaf node then its value is 1
        return;
    }

    ll mid = (low+high)/2;
    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);

    seg[index]=seg[2*index+1]+seg[2*index+2];       // Summing up the number of elements
}

ll solve(ll index, ll low, ll high, ll pos){
    if(low==high){
        seg[index]=0;       // If we found the number then remove it making seg[index]=0
        return a[low];      //  Return that number
    }

    ll mid=(low+high)/2;
    ll ans;
    if(seg[2*index+1]>=pos){        // If numbers of elements are more in the left subtree
        ans=solve(2*index+1,low,mid,pos);
    }else{
        ans=solve(2*index+2,mid+1,high,pos-seg[2*index+1]); // If not then remove the number of elements in the left subtree
    }

    seg[index]=seg[2*index+1]+seg[2*index+2];      // Recomputing its value
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    build(0,0,n-1);     // Building the segment tree
    ll m=n;

    while(m--){
        ll pos;
        cin>>pos;

        cout<<solve(0,0,n-1,pos)<<" ";      // Solving the query
    }

    return 0;
}
