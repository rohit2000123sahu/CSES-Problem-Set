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

    for(i=2;i<=n;i++){
        ll temp;
        cin>>temp;
        adj[i].pb(temp);
        adj[temp].pb(i);
    }

    memset(up,-1,sizeof(sizeof(up)));

    fillUp(1,-1);
    fillLvl(1,-1,0);

    while(q--){
        ll a,b;
        cin>>a>>b;

        if(lvl[a]<lvl[b]){
            swap(a,b);
        }

        a=jump(a,lvl[a]-lvl[b]);    // Making level of a and b same

        if(a==b){                   // If after making level of a and b same if both become equal then print it.
            cout<<a<<endl;
            continue;
        }
                                    // Else we will try to find both the nodes to the maximum they could be lifted such that a!=b
        for(i=19;i>=0;i--){
            if(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
            }
        }

        cout<<up[a][0]<<endl;     // After that just printing the parent of either a or b. It would be our LCA.
        
    }



    return 0;
}
