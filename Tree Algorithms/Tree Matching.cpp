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
ll dp[200005];
ll n;

ll solve(ll i, ll par){
    if(i>n){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];       // If the subproblem is already computed then return it.
    }

    ll ans=0;

    map< ll ,bool > m;     // Map to store if we have selected the its child then true and if we selected its grandchild then false
    
    for(auto c: adj[i]){
        if(c==par){         // If parent then continue
            continue;
        }

        ll temp1=solve(c,i);    // For child  (also passing the parent)
        ll temp2=0;             // For grand child

        for(auto d: adj[c]){    // Computation for grand child
            if(d==i){       
                continue;
            }
            temp2+=solve(d,c);  
        }

        if(temp1>temp2){        // If maximum is for child then select it.
            ans+=temp1;
            m[c]=true;
        }else{                 //  If maximum is for grand child then include it.
            ans+=temp2;
            m[c]=false;
        }

    }

    for(auto c: m){             // Now we will loop through the map and will see if we have selected any grand child 
        if(c.second==false){    // If we have selected any grand child then we can increment ourr answer by 1 because we can consider one more edge as (parent, child)
            ans++;
            break;
        }
    }

    dp[i]=ans;


    return dp[i];           // Returning the ans after storing it in dp

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;

    ll i;
    ll u,v;

    for(i=0;i<n-1;i++){
        cin>>u>>v;
        adj[v].pb(u);
        adj[u].pb(v);
    }

    memset(dp,-1,sizeof(dp));
    
    cout<<solve(1,-1)<<endl;

  
    return 0;
}
