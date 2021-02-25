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
#define INF 1e17
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,k;
    cin>>n>>m>>k;

    vpl adj[n+1];
    ll i,j;
    ll u,v,weight1,weight2;

    for(i=0;i<m;i++){
        cin>>u>>v>>weight1;
        adj[u].pb(mp(weight1,v));
    }

    ll dist[n+1][k];

    for(i=0;i<=n;i++){
        for(j=0;j<k;j++){
            dist[i][j]=INF;
        }
    }

    dist[1][0]=0;

    priority_queue< pl ,vpl, greater< pl > > q;
    q.push(mp(0,1));

    while(!q.empty()){
        pl curr = q.top();
        q.pop();

        u=curr.S;
        weight1=curr.F;

        if(dist[u][k-1]<weight1){
            continue;
        }

        for(auto c: adj[u]){
            v=c.S;
            weight2=c.F;

            if(dist[v][k-1]>weight1+weight2){
                dist[v][k-1]=weight1+weight2;
                q.push(mp(dist[v][k-1],v));
                sort(dist[v],dist[v]+k);
            }
            
        }
        
    }

    for(i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }



    return 0;
}
