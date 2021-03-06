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

vl adj[200005];
ll up[200005][20];

// In this problem we have used the binary liftinf concept

void fillUp(ll src, ll par){      // For finding the 2^i th parent of the current src
    up[src][0]=par;
    ll i;
    for(i=1;i<20;i++){
        if(up[src][i-1]!=-1){
            up[src][i]=up[up[src][i-1]][i-1];
        }else{
            up[src][i]=-1;
        }
    }

    for(auto c: adj[src]){
        if(c!=par){
            fillUp(c,src);
        }
    }
}

ll solve(ll src, ll k){
    if(src==-1 || k==0){
        return src;
    }

    ll i;
    for(i=19;i>=0;i--){
        if(k>=1<<i){
            return solve(up[src][i],k-(1<<i));
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,q;
    cin>>n>>q;

    ll i;

    for(i=2;i<=n;i++){
        ll temp;
        cin>>temp;
        adj[i].pb(temp);
        adj[temp].pb(i);
    }

    memset(up,-1,sizeof(sizeof(up)));

    fillUp(1,-1);

    while(q--){
        ll src,k;
        cin>>src>>k;

        cout<<solve(src,k)<<endl;

    }

    return 0;
}
