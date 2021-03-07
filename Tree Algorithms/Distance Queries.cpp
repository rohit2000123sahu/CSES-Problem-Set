// This code is slight modification of company queries 2
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
ll lvl[200005];

ll power(ll a, ll b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    ll temp = power(a,b/2);

    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

void fillUp(ll src, ll par){
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

void fillLvl(ll src, ll par, ll level){
    lvl[src]=level;
    
    for(auto c: adj[src]){
        if(c!=par){
            fillLvl(c,src,level+1);
        }
    }
    
}

ll jump(ll src, ll k){
    if(src==-1 || k==0){
        return src;
    }

    ll i;
    for(i=19;i>=0;i--){
        if(k>=1<<i){
            return jump(up[src][i],k-(1<<i));
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

    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(up,-1,sizeof(sizeof(up)));

    fillUp(1,-1);
    fillLvl(1,-1,0);

    while(q--){
        ll a,b;
        ll ans=0;
        cin>>a>>b;
        // cout<<ans<<endl;

        if(lvl[a]<lvl[b]){
            swap(a,b);
        }

        ans+=lvl[a]-lvl[b];
        a=jump(a,lvl[a]-lvl[b]);

        if(a==b){
            cout<<ans<<endl;
            continue;
        }

        for(i=19;i>=0;i--){
            if(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
                ans+=2*power(2,i);    //For a to child of LCA and b to child of LCA
            }
        }

        cout<<ans+2<<endl;          // For a to LCA and b to LCA 

        
    }



    return 0;
}
