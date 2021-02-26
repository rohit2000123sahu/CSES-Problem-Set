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

vl adj[100005];
ll dp[100005];
ll print[100005];       // For printing the result
ll n;

ll solve(ll i){
    if(i==n){
        return 1;      // If we have reached the nth city then only return 1;
    }

    if(dp[i]!=-1){
        return dp[i];      // Memoization
    }

    ll ans=0;
    ll nxt=-1;            // For storing the next element in the city

    for(auto c: adj[i]){
        ll temp=solve(c);
        if(ans<temp){
            ans=temp;
            nxt=c;
        }
    }

    if(ans==0){         // If ans==0 then we could not reach the nth city hence this case should not be considered
        // cout<<i<<" ";
        ans=-1e7;
    }

    dp[i]=ans+1;
    print[i]=nxt;

    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll m;
    cin>>n>>m;

    ll u,v;

    while(m--){
        cin>>u>>v;
        adj[u].pb(v);
    }

    memset(dp,-1,sizeof(dp));
    memset(print,-1,sizeof(print));

    solve(1);

    // for(ll i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }

    if(dp[1]<=0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<dp[1]<<endl;
        ll temp=1;
        while(temp!=-1){
            cout<<temp<<" ";
            temp=print[temp];
        }
    }

    



    return 0;
}
