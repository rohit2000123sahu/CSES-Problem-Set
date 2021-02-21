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
#define INF 1e18
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

    vpl adj[n+1];       //Adjacency list
    ll a,b,c,i;

    while(m--){
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
    }

    ll dist[n+1];       // Distance

    for(i=1;i<=n;i++){
        dist[i]=INF;
    }

    priority_queue< pl, vector< pl > , greater< pl > > q;
    bool visited[n+1];

    memset(visited,false,sizeof(visited));

    q.push(mp(0,1));        // Inserting the initial distance and source node
    dist[1]=0;

    while(!q.empty()){
        pl curr=q.top();
        q.pop();

        ll u =curr.S;       // Here u is the source node

        if(visited[u]==true){   // It is because if we have inserted in it queue multiple times (Let say on the first time it was (5,x) , second time (4,x) and thrid time(3,x))
            continue;           // On the first time it has been processed with (3,x) then it not needed to be processed again and again because nothing will get updated. Hence just skip it.
        }

        visited[u]=true;    

        for(auto c: adj[u]){
            ll v=c.S;       // Here v is the destination node
            ll weight=c.F;  // This is the weight of the vertex u to v;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                q.push(mp(dist[v],v));
            }
        }
    }

    for(i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}
