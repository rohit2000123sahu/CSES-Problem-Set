#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S secondP
#define PI 3.1415926535897932384626
#define all(x) x.begin(),x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

ll n;
vl adj[200005];
ll subordinates[200005];

ll solve(ll i){
    ll ans=0;
    for(auto c: adj[i]){
        ans+=solve(c);
    }
    subordinates[i]=ans;
    return ans+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;

    ll i,temp;

    for(i=2;i<=n;i++){
        cin>>temp;
        adj[temp].pb(i);
    }

    solve(1);

    for(i=1;i<=n;i++){
        cout<<subordinates[i]<<" ";
    }

    return 0;
}
