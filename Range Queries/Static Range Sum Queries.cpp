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
    
    ll n,q;
    cin>>n>>q;

    ll i,a[n];

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll prefix[n+1]={0};
    prefix[0]=0;

    for(i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
    }

    ll l,r;

    while(q--){
        cin>>l>>r;

        cout<<prefix[r]-prefix[l-1]<<endl;
    }

    return 0;
}
