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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,target,sum;
    cin>>n>>target;

    ll a[n];
    ll i;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ml umap;
    sum=0;
    ll ans=0;

    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum==target){
            ans++;
        }
        ll temp = sum-target;
        ans+=umap[temp];
        umap[sum]++;
    }

    cout<<ans<<endl;

    return 0;
}
