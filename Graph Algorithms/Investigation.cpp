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
    
    ll n,m;
    cin>>n>>m;

    vpl adj[n+1];
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    ll u,v,weight;

    while(m--){
        cin>>u>>v>>weight;
        adj[u].pb(mp(weight,v));
    }

    ll minimum[n+1];
    ll maximum[n+1]={0};

    ll i;
    ll dist[n+1];

    for(i=0;i<=n;i++){
        minimum[i]=1e18;
        dist[i]=1e18;
    }

    ll routes[n+5]={0};
    routes[1]=1;            // There is one way to reaching to the first node

    dist[1]=0;
    minimum[1]=0;
    maximum[1]=0;
    priority_queue< pl, vpl, greater< pl > > q;

    q.push(mp(0,1));

    while(!q.empty()){
        pl curr=q.top();
        q.pop();

        u=curr.S;

        if(visited[u]){
            continue;
        }
        visited[u]=true;

        for(auto c: adj[u]){
            v=c.S;
            weight=c.F;

            if(weight+dist[u]==dist[v]){
                routes[v]+=routes[u];
                routes[v]%=MOD;
                minimum[v]=min(minimum[u]+1,minimum[v]);
                maximum[v]=max(maximum[u]+1,maximum[v]);
                dist[v]=weight+dist[u];
            }

            if(weight+dist[u]<dist[v]){
                dist[v]=weight+dist[u];
                routes[v]=routes[u];
                minimum[v]=minimum[u]+1;
                maximum[v]=maximum[u]+1;
                q.push(mp(dist[v],v));
            }
        }
    }

    cout<<dist[n]<<" "<<routes[n]<<" "<<minimum[n]<<" "<<maximum[n]<<endl;


    return 0;
}
